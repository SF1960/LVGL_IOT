#pragma once

/**************************************************************************
* GLOBAL VARIABLES AND CONSTANTS
**************************************************************************/

#define WHITE 0xffffff
#define BLACK 0x000000
#define ARDUINO 0x03989e
#define GRID 0x046f87

#define TITLE_X -280
#define TITLE_Y -170

#define BUTTON1_LABEL "FAN"
#define BUTTON2_LABEL "O/S LAMP"
#define BUTTON3_LABEL "XMAS TREE"
#define BUTTON4_LABEL "HEATING"

#define METER1_LABEL "Temperature : "
#define METER1_LABEL_OFFSET -35
#define METER1_MIN 0
#define METER1_MAX 40
#define METER1_COLD 15
#define METER1_HOT 30
#define METER1_NEEDLE_WIDTH 3
#define METER1_MAJOR_TICKS 5
#define METER1_MAJOR_WIDTH 3
#define METER1_MAJOR_LENGTH 15
#define METER1_TICKS 41
#define METER1_TICKS_WIDTH 2
#define METER1_TICKS_LENGTH 10
#define METER1_ANGLE 270
#define METER1_ROTATION 135

#define METER2_LABEL "Humidity : "
#define METER2_LABEL_OFFSET -35
#define METER2_MIN 0
#define METER2_MAX 100
#define METER2_NORMAL 80
#define METER2_ANGLE 270
#define METER2_ROTATION 135

#define ROLLER_X 250
#define ROLLER_Y 100
#define ROLLER_W 110
#define ROLLER_ROWS 4
#define ROLLER_INDEX 1
#define ROLLER_LABEL "Fan Speed"
#define ROLLER_Y_OFFSET 40

#define LED_ON_X -280
#define LED_ON_Y -100
#define LED_ON_BRIGHTNESS 150
#define LED_ON_LABEL "IOT Connected"
#define LED_OFF_X 150
#define LED_OFF_Y 100
#define LED_OFF_BRIGHTNESS 50
#define LED_OFF_LABEL "IOT DISCONNECTED"

#define BRIGHTNESS 40              // start up brightness (0 to 100)
#define MAX_BRIGHTNESS 90          // maximum allowed screen brightness
#define MIN_BRIGHTNESS 10          // minumum allowed screen brightness

#define STARTUP_TEMP 22            // default meter temperature reading
#define STARTUP_HUM 85             // default meter humidity reading