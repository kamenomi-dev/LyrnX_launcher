#pragma once
#include <string>
#include <codecvt>

using namespace std;

namespace cli_base {

  void handleUpdate();
  bool pointA(POINT position, COLOR16 bgColor, string text, COLOR16 ftColor);
  bool pointW(POINT position, COLOR16 bgColor, wstring text, COLOR16 ftColor);

}