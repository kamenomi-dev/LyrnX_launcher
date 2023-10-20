// Here is components base, isn't logic base.
#include "cli_ui.define.h"
#include "cli_ui.native.h"
#include "cli_ui.base.h"
#include <iostream>

using namespace cli_def;
HANDLE hCliOut = NULL;//cli_nt::hOut;

namespace cli_base {

  CONSOLE_SCREEN_BUFFER_INFOEX * info;
  
  void baseInit(HANDLE hOut) {
    hCliOut = hOut;

    info = new CONSOLE_SCREEN_BUFFER_INFOEX;
    info->cbSize = sizeof info;
  }

  void pointA(POINT* position, int bgColor, string text) {
    auto rawText = text.c_str();
    DWORD noop;

    setColor(bgColor, NULL);
    WriteConsoleOutputCharacterA(hCliOut, rawText, lstrlenA(rawText), pt2cr(*position), &noop);
    restoreColor();
  }
  
  void pointW(POINT* position, int bgColor, wstring text) {
    auto rawText = text.c_str();
    DWORD noop;

    setColor(bgColor, NULL);
    WriteConsoleOutputCharacterW(hCliOut, rawText, lstrlenW(rawText), pt2cr(*position), &noop);
    restoreColor();
  }

  void pointExA(POINT* position, int bgColor, string text, int txtColor) {
    auto rawText = text.c_str();
    DWORD noop;

    setColor(bgColor, txtColor);
    WriteConsoleOutputCharacterA(hCliOut, rawText, lstrlenA(rawText), pt2cr(*position), &noop);
    restoreColor();
  }

  void lineA() {

  };

  void lineW() {

  };

  COORD pt2cr(POINT point) {
    COORD cr{};
    cr.X = point.x;
    cr.Y = point.y;
    return cr;
  }

  void setColor(DWORD edColor, DWORD frColor) {
    if (info == nullptr) {
      info = new CONSOLE_SCREEN_BUFFER_INFOEX;
      info->cbSize = sizeof CONSOLE_SCREEN_BUFFER_INFOEX;

      GetConsoleScreenBufferInfoEx(hCliOut, info);
    };

    info->srWindow.Bottom += 1;
    CONSOLE_SCREEN_BUFFER_INFOEX newInfo = *info;

    if (edColor != NULL)
    newInfo.ColorTable[0] = edColor;

    if (frColor != NULL)
      newInfo.ColorTable[7] = frColor;
    SetConsoleScreenBufferInfoEx(hCliOut, &newInfo);
  }

  void restoreColor() {
    SetConsoleScreenBufferInfoEx(hCliOut, info);
    delete info;
    info = nullptr;
  }

}