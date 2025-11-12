//I'm going to make this the main file for now since we have like a billion others
#include <iostream>
#include <vector>
#include "components.h"
#include "source.h"
using namespace std;


class Circuit{
protected:
    vector<Node> nodes;
    Source source;
    Ground ground;

public:
    Circuit(const Source &src, const Ground &gnd) : 
    source(src), ground(gnd), totalResistance(0.0), totalCurrent(0.0) {}

    void buildC(){
        cout << "how many nodes, not including GND: " ;
        cin >> numNodes;
            if (numNodes <= 0){
                throw invalid_argument("Invalid input");
            }
        

    for(int i = 0; i < numNodes; i++){
        Node n(i);
        char resp;

        cout << "would you like to add resistors to node " << i << "(y/n)";
        cin resp;

        while(resp == y){
            double value;
            cout << "enter resistor value (ohms): "
            cin >> value;
            n.addResistor(value);

            cout << "would you like to add another resistor to node " << i << "(y/n)";
            cin >> resp;
        }
    nodes.push_back(n);
    }
}



    void CalcVoltage() {
        try{
            totalres = 0.0;

            for(numNodes){
                totalres += n.totalres;
            }
            if(totalres <= 0){
                throw runtime_error("invalid circuit, resistance cannot be 0 or negative");
            }

            double vs = source.getVoltage(); //gets voltage from user input
            totalC = vs / totalres; // v= i*r -> i = v/r

            cout << "**voltage division**" << endl;
            cout << "Total resistance: " << totalres << " ohms" << endl;
            cout << "current: " << totalc << " A" << endl;
            
//need math 
        }
    }
    
    void printCircuit() const{
        cout << "*****************" << endl;
        source.print();

        for(const auto &n : nodes)
            cout << n;
    }


};//end circuit class

