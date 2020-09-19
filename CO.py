import serial
import time
import sys
arduino = serial.Serial('/dev/ttyACM0', 9600)
lista=["\n"]
print ("Arduino")
time.sleep(2)
try:
    while(True):
        if(arduino.in_waiting>0):
            try:
                cadena=arduino.readline()
                numero=float(cadena)
                print(numero)
                lista.append(numero)
            except(ValueError):
                print("Formato invalido no se recibio numer"+cadena.strip())
        elif (len(lista)>10):
            for element in lista:
                print (element)
            sys.exit()
except(KeyboardInterrupt,SystemExit):
    arduino.close()

