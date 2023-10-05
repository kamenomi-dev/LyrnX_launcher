#include "cli_ui.common.h"
#include <iostream>
using namespace cli_cm;

std::unordered_map<DWORD, std::unordered_set<LONG_PTR>*> EventMap;

namespace cli_cm {

  // Class definition

  EventEmitter::EventEmitter() {
    // Nothing to do.
  }

  void EventEmitter::on(DWORD event_code, EventCallback proc) {
    if (EventMap.find(event_code) == EventMap.end()) {
      EventMap.emplace(event_code, new std::unordered_set<LONG_PTR>);
    }

    auto& value = EventMap.find(event_code)->second;
    value->emplace((LONG_PTR)(void*)proc);
  }

  void EventEmitter::off(DWORD event_code, EventCallback proc) {
    if (EventMap.find(event_code) == EventMap.end()) {
      EventMap.emplace(event_code, new std::unordered_set<LONG_PTR>);
    }

    auto& value = EventMap.find(event_code)->second;
    value->erase((LONG_PTR)(void*)proc);
  }

  void EventEmitter::emit(DWORD event_code, void* data) {
    if (EventMap.find(event_code) == EventMap.end()) {
      EventMap.emplace(event_code, new std::unordered_set<LONG_PTR>);
    }

    std::cout << event_code;
    auto& value = EventMap.find(event_code)->second;
    
    for (auto it = value->begin(); it != value->end(); ++it) {
      auto some = (EventCallback*)*it;
      some(data);
    }
  }
  void EventEmitter::em(DWORD event_code, void* data) {
    EventEmitter::emit(event_code, data);
  }
}
