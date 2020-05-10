import serial

connection = serial.SerialBase('COM4', 115200)


def sendComand(comand):
    if connection.isOpen():
        commandbytes = str(comand)
        connection.write(commandbytes.encode())

    return comand
