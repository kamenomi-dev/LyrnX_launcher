// LyrnX.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <string>
#include "LyrnX.Logger.h"
#include "cli_ui/cli_ui.h"

using namespace std;

void foo(cli_def::EventKeyData mice);

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

  cli_base::baseInit(option.handleOut);
  cli_ui::globalEventEmitter.on(CLI_KEYEVENT, (cli_cm::EventCallback*)foo);

  cli_ui::init(option);

  srand((DWORD) *foo);

  cli_ui::loop();
}

bool IsColorLight(byte r, byte g, byte b) {
  return (((5 * g) + (2 * r) + b) > (8 * 128));
}

int random(int max) {
  return rand() % max + 1;
}

void __stdcall foo(cli_def::EventKeyData mice) {
  if (not mice.bKeyDown) {
    return;
  }

  POINT aa{};
  aa.x = 20;
  aa.y = 20;

  int cr[3];
  cr[0] = random(255);
  cr[1] = random(255);
  cr[2] = random(255);

  pointExA(
    &aa, ((COLORREF)(
      ((BYTE)(cr[0])
    | ((WORD)((BYTE)(cr[1])) << 8))
    | (((DWORD)(BYTE)(cr[2])) << 16))
  ), string(&mice.wInput),
    IsColorLight(cr[0], cr[1], cr[2]) ? RGB(255, 255, 255) : RGB(0, 0, 0));
}