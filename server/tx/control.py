## @package this is the control module of tx.
 # this module will operate with the tx data, inserting, deleting,
 # listing the objects in the database

import tx.db
import tx.model

session = tx.db.newsession()

class ControlError(BaseException):

    def __init__(self, msg, code):
        self.msg = msg
        self.code = code

## get a account with the id `id`
 # @param id the number of the account
 #
 # @return the model.Account with the id == `id` in case
 #         of the account exists, None otherwise
def get_account(id):

    account = session.query(tx.model.Account)\
               .filter(tx.model.Account.id == id)\
               .one_or_none()

    return account

## get a bank with the id `id`
 # @param id the number of the bank
 #
 # @return the model.Bank with the id == `id` in case
 #         of the bank exists, None otherwise
def get_bank(id):
    bank = session.query(tx.model.Bank)\
            .filter(tx.model.Bank.id == id)\
            .one_or_none()
    return bank

## get a list of all banks supported by tx
 # @return a list of model.Bank
def get_banks():
    bank = session.query(tx.model.Bank).all()
    return bank

## get client with cpf `cpf`
def get_client(cpf):
    client = session.query(tx.model.Client)\
              .filter(tx.model.Client.cpf == cpf)\
              .one_or_none()
    return client

## Realize the withdraw of `value` in `account` using
 # the savings or the current account specified by `method`
 #
 # @param account the model.Account to realize the withdraw
 # @param value   the value of the withdraw
 # @param method  must be 'saving' or 'current'
def withdraw(account, value, method):
    if value <= 0:
        raise ControlError('The withdraw value cannot be 0 or less', 400)

    with account.lock:
        if method == 'current':
            if value > account.balance:
                raise ControlError(
                        'The account %d does not have the money to withdraw'
                        % account.id, 400)
            else:
                account.balance -= value
                session.commit()

        elif method == 'saving':
            if value > account.saving:
                raise ControlError(
                        'The account %d does not have the money to withdraw'
                        % account.id, 400)
            else:
                account.saving -= value
                session.commit()

        else:
            raise ControlError(
                    'The withdraw method must be saving or current', 400)


## Realize the withdraw of `value` in `account` using
 # the savings or the current account specified by `method`
 #
 # @param account the model.Account to realize the withdraw
 # @param value   the value of the withdraw
 # @param method  must be 'saving' or 'current'
def deposit(account, value, method):
    if value <= 0:
        raise ControlError('The deposit value cannot be 0 or less', 400)

    with account.lock:
        if method == 'current':
            account.balance += value
            session.commit()

        elif method == 'saving':
            account.saving += value
            session.commit()

        else:
            raise ControlError(
                    'The deposit method must be saving or current', 400)


## Realize a transaction from `sender` to `receiver` of value `value`
 #
def transaction(sender, receiver, sender_method, receiver_method, value):
    if value <= 0:
        raise ControlError('The transaction value cannot be 0 or less', 400)

    if( (sender_method != 'saving' and
        sender_method != 'current') or
        (receiver_method != 'saving' and
        receiver_method != 'current')):
        raise ControlError(
                'The transaction method must be saving or current', 400)

    if sender_method == 'current':
        sender_method = 'balance'
    if receiver_method == 'current':
        receiver_method = 'balance'

    with sender.lock:
        sender_amount = getattr(sender, sender_method)

        if sender_amount < value:
            raise ControlError(
                    'The account %d does not have the money to transact'
                    % sender.id, 400)

        setattr(sender, sender_method, sender_amount - value)
        setattr(receiver, receiver_method,
                getattr(receiver, receiver_method) + value)

        session.commit()

