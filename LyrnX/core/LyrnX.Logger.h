#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

#ifndef LyrnX_logger
#define LyrnX_logger 

struct TLoggerOption {
  bool enableConsole;
  bool writeFile;
  string filePath;
};

class Clogger {
  private:
  TLoggerOption _option;

  public:
  Clogger(TLoggerOption option);

  void log(string data);
};

#endif // !LyrnX_logger
