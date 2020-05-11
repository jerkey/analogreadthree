#!/usr/bin/python

import serial
import sys
import datetime

p = serial.Serial("/dev/serial/by-id/usb-Arduino_LLC_Arduino_Micro-if00", baudrate=57600)

sys.stdout.write("Start time: "+datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n')
while(1):
    sys.stdout.write(p.readline())
