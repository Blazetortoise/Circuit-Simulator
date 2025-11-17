#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Resistor{

protected:
    double resistance;
    double voltage;
    double current;
public:

    Resistor(double r = 1.0);
    double getResistance() const { return resistance; }
    double getVoltage() const { return voltage; }
    double getCurrent() const { return current; }   

    void setCurrent(double i){
        current = i;
        voltage = current * resistance;
    }

    void print(){ //make this an overloaded insertion operator later
        cout << "Resistor with Resistance: " << res << " Current: " << resCurrent << " Voltage: " << resVoltage<<endl;
    }
    double getValue() {return res; }
};

class Node{ // not really a "node" as they are in nodal analysis, basically just a resistor honestly 
protected:
    int position;
    
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

#endif
