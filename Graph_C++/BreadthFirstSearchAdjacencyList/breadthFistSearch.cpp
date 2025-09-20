#include<iostream>
#include<vector> 
#include<list> 
#include<string> 
#include<queue>
#include"graph.hpp"

   


int main(){

    int  prec; 
    int  Distsucc;
    int  distance;
    int  Lenght;


  
    std::vector<Edge> vertices = {{0,1},{0,3},{1,2},{1,3}, {2,3}, {2,4}, {3,4}, {4,5}};
    std::vector<int> poids = {1,9,2,4,5,7,1,10}; 
   

    
    breadthFistSearch_list_adjacence graph(5);
    
    for(int i = 0; i < 8; i++){
        graph.add_edges(vertices[i].pred, vertices[i].succ, poids[i]); 
        };

    graph.display_graph();
    graph.breadthFistSearch();

    

}