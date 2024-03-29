﻿# Balcony Plants

ESP32 controlled system for sensors monitoring

This project consysts two different parts - front-end and back-end

## Readme links
- [How to use](#how-to-use)
- [Front-end](#front-end)
    - Elements
- [Back-end](#back-end)
    - Devices
    - Server
- [Images](#images)

## How to use

At first you must clone this repo  
You can see two folder - ESP-balcony and esp-panel  
ESP-balcony is Arduino project (but I use the PlatformIO) for ESP-32 (but you can adapt to esp8266, it`s not hard)
esp-panel is front-end, the create-react-app project

### How to use Arduino project

My project using PlatformIO and you need to have it (I use it with VS Code)

Step by step:
1. Open project folder with PlatformIO
2. Connect your ESP32 to computer
3. Press "Upload" button
4. Add files from "build" folder in esp-panel folder (first do build, you can read about that in front-end guide) to data folder
5. Rename files from build/static, from js folder file main.xxxx.js to main.js, you also can remove other files from this folder. Do same with css folder (main.xxxx.css to main.css). Next rename these files in index.html
6. Next press PlatformIO extension button (on the left), in Project tasks find "Build Filesystem Image" and press it (it will build filesystem)
7. Next press "Upload Filesystem Image"
8. You got smart device (connect via serial and check ip adress, next type it in your browser)

### How to use Front-end project

Front-end is usuall Rect project, if you know what is npm it will be easy to modify

Step-by-step :
1. Open in terminal project folder
2. Type `npm install`, it will load project modules
3. To run project type command `npm start`, it will start local server and opens in browser
4. If you want to try elements at local server, you must to uncomment in src/components/App/App the `staticDataList` const and put it to state. Also comment `useState` with request. After that will be used local data
5. If all right, you must to return in App as was and type command `npm run build`
6. You've got minimized web app (to use in paragraph 4 Arduino project step-by-step) 

## Front-end

The front-end based on React

### Front-end elements

There are few basic elements, they can be named as functional blocks

#### Sensor block
Sensor block has text part for sensor`s data and button for updating data

#### Slider block
Slider block has text part with name and value, and  slider (input range) block where you can choose sending value

#### Switch block
Switch block has part with name and checkbox

## Back-end

Based on ESP32 microcontroller and AsyncWebServer

### Devices

#### Soil moisture sensor
As example used  the capacitive soil moisture sensor(s)

#### BME280
BME280 used for temperature and humidity monitoring. Can be used with different libraries

### Server
Communication occurs through the API

#### Front-end files
The front-end files must be placed in 'data' folder

#### Requests
All requests must be written to the program. Don't forget to write path to all front-end files!

## Images

On this image you can see main view of system (esp32 with antenna, bme280, bredboard, wires)
![system](/images/IMG_6467.jpg)

On next image you can see plant with capacitive moisture sensors. As you can see, moisture sensor have uncovered electronics, be better to insulate it.
![plants](/images/IMG_6465.jpeg)

How it's looks on the mobile device:    
<img alt='mobile view' src='./images/SB-mobile.jpg' style='width: 300px;'></img>
