#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void setScanPotVal(bool scanEnabled);
    int getPotVal();
protected:
    ModelListener* modelListener;
    int tickCounter;
    bool scanPotVal;
};

#endif // MODEL_HPP
