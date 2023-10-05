#include "cli_ui.define.h"
#include "cli_ui.h"
#include "cli_ui.common.h"
#include "cli_ui.native.h"


namespace cli_ui {

  static CliUI_InitOption initOption{};
  // static cli_cm::EventEmitter globalEventEmitter;

  void init(CliUI_InitOption option) {
	cli_nt::InitHandle(
	  option.handleIn,
	  option.handleOut
	);
	cli_nt::SetMode();
	initOption = option;
  }

  void loop() {
	HANDLE hIn = initOption.handleIn;
	HANDLE hOut = initOption.handleOut;
	INPUT_RECORD	input_record{};
	DWORD			res{};


	while (true) {
	  // Sync loop. Like message loop.

	  ReadConsoleInput(hIn, &input_record, 1, &res);

	  if (input_record.EventType == KEY_EVENT) {
		handleKeyEvent(input_record);
		continue;
	  }

	  if (input_record.EventType == MOUSE_EVENT) {
		handleMouseEvent(input_record);
		continue;
	  }

	  if (input_record.EventType == FOCUS_EVENT) {
		globalEventEmitter.emit(CLI_FOCUSEVENT, &input_record.Event.FocusEvent.bSetFocus);
		continue;
	  }

	  if (input_record.EventType == WINDOW_BUFFER_SIZE_EVENT) {
		globalEventEmitter.emit(CLI_SIZEEVENT, &input_record.Event.WindowBufferSizeEvent.dwSize);
		continue;
	  }
	}
	CloseHandle(hOut);
	CloseHandle(hIn);
  }


  void handleKeyEvent(INPUT_RECORD key_event) {
	auto ev_key = key_event.Event.KeyEvent;
	WORD key_control;

	{

	  DWORD control_key = ev_key.dwControlKeyState;

	  if (control_key == ENHANCED_KEY) {
		key_control = NULL;
	  }

	  else if (control_key == LEFT_ALT_PRESSED) {
		key_control = VK_LMENU;
	  }

	  else if (control_key == LEFT_CTRL_PRESSED) {
		key_control = VK_LCONTROL;
	  }

	  else if (control_key == RIGHT_ALT_PRESSED) {
		key_control = VK_RMENU;
	  }

	  else if (control_key == RIGHT_CTRL_PRESSED) {
		key_control = VK_RCONTROL;
	  }

	  else if (control_key == NUMLOCK_ON) {
		key_control = VK_NUMLOCK;
	  }

	  else if (control_key == SCROLLLOCK_ON) {
		key_control = VK_SCROLL;
	  }

	  else if (control_key == CAPSLOCK_ON) {
		key_control = VK_CAPITAL;
	  }

	  else {
		key_control = VK_SHIFT;
	  }

	}

	cli_def::EventKeyData data{};
	data.bKeyDown = ev_key.bKeyDown;
	data.dwRepeatCount = ev_key.wRepeatCount;
	data.dwVirtualKeyCode = ev_key.wVirtualKeyCode;
	data.wInput = ev_key.uChar.AsciiChar;
	data.wcInput = ev_key.uChar.UnicodeChar;
	data.dwKeyControl = key_control;
	
	globalEventEmitter.emit(CLI_KEYEVENT, &data);
  }

  void handleMouseEvent(INPUT_RECORD mouse_event) {
	DWORD mouse_type = NULL;
	DWORD mouse_control = NULL;
	DWORD mouse_flag = mouse_event.Event.MouseEvent.dwEventFlags;

	{

	  DWORD mouse_state = mouse_event.Event.MouseEvent.dwButtonState;

	  if (mouse_state == FROM_LEFT_1ST_BUTTON_PRESSED) {
		mouse_type = VK_LBUTTON;
	  }

	  else if (mouse_state == FROM_LEFT_2ND_BUTTON_PRESSED) {
		mouse_type = VK_MBUTTON;
	  }

	  else {
		mouse_type = VK_RBUTTON;
	  }

	} {

	  DWORD control_key = mouse_event.Event.MouseEvent.dwControlKeyState;

	  if (control_key == ENHANCED_KEY) {
		mouse_control = NULL;
	  }

	  else if (control_key == LEFT_ALT_PRESSED) {
		mouse_control = VK_LMENU;
	  }

	  else if (control_key == LEFT_CTRL_PRESSED) {
		mouse_control = VK_LCONTROL;
	  }

	  else if (control_key == RIGHT_ALT_PRESSED) {
		mouse_control = VK_RMENU;
	  }

	  else if (control_key == RIGHT_CTRL_PRESSED) {
		mouse_control = VK_RCONTROL;
	  }

	  else if (control_key == NUMLOCK_ON) {
		mouse_control = VK_NUMLOCK;
	  }

	  else if (control_key == SCROLLLOCK_ON) {
		mouse_control = VK_SCROLL;
	  }

	  else if (control_key == CAPSLOCK_ON) {
		mouse_control = VK_CAPITAL;
	  }

	  else {
		mouse_control = VK_SHIFT;
	  }

	}

	cli_def::EventMouseData data{};
	data.dwMouseType = mouse_type;
	data.dwMouseFlag = mouse_flag;
	data.dwMouseControl = mouse_control;

	globalEventEmitter.emit(CLI_MOUSEEVENT, &data);
  }
}