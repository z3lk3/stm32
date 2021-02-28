#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>
#define TIM_CHANNEL_1 0x00000000U

extern "C"
{
	extern uint32_t GetPotVal(void);
	void setPWMtim12(int value);
}

Model::Model() : modelListener(0), tickCounter(0), scanPotVal(false), lastSliderVal(0)
{

}

void Model::tick()
{
	tickCounter++;
	if (((tickCounter % 20) == 0) && (scanPotVal))
	{
		if (modelListener != 0)
	    {
			modelListener -> newPotVal(getPotVal());
	    }
	}
}

int Model::getPotVal()
{
#ifndef SIMULATOR
	return GetPotVal();
#else
  // Implementation for simulator
  return 25;
#endif /*SIMULATOR*/
}

void Model::setScanPotVal(bool scanEnabled)
{
    scanPotVal = scanEnabled;
}

void Model::SetPwmValue(int value)
{
#ifndef SIMULATOR
	if(lastSliderVal != value)
	{
		lastSliderVal = value;
		setPWMtim12(value);
	}
#endif /*SIMULATOR*/
}
