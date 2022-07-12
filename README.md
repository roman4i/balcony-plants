# Balcony Plants

ESP32 controlled system for sensors monitoring

This project consysts two different parts - front-end and back-end

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