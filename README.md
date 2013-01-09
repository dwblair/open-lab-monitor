open-lab-monitor
=================

### Overview

An open hardware microcontroller device for use in research and teaching laboratory settings, and as an independent sensing node.

### PCB

### Code

Code for controlling the Open Lab Monitor device, the development and goals and applications of which are documented [here](https://github.com/Pioneer-Valley-Open-Science/pioneer-valley-open-science.github.com/issues/8).

The code consists of Arduino code to be loaded on an Arduino-based sensor platform, as well as a Processing and Python interface for interacting with the platform (e.g. plotting sensor values, downloading data as a CSV file). 

#### Notes on the Arduino Code

Some non-standard Arduino libraries are required, frozen versions of which can be found [here](https://github.com/dwblair/open-lab-monitor/tree/master/arduino/libraries).  Copy (or better yet, link) the folders under "libraries" to your "libraries" folder for your Arduino sketchbook:

* ThermistorLib (cversek's library for reading thermistor values) -- latest version found [here](https://github.com/cversek/umass-physics/tree/master/teis/arduino/ThermistorLib).
                                                                  
* SerialCommand (originally Steven Cogswell's slick library for parsing commands over serial)  -- check out his surly [blog post](http://husks.wordpress.com/2011/05/23/a-minimal-arduino-library-for-processing-serial-commands/); we are using the new and improved version hosted on github [here](https://github.com/kroimon/Arduino-SerialCommand)
