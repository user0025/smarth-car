from flask import Flask, request
from flask_socketio import SocketIO
from project.packages.tfsimage.exemple import tfsImage

app = Flask(__name__)


@app.route('/')
def hello_world():
    return 'Hello, World!'


socketio = SocketIO(app)


@socketio.on('message')
def handleSocket(menssage):
    tfsImage(menssage)
