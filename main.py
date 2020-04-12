from project.packages.server.server import app
from flask_socketio import SocketIO

socketio = SocketIO(app)

if __name__ == '__main__':
    socketio.run(app, host='localhost', port=5555)
