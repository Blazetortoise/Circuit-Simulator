#include <iostream>
using namespace std;

class Source : public Node{
protected:
    double voltage;

public:
    Source(double v = 0.0) : Node(0),  voltage(v) {}

    double getVoltage() const { return voltage; }

    void print() const {
        cout << "Voltage Source: " << voltage << " V" << endl;
    }
};

class Ground : public Node{
public:
    Ground() : Node(-1){ setVoltage(0.0);}
    double getVoltage() const { return 0.0; }
};
