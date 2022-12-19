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

File myFile;

uint8_t press_channels[] = {A8, A9, A10, A11, A12, A13, A14};

uint8_t readTime = 5000; //read period

unsigned long ellapsedTime = 0;

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemValP1      = NULL;
gslc_tsElemRef* m_pElemValP2      = NULL;
gslc_tsElemRef* m_pElemValP3      = NULL;
gslc_tsElemRef* m_pElemValP4      = NULL;
gslc_tsElemRef* m_pElemValP5      = NULL;
gslc_tsElemRef* m_pElemValP6      = NULL;
gslc_tsElemRef* m_pElemValP7      = NULL;
gslc_tsElemRef* m_pElemValT1      = NULL;
gslc_tsElemRef* m_pElemValT2      = NULL;
gslc_tsElemRef* m_pElemValT3      = NULL;
gslc_tsElemRef* m_pElemValT4      = NULL;
gslc_tsElemRef* m_pElemValT5      = NULL;
gslc_tsElemRef* m_pElemValT6      = NULL;
gslc_tsElemRef* m_pElemValT7      = NULL;
gslc_tsElemRef* m_pElemValT8      = NULL;
gslc_tsElemRef* m_pElemValT9      = NULL;
gslc_tsElemRef* m_pElemKeyPadNum  = NULL;
//<Save_References !End!>


unsigned  m_nCount = 0;

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
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
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)pvGui;
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  // From the pvData we can get the ID element that is ready.
  int16_t nTargetElemId = gslc_ElemXKeyPadDataTargetIdGet(pGui, pvData);
  if (nState == XKEYPAD_CB_STATE_DONE) {
    // User clicked on Enter to leave popup
    // - If we have a popup active, pass the return value directly to
    //   the corresponding value field
    switch (nTargetElemId) {
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
  } else if (nState == XKEYPAD_CB_STATE_CANCEL) {
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

void setup()
{
  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  Serial.begin(9600);
  if (!SD.begin(4)) {
    Serial.println("SD init failed");
  }
  Serial.println("SD init OK");

  // Wait for USB Serial 
  //delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

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

  char              acTxt[MAX_STR];

  // Update the data display values
  m_nCount++;

  // Perform any immediate updates on active page
  snprintf(acTxt,MAX_STR,"%u",m_nCount);
  gslc_ElemSetTxtStr(&m_gui,m_pElemValT1,acTxt);

  delay(100);
  
  //TODO - Add update code for any text, gauges, or sliders
  
  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);
    
}

