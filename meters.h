#pragma once

#include "globals.h"

/***************************************************************************************
* HUMIDITY METER WIDGET LIBRARY
**************************************************************************************/

lv_obj_t * labelMeterHum;                         // LVGL meter label library object
lv_obj_t * labelMeterTemp;                        // LVGL meter label library object

static lv_obj_t * meterHum;
static lv_meter_indicator_t * indicHum;

// set the meter needle and label value
static void setValueHum(void * indicHum, int32_t v) {

  lv_meter_set_indicator_value(meterHum, (lv_meter_indicator_t *) indicHum, v);
  lv_obj_set_style_text_color (labelMeterHum,lv_color_hex(ARDUINO), NULL);
  lv_obj_align_to(labelMeterHum, meterHum, LV_ALIGN_OUT_BOTTOM_MID, 0, METER1_LABEL_OFFSET);
  lv_label_set_text_fmt(labelMeterHum, "Humidity: %d%%", v);
  Serial.print(METER2_LABEL);Serial.print(v);Serial.println("%");
  
}

// create the Humidity meter
void createMeterHumidty(void) {

  meterHum = lv_meter_create(lv_scr_act());
  labelMeterHum = lv_label_create(lv_scr_act());
  lv_obj_align(meterHum, LV_ALIGN_CENTER, 250, -130);
  lv_obj_set_size(meterHum, 200, 200);

  /*Add a scale first*/
  lv_meter_scale_t * scale = lv_meter_add_scale(meterHum);
   lv_meter_set_scale_range(meterHum, scale, METER2_MIN, METER2_MAX, METER2_ANGLE, METER2_ROTATION);
  lv_meter_set_scale_ticks(meterHum, scale, 41, 2, 10, lv_palette_main(LV_PALETTE_GREY));
  lv_meter_set_scale_major_ticks(meterHum, scale, 8, 4, 15, lv_color_black(), 10);

  /*Add a GREEN arc to the start*/
  indicHum = lv_meter_add_arc(meterHum, scale, 3, lv_palette_main(LV_PALETTE_GREEN), 0);
  lv_meter_set_indicator_start_value(meterHum, indicHum, METER2_MIN);
  lv_meter_set_indicator_end_value(meterHum, indicHum, METER2_NORMAL);

  /*Make the tick lines GREEN at the start of the scale*/
  indicHum = lv_meter_add_scale_lines(meterHum, scale, lv_palette_main(LV_PALETTE_GREEN), lv_palette_main(LV_PALETTE_GREEN), false, 0);
  lv_meter_set_indicator_start_value(meterHum, indicHum, METER2_MIN);
  lv_meter_set_indicator_end_value(meterHum, indicHum, METER2_NORMAL);

  /*Add a red arc to the end*/
  indicHum = lv_meter_add_arc(meterHum, scale, 3, lv_palette_main(LV_PALETTE_RED), 0);
  lv_meter_set_indicator_start_value(meterHum, indicHum, METER2_NORMAL);
  lv_meter_set_indicator_end_value(meterHum, indicHum, METER2_MAX);

  /*Make the tick lines red at the end of the scale*/
  indicHum = lv_meter_add_scale_lines(meterHum, scale, lv_palette_main(LV_PALETTE_RED), lv_palette_main(LV_PALETTE_RED), false, 0);
  lv_meter_set_indicator_start_value(meterHum, indicHum, METER2_NORMAL);
  lv_meter_set_indicator_end_value(meterHum, indicHum, METER2_MAX);

  /*Add a needle line indicator*/
  indicHum = lv_meter_add_needle_line(meterHum, scale, 4, lv_palette_main(LV_PALETTE_GREY), -10);

  /*Create an animation to set the value*/
  lv_anim_t a;
  lv_anim_init(&a);
  lv_anim_set_exec_cb(&a, setValueHum);
  lv_anim_set_var(&a, indicHum);
  lv_anim_set_values(&a, 0, 100);
  lv_anim_set_time(&a, 1000);
  lv_anim_set_repeat_delay(&a, 100);
  lv_anim_set_playback_time(&a, 300);
  lv_anim_set_playback_delay(&a, 100);
  lv_anim_start(&a);

}

/***************************************************************************************
* TEMPERATURE METER WIDGET
**************************************************************************************/

// set up the two meters
static lv_obj_t * meterTemp;
static lv_meter_indicator_t * indicTemp;

// set the meter needle and label depending on the value
static void setValueTemp(void * indicTemp, int32_t v) {

  lv_meter_set_indicator_value(meterTemp, (lv_meter_indicator_t *) indicTemp, v);
  lv_obj_set_style_text_color (labelMeterTemp,lv_color_hex(ARDUINO), NULL);
  lv_obj_align_to(labelMeterTemp, meterTemp, LV_ALIGN_OUT_BOTTOM_MID, 0, METER2_LABEL_OFFSET);
  lv_label_set_text_fmt(labelMeterTemp, "Temp: %d*C", v);
  Serial.print(METER1_LABEL);Serial.print(v);Serial.println("*C");

}

// Create Temperature Meter
void createMeterTemperature(void) {

  meterTemp = lv_meter_create(lv_scr_act());
  labelMeterTemp = lv_label_create(lv_scr_act());
  lv_obj_align(meterTemp, LV_ALIGN_CENTER, 10, -130);
  lv_obj_set_size(meterTemp, 200, 200);

  /*Add a scale first*/
  lv_meter_scale_t * scale = lv_meter_add_scale(meterTemp);
  lv_meter_set_scale_range(meterTemp, scale, METER1_MIN, METER1_MAX, METER1_ANGLE, METER1_ROTATION);
  lv_meter_set_scale_ticks(meterTemp, scale, METER1_TICKS, METER1_TICKS_WIDTH, METER1_TICKS_LENGTH, lv_palette_main(LV_PALETTE_GREY));
  lv_meter_set_scale_major_ticks(meterTemp, scale, METER1_MAJOR_TICKS, METER1_MAJOR_WIDTH, METER1_MAJOR_LENGTH, lv_color_black(), 10);

  /*Add a blue arc to the start*/
  indicTemp = lv_meter_add_arc(meterTemp, scale, 3, lv_palette_main(LV_PALETTE_BLUE), 0);
  lv_meter_set_indicator_start_value(meterTemp, indicTemp, METER1_MIN);
  lv_meter_set_indicator_end_value(meterTemp, indicTemp, METER1_COLD);

  /*Make the tick lines blue at the start of the scale*/
  indicTemp = lv_meter_add_scale_lines(meterTemp, scale, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_ORANGE), false, 0);
  lv_meter_set_indicator_start_value(meterTemp, indicTemp, METER1_MIN);
  lv_meter_set_indicator_end_value(meterTemp, indicTemp, METER1_COLD);

  /*Add a orange arc to the start*/
  indicTemp = lv_meter_add_arc(meterTemp, scale, 3, lv_palette_main(LV_PALETTE_ORANGE), 0);
  lv_meter_set_indicator_start_value(meterTemp, indicTemp, METER1_COLD);
  lv_meter_set_indicator_end_value(meterTemp, indicTemp, METER1_HOT);

  /*Make the tick lines orange at the start of the scale*/
  indicTemp = lv_meter_add_scale_lines(meterTemp, scale, lv_palette_main(LV_PALETTE_ORANGE), lv_palette_main(LV_PALETTE_RED), false, 0);
  lv_meter_set_indicator_start_value(meterTemp, indicTemp, METER1_COLD);
  lv_meter_set_indicator_end_value(meterTemp, indicTemp, METER1_HOT);

  /*Add a red arc to the end*/
  indicTemp = lv_meter_add_arc(meterTemp, scale, 3, lv_palette_main(LV_PALETTE_RED), 0);
  lv_meter_set_indicator_start_value(meterTemp, indicTemp, METER1_HOT);
  lv_meter_set_indicator_end_value(meterTemp, indicTemp, METER1_MAX);

  /*Make the tick lines red at the end of the scale*/
  indicTemp = lv_meter_add_scale_lines(meterTemp, scale, lv_palette_main(LV_PALETTE_RED), lv_palette_main(LV_PALETTE_RED), false, 0);
  lv_meter_set_indicator_start_value(meterTemp, indicTemp, METER1_HOT);
  lv_meter_set_indicator_end_value(meterTemp, indicTemp, METER1_MAX);

  /*Add a needle line indicator*/
  indicTemp = lv_meter_add_needle_line(meterTemp, scale, METER1_NEEDLE_WIDTH, lv_palette_main(LV_PALETTE_GREY), -10);

  /*Create an animation to set the value*/
  lv_anim_t a;
  lv_anim_init(&a);
  lv_anim_set_exec_cb(&a, setValueTemp);
  lv_anim_set_var(&a, indicTemp);
  lv_anim_set_values(&a, 0, 100);
  lv_anim_set_time(&a, 1000);
  lv_anim_set_repeat_delay(&a, 100);
  lv_anim_set_playback_time(&a, 300);
  lv_anim_set_playback_delay(&a, 100);
  //lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
  lv_anim_start(&a);

}