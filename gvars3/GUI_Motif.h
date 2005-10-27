#ifndef __GUI_MOTIF_H
#define __GUI_MOTIF_H

#include <gvars3/config.h>
#ifdef GV3_HAVE_MOTIF

#include <gvars3/GUI.h>
#include <Xm/Xm.h>

namespace GVars3
{


class GUI_Motif
{
 public:
  GUI_Motif(GUI *pGUI, GVars2 *pGV2);
  void InitXInterface(std::string sDisplay);
  void AddPushButton(std::string sCommand, std::string sParams);
  void AddToggleButton(std::string sCommand, std::string sParams);
  void AddMonitor(std::string sCommand, std::string sParams);
  void AddSlider(std::string sCommand, std::string sParams);
  void AddWindow(std::string sParams);
  void DestroyWindow(std::string sCommand);
  
  
  
  
  
 private:
  std::string msName;

  void DoMotifEvents();
  static void InitXInterfaceCB(void*, std::string, std::string);
  static void AddPushButtonCB(void*, std::string, std::string);
  static void AddSliderCB(void*, std::string, std::string);
  static void AddWindowCB(void*, std::string, std::string);
  static void AddToggleButtonCB(void*, std::string, std::string);
  static void AddMonitorCB(void*, std::string, std::string);
  static void DestroyCB(void*, std::string, std::string);
  static void* GUI_Motif_Thread_CB(void* ptr);
  static void ButtonHandlerCB(Widget, XtPointer, XtPointer);
  void ButtonHandler(Widget, XtPointer);
  void GUI_Motif_Thread();

  static void RemoveWindowCB(Widget, void*, void*);
  void RemoveWindow(Widget w);
  
  GUI *mpGUI;
  GVars2 *mpGV2;
  
  void* mpMutex;
  
 
  Display* mpDisplay;
  XtAppContext mxtac;
  
  typedef struct {std::string sLabel; std::string sVarName; std::string sCache; int nDelaySetting; int nCurrentDelay; } monitorMapStruct;
  typedef struct {std::string sName; gvar2_int gvn;   int nCache; }   toggleMapStruct;
  typedef struct {std::string sVarName; double dMin; double dMax; std::string sCachedValue; }   sliderMapStruct;
  
  typedef struct {
    Widget wTopLevel;
    Widget wRowCol;
    int nWidth;
    int nHeight;
    std::map<Widget, std::string> PushButtonMap;
    std::map<Widget, monitorMapStruct> MonitorMap;
    std::map<Widget, toggleMapStruct > ToggleButtonMap;
    std::map<Widget, sliderMapStruct > SliderMap;
  } GUIWindowStruct;
  
  std::map<std::string, GUIWindowStruct> mmWindows;
  
};

}


#endif
#endif
