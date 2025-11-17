#include "Source.h"
#include <iostream>
using namespace std;

Source::Source(double v) : Node(0), voltage(v){
  nodeVoltage = v;
}
Ground::Ground() : Node(-1) {
  nodeVoltage = 0.0;
}

double Source::getVoltage() const{ return voltage;}
double Ground::getVoltage() const { return 0.0;}

void Source::setSourceVoltage(double v) {
  voltage = v;
  nodeVoltage = v;
}


void Source::print() const {
  cout << "Voltage Source: " << voltage << " V" << endl;
}
void Ground::print() const {
  cout << "Ground: 0.0 V" << endl;
}
