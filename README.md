# volley-scoreboard
A simple volleyball scoreboard made with Arduino.
It uses a display based on the TM1638 chip that can be easily found on [ebay](http://www.ebay.it/itm/400531985021?_trksid=p2055119.m1438.l2649&ssPageName=STRK%3AMEBIDX%3AIT) or [dealextreme](http://www.dx.com/p/8-bit-digital-led-tube-8-bit-tm1638-key-display-module-for-arduino-blue-399381#.VuVw-HozKM8).
To interact with the display it uses the [TM1638 library](https://github.com/rjbatista/tm1638-library) written by Ricardo Batista.

Features:
 - increase/decrease of points
 - show number of sets won
 - notification of setpoint (blinking)
 - reset score or game