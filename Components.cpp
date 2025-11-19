#include "Components.h"
#include <stdexcept>
#include <iomanip>
#include <cmath>
using namespace std;

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


double Resistor::getResistance() const { return resistance;} //inline get functions
double Resistor::getVoltage() const { return voltage;}
double Resistor::getCurrent() const { return current;}

double Node::getVoltage() const { return nodeVoltage;}
int Node::getNodeNumber() const { return nodeNumber;}
int Node::getResistorCount() const { return resistors.size();}



void Resistor::setVoltage(double v) {//set sources
    voltage = v;
    current = voltage / resistance;
}
void Resistor::setCurrent(double i) {
    current = i;
    voltage = current * resistance;
}
void Node::setVoltage(double v) { // update voltage across all resistors in this node
    nodeVoltage = v; 
    for (auto& r : resistors) { //auto for variable as could be int or double based on division
        r.setVoltage(v);
    }
}
void Node::calculateCurrents(double totalCurrent) {
    // Current division for parallel resistors
    for (auto& r : resistors) { //auto for variable as could be int or double based on division
        double req = getEquivalentResistance();
        double current = totalCurrent * (req / r.getResistance());
        r.setCurrent(current);
    }
}

void Node::addResistor(double resistance) {
    resistors.push_back(Resistor(resistance));
}


double Node::getEquivalentResistance() const {//resistance
    if (resistors.empty()) return 0.0;
    
    // For parallel resistors: 1/Req = 1/R1 + 1/R2 + ... + 1/Rn
    double sum = 0.0;
    for (const auto& r : resistors) {
        sum += 1.0 / r.getResistance();
    }
    return 1.0 / sum;
}
double Node::getTotalResistance() const {
    double total = 0.0;
    for (const auto& r : resistors) {
        total += r.getResistance();
    }
    return total;
}



void Node::print() const {
    cout << "Node " << nodeNumber << " [V=" << fixed 
              << setprecision(3) << nodeVoltage << "V, "
              << resistors.size() << " resistor(s)]" << endl;
    for (size_t i = 0; i < resistors.size(); i++) {
        cout << "  " << i + 1 << ". " << resistors[i] << endl;
    }
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

