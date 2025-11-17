#include <iostream>
#include <string>
#include "Circuit.h"
using namespace std;

int main(){

  Circuit circuit(5,"Circuit1");
  circuit.buildCircuit();
  circuit.analyzeCircuit();
  circuit.printAnalysis();

  return 0;
}
