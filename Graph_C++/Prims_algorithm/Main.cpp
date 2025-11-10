#include <iostream>
#include "Prim.hpp"


int main() {
  Prim prim = Prim(5);
  prim.parse_data("data.txt");
  prim.display_adjacency_list();
  prim.run_prim();
  prim.display_result_path();

       
}