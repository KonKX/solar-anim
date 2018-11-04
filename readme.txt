This is an interactive animation of the sun and a rotating planet with a satellite. 

Implemented in Visual Studio 13. 

Usage: The "a" and "d" buttons rotate the camera along the X-axis while using the "w" and "x" on the Y axis.
Pressing the "r" button pauses the animation and when pressed again it restarts. Exit with "q".

Solar.cpp: Hour, Day, and Increment variables are initialized and manipulate the position and speed of animation.
The KeyFunc function consists of a switch that controls the push of a button.
Idle is the main function of the program that designs and renders the animation. This is where the objects are made
and their position and behavior are determined.

OpenGLInit has to do with OpenGL rendering modes.

ResizeWindow is called when resizing our window.

Main.cpp: The main function sets up OpenGl, calls the appropriate functions and starts the main loop.

Solar.h: Includes function statements.
