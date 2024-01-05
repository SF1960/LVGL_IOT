#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled 2"
  https://create.arduino.cc/cloud/things/b7dc4866-dc62-4e3f-a061-8975ef809c6a 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float float_kitchen_humidity;
  float float_kitchen_temperature;
  CloudDimmedLight fanSpeed;
  CloudLight relay_1;
  CloudLight relay_2;
  CloudLight relay_3;
  CloudLight relay_4;
  bool iOT_Connected;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

/***************************************************************************************
* Description:  Connecting a GIGA R1 with Display Sheild to Ardunio IOT. Using LVLG widgets
* Sketch:       GIGA_R1_dec18a.ino
* Version:      2.0 
* Version Desc: 1.0 Default version. 2 meters for temp and hum. 4 buttons. 1 roller. 1 label
*               2.0 adding an LED to the GIGA shield to show Arduino Connection
* Board:        GIGA R1 with Display Shield
* Author:       steve fuller
* Website:      sgfpcb@gmail.com
* Comments      
***************************************************************************************/

// System Libraries
#include <Arduino_H7_Video.h>
#include <Arduino_GigaDisplayTouch.h>
#include <Arduino_GigaDisplay.h>
#include <ArduinoGraphics.h>

// Program Libraries
#include "thingProperties.h"
#include "lvgl.h"
#include "globals.h"
#include "buttons.h"
#include "meters.h"
#include "roller.h"
#include "title.h"
#include "led.h"

// Create screen objects
Arduino_H7_Video Display(800, 480, GigaDisplayShield); /* Arduino_H7_Video Display(1024, 768, USBCVideo); */
Arduino_GigaDisplayTouch TouchDetector;

//Create backlight object
GigaDisplayBacklight backlight;

/**************************************************************************
*  SETUP ROUTINE
***************************************************************************/

void setup() {

  Serial.begin(115200);              // Initialize serial and wait for port to open:
  delay(1500);                       // This delay gives the chance to wait for a Serial Monitor

  Display.begin();
  TouchDetector.begin();
  backlight.begin();
  backlight.set(BRIGHTNESS);

  width = Display.width();
  height = Display.height();

  //set up screen
  lv_obj_t* screen = lv_obj_create(lv_scr_act());
  lv_obj_set_size(screen, width, height);
  lv_obj_set_style_bg_color(screen, lv_color_hex(ARDUINO), LV_PART_MAIN);
  static lv_coord_t col_dsc[] = { width, LV_GRID_TEMPLATE_LAST }; // was 800
  static lv_coord_t row_dsc[] = { height, LV_GRID_TEMPLATE_LAST }; // was 480

  // draw lvgl widgets
  btnRelay_1();
  btnRelay_2();
  btnRelay_3();
  btnRelay_4();
  createMeterHumidty();
  createMeterTemperature();
  lv_fan_roller();
  title_label();

  delay(2000);

  // set meters and cloud connection variable
  setValueHum(indicHum, STARTUP_HUM);
  setValueTemp(indicTemp, STARTUP_TEMP);
  iOT_Connected = false;

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  Serial.println("********************");
  Serial.println("* SET UP COMPLETED *");
  Serial.println("********************");

} // setup()

/*************************************************************************
* MAIN PROGRAM LOOP
**************************************************************************/

void loop() {
  ArduinoCloud.update();

  lv_timer_handler();

  // set the LED cloud to show device connected to Arduino
  if (ArduinoCloud.connected() == 0) {
    iOT_Connected = false;               // this sets the cloud LED as green
    disconnectedLED();                   // show the disconnected LED
  } else {
    iOT_Connected = true;                // this sets the cloud LED as red
    connectedLED();                      // show the connected LED
  }
  
} // loop()

/***************************************************************************
* ARDUINO CLOUD FUNCTIONS
***************************************************************************/

// update Cloud and Display when temperature variable changes
void onFloatKitchenTemperatureChange() {
  int sensor_temp = float_kitchen_temperature;
  setValueTemp(indicTemp, sensor_temp);
}

// update Cloud and Display when humidity variable changes
void onFloatKitchenHumidityChange() {
  int sensor_hum = float_kitchen_humidity;
  setValueHum(indicHum, sensor_hum);
}

// update Cloud and Display when fan speed variable changes
void onFanSpeedChange() {
  Serial.print("Fan Speed: ");
  Serial.println(fanSpeed.getBrightness());
  Serial.print("Fan Switch: ");
  Serial.println(fanSpeed.getSwitch());
  if (fanSpeed.getSwitch() == 1 ? relay_1 = true : relay_1 = false);
}

// update Cloud and Display when relay 1 variable changes
void onRelay1Change() {

  if (relay_1 == 1) {
    fanSpeed.setSwitch(true);
    relay_1 = true;
  } else {
    fanSpeed.setSwitch(false);
    relay_1 = false;
  }

}

void onRelay2Change() {
}

void onRelay3Change() {
}

void onRelay4Change() {
}

void onIOTConnectedChange() {
}
