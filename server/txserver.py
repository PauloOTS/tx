import flask
import tx.db
import tx.model
import tx.control

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
        return txerror('Cannot found client with cpf %d' % cpf)

    return flask.jsonify(txjson(client))

if __name__ == '__main__':
    app.run(debug=True)
