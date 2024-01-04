#pragma once

#include "globals.h"

/***************************************************************************
* ROLLER
***************************************************************************/

// roller call back function
static void roller_event_handler(lv_event_t * e) {

  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);

  if (code == LV_EVENT_VALUE_CHANGED) {
    char buf[32];
    lv_roller_get_selected_str(obj, buf, sizeof(buf));
    LV_LOG_USER("Selected value: %s", buf);

    // UPDATE THE ARDUINO CLOUD VARIABLE
    int fan_speed_value;
    fan_speed_value = atoi(buf);                      
    Serial.print("Roller: ");Serial.println(fan_speed_value);
    fanSpeed.setBrightness(fan_speed_value);
  }

}

// Create a roller widget
void lv_fan_roller(void) {
  /*A style to make the selected option larger*/
  static lv_style_t style_sel;
  lv_style_init(&style_sel);

  const char * opts = "FAN SPEED\n0\n25\n50\n75\n100";
  lv_obj_t * roller;

  /*A roller on the left with left aligned text, and custom width*/
  roller = lv_roller_create(lv_scr_act());
  lv_roller_set_options(roller, opts, LV_ROLLER_MODE_NORMAL);
  lv_roller_set_visible_row_count(roller, ROLLER_ROWS);
  lv_obj_set_width(roller, ROLLER_W);
  lv_obj_add_style(roller, &style_sel, LV_PART_SELECTED);
  lv_obj_set_style_text_align(roller, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(roller, LV_ALIGN_CENTER, ROLLER_X, ROLLER_Y); 
  lv_obj_add_event_cb(roller, roller_event_handler, LV_EVENT_ALL, NULL);
  lv_roller_set_selected(roller, ROLLER_INDEX, LV_ANIM_OFF);

  /*Create a style for the shadow*/
  static lv_style_t style_shadow;
  lv_style_init(&style_shadow);
  lv_style_set_text_opa(&style_shadow, LV_OPA_30);
  lv_style_set_text_color(&style_shadow, lv_color_black());

  /*Create a label for the shadow first (it's in the background)*/
  lv_obj_t * shadow_label = lv_label_create(lv_scr_act());
  lv_obj_add_style(shadow_label, &style_shadow, 0);

  /*Create the main label*/
  lv_obj_t * main_label = lv_label_create(lv_scr_act());
  lv_obj_set_style_text_color (main_label,lv_color_hex(WHITE), NULL);
  lv_label_set_text(main_label, ROLLER_LABEL);

  /*Set the same text for the shadow label*/
  lv_label_set_text(shadow_label, lv_label_get_text(main_label));

  /*Position the main label*/
  lv_obj_align_to(main_label, roller, LV_ALIGN_BOTTOM_MID, 0, ROLLER_Y_OFFSET);

  /*Shift the second label down and to the right by 2 pixel*/
  lv_obj_align_to(shadow_label, main_label, LV_ALIGN_TOP_LEFT, 2, 2);

}