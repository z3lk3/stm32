#include <gui/startupscreen_screen/StartupScreenView.hpp>
#include <gui/startupscreen_screen/StartupScreenPresenter.hpp>

StartupScreenPresenter::StartupScreenPresenter(StartupScreenView& v)
    : view(v)
{

}

void StartupScreenPresenter::activate()
{
	model -> setScanPotVal(true);
	view.ChangeUpdateInterval(false, false);//Disabling animation at startup
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

//long map(long x, long in_min, long in_max, long out_min, long out_max)
//{
//  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
//}

int mapv2(int value)
{
	if(value >= 3500)
		return 4;
	else if(value >= 3072)
		return 3;
	else if(value >= 2048)
		return 2;
	else if(value >= 1024)
		return 1;
	else
		return 0;
}

void StartupScreenPresenter::NewUpdateInterval(int value)
{
	sliderValueMap = mapv2(value);
	sliderValue = 5 - sliderValueMap;
	view.ChangeUpdateInterval(sliderValue, value);
}


