# Handsfree Remote Control
For many of us, we taking changing the channel or volume for granted, however, for many this is not a simple task. The purpose of this project is to produce a Remote Control that can be controlled through an assitive device, like a tablet in conjunction with a joystick or eyetracker.
##Techical Details
Utilizing an ESP32, the remote control hosts a web server through which a user has access to large, east to "click" buttons. When these buttons are "clicked", they issue a command which blinks an IR LED at a precise frequency that has already been matched with any given set-top box's remote sequencing.
