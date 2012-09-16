open-lab-monitor
=================

Code for controlling the Open Lab Monitor device, the development and goals and applications of which are documented [here](https://github.com/Pioneer-Valley-Open-Science/pioneer-valley-open-science.github.com/issues/8).

The code consists of Arduino code to be loaded on an Arduino-based sensor platform, as well as a Processing and Python interface for interacting with the platform (e.g. plotting sensor values, downloading data as a CSV file). 

### Python Code

###Arduino Code

Non-standard Arduino libraries required:

* ThermistorLib (cversek's library for reading thermistor values) -- In order to acquire this library, download cversek's entire umass-physics repository [here](https://github.com/cversek/umass-physics), then navigate into "teis/arduino/", and copy the entire "ThermistorLib" folder you find there into your the "libraries" folder for your Arduino sketchbook


