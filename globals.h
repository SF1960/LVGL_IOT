#pragma once

/**************************************************************************
* GLOBAL VARIABLES AND CONSTANTS
**************************************************************************/

int height = 0;                        // the screen's height
int width = 0;                         // the screen's width

// colour definitions
#define WHITE 0xffffff
#define BLACK 0x000000
#define ARDUINO 0x03989e
#define GRID 0x046f87
#define DARKGREY 0x6b6e73
#define LIGHTGREY 0xa7a7a8

// title definitions
#define TITLE_X -280
#define TITLE_Y -170

// button definitions
#define BUTTON1_LABEL "FAN"
#define BUTTON2_LABEL "O/S LAMP"
#define BUTTON3_LABEL "XMAS TREE"
#define BUTTON4_LABEL "HEATING"

// meter 1 definitions
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

// meter 2 definitions
#define METER2_LABEL "Humidity : "
#define METER2_LABEL_OFFSET -35
#define METER2_MIN 0
#define METER2_MAX 100
#define METER2_NORMAL 80
#define METER2_ANGLE 270
#define METER2_ROTATION 135

// roller definitions
#define ROLLER_X 250
#define ROLLER_Y 100
#define ROLLER_W 110
#define ROLLER_ROWS 4
#define ROLLER_INDEX 1
#define ROLLER_LABEL "Fan Speed"
#define ROLLER_Y_OFFSET 40

// LED definitions
#define LED_CONNECTED_X -335
#define LED_CONNECTED_Y -100
#define LED_CONNECTED_TRUE_COLOUR LV_PALETTE_GREEN
#define LED_CONNECTED_FALSE_COLOUR LV_PALETTE_RED
#define LED_CONNECTED_BRIGHTNESS 150
#define LED_CONNECTED_LABEL "Connected"
#define LED_CONNECTED_LABEL_OFFSET_X 10

// Switch state
#define LED_SWITCH_X -335
#define LED_SWITCH_Y -50
#define LED_SWITCH_TRUE_COLOUR LV_PALETTE_BLUE
#define LED_SWITCH_FALSE_COLOUR LV_PALETTE_RED
#define LED_SWITCH_BRIGHTNESS 150
#define LED_SWITCH_LABEL "Switch"
#define LED_SWITCH_LABEL_OFFSET_X 10

// Switch definitions
#define SWITCH_X -200
#define SWITCH_Y -50
#define SWITCH_LABEL "On Off"
bool swStatus = false;

// screen definitions
#define BRIGHTNESS 40              // start up brightness (0 to 100)
#define MAX_BRIGHTNESS 90          // maximum allowed screen brightness
#define MIN_BRIGHTNESS 10          // minumum allowed screen brightness

// default definitions
#define STARTUP_TEMP 0             // default meter temperature reading
#define STARTUP_HUM 0              // default meter humidity reading