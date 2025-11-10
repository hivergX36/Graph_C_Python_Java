#include<iostream>
#include<vector> 
#include<list> 
#include<string> 
#include<queue>
#include"graphMatrixBreathFirstSearch.hpp"

   


int main(){

    int NbSommet = 6;
    std::vector<Edges> vertices  = {{0,1,1},{0,3,1},{1,2,1},{1,3,1}, {2,3,1}, {2,4,1}, {3,4,1}, {4,5,1}};

    BreathFistSearchMatrix  graph =  BreathFistSearchMatrix(NbSommet);
    for (int i = 0; i < vertices.size(); i ++){
       
        graph.add_edge(vertices[i].x, vertices[i].y,vertices[i].p);
    
    }; 

    graph.display_matrix();
    

    graph.breathFistSearch();



    


};