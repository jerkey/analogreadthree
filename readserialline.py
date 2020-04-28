#!/usr/bin/python

import serial
import sys

p = serial.Serial("/dev/serial/by-id/usb-Arduino_LLC_Arduino_Micro-if00", baudrate=57600)

while(1):
        sys.stdout.write(p.readline())
