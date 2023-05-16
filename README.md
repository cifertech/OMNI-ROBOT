<div align="center">

  <img src="https://user-images.githubusercontent.com/62047147/195847997-97553030-3b79-4643-9f2c-1f04bba6b989.png" alt="logo" width="100" height="auto" />
  <h1>OMNI ROBOT</h1>
  
  <p>
    Robot based on OMNI wheels
  </p>
  
  
<!-- Badges -->

<a href="https://github.com/cifertech/OMNI-ROBOT" title="Go to GitHub repo"><img src="https://img.shields.io/static/v1?label=cifertech&message=OMNI-ROBOT&color=white&logo=github" alt="cifertech - OMNI-ROBOT"></a>
<a href="https://github.com/cifertech/OMNI-ROBOT"><img src="https://img.shields.io/github/stars/cifertech/OMNI-ROBOT?style=social" alt="stars - OMNI-ROBOT"></a>
<a href="https://github.com/cifertech/OMNI-ROBOT"><img src="https://img.shields.io/github/forks/cifertech/OMNI-ROBOT?style=social" alt="forks - OMNI-ROBOT"></a>
   
<h4>
    <a href="https://twitter.com/cifertech1">TWITTER</a>
  <span> · </span>
    <a href="https://www.instagram.com/cifertech/">INSTAGRAM</a>
  <span> · </span>
    <a href="https://www.youtube.com/c/cifertech">YOUTUBE</a>
  <span> · </span>
    <a href="https://cifertech.net/">WEBSITE</a>
  </h4>
</div>

<br />

<!-- Table of Contents -->
# :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  * [Pictures](#camera-Pictures)
  * [Features](#dart-features)
- [Getting Started](#toolbox-getting-started)
  * [Schematic](#electric_plug-Schematic)
  * [Installation](#gear-installation)
- [Usage](#eyes-usage)
- [Contributing](#wave-contributing)
- [License](#warning-license)
- [Contact](#handshake-contact)

  

<!-- About the Project -->
## :star2: About the Project
In this project, I decided to make an omni wheel robot, this type of robot is able to move in many directions compared to normal robots due to the special wheels they have.


<!-- Pictures -->
### :camera: Pictures

<div align="center"> 
  <img src="https://github.com/cifertech/OMNI-ROBOT/assets/62047147/40cc8c19-6b7a-424e-a193-0292f9bbcf4c" alt="screenshot" />
</div>


<!-- Features -->
### :dart: Features

- Ability to move in 8 different directions
- Control using web server

<!-- Getting Started -->
## 	:toolbox: Getting Started

We will use ESP8266 as a processor. and we will add an ws2812 Matrix Display to make it look better. Also with the Help of the DRV8833 Dual Motor Driver Module, we were able to control our DC Motors using WebServer over WiFi.

- ESP8266
- DRV8833 Dual Motor Driver
- ws2812 Matrix Display
- DC Motor

<!-- Schematic -->
### :electric_plug: Schematic
Make the connections according to the table and schematic below.

* ESP8266 and DRV8833.

We Should Connect STBY pin to VCC pin.

| ESP8266 | DRV8833 |  
| ----   | -----|
| D3   | AIN1|
| D4   | AIN2|
| D5   | BIN1|
| D6   | BIN2|
| D7   | AIN3|
| D8   | AIN4|
| 5V  | Vm  |
| GND | GND |


* ESP8266 and Matrix Display.

| ESP8266 | Matrix Display|
| ----   | -----|
| D2  | Din |
| 5V | VDD |
| GND | GND |

 
* Complete Schematic

<img src="https://github.com/cifertech/OMNI-ROBOT/assets/62047147/ad5d8f9e-8aa0-4af3-a663-f08a25fc4ce8" alt="screenshot" width="800" height="auto" />


<!-- Installation -->
### :gear: Installation

Before uploading the code you need to install the required library in Arduino IDE. Follow these steps:

- Follow this path Sketch> Include Library> Manage Libraries
- Search for Adafruit_NeoPixel
- Install the library


<!-- Usage -->
## :eyes: Usage

After completing all the steps, an access point will be created for you and by connecting to it and searching for the IP address "192.168.4.1", you can access the web server and control the robot.

<!-- Contributing -->
## :wave: Contributing

<a href="https://github.com/cifertech/OMNI-ROBOT/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=cifertech/OMNI-ROBOT" />
</a>


<!-- License -->
## :warning: License

Distributed under the MIT License. See LICENSE.txt for more information.


<!-- Contact -->
## :handshake: Contact

CiferTech - [@twitter](https://twitter.com/cifertech1) - [@instagram](https://www.instagram.com/cifertech/) - CiferTech@gmali.com

Project Link: [https://github.com/cifertech/OMNI-ROBOT](https://github.com/cifertech/OMNI-ROBOT)

