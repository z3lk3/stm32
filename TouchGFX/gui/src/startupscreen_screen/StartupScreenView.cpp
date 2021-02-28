#include <gui/startupscreen_screen/StartupScreenView.hpp>

StartupScreenView::StartupScreenView() : lastPotVal(0), animationState(0), sliderValueChangedCallback(this, &StartupScreenView::sliderValueChangedCallbackHandler)
{

}

void StartupScreenView::setupScreen()
{
    StartupScreenViewBase::setupScreen();
    slider.setNewValueCallback(sliderValueChangedCallback);
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

void StartupScreenView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider)
    {
       presenter -> ChangePwmValue(value);
       presenter -> NewUpdateInterval(value);
    }
}

void StartupScreenView::ChangeUpdateInterval(int sliderMapValue,int sliderValue)
{
	if(sliderValue <= 10)
	{
		EngineAnimation.pauseAnimation();
		animationState = false;
	}
	else
	{
		if(animationState == false)
		{
			EngineAnimation.startAnimation(false, false, true);
			animationState = true;
		}
		EngineAnimation.setUpdateTicksInterval(sliderMapValue);
	}
}
