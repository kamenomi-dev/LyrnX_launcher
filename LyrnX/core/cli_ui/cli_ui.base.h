#pragma once
#include <string>

using namespace std;

namespace cli_base {

  void baseInit(HANDLE hOut);
  void pointA(POINT* position, int bgColor, string text);
  void pointExA(POINT* position, int bgColor, string text, int txtColor);
  void pointW(POINT* position, int bgColor, wstring text);

  COORD pt2cr(POINT point);
  void setColor(DWORD edColor, DWORD frColor);
  void restoreColor();
}