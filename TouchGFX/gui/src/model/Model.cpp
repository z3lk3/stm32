#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>

extern "C"
{
extern uint32_t GetPotVal(void);
}

Model::Model() : modelListener(0), tickCounter(0), scanPotVal(false)
{

}

void Model::tick()
{
	tickCounter++;
	if (((tickCounter % 10) == 0) && (scanPotVal))
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
