#pragma once

#include "globals.h"

/**************************************************************************
* TITLE
**************************************************************************/

// create title text
void title_label(){

  lv_obj_t * labelTitle = lv_label_create(lv_scr_act());
  lv_obj_set_style_text_color (labelTitle,lv_color_hex(WHITE), NULL);
  lv_obj_align(labelTitle, LV_ALIGN_CENTER, TITLE_X, TITLE_Y);
  lv_obj_set_style_text_color (labelTitle,lv_color_hex(WHITE), NULL);
  lv_label_set_text_fmt(labelTitle, "Home Automation\n\nArduino IOT Cloud\nby Steve Fuller\n\nIOT Connected: [ %b ]", !iOT_Connected); 

}