#include <gui/startupscreen_screen/StartupScreenView.hpp>

StartupScreenView::StartupScreenView() : lastPotVal(0)
{

}

void StartupScreenView::setupScreen()
{
    StartupScreenViewBase::setupScreen();
}

void StartupScreenView::tearDownScreen()
{
    StartupScreenViewBase::tearDownScreen();
}

void StartupScreenView::setPotVal(int value)
{
	if (lastPotVal != value)
	{
		lastPotVal = value;
		circleProgress.setValue(value);
		circleProgress.invalidate();
	}
}
