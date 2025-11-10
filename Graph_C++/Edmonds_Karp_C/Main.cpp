
#include <iostream>
#include "Edmonds_Karp.hpp"


int main() {
  EdmondsKarp edmondsKarp = EdmondsKarp();
  edmondsKarp.parse_file("data.txt");
  edmondsKarp.solve();
  edmondsKarp.display_result();

  return 0;
}

 
