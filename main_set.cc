#include <iostream>
#include <fstream>
#include <vector>

#include "Set.h"

int main(void) {

  Set A;
  Set B(69);

  A.AddElement(2);
  A.AddElement(8);
  A.AddElement(16);
  A.AddElement(25);
  
  B.AddElement(56);
  B.AddElement(24);
  B.AddElement(25);
  B.AddElement(11);

  (A + B).WriteSet();
  std::cout << "hola\n";

  return 0;
}