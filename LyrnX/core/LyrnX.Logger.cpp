#include "LyrnX.Logger.h"

Clogger::Clogger(TLoggerOption option) {
  this->_option = option;
};

void Clogger::log(string data) {
  TLoggerOption option = this->_option;
  if (option.writeFile) {
    // todo
  }
  
  if (option.enableConsole) {
    std::cout << data.c_str();
  }
  
  OutputDebugStringA(
    (data + "\n").data()
  );
}