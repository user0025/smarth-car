
import socket

HOST = '127.0.0.1'
PORT = 4444

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as socketClient:
    try:
        socketClient.bind((HOST, PORT))
        socketClient.listen()
        while True:
            client, addr = socketClient.accept()
            data = client.recv(1024)
            if data:
                print('Received', repr(data.decode('utf-8')))
            else:
                print('await')

    except:
        pass
