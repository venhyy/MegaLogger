//<File !Start!>
// FILE: [MegaLogger_GSLC.h]
// Created by GUIslice Builder version: [0.17.b18]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XKeyPad_Num.h"

// Ensure optional features are enabled in the configuration
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if defined(DRV_DISP_TFT_ESPI)
  #error E_PROJECT_OPTIONS tab->Graphics Library should be TFT_eSPI
#endif
#include <Adafruit_GFX.h>
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_MAIN,E_POP_KEYPAD_NUM};
enum {E_ELEM_NUMINPUT1,E_ELEM_NUMINPUT10,E_ELEM_NUMINPUT11
      ,E_ELEM_NUMINPUT12,E_ELEM_NUMINPUT13,E_ELEM_NUMINPUT14
      ,E_ELEM_NUMINPUT15,E_ELEM_NUMINPUT16,E_ELEM_NUMINPUT2
      ,E_ELEM_NUMINPUT3,E_ELEM_NUMINPUT4,E_ELEM_NUMINPUT5
      ,E_ELEM_NUMINPUT6,E_ELEM_NUMINPUT7,E_ELEM_NUMINPUT8
      ,E_ELEM_NUMINPUT9,E_ELEM_TEXT10,E_ELEM_TEXT11,E_ELEM_TEXT12
      ,E_ELEM_TEXT13,E_ELEM_TEXT14,E_ELEM_TEXT15,E_ELEM_TEXT16
      ,E_ELEM_TEXT17,E_ELEM_TEXT18,E_ELEM_TEXT19,E_ELEM_TEXT20
      ,E_ELEM_TEXT21,E_ELEM_TEXT4,E_ELEM_TEXT5,E_ELEM_TEXT6
      ,E_ELEM_TEXT7,E_ELEM_TEXT8,E_ELEM_TEXT9,E_ELEM_KEYPAD_NUM};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN10X16,E_BUILTIN5X8,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                2

#define MAX_ELEM_PG_MAIN 34 // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_MAIN_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_MAIN];
gslc_tsElem                     m_asKeypadNumElem[1];
gslc_tsElemRef                  m_asKeypadNumElemRef[1];
gslc_tsXKeyPad                  m_sKeyPadNum;

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElemValP1;
extern gslc_tsElemRef* m_pElemValP2;
extern gslc_tsElemRef* m_pElemValP3;
extern gslc_tsElemRef* m_pElemValP4;
extern gslc_tsElemRef* m_pElemValP5;
extern gslc_tsElemRef* m_pElemValP6;
extern gslc_tsElemRef* m_pElemValP7;
extern gslc_tsElemRef* m_pElemValT1;
extern gslc_tsElemRef* m_pElemValT2;
extern gslc_tsElemRef* m_pElemValT3;
extern gslc_tsElemRef* m_pElemValT4;
extern gslc_tsElemRef* m_pElemValT5;
extern gslc_tsElemRef* m_pElemValT6;
extern gslc_tsElemRef* m_pElemValT7;
extern gslc_tsElemRef* m_pElemValT8;
extern gslc_tsElemRef* m_pElemValT9;
extern gslc_tsElemRef* m_pElemKeyPadNum;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN10X16,GSLC_FONTREF_PTR,NULL,2)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPage1Elem,MAX_ELEM_PG_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MAIN);
  gslc_PageAdd(&m_gui,E_POP_KEYPAD_NUM,m_asKeypadNumElem,1,m_asKeypadNumElemRef,1);  // KeyPad

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_MAIN);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_BLACK);

  // -----------------------------------
  // PAGE: E_PG_MAIN
  
  
  // Create E_ELEM_TEXT4 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT4,E_PG_MAIN,(gslc_tsRect){174,31,37,18},
    (char*)"P1:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT5 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT5,E_PG_MAIN,(gslc_tsRect){174,54,37,18},
    (char*)"P2:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT6 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT6,E_PG_MAIN,(gslc_tsRect){174,77,37,18},
    (char*)"P3:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT7 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT7,E_PG_MAIN,(gslc_tsRect){174,100,37,18},
    (char*)"P4:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT8 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT8,E_PG_MAIN,(gslc_tsRect){174,123,37,18},
    (char*)"P5:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT9 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT9,E_PG_MAIN,(gslc_tsRect){174,146,37,18},
    (char*)"P6:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT10 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT10,E_PG_MAIN,(gslc_tsRect){174,169,37,18},
    (char*)"P7:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT11 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT11,E_PG_MAIN,(gslc_tsRect){25,30,37,18},
    (char*)"T1:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT12 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT12,E_PG_MAIN,(gslc_tsRect){25,53,37,18},
    (char*)"T2:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT13 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT13,E_PG_MAIN,(gslc_tsRect){25,76,37,18},
    (char*)"T3:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT14 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT14,E_PG_MAIN,(gslc_tsRect){25,99,37,18},
    (char*)"T4:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT15 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT15,E_PG_MAIN,(gslc_tsRect){25,122,37,18},
    (char*)"T5:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT16 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT16,E_PG_MAIN,(gslc_tsRect){25,145,37,18},
    (char*)"T6:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT17 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT17,E_PG_MAIN,(gslc_tsRect){25,168,37,18},
    (char*)"T7:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT18 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT18,E_PG_MAIN,(gslc_tsRect){25,191,37,18},
    (char*)"T8:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT19 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT19,E_PG_MAIN,(gslc_tsRect){25,214,37,18},
    (char*)"T9:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT20 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT20,E_PG_MAIN,(gslc_tsRect){10,10,85,18},
    (char*)"Teplota",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_TEXT21 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT21,E_PG_MAIN,(gslc_tsRect){160,10,49,18},
    (char*)"Tlak",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_NUMINPUT1 numeric input field
  static char m_sInputNumber1[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT1,E_PG_MAIN,(gslc_tsRect){60,30,71,18},
    (char*)m_sInputNumber1,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValT1 = pElemRef;
  
  // Create E_ELEM_NUMINPUT2 numeric input field
  static char m_sInputNumber2[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT2,E_PG_MAIN,(gslc_tsRect){60,53,71,18},
    (char*)m_sInputNumber2,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValT2 = pElemRef;
  
  // Create E_ELEM_NUMINPUT3 numeric input field
  static char m_sInputNumber3[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT3,E_PG_MAIN,(gslc_tsRect){60,76,71,18},
    (char*)m_sInputNumber3,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValT3 = pElemRef;
  
  // Create E_ELEM_NUMINPUT4 numeric input field
  static char m_sInputNumber4[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT4,E_PG_MAIN,(gslc_tsRect){60,99,71,18},
    (char*)m_sInputNumber4,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValT4 = pElemRef;
  
  // Create E_ELEM_NUMINPUT5 numeric input field
  static char m_sInputNumber5[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT5,E_PG_MAIN,(gslc_tsRect){60,122,71,18},
    (char*)m_sInputNumber5,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValT5 = pElemRef;
  
  // Create E_ELEM_NUMINPUT6 numeric input field
  static char m_sInputNumber6[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT6,E_PG_MAIN,(gslc_tsRect){60,145,71,18},
    (char*)m_sInputNumber6,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValT6 = pElemRef;
  
  // Create E_ELEM_NUMINPUT7 numeric input field
  static char m_sInputNumber7[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT7,E_PG_MAIN,(gslc_tsRect){60,168,71,18},
    (char*)m_sInputNumber7,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValT7 = pElemRef;
  
  // Create E_ELEM_NUMINPUT8 numeric input field
  static char m_sInputNumber8[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT8,E_PG_MAIN,(gslc_tsRect){60,191,71,18},
    (char*)m_sInputNumber8,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValT8 = pElemRef;
  
  // Create E_ELEM_NUMINPUT9 numeric input field
  static char m_sInputNumber9[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT9,E_PG_MAIN,(gslc_tsRect){60,214,71,18},
    (char*)m_sInputNumber9,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValT9 = pElemRef;
  
  // Create E_ELEM_NUMINPUT10 numeric input field
  static char m_sInputNumber10[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT10,E_PG_MAIN,(gslc_tsRect){210,31,71,18},
    (char*)m_sInputNumber10,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValP1 = pElemRef;
  
  // Create E_ELEM_NUMINPUT11 numeric input field
  static char m_sInputNumber11[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT11,E_PG_MAIN,(gslc_tsRect){210,54,71,18},
    (char*)m_sInputNumber11,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValP2 = pElemRef;
  
  // Create E_ELEM_NUMINPUT12 numeric input field
  static char m_sInputNumber12[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT12,E_PG_MAIN,(gslc_tsRect){210,77,71,18},
    (char*)m_sInputNumber12,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValP3 = pElemRef;
  
  // Create E_ELEM_NUMINPUT13 numeric input field
  static char m_sInputNumber13[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT13,E_PG_MAIN,(gslc_tsRect){210,100,71,18},
    (char*)m_sInputNumber13,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValP4 = pElemRef;
  
  // Create E_ELEM_NUMINPUT14 numeric input field
  static char m_sInputNumber14[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT14,E_PG_MAIN,(gslc_tsRect){210,123,71,18},
    (char*)m_sInputNumber14,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValP5 = pElemRef;
  
  // Create E_ELEM_NUMINPUT15 numeric input field
  static char m_sInputNumber15[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT15,E_PG_MAIN,(gslc_tsRect){210,146,71,18},
    (char*)m_sInputNumber15,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValP6 = pElemRef;
  
  // Create E_ELEM_NUMINPUT16 numeric input field
  static char m_sInputNumber16[6] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUMINPUT16,E_PG_MAIN,(gslc_tsRect){210,169,71,18},
    (char*)m_sInputNumber16,6,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemValP7 = pElemRef;

  // -----------------------------------
  // PAGE: E_POP_KEYPAD_NUM
  
  static gslc_tsXKeyPadCfg_Num sCfg;
  sCfg = gslc_ElemXKeyPadCfgInit_Num();
  gslc_ElemXKeyPadCfgSetFloatEn_Num(&sCfg, true);
  gslc_ElemXKeyPadCfgSetSignEn_Num(&sCfg, true);
  m_pElemKeyPadNum = gslc_ElemXKeyPadCreate_Num(&m_gui, E_ELEM_KEYPAD_NUM, E_POP_KEYPAD_NUM,
    &m_sKeyPadNum, 65, 80, E_BUILTIN5X8, &sCfg);
  gslc_ElemXKeyPadValSetCb(&m_gui, m_pElemKeyPadNum, &CbKeypad);
//<InitGUI !End!>

//<Startup !Start!>
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
