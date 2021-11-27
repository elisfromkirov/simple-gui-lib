#include "GUI/Styles/DefaultStyle.hpp"

SystemButtonStyle::SystemButtonStyle()
    : FilledStyle{ColorFromRGBA(0x313131ff), 
                  ColorFromRGBA(0x5177b2ff), 
                  ColorFromRGBA(0x3b3b3bff)} {}

SystemButtonStyle::~SystemButtonStyle() {}

TabButtonStyle::TabButtonStyle()
    : FilledStyle{ColorFromRGBA(0x2b2b2bff),
                  ColorFromRGBA(0x343434ff),
                  ColorFromRGBA(0x424242ff)} {}

TabButtonStyle::~TabButtonStyle() {}

MenuStyle::MenuStyle()
    : FilledStyle{ColorFromRGBA(0x212121ff),
                  ColorFromRGBA(0x5177b2ff),
                  ColorFromRGBA(0x5177b2ff)} {}

MenuStyle::~MenuStyle() {}

MenuBarStyle::MenuBarStyle()
    : FilledStyle{ColorFromRGBA(0x232323ff)} {}

MenuBarStyle::~MenuBarStyle() {}

TitleBarStyle::TitleBarStyle()
    : FilledStyle{ColorFromRGBA(0x313131ff)} {}

TitleBarStyle::~TitleBarStyle() {}

TabBarStyle::TabBarStyle()
    : FilledStyle{ColorFromRGBA(0x232323ff)} {}

TabBarStyle::~TabBarStyle() {}