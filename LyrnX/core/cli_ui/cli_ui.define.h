#pragma once
#include <Windows.h>
using namespace std;

namespace cli_def {

  struct CliUI_InitOption {
    HANDLE handleIn, handleOut;
  };

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

}

#ifndef CLI_UI_EVENT_FLAGS_DEFINED

#define CLI_KEYEVENT       0x1
#define CLI_MOUSEEVENT     0x2

#define CLI_SIZEEVENT      0x4
#define CLI_FOCUSEVENT     0x8

#endif // CLI_UI_EVENT_FLAGS_DEFINED