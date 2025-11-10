#include <iostream>
#include "max_coupling.hpp"


int main() {
  Maxcoupling maxcoupling = Maxcoupling();
  maxcoupling.parse_file("data.txt");
  maxcoupling.solve();
  maxcoupling.display_result();

  return 0;
}

 