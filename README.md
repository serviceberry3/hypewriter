This is a WIP. I'm taking an old Royal Safari typewriter and digitizing it by adding an array of buttons on the underside of the machine. When a key is pressed, it will hit a button that triggers a specific voltage input for an Arduino (Elegoo, actually) Nano. The letter will appear on an LCD dislay, and it will look like the typewriter is "stamping" the display. An interface will be created allowing the user to create files on an SD card and write text, and also pan around within the file.  
An end goal is to convert the entire thing into either a standard USB keyboard or a bluetooth keyboard.

Here's what it looks like so far:  
[Hypewriter demo](img/hypewriter_demo.gif)


# ISSUES #
* The current obstacle is that I'm trying to use two old Lego Mindstorms servos to control the carriage. The NXT brick communicates with the original Mindstorms sensors via I2C, and I've found some tutorials online explaining how to interface the brick with an Arduino via I2C, but the I2C sequence isn't working right now.
Looking to use an oscilloscope to debug the signal.
