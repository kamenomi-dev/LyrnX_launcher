// Here is components base, isn't logic base.
#include "cli_ui.define.h"
#include "cli_ui.base.h"
#include "cli_ui.native.h"

using namespace cli_def;

namespace cli_base {
  HANDLE hOut = cli_nt::hOut;
  
  void handleUpdate() {
    hOut = cli_nt::hOut;
  }

  inline bool pointA(POINT position, DWORD bgColor, string text) {
    auto rawText = text.c_str();

    return WriteConsoleOutputCharacterA(hOut, rawText, lstrlenA(rawText), pt2cr(position), (LPDWORD) 0);
  }
  
  inline bool pointW(POINT position, DWORD bgColor, wstring text) {
    auto rawText = text.c_str();

    return WriteConsoleOutputCharacterW(hOut, rawText, lstrlenW(rawText), pt2cr(position), (LPDWORD) 0);
  }

  inline bool pointExA(POINT position, DWORD bgColor, wstring text, DWORD txtColor) {

  }

  inline bool lineA() {

  };

  inline bool lineW() {

  };

  inline COORD pt2cr(POINT point) {
    COORD cr{};
    cr.X = point.x;
    cr.Y = point.y;
    return cr;
  }

}