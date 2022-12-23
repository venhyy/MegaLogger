//<App !Start!>
// FILE: [main.cpp]
// Created by GUIslice Builder version: [0.17.b18]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "MegaLogger_GSLC.h"
#include <SPI.h>
#include <SD.h>
#include <max6675.h>
#include <Wire.h>
#include "RTClib.h"

#define thermoDOT1 1
#define thermoDOT2 1
#define thermoDOT3 1
#define thermoDOT4 1
#define thermoDOT5 1
#define thermoDOT6 1
#define thermoDOT7 1
#define thermoDOT8 1
#define thermoDOT9 1

#define SD_CS 4

int thermoCS = 5;
int thermoCLK = 6;

MAX6675 thermocoupleT1(thermoCLK, thermoCS, thermoDOT1);
MAX6675 thermocoupleT2(thermoCLK, thermoCS, thermoDOT2);
MAX6675 thermocoupleT3(thermoCLK, thermoCS, thermoDOT3);
MAX6675 thermocoupleT4(thermoCLK, thermoCS, thermoDOT4);
MAX6675 thermocoupleT5(thermoCLK, thermoCS, thermoDOT5);
MAX6675 thermocoupleT6(thermoCLK, thermoCS, thermoDOT6);
MAX6675 thermocoupleT7(thermoCLK, thermoCS, thermoDOT7);
MAX6675 thermocoupleT8(thermoCLK, thermoCS, thermoDOT8);
MAX6675 thermocoupleT9(thermoCLK, thermoCS, thermoDOT9);

File sensorData;
String dataString;

uint8_t press_channels[] = {A8, A9, A10, A11, A12, A13, A14};
MAX6675 temp_obj[] = {thermocoupleT1, thermocoupleT2};

gslc_tsElemRef *tempTxtArr[] = {m_pElemValT1, m_pElemValT2, m_pElemValT3, m_pElemValT4, m_pElemValT5, m_pElemValT6, m_pElemValT7, m_pElemValT8, m_pElemValT9};
gslc_tsElemRef *pressTxtArr[] = {m_pElemValP1, m_pElemValP2, m_pElemValP3, m_pElemValP4, m_pElemValP5, m_pElemValP6, m_pElemValP7};

int pressure[7] = {};
int temperature[9] = {};

uint8_t readTime = 5000; // read period

unsigned long ellapsedTime = 0;

RTC_DS3231 rtc;
bool rtc_ok = false;
String time_str;

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef *m_pElemValP1 = NULL;
gslc_tsElemRef *m_pElemValP2 = NULL;
gslc_tsElemRef *m_pElemValP3 = NULL;
gslc_tsElemRef *m_pElemValP4 = NULL;
gslc_tsElemRef *m_pElemValP5 = NULL;
gslc_tsElemRef *m_pElemValP6 = NULL;
gslc_tsElemRef *m_pElemValP7 = NULL;
gslc_tsElemRef *m_pElemValT1 = NULL;
gslc_tsElemRef *m_pElemValT2 = NULL;
gslc_tsElemRef *m_pElemValT3 = NULL;
gslc_tsElemRef *m_pElemValT4 = NULL;
gslc_tsElemRef *m_pElemValT5 = NULL;
gslc_tsElemRef *m_pElemValT6 = NULL;
gslc_tsElemRef *m_pElemValT7 = NULL;
gslc_tsElemRef *m_pElemValT8 = NULL;
gslc_tsElemRef *m_pElemValT9 = NULL;
gslc_tsElemRef *m_pElemKeyPadNum = NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch)
{
  if (ch == (char)'\n')
    Serial.println("");
  else
    Serial.write(ch);
  return 0;
}

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
  gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
  gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);

  if (eTouch == GSLC_TOUCH_UP_IN)
  {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId)
    {
      //<Button Enums !Start!>
    case E_ELEM_NUMINPUT1:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValT1);
      break;
    case E_ELEM_NUMINPUT2:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValT2);
      break;
    case E_ELEM_NUMINPUT3:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValT3);
      break;
    case E_ELEM_NUMINPUT4:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValT4);
      break;
    case E_ELEM_NUMINPUT5:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValT5);
      break;
    case E_ELEM_NUMINPUT6:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValT6);
      break;
    case E_ELEM_NUMINPUT7:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValT7);
      break;
    case E_ELEM_NUMINPUT8:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValT8);
      break;
    case E_ELEM_NUMINPUT9:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValT9);
      break;
    case E_ELEM_NUMINPUT10:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValP1);
      break;
    case E_ELEM_NUMINPUT11:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValP2);
      break;
    case E_ELEM_NUMINPUT12:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValP3);
      break;
    case E_ELEM_NUMINPUT13:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValP4);
      break;
    case E_ELEM_NUMINPUT14:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValP5);
      break;
    case E_ELEM_NUMINPUT15:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValP6);
      break;
    case E_ELEM_NUMINPUT16:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValP7);
      break;
      //<Button Enums !End!>
    default:
      break;
    }
  }
  return true;
}
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
// KeyPad Input Ready callback
bool CbKeypad(void *pvGui, void *pvElemRef, int16_t nState, void *pvData)
{
  gslc_tsGui *pGui = (gslc_tsGui *)pvGui;
  gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
  gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);

  // From the pvData we can get the ID element that is ready.
  int16_t nTargetElemId = gslc_ElemXKeyPadDataTargetIdGet(pGui, pvData);
  if (nState == XKEYPAD_CB_STATE_DONE)
  {
    // User clicked on Enter to leave popup
    // - If we have a popup active, pass the return value directly to
    //   the corresponding value field
    switch (nTargetElemId)
    {
      //<Keypad Enums !Start!>
    case E_ELEM_NUMINPUT1:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValT1, pvData);
      gslc_PopupHide(&m_gui);
      break;

    case E_ELEM_NUMINPUT2:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValT2, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT3:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValT3, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT4:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValT4, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT5:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValT5, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT6:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValT6, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT7:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValT7, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT8:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValT8, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT9:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValT9, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT10:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValP1, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT11:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValP2, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT12:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValP3, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT13:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValP4, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT14:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValP5, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT15:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValP6, pvData);
      gslc_PopupHide(&m_gui);
      break;
    case E_ELEM_NUMINPUT16:
      gslc_ElemXKeyPadInputGet(pGui, m_pElemValP7, pvData);
      gslc_PopupHide(&m_gui);
      break;
      //<Keypad Enums !End!>
    default:
      break;
    }
  }
  else if (nState == XKEYPAD_CB_STATE_CANCEL)
  {
    // User escaped from popup, so don't update values
    gslc_PopupHide(&m_gui);
  }
  return true;
}
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
//<Listbox Callback !Start!>
//<Listbox Callback !End!>
//<Draw Callback !Start!>
//<Draw Callback !End!>
//<Slider Callback !Start!>
//<Slider Callback !End!>
//<Tick Callback !Start!>
//<Tick Callback !End!>

void printValuesToDisplay()
{
  char acTxt[MAX_STR];

  for (int i = 0; i < 6; i++)
  {
    snprintf(acTxt, MAX_STR, "%u", pressure[i]);
    gslc_ElemSetTxtStr(&m_gui, pressTxtArr[i], acTxt);
  }
  for (int i = 0; i < 8; i++)
  {
    snprintf(acTxt, MAX_STR, "%u", temperature[i]);
    gslc_ElemSetTxtStr(&m_gui, tempTxtArr[i], acTxt);
  }
}

void saveData()
{
  dataString = "";

  if (rtc_ok)
  {
    DateTime now = rtc.now();
    char buf2[] = "YYMMDD-hh:mm:ss";
    time_str = now.toString(buf2);
  }
  else
    time_str = "rtc_err";

  if (SD.exists("data.csv"))
  { // check the card is still there
    // now append new data file
    sensorData = SD.open("data.csv", FILE_WRITE);
    if (sensorData)
    {
      for (int i = 0; i < 6; i++)
      {
        char text[100];
        sprintf(text, "P%d, %d", i + 1, pressure[i]);
        sensorData.println(time_str + "," + text);
      }
      for (int i = 0; i < 8; i++)
      {
        char text[100];
        sprintf(text, "T%d, %d", i + 1, temperature[i]);
        sensorData.println(time_str + "," + text);
      }

      sensorData.close(); // close the file
    }
  }
  else
  {
    Serial.println("Error writing to file !");
  }
}

int RTCInit()
{
  if (!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    return -1;
  }

  if (rtc.lostPower())
  {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  return 0;
}

void showDate(const char *txt, const DateTime &dt)
{
  Serial.print(txt);
  Serial.print(' ');
  Serial.print(dt.year(), DEC);
  Serial.print('/');
  Serial.print(dt.month(), DEC);
  Serial.print('/');
  Serial.print(dt.day(), DEC);
  Serial.print(' ');
  Serial.print(dt.hour(), DEC);
  Serial.print(':');
  Serial.print(dt.minute(), DEC);
  Serial.print(':');
  Serial.print(dt.second(), DEC);

  Serial.print(" = ");
  Serial.print(dt.unixtime());
  Serial.print("s / ");
  Serial.print(dt.unixtime() / 86400L);
  Serial.print("d since 1970");

  Serial.println();
}

void setup()
{
  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  Serial.begin(9600);
  if (!SD.begin(SD_CS))
  {
    Serial.println("SD init failed");
  }
  Serial.println("SD init OK");

  rtc_ok = RTCInit() == 0 ? true : false;

  // Wait for USB Serial
  // delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

  gslc_InitDebug(&DebugOut);

  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUIslice_gen();
}

// -----------------------------------
// Main event loop
// -----------------------------------
void loop()
{

  // ------------------------------------------------
  // Update GUI Elements
  // ------------------------------------------------

  for (int i = 0; i < 6; i++)
  {
    pressure[i] = analogRead(press_channels[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    temperature[i] = (int)temp_obj[i].readCelsius();
  }

  // Update the data display values

  // Perform any immediate updates on active page

  delay(100);

  // TODO - Add update code for any text, gauges, or sliders

  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  printValuesToDisplay();
  gslc_Update(&m_gui);
}
