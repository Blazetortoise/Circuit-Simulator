#include "Components.h"
#include <stdexcept>
#include <iomanip>
#include <cmath>


Resistor::Resistor(double r) : resistance(r), voltage(0.0), current(0.0) {
    if (r <= 0) {
        throw invalid_argument("invalid resistance");
    }
}

Node::Node(int num) : nodeNumber(num), nodeVoltage(0.0) {
    cout << "Node " << nodeNumber << " created" << endl;
}

Node::~Node() {
    cout << "Node " << nodeNumber << " destroyed" << endl;
}


double Resistor::getResistance() const { return resistance;} //inline get func
double Resistor::getVoltage() const { return voltage;}
double Resistor::getCurrent() const { return current;}

double Node::getVoltage() const { return nodeVoltage; }
int Node::getNodeNumber() const { return nodeNumber;}


void Resistor::setVoltage(double v) {//
    voltage = v;
    current = voltage / resistance;
}

void Resistor::setCurrent(double i) {
    current = i;
    voltage = current * resistance;
}





ostream& operator<< (ostream& os, const Resistor& r) {//overload operators
    os << "Resistor [R = " << r.resistance << " ohms, V=" 
       << r.voltage << "V, I=" << r.current << "A]";
    return os;
}
ostream& operator<<(ostream& os, const Node& node) {
    node.print();
    return os;
}










