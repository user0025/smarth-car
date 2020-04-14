import socket
import json


class Server:

    HOST = socket.gethostname()
    PORT = 5555
    socketServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    functions = []

    def createServer(self):
        self.socketServer.bind((self.HOST, self.PORT))
        self.socketServer.listen(5)
        while True:
            print('waiting for a connection')
            client, addr = self.socketServer.accept()
            with client:
                print('Connected by', addr)
                if len(self.functions) > 0:
                    for data in self.functions:

                        client.send(bytes(data, 'utf-8'))

    def sendMessage(self, typeMessage, message, address, port, json=True):
        try:
            connection = socket.create_connection((address, port))
            with connection:
                data = message
                if(json):
                    data = json.dumps(
                        {"message": typeMessage, 'data': message})

                connection.send(bytes(data, 'utf-8'))
        except:
            print(f'{typeMessage} refuse')

    def appendFunction(self, func, args=False):
        def executeFunction():
            if args:
                return func(args)
            return func()

        resultFunc = executeFunction()
        self.functions.append(resultFunc)


serverInstance = Server()
