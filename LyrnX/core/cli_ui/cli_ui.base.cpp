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

  bool point(POINT position, COLOR16 color) {
    pointA(position, color, "", NULL);
  }

  bool pointA(POINT position, COLOR16 bgColor, string text, COLOR16 ftColor) {
    auto rawText = text.c_str();
    COORD pos{};
    pos.X = position.x;
    pos.Y = position.y;

    return WriteConsoleOutputCharacterA(hOut, rawText, lstrlenA(rawText), pos, nullptr) != 0;
  }
  
  bool pointW(POINT position, COLOR16 bgColor, wstring text, COLOR16 ftColor) {
    auto rawText = text.c_str();
    COORD pos{};
    pos.X = position.x;
    pos.Y = position.y;

    return WriteConsoleOutputCharacterW(hOut, rawText, lstrlenW(rawText), pos, nullptr) != 0;
  }

  bool line() {
  
  };

  bool lineA() {

  };

  bool lineW() {

  };

}