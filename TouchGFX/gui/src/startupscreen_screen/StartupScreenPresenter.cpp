#include <gui/startupscreen_screen/StartupScreenView.hpp>
#include <gui/startupscreen_screen/StartupScreenPresenter.hpp>

StartupScreenPresenter::StartupScreenPresenter(StartupScreenView& v)
    : view(v)
{

}

void StartupScreenPresenter::activate()
{
	model -> setScanPotVal(true);
}

void StartupScreenPresenter::deactivate()
{

}

void StartupScreenPresenter::newPotVal(int value)
{
    view.setPotVal(value);
}

void StartupScreenPresenter::ChangePwmValue(int value)
{
	model -> SetPwmValue(value);
}
