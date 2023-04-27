//Implement Adapter Design Pattern
#include <iostream>
using namespace std;

class WeightMachineInterface
{
    public:
    virtual double calculateWeight(string name) = 0;
};

class WeightMachine: public WeightMachineInterface
{
    double calculateWeight(string name) override
    {
        return 200.55;
    }
};

class AdapterWeightMachineInterface
{
    public:
    virtual double calculateWeighInKg() = 0;
};

class AdapterWeightMachine:public AdapterWeightMachineInterface
{
    WeightMachineInterface *ptr;
    string name;
    double calculateWeighInKg()
    {
        return (ptr->calculateWeight(name))*0.45;
    }
    public:
    AdapterWeightMachine(string persionName) :name{persionName}, ptr{new WeightMachine}
    {
    }
};

int main() {
    string name;
    cout<<"Enter Persion: ";
    cin>>name;
    cout<<"\n";
	AdapterWeightMachineInterface *wtMachine = new AdapterWeightMachine(name);
	cout<<"Weight of "<<name<<" in Kg: "<<wtMachine->calculateWeighInKg();
	return 0;
}