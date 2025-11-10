//I'm going to make this the main file for now since we have like a billion others

#include <iostream>
#include "resistors.h"
using namespace std;


class Circuit{
protected:
int rtotal; //this is the total resistance of the circuit
double 

public:
    Circuit(){

    }

    void nodecalc(){
        if(!voltagesource){
            cout << "No voltage source" << endl;
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
