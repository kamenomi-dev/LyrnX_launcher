#pragma once

#include <Windows.h>

using namespace std;

namespace cli_nt {
  bool InitHandle(HANDLE hIn, HANDLE hOut);
  void SetMode();
}