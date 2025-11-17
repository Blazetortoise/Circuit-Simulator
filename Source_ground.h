#ifndef SOURCE_H
#define SOURCE_H
#include "Node.h"
#include <iostream>
using namespace std;

class Source : public Node{
protected:
    double voltage;

public:
    Source(double v = 0.0);

    double getVoltage() const;
    void print() const;
};

class Ground : public Node{
public:
    Ground();
    double getVoltage() const;
    void print() const;
};

#endif
