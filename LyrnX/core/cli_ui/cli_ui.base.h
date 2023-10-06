#pragma once
#include <string>
#include <codecvt>

using namespace std;

namespace cli_base {

  void handleUpdate();
  bool pointA(POINT position, DWORD bgColor, string text);
  bool pointW(POINT position, DWORD bgColor, wstring text);

}