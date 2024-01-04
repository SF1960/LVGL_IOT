#pragma once

#include "globals.h"

/****************************************************************************
* Button Library
****************************************************************************/

// event handler button 1
static void btn1_event_handler(lv_event_t * e) {

  lv_event_code_t code = lv_event_get_code(e);
  static bool btnState = false;

  if (code == LV_EVENT_CLICKED) {
    if (btnState == false ? btnState = true : btnState = false);
    relay_1 = btnState;
    Serial.print(BUTTON1_LABEL);Serial.print(": ");Serial.println(btnState);
  }
}

// Create button 1
void btnRelay_1(void) {

  lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(btn1, btn1_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_align(btn1, LV_ALIGN_CENTER, -250, 50);
  lv_obj_add_flag(btn1, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_size(btn1, 200, 80);

  lv_obj_t * label = lv_label_create(btn1);
  lv_label_set_text(label, BUTTON1_LABEL);
  lv_obj_center(label);

}

// Event Handler Button 2
static void btn2_event_handler(lv_event_t * e) {

  lv_event_code_t code = lv_event_get_code(e);
  static bool btnState = false;

  if (code == LV_EVENT_CLICKED) {
    if (btnState == false ? btnState = true : btnState = false);
    relay_2 = btnState;
    Serial.print(BUTTON2_LABEL);Serial.print(": ");Serial.println(btnState);
  }

}

// Create button 2
void btnRelay_2(void) {

  lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(btn2, btn2_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_align(btn2, LV_ALIGN_CENTER, -250, 150);
  lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_size(btn2, 200, 80);

  lv_obj_t * label = lv_label_create(btn2);
  lv_label_set_text(label, BUTTON2_LABEL);
  lv_obj_center(label);

}

// Button 3 event handler
static void btn3_event_handler(lv_event_t * e) {

  lv_event_code_t code = lv_event_get_code(e);
  static bool btnState = false;

  if (code == LV_EVENT_CLICKED) {
    if (btnState == false ? btnState = true : btnState = false);
    relay_3 = btnState;
    Serial.print(BUTTON3_LABEL);Serial.print(": ");Serial.println(btnState);
  }

}

// Create button 3
void btnRelay_3(void) {

  lv_obj_t * btn3 = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(btn3, btn3_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_align(btn3, LV_ALIGN_CENTER, -30, 50);
  lv_obj_add_flag(btn3, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_size(btn3, 200, 80);

  lv_obj_t * label = lv_label_create(btn3);
  lv_label_set_text(label, BUTTON3_LABEL);
  lv_obj_center(label);

}

// Button 4 event handler
static void btn4_event_handler(lv_event_t * e) {

  lv_event_code_t code = lv_event_get_code(e);
  static bool btnState = false;

  if (code == LV_EVENT_CLICKED) {
    if (btnState == false ? btnState = true : btnState = false);
    relay_4 = btnState;
    Serial.print(BUTTON4_LABEL);Serial.print(": ");Serial.println(btnState);
  }
}

// Create Button 4
void btnRelay_4(void) {

  lv_obj_t * btn4 = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(btn4, btn4_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_align(btn4, LV_ALIGN_CENTER, -30, 150);
  lv_obj_add_flag(btn4, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_size(btn4, 200, 80);

  lv_obj_t * label = lv_label_create(btn4);
  lv_label_set_text(label, BUTTON4_LABEL);
  lv_obj_center(label);

}