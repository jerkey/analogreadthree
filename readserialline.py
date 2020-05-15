#!/usr/bin/python
# https://stackoverflow.com/questions/18499497/how-to-process-sigterm-signal-gracefully
import signal
import serial
import sys
import datetime

p = serial.Serial("/dev/ttyACM0", baudrate=57600)

def exit_gracefully(signum, frame):
    sys.stdout.write("Stopped time: "+datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n')
    # tried to set a flag here to open the while(1) loop but the OS killed us too fast

signal.signal(signal.SIGTERM, exit_gracefully) # attach handler to kill -SIGTERM signal
signal.signal(signal.SIGINT, exit_gracefully) # attach handler to control-C signal
signal.signal(signal.SIGHUP, exit_gracefully) # attach handler to SIGHUP signal

sys.stdout.write("Start time: "+datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n')
while(1):
    sys.stdout.write(p.readline())
