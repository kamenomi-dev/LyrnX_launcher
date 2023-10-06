#pragma once
#include <wincon.h>
#include <Windows.h>
using namespace std;

namespace cli_def {

  // cli_ui.cpp

  struct CliUI_InitOption {
    HANDLE handleIn, handleOut;
  };

  // cli_ui.native.cpp

  struct EventMouseData {
    DWORD dwMouseType;
    DWORD dwMouseFlag;
    DWORD dwMouseControl;
  };

  struct EventKeyData {
    bool bKeyDown;
    DWORD dwRepeatCount;
    DWORD dwVirtualKeyCode;
    CHAR wInput;
    WCHAR wcInput;
    DWORD dwKeyControl;
  };

  // cli_ui.base.cpp

  typedef struct __tagColorData {
    // Single Color only;

    COLOR16 sColor;

    // Gradient Color only;

    COLOR16 aColor;
    COLOR16 bColor;
  } CharColor, BgColor;

  typedef struct __tagStringFormat {
    RECT rcMarginRect;
    CharColor stringColor;
    BgColor BackgroundColor;
  };

}

#ifndef CLI_UI_EVENT_FLAGS_DEFINED
#define CLI_UI_EVENT_FLAGS_DEFINED

#define CLI_KEYEVENT       0x1
#define CLI_MOUSEEVENT     0x2

#define CLI_SIZEEVENT      0x4
#define CLI_FOCUSEVENT     0x8

#endif // CLI_UI_EVENT_FLAGS_DEFINED
