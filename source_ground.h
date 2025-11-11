#include <iostream>
using namespace std;

class Source {
protected:
    double voltage;

public:
    Source(double v = 0.0) : voltage(v) {}

    double getVoltage() const { return voltage; }

    void print() const {
        cout << "Voltage Source: " << voltage << " V" << endl;
    }
};

class Ground {
public:
    Ground() {}
    double getVoltage() const { return 0.0; }
};
