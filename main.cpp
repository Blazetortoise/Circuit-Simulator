#include <iostream>
#include <string>
#include "Circuit.h"
using namespace std;

int main() {

    cout << "=== Simple Circuit Builder ===" << endl;

    double sourceVoltage;

    //voltage
    cout << "Enter source voltage (V): ";
    cin >> sourceVoltage;

    try {
        Circuit circuit(sourceVoltage);

        //number of nodes
        int numNodes;
        cout << "How many nodes (not including ground)? ";
        cin >> numNodes;

        if (numNodes <= 0) {
            throw invalid_argument("Number of nodes must be positive.");
        }

        // nodes + resistors
        for (int i = 0; i < numNodes; i++) {

            cout << "\n--- Node " << (i + 1) << " ---" << endl;

            // Add node to circuit
            circuit.nodes.push_back(Node(i + 1));

            char resp;
            cout << "Add resistors to this node? (y/n): ";
            cin >> resp;

            while (resp == 'y' || resp == 'Y') {

                double value;
                cout << "Enter resistor value (ohms): ";
                cin >> value;

                try {
                    circuit.nodes[i].addResistor(value);
                    cout << "Resistor added.\n";
                }
                catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                }

                cout << "Add another resistor? (y/n): ";
                cin >> resp;
            }
        }

        // Run analysis 
        cout << "\n\n=== Running Circuit Analysis ===\n";
        circuit.analyzeCircuit();

        // Print results
        cout << "\n=== Final Circuit ===\n";
        circuit.printCircuit();
    }
    catch (const exception& e) {
        cerr << "Fatal Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
