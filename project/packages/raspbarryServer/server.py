import socket
import json


class ServerRaspy:

    HOST = socket.gethostname()
    PORT = 4444
    socketInstance = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def __init__(self):
        self.createCliente()

    def createCliente(self):
        self.socketInstance.connect((self.HOST, self.PORT))
        self.socketInstance.bind((self.HOST, self.PORT))

    def sendMensage(self, mensage: str, type):
        mensageJson = str(json.loads({'data': mensage, 'type': type}))
        self.socketInstance.send(mensageJson.encode())


serverInstance = ServerRaspy()
