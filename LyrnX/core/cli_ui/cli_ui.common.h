#pragma once


#include <Windows.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

namespace cli_cm {

  typedef void __stdcall EventCallback(void* data);

  class EventEmitter {
    public:
    EventEmitter();

    void on(DWORD event_code, EventCallback);
    // void once(DWORD event_code, EventCallback);
    void off(DWORD event_code, EventCallback);

    void em(DWORD event_code, void* data);
    void emit(DWORD event_code, void* data);
  };

}