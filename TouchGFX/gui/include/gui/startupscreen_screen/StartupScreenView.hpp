#ifndef STARTUPSCREENVIEW_HPP
#define STARTUPSCREENVIEW_HPP

#include <gui_generated/startupscreen_screen/StartupScreenViewBase.hpp>
#include <gui/startupscreen_screen/StartupScreenPresenter.hpp>

class StartupScreenView : public StartupScreenViewBase
{
public:
    StartupScreenView();
    virtual ~StartupScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void setPotVal(int value);
protected:
    int lastPotVal;
    touchgfx::Callback<StartupScreenView, const touchgfx::Slider&, int> sliderValueChangedCallback;
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
};

#endif // STARTUPSCREENVIEW_HPP
