// addr: cli_ui.cli_nt
#include "cli_ui.native.h"

namespace cli_nt {

  DWORD origin_in_flag = 0;
  DWORD origin_out_flag = 0;

  bool InitHandle(HANDLE hIn, HANDLE hOut) {
    if (hIn != 0 && hOut != 0) {
      return false;
    }

    hIn = hIn;
    hOut = hOut;

	if (not GetConsoleMode(hIn, &origin_in_flag) && not GetConsoleMode(hOut, &origin_out_flag)) {
	  throw "GetConsoleMode fail";
	}

    return true;
  }

  void SetMode() {
	DWORD out_flag = origin_out_flag;
	out_flag |= (ENABLE_VIRTUAL_TERMINAL_PROCESSING | DISABLE_NEWLINE_AUTO_RETURN);
	SetConsoleMode(hOut, out_flag);
	SetConsoleOutputCP(65001);

	DWORD in_flag = 0;
	in_flag = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE;
	in_flag &= ~ENABLE_ECHO_INPUT;
	SetConsoleMode(hIn, in_flag);
  }
}