import tx.db as db
import sqlalchemy.orm
import sqlalchemy as sql

class Client(db.base):
    __tablename__ = 'clients'

    cpf  = sql.Column(sql.String, primary_key=True)
    name = sql.Column(sql.String)

    accounts = sql.orm.relationship('Account', back_populates='client')

    def __json__(self):
        accounts = []
        for a in self.accounts:
            accounts.append(a.__json__())

        return {
            'type': self.__tablename__,
            'cpf' : self.cpf,
            'name': self.name,
            'accounts' : accounts
        }

class Bank(db.base):
    __tablename__ = 'banks'

    id    =  sql.Column(sql.Integer,  primary_key=True)
    name  =  sql.Column(sql.String)

    branches = sql.orm.relationship('Branch', back_populates='bank')

    def __json__(self):
        return {
            'type' : self.__tablename__,
            'id'   : self.id,
            'name' : self.name
        }


class Branch(db.base):
    __tablename__ = 'branches'

    id        = sql.Column(sql.Integer, primary_key=True)
    bank_id   = sql.Column(sql.Integer, sql.ForeignKey('banks.id'))
    bank      = sql.orm.relationship('Bank', back_populates='branches')

    accounts  = sql.orm.relationship('Account', back_populates='branch')

class Account(db.base):
    __tablename__ = 'accounts'

    id          = sql.Column(sql.Integer, primary_key=True)
    client_cpf  = sql.Column(sql.String, sql.ForeignKey('clients.cpf'))
    branch_id   = sql.Column(sql.Integer, sql.ForeignKey('branches.id'))

    balance     = sql.Column(sql.Float)
    saving      = sql.Column(sql.Float)

    client  = sql.orm.relationship('Client', back_populates='accounts')
    branch  = sql.orm.relationship('Branch', back_populates='accounts', uselist=False)

    def __json__(self):
        return {
            'type'      : self.__tablename__,
            'id'        : self.id,
            'client_cpf' : self.client_cpf,
            'branch_id' : self.branch_id,
            'bank_id'   : self.branch.bank_id,
            'bank_name' : self.branch.bank.name,
            'balance'   : self.balance,
            'saving'    : self.saving
        }


