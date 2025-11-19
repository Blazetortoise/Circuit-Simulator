#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Components.h"
#include "Source.h"
#include <vector>
#include <string>
using namespace std;

class Circuit {
private:
    vector<Node> nodes;  // STL vector dynamic collection
    Source source;
    Ground ground;
    string circuitName;

public:
    Circuit(double sourceVoltage, const string& name = "Circuit");
    ~Circuit();

    void buildC(); //build func
    void addNode();

    void calculateVoltages(); // circuit analysis
    void analyzeCircuit();

    void printCircuit() const; // displays
    void printAnalysis() const;

    void saveToFile(const string& filename) const; // file I/O
    void loadFromFile(const string& filename);
    // Advanced C++ feature: Lambda function usage
    void demonstrateLambda() const;

     friend ostream& operator<<(ostream& out,const Circuit& c); //another way to print the circuit, also for operator overloading requirement
};

#endif
