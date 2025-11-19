#include "Circuit.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "Components.h"
#include "Source.h"
using namespace std;

//constructor
Circuit::Circuit(double sourceVoltage, const string& name)
    : source(sourceVoltage), ground(), circuitName(name) {
    cout << "Circuit " << circuitName << " created with "
              << sourceVoltage << "V source" << endl;
}

//destructor
Circuit::~Circuit() {
    cout << "Circuit '" << circuitName << "' destroyed" << endl;
}

void Circuit::buildC(){
    int numNodes;
    cout << "how many nodes, not including GND: " ;
    cin >> numNodes;

    if (numNodes <= 0){ //if number is negative then throw exception
    throw invalid_argument("Invalid input");
    }

    for (int i = 0; i < numNodes; i++) {
        nodes.push_back(Node(i + 1));

        char resp;
        cout << "\n would you like to add resistors to node " << (i + 1) << "? (y/n): ";
        cin >> resp;

        while (resp == 'y' || resp == 'Y') {
            double value;
            cout << "enter resistor value (ohms): ";
            cin >> value;

            try {
                nodes[i].addResistor(value);
                cout << "Resistor added successfully!" << endl;
            } catch (const exception& e) {//any error for resistor input
                cout << "Error: " << e.what() << endl;
            }

            cout << "Add another resistor to Node " << (i + 1) << "? (y/n): ";
            cin >> resp;
        }
    }
}

//void Circuit::addNode() {
  //  int nodeNum = nodes.size() + 1;
    //nodes.push_back(Node(nodeNum));
    //cout << "Node " << nodeNum << " added to circuit" << endl;
//}

void Circuit::calculateVoltages() {
    if (nodes.empty()) {
        throw runtime_error("circuit has no nodes");
    }
    //series calc
    double totalResistance = 0.0;
    for (auto& node : nodes) {
        double req = node.getEquivalentResistance();
        if (req <= 0) {
            throw runtime_error("invalid node");
        }
        totalResistance += req;
    }
    if (totalResistance <= 0) {
        throw runtime_error("total resistance cannot be zero or negative");
    }

    double totalCurrent = source.getVoltage() / totalResistance; //ohms law calc

    // volt div calc
    double voltageSum = source.getVoltage();
    for (auto& node : nodes) {
        double req = node.getEquivalentResistance();
        double nodeCurrent = totalCurrent;
        double nodeVoltage = nodeCurrent * req;
        voltageSum -= nodeVoltage;
        node.setVoltage(nodeVoltage);
        node.calculateCurrents(nodeCurrent);
    }
}


void Circuit::analyzeCircuit(){
    cout << "\n ***circuit analysis***" << endl;
    try{
        calculateVoltages();

        // Calculate total resistance
        double totalResistance = 0.0;
        for (const auto& node : nodes) {
            totalResistance += node.getEquivalentResistance();
        }
        double totalCurrent = source.getVoltage() / totalResistance;

        cout << "\nTotal Circuit Resistance: " << totalResistance << " ohms" << endl;
        cout << "Total Current: " << totalCurrent << " A" << endl;
        cout << "Source Voltage: " << source.getVoltage() << " V" << endl;

        cout << "\n***Node Analysis***" << endl;
        for (const auto& node : nodes) {
            node.print();
        }
        } catch (const exception& e) {
            cerr << "Analysis Error: " << e.what() << endl;
        }
}


void Circuit::printCircuit() const {
    cout << "\n-------------------------------------" << endl;
    source.print();

    for (const auto& node : nodes) {
        node.print();
    }
    ground.print();

    cout << "\n-------------------------------------" << endl;


}
    void Circuit::printAnalysis() const {
    printCircuit();
    }

    void Circuit::saveToFile(const string& filename) const {//file io
        ofstream outFile(filename);
        if (!outFile) {
            throw runtime_error("Cannot open file for writing: " + filename);
        }

        outFile << circuitName << endl;
        outFile << source.getVoltage() << endl;
        outFile << nodes.size() << endl;

        for (const auto& node : nodes) {
            outFile << node.getNodeNumber() << " "
            << node.getResistorCount() << " "
            << node.getVoltage() << endl;
        }
        outFile.close();
        cout << "Circuit saved to " << filename << endl;
}


// Advanced C++ feature: Lambda functions (not typically covered in intro classes)
void Circuit::demonstrateLambda() const {
    cout << "\n=== Lambda Function Demonstration ===" << endl;
    cout << "Using lambda to calculate total power dissipation:" << endl;

    // Lambda function to calculate power (P = V * I)
    auto calculatePower = [](double voltage, double current) -> double {
        return voltage * current;
    };

    double totalPower = 0.0;
    for (const auto& node : nodes) {
        double power = calculatePower(node.getVoltage(),
            node.getVoltage() / node.getEquivalentResistance());
        totalPower += power;
    }

    cout << "Total Power Dissipation: " << totalPower << " W" << std::endl;
}

ostream& operator<<(ostream& out,const Circuit& c) {
    double totalResistance = 0.0;
    for (int i = 0; i < c.nodes.size(); i++) {
        double req = c.nodes[i].getEquivalentResistance();
        totalResistance += req;
    }
    out<< "  ***"<<endl;
    out<<" * + *"<<endl;
    out<<"*     * "<<c.source.getVoltage()<<"V"<<endl;
    out<<" * - *"<<endl;
    out<<"  ***"<<endl;
    out<<"   | "<< "Series Current: " << c.source.getVoltage() / totalResistance << "A"<<endl;
    out<<"   | "<<endl;
    out<<"   | "<<endl;
    out<<"   | "<<endl;
    for(int i = 0; i < c.nodes.size(); i++) {
        if (c.nodes[i].getResistorCount()<=3){
            switch(c.nodes[i].getResistorCount()) {
                case 1:
                    out<<"   |  Node "<< i+1 <<endl;
                    out<<"   \\ "<<endl;
                    out<<"   /  "<< "R:" << c.nodes[i].getResistances()[0] << " V:" << c.nodes[i].getVoltage()<<endl;
                    out<<"   \\ "<<endl;
                    out<<"   / "<<endl;
                    break;
                case 2: {
                    double v1 = c.nodes[i].getVoltage()*(c.nodes[i].getResistances()[0]/(c.nodes[i].getResistances()[0] + (c.nodes[i].getResistances()[1])));
                    double v2 = c.nodes[i].getVoltage()-v1;
                    out<<"    | "<<endl;
                    out<<"   ___ "<<endl;
                    out<<"   | | "<<endl;
                    out<<"   \\ \\ "<<endl;
                    out<<"   / / "<< "R:" <<  c.nodes[i].getResistances()[0]<<" V:"<< v1 <<" I:" << v1/c.nodes[i].getResistances()[0]<<endl;
                    out<<"   \\ \\"<<"R:" <<  c.nodes[i].getResistances()[1]<<" V:"<< v2 << v2/c.nodes[i].getResistances()[1]<<endl;
                    out<<"   / /"<<endl;
                    out<<"   --- "<<endl;
                    out<<"    | "<<endl;
                    break;
                }
                case 3:
                    double v1 = c.nodes[i].getVoltage()*(c.nodes[i].getResistances()[0]/(c.nodes[i].getResistances()[0] + (c.nodes[i].getResistances()[1])+
                        (c.nodes[i].getResistances()[2])));
                    double v2 =  c.nodes[i].getVoltage()*(c.nodes[i].getResistances()[1]/(c.nodes[i].getResistances()[0] + (c.nodes[i].getResistances()[1])+
                        (c.nodes[i].getResistances()[2])));
                    double v3 =  c.nodes[i].getVoltage()*(c.nodes[i].getResistances()[2]/(c.nodes[i].getResistances()[0] + (c.nodes[i].getResistances()[1])+
                        (c.nodes[i].getResistances()[2])));
                    out<<"    | "<<endl;
                    out<<"  _____ "<<endl;
                    out<<"  | | | Node Voltage Drop:"<<c.nodes[i].getVoltage()<<endl;
                    out<<"  \\ \\ \\ "<< "R:" <<  c.nodes[i].getResistances()[0]<<" V=" <<v1 << " " <<"I=" << v1/c.nodes[i].getResistances()[0] <<endl;
                    out<<"  \\ \\ \\"<< "R:" <<  c.nodes[i].getResistances()[1]<<" V=" << v2 << " " <<"I=" << v2/c.nodes[i].getResistances()[1] <<endl;
                    out<<"  / / /"<< "R:" << c.nodes[i].getResistances()[0]<<" V=" <<v3 << " " <<"I=" << v3/c.nodes[i].getResistances()[2] <<endl;
                    out<<"  ----- "<<endl;
                    out<<"    | "<<endl;
                    break;
            }

        } else {
            out<<"   \\ "<<endl;
            out<<"   /  "<<"Total Node Resistance: " << c.nodes[i].getTotalResistance()<<endl;
            out<<"   \\ "<<"Node Voltage:"<< c.nodes[i].getVoltage()<<endl;
            out<<"   / "<<endl;
            out<<"   |"<<endl;
        }
    }
    out<<"  ___  GND " <<endl;
    out<<"  /// " <<endl;
}
