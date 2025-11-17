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
    double getResistance() const;
    double getVoltage() const;
    double getCurrent() const;

    void setVoltage(double v);
    void setCurrent(double i);

    friend ostream& operator<<(ostream& os, const Resistor& r);
};

class Node{ 
protected:
    int nodeNumber;
    vector<Resistor> resistors;  
    double nodeVoltage;

 public:

    Node(int num = 0);
    virtual ~Node();

    void addResistor(double resistance);
    double getTotalResistance() const;
    double getEquivalentResistance() const;

    int getNodeNumber() const;
    double getVoltage() const;
    void setVoltage(double v);
    int getResistorCount() const;

    void calculateCurrents(double totalCurrent);
    virtual void print() const;


    friend ostream& operator<<(ostream& os, const Node& node);
};

#endif
