import flask
import tx.db
import tx.model
import tx.control

import json

tx.db.base.metadata.create_all(tx.db.engine)
app = flask.Flask(__name__)

@app.errorhandler(404)
def not_found(error):
    return flask.make_response(
            flask.jsonify(
                {
                    'type' : 'error',
                    'msg': 'Not found'
                }), 404)

@app.errorhandler(400)
def not_found(error):
    return flask.make_response(
            flask.jsonify(
                {
                    'type' : 'error',
                    'msg': 'Bad request'
                }), 400)

def txjson(obj):
    if isinstance(obj, list):
        j = []
        for i in obj:
            j.append(i.__json__())

        return j
    else:
        return obj.__json__()

def txerror(msg, code = 404):
    json_response = flask.jsonify(
            {
                'type' : 'error',
                'msg'  : msg
            })

    return flask.make_response(json_response, code)

## get the account with number `account_number`
@app.route('/accounts/<int:account_number>', methods=['GET'])
def accounts(account_number):

    account = tx.control.get_account(account_number)

    if account == None:
        return txerror('Cannot found account with number %d' % account_number)

    return flask.jsonify(txjson(account))

## get and translate to json the bank with `bank_number`
@app.route('/banks/<int:bank_number>', methods=['GET'])
def bank(bank_number):

    bank = tx.control.get_bank(bank_number)

    if bank == None:
        return txerror('Cannot found bank with number %d' % bank_number)

    return flask.jsonify(txjson(bank))

@app.route('/banks', methods=['GET'])
def banks():
    banks = tx.control.get_banks()
    return flask.jsonify(banks=txjson(banks))

@app.route('/clients/<string:cpf>', methods=['GET'])
def clients(cpf):
    client = tx.control.get_client(cpf)

    if client == None:
        return txerror('Cannot found client with cpf %s' % cpf)

    return flask.jsonify(txjson(client))

@app.route('/withdraw', methods=['PUT'])
def withdraw():
    withdraw_request = json.loads(flask.request.get_data())

    if( not 'type' in withdraw_request or
        withdraw_request['type'] != 'withdraw' or
        not 'account_id' in withdraw_request or
        not 'value' in  withdraw_request or
        not 'withdraw_method' in withdraw_request):
        flask.abort(400)

    withdraw_method = withdraw_request['withdraw_method']
    withdraw_value  = withdraw_request['value']

    account = tx.control.get_account(withdraw_request['account_id'])

    if account == None:
        return txerror('Cannot found account with number %d' % withdraw_request['account_id'])

    try:
        tx.control.withdraw(account, withdraw_value, withdraw_method)
        return flask.make_response(flask.jsonify(
                { 'status' : 'Accepted' }), 202 )
    except tx.control.ControlError as error:
        return txerror(error.msg, error.code)

@app.route('/deposit', methods=['PUT'])
def deposit():
    deposit_request = json.loads(flask.request.get_data())

    if( not 'type' in deposit_request or
        deposit_request['type'] != 'deposit' or
        not 'account_id' in deposit_request or
        not 'value' in deposit_request or
        not 'deposit_method' in deposit_request):
        flask.abort(400)

    deposit_value = deposit_request['value']
    deposit_method = deposit_request['deposit_method']

    account = tx.control.get_account(deposit_request['account_id'])

    if account == None:
        return txerror('Cannot found account with number %d'
                        % deposit_request['account_id'])

    try:
        tx.control.deposit(account, deposit_value, deposit_method)
        return flask.make_response(flask.jsonify(
                { 'status' : 'Accepted' }), 202 )
    except tx.control.ControlError as error:
        return txerror(error.msg, error.code)

@app.route('/transaction', methods=['POST'])
def transaction():
    transaction_request = json.loads(flask.request.get_data())

    if( not 'type' in transaction_request or
        transaction_request['type'] != 'transaction' or
        not 'sender_id' in transaction_request or
        not 'receiver_id' in transaction_request or
        not 'sender_method' in transaction_request or
        not 'receiver_method' in transaction_request or
        not 'value' in transaction_request):
        flask.abort(400)

    sender_id = transaction_request['sender_id']
    receiver_id = transaction_request['receiver_id']
    sender_method = transaction_request['sender_method']
    receiver_method = transaction_request['receiver_method']
    value = transaction_request['value']

    sender_account = tx.control.get_account(sender_id)
    receiver_account = tx.control.get_account(receiver_id)

    if sender_account == None:
        return txerror('Cannot found account with number %d'
                        % sender_id)

    if receiver_account == None:
        return txerror('Cannot found account with number %d'
                        % receiver_id)

    try:
        tx.control.transaction(
                sender_account,
                receiver_account,
                sender_method,
                receiver_method,
                value)

        return flask.make_response(flask.jsonify(
                { 'status' : 'Accepted' }), 202 )
    except tx.control.ControlError as error:
        return txerror(error.msg, error.code)

if __name__ == '__main__':
    app.run(debug=True, threaded=True)
