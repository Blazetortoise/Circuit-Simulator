#include <iostream>
using namespace std;

class Resistor{

protected:
      int res;
      double voltage;
      double current;
public:
      
      Resistor(): {
            int input; //Every time a resistor is created you are asked for the value
            cout<< "What value should this resistor have? " <<endl;
            cin>input;
            res = input;
      }



  void print(){ //make this an overloaded insertion operator later
      cout << "Resistor with Resistance: " << res << " Current: " << current << " Voltage: " << voltage<<endl;
    }
      double getValue() {return res; }
};
