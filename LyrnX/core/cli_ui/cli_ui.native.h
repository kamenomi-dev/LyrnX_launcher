#pragma once

#include <Windows.h>

using namespace std;

namespace cli_nt {
  HANDLE hIn{};
  HANDLE hOut{};

  bool InitHandle(HANDLE hIn, HANDLE hOut);
  void SetMode();
}