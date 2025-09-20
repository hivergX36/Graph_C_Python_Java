#include<iostream>
#include<vector> 
#include<list> 
#include<string> 
#include<queue>
#include"graphMatrix.hpp"

   


int main(){

    int NbSommet = 6;
    std::vector<Edges> vertices  = {{0,1,1},{0,3,9},{1,2,2},{1,3,4}, {2,3,5}, {2,4,7}, {3,4,1}, {4,5,10}};

    Adjacency_Matrix  graph =  Adjacency_Matrix(NbSommet);
    for (int i = 0; i < vertices.size(); i ++){
       
        graph.add_edge(vertices[i].x, vertices[i].y,vertices[i].p);
    
    }; 

    graph.display_matrix();
    

    graph.djikstra();



    


};