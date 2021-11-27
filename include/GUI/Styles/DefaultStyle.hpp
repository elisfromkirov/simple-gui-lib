#ifndef __DEFAULT_STYLE_HPP__
#define __DEFAULT_STYLE_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Styles/FilledStyle.hpp"

class SystemButtonStyle : public FilledStyle {
public:
    SystemButtonStyle();
    virtual ~SystemButtonStyle() override;
};

class TabButtonStyle : public FilledStyle {
public:
    TabButtonStyle();
    virtual ~TabButtonStyle() override;
};

class MenuStyle : public FilledStyle {
public:
    MenuStyle();
    virtual ~MenuStyle() override;
};

class MenuBarStyle : public FilledStyle {
public:
    MenuBarStyle();
    virtual ~MenuBarStyle() override;
};

class TitleBarStyle : public FilledStyle {
public:
    TitleBarStyle();
    virtual ~TitleBarStyle() override;
};

class TabBarStyle : public FilledStyle {
public:
    TabBarStyle();
    virtual ~TabBarStyle() override;
};

#endif // __DEFAULT_STYLE_HPP__