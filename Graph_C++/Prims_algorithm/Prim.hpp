#include "Path.hpp"
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue> 
#include "Adgency_list.hpp"

class Prim
{

    private:
    int V; // Number of vertics
    Adgency_list* adj_list; // Adjacency list representation of the graph
    Path *result_path; // Resulting path after running Prim's algorithm
    std::queue<int> fifo; // Queue to select the edge with the minimum weight

    public:

    Prim(int v) : V(v) {
        adj_list = new Adgency_list(V);
        result_path = new Path(V);
    }

    ~Prim() {
        delete adj_list;
        delete result_path;
    }

    void add_edge_components(int u, int v, int weight) {
        adj_list->add_edge(u, v, weight);
    }

    void parse_data(std::string filename){
     std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }else{
            int V,u, v, weight;
            file >> V;
            for (int i = 0; i < V; i++) {
                fifo.push(i); // Initialize the min-heap with vertex indices
             
            }
            adj_list = new Adgency_list(V);
            result_path = new Path(V);
            while (file >> u >> v >> weight) {
                add_edge_components(u, v, weight);
            }
            std::cout << "Data parsed successfully from " << filename << std::endl;
            file.close();
        }
    };

    void display_adjacency_list() {
        adj_list->display_adjacency_list();
    }

    void run_prim() {
        while (!fifo.empty()) {
            int current_vertex = fifo.front();
            fifo.pop();

            // Process the current vertex and its edges
            for (const auto& succ : adj_list->list[current_vertex]) {
                int successor = succ.successor;
                int weight = succ.weight;

                // Check if this edge can be added to the result path
                if (result_path->cost[successor] > weight) {
                    result_path->cost[successor] = weight;
                    result_path->path[successor] = current_vertex;
                }
            }
        }
        // Implementation of Prim's algorithm
    }

    void display_result_path() {
        result_path->display_path();
    }
};




