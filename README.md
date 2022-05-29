# Chamber-for-Rheotaxis-Study

Chamber-for-Rheotaxis-Study consists of open software and hardware designed for studying rheotaxis for small swimming animals. This system was designed for experiments with the Ciona Intestinalis larvae.

![](https://github.com/EmilNostbakken/Chamber-for-Rheotaxis-Study/blob/main/Pictures/Heile_Oppsettet.png?raw=true)

## Hardware

The Hardware folder contains all STL files for 3D-printing, electronic components list, schematic and files for laser cutting.

## Software
The MicroControllerCode folder contains the arduino code used for this project

## User Guide

Before you start, make sure the system is clean, especially the meshes. You can clean the meshes with ethanol but be careful to not get ethanol on the glue. The chamber should be cleaned with water and soap because the glue used on the chamber could be damaged with ethanol. Ensure that the IR-light components are correctly positioned.

__Step 1: Setup__

Make sure the tubes are in their respective tracks and that they are properly inside each hole of both sides of the chamber. Turn on the PC and check if the camera is in position and working. This is how the setup should look like before starting:
![](https://github.com/EmilNostbakken/Chamber-for-Rheotaxis-Study/blob/main/Pictures/Picture1.jpg?raw=true)

__Step 2: Power__

There are three components that needs to be plugged into a 230V AC power socket. Two power plugs for the electrical box and one for the IR-lighting. The two power plugs from the box are for the Arduino and H-bridge.
![](https://github.com/EmilNostbakken/Chamber-for-Rheotaxis-Study/blob/main/Pictures/Picture2.jpg?raw=true)

__Step 3: Prepare for animals__

Fill the chamber with cooled sea water (about 15°C) until the water is above the tube level. Press the “ON” button and look at the camera preview if the waterflow is desirable. You can turn the potentiometer for desired pump effect. When there’s no air in the tubes, press the “OFF” button and add the animals to the observation section of the chamber (between the meshes in the middle).
![](https://github.com/EmilNostbakken/Chamber-for-Rheotaxis-Study/blob/main/Pictures/Picture3.jpg?raw=true)

__Step 4: Collecting video__

When satisfied with amount of animals and camera quality you start the recording on the PC. Approximately 1-2 seconds after you begin recording, start the pump using the “ON” button. When you are satisfied with the recording length you press the “OFF” button, then stop recording.
