// LyrnX.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "LyrnX.Logger.h"
#include "cli_ui/cli_ui.h"

void foo(cli_def::EventMouseData mice);

int main()
{
  TLoggerOption opt{};
  opt.enableConsole = true;
  auto something = new Clogger(opt);

  something->log("hello world~~~`");
  std::cout << "Hello World!\n";
  
  cli_def::CliUI_InitOption option{};
  option.handleIn = GetStdHandle(STD_INPUT_HANDLE);
  option.handleOut = GetStdHandle(STD_OUTPUT_HANDLE);

  cli_ui::globalEventEmitter.on(CLI_MOUSEEVENT, (cli_cm::EventCallback*)foo);

  cli_ui::init(option);
  cli_ui::loop();
}

void __stdcall foo(cli_def::EventMouseData mice) {
  std::cout << "test" << std::endl;
  std::cout << mice.dwMouseType << " | " << mice.dwMouseFlag << " | " << mice.dwMouseControl << std::endl;
}