#pragma  once

#include "globals.h"

/**************************************************************************
* SWITCH WIDGET
**************************************************************************/

lv_obj_t * sw1;

/* Switch call back */
static void sw1_event_cb(lv_event_t * e) {
  static bool sw = false;
  if (sw == 1 ? sw = false : sw = true);
  Serial.print("Switch Condition: "); Serial.println(sw);
  swStatus = sw; // could variable
  createLEDSwitch(swStatus);
  switch1 = swStatus;
}

// create the switch widget
void createSwitch(bool swStatus){

  sw1 = lv_switch_create(lv_scr_act());
  lv_obj_align(sw1, LV_ALIGN_CENTER, SWITCH_X, SWITCH_Y);
  lv_obj_add_event_cb(sw1, sw1_event_cb, LV_EVENT_CLICKED, NULL);
  if (swStatus == true){
    lv_obj_add_state(sw1, LV_STATE_CHECKED);
  }else{
    lv_obj_clear_state(sw1, LV_STATE_CHECKED);
  }


  lv_obj_t * labelSW = lv_label_create(lv_scr_act());
  lv_obj_center(labelSW);
  lv_obj_set_style_text_color (labelSW,lv_color_hex(WHITE), NULL);
  lv_obj_align_to(labelSW, sw1, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
  lv_label_set_text(labelSW, SWITCH_LABEL);

}

