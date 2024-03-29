#pragma once

#include "globals.h"

/**************************************************************************
* LED WIDGET
**************************************************************************/

lv_obj_t * ledConnect;
lv_obj_t * ledDisconnect;
lv_obj_t * ledSwitch;

// function global variables
bool ledConnectedCreated = false;
bool ledDisconnectedCreated = false;

// create an green LED to show connection status
void connectedLED(){

  if (ledConnectedCreated){ // if already created then return
    return;
  }

  ledConnect  = lv_led_create(lv_scr_act());
  lv_obj_align(ledConnect, LV_ALIGN_CENTER, LED_CONNECTED_X, LED_CONNECTED_Y);
  lv_led_set_brightness(ledConnect, LED_CONNECTED_BRIGHTNESS);
  lv_led_set_color(ledConnect, lv_palette_main(LED_CONNECTED_TRUE_COLOUR));
  lv_led_on(ledConnect);

  /*Create the main label*/
  lv_obj_t * labelLED = lv_label_create(lv_scr_act());
  lv_obj_set_style_text_color (labelLED,lv_color_hex(WHITE), NULL);
  lv_obj_align_to(labelLED, ledConnect, LV_ALIGN_OUT_RIGHT_MID, LED_CONNECTED_LABEL_OFFSET_X, 0);
  lv_label_set_text(labelLED, LED_CONNECTED_LABEL);

  ledConnectedCreated = true;     // once created set the flag
  ledDisconnectedCreated = false; // reset the opossite flag

}

// create an red LED to show connection status
void disconnectedLED(){

  if (ledDisconnectedCreated){  // if already created then return
    return;
  }

  ledDisconnect  = lv_led_create(lv_scr_act());
  lv_obj_align(ledDisconnect, LV_ALIGN_CENTER, LED_CONNECTED_X, LED_CONNECTED_Y);
  lv_led_set_brightness(ledDisconnect, LED_CONNECTED_BRIGHTNESS);
  lv_led_set_color(ledDisconnect, lv_palette_main(LED_CONNECTED_FALSE_COLOUR));
  lv_led_off(ledDisconnect);

  /*Create the main label*/
  lv_obj_t * labelLED = lv_label_create(lv_scr_act());
  lv_obj_set_style_text_color (labelLED,lv_color_hex(LIGHTGREY), NULL);
  lv_obj_align_to(labelLED, ledDisconnect, LV_ALIGN_OUT_RIGHT_MID, LED_CONNECTED_LABEL_OFFSET_X, 0);
  lv_label_set_text(labelLED, LED_CONNECTED_LABEL);

  ledDisconnectedCreated = true;  // set the flag once created
  ledConnectedCreated = false;    // reset the opposite flag

}

// create a Switch LED
void createLEDSwitch(bool state){

  ledSwitch  = lv_led_create(lv_scr_act());
  lv_obj_align(ledSwitch, LV_ALIGN_CENTER, LED_SWITCH_X, LED_SWITCH_Y);
  lv_led_set_brightness(ledSwitch, LED_SWITCH_BRIGHTNESS);

  if (state == true){
    lv_led_set_color(ledSwitch, lv_palette_main(LED_SWITCH_TRUE_COLOUR));
    lv_led_on(ledSwitch);
  }else{
    lv_led_set_color(ledSwitch, lv_palette_main(LED_SWITCH_FALSE_COLOUR));
    lv_led_off(ledSwitch);
  }

  /*Create the main label*/
  lv_obj_t * labelLED = lv_label_create(lv_scr_act());
  lv_obj_set_style_text_color (labelLED,lv_color_hex(WHITE), NULL);
  lv_obj_align_to(labelLED, ledSwitch, LV_ALIGN_OUT_RIGHT_MID, LED_SWITCH_LABEL_OFFSET_X, 0);
  lv_label_set_text(labelLED, LED_SWITCH_LABEL);

}

