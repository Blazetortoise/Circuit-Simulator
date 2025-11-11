//I'm going to make this the main file for now since we have like a billion others
#include <iostream>
#include "resistors.h"
using namespace std;


class Circuit{
protected:
    vector<Node> nodes;
    Source source;
    Ground ground;

public:
    Circuit(){}

    void nodecalc(){
        if(!voltagesource){
            cout << "No voltage source" << endl;
        }


    void addResistor(double r) {
        resistors.push_back(Resistor(r));
    }
        
        double totalR, Vs, cur;
        
    }


};//end circuit class

int main(){

circuit Circuit();

}



int main()
{
    
    return 0;
}
