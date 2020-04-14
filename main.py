from project.packages.server import server
from project.packages.arduino import integracaoArduino

server.serverInstance.sendMessage('arduino-command', integracaoArduino.sendComand(7),
                                  '127.0.0.1', 4444, False)

server.serverInstance.createServer()
