// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)

void onFloatKitchenHumidityChange();
void onFloatKitchenTemperatureChange();
void onFanSpeedChange();
void onRelay1Change();
void onRelay2Change();
void onRelay3Change();
void onRelay4Change();
void onSwitch1Change();

float float_kitchen_humidity;
float float_kitchen_temperature;
CloudDimmedLight fanSpeed;
CloudLight relay_1;
CloudLight relay_2;
CloudLight relay_3;
CloudLight relay_4;
bool iOT_Connected;
bool switch1;

void initProperties(){

  ArduinoCloud.addProperty(float_kitchen_humidity, READWRITE, ON_CHANGE, onFloatKitchenHumidityChange);
  ArduinoCloud.addProperty(float_kitchen_temperature, READWRITE, ON_CHANGE, onFloatKitchenTemperatureChange);
  ArduinoCloud.addProperty(fanSpeed, READWRITE, ON_CHANGE, onFanSpeedChange);
  ArduinoCloud.addProperty(relay_1, READWRITE, ON_CHANGE, onRelay1Change);
  ArduinoCloud.addProperty(relay_2, READWRITE, ON_CHANGE, onRelay2Change);
  ArduinoCloud.addProperty(relay_3, READWRITE, ON_CHANGE, onRelay3Change);
  ArduinoCloud.addProperty(relay_4, READWRITE, ON_CHANGE, onRelay4Change);
  ArduinoCloud.addProperty(iOT_Connected, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(switch1, READWRITE, ON_CHANGE, onSwitch1Change);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
