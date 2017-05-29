## @package this is the control module of tx.
 # this module will operate with the tx data, inserting, deleting,
 # listing the objects in the database

import tx.db
import tx.model

session = tx.db.newsession()

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

