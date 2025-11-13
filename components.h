#include <iostream>
using namespace std;

class Resistor{

protected:
    int res;
    double resVoltage;
    double resCurrent;
public:

    Resistor(){
        int input; //Every time a resistor is created you are asked for the value
        cout<< "What value should this resistor have? " <<endl;
        cin>>input;
        res = input;
    }
    void print(){ //make this an overloaded insertion operator later
        cout << "Resistor with Resistance: " << res << " Current: " << resCurrent << " Voltage: " << resVoltage<<endl;
    }
    double getValue() {return res; }
};

class Node{ // not really a "node" as they are in nodal analysis, basically just a resistor honestly 
protected:
    int position; // since there are going to be multiple nodes in a circuit, might add this to circuit class instead idk
    Resistor *resistors; // for dynamic memory allocation later
    int rtot; // total resistance to be counted as resistors are created
    double nodeVoltage;
    int numResistors; //Handy for current division later
public:
    Node(){
        string type; // input variables
        int num;
        cin>>num;
        resistors = new Resistor[num];
        }
    }


};
