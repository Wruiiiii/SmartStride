This project is a two-part wireless system, so the code is organized into two separate Arduino sketches:

/transmitter: This folder contains the code for the wearable sensor unit that is worn on the ankle. 
/receiver: This folder contains the code for the stimulation unit. Its job is to listen for the command from the transmitter and activate the TENS unit.


To get the project set up on your computer, follow these steps:
1. Open Your Terminal: Open a Terminal (macOS) or Git Bash (Windows).
2. Clone the Repository: Use the git clone command to download the project to your computer. Replace the URL with our repository's URL from GitHub.
git clone https://github.com/your-team/smartstride-firmware.git

3. Set Arduino IDE Path: In the Arduino IDE, go to File > Preferences and set your "Sketchbook location" to point to the smartstride-firmware folder you just downloaded.
4. Open a Sketch: You can now open either the transmitter or receiver sketch via File > Sketchbook in the Arduino IDE.
