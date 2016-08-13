
#! /usr/bin/python
delayTime = 20
import timeit


BluetoothData = bluetoothSerial.read()

if BluetoothData == "u": #RGB slider initializer
    bluetoothSerial.write("u")    #Change for Xbee  

if BluetoothData == "l": #ldr
    bluetoothSerial.write("l")      

if BluetoothData == "u": #RGB slider initializer
    bluetoothSerial.write("u")  

if BluetoothData == "t": #Timer 
    bluetoothSerial.write("t")  

if BluetoothData == "v": #Timer
    bluetoothSerial.write("v")      

if BluetoothData == "x": #Timer
    bluetoothSerial.write("x")   

if BluetoothData == "k": #Timer
    bluetoothSerial.write("k")

if BluetoothData == "y": #Timer
    bluetoothSerial.write("y") 

if BluetoothData == "m": #Timer
    bluetoothSerial.write("m")            

if BluetoothData == "d": #bulb off
    bluetoothSerial.write("d")

if BluetoothData == "a": #bulb on
    bluetoothSerial.write("a")   

if BluetoothData == "r": #reading
    bluetoothSerial.write("r")  

if BluetoothData == "s": #sleeping light
    bluetoothSerial.write("s")         

if BluetoothData == "o": #romance
    bluetoothSerial.write("o")   

if BluetoothData == "c": #cinema
    bluetoothSerial.write("c")

if BluetoothData == "p": #party
    bluetoothSerial.write("p")       

if BluetoothData == "z": #zen
    bluetoothSerial.write("z")   

if BluetoothData == "c": #circadian cicle
    bluetoothSerial.write("c")   
    #repeat for other modes




import serial
from time import sleep
 
bluetoothSerial = serial.Serial( "/dev/rfcomm1", baudrate=9600 )
 
count = None
while count == None:
    try:
        count = int(raw_input( "Please enter the number of times to blink the L$"))
    except:
        pass    # Ignore any errors that may occur and try again
 
 
bluetoothSerial.write( str(count) )
print bluetoothSerial.readline()
