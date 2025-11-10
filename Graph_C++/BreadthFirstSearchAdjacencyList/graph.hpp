
class Edge{
    public:

    int pred, succ;
};



class Succ{

    public: 

    int succ, weight;
};


struct breadthFistSearch_list_adjacence{

    public:
    int V;
    std::vector<Succ>*l;


    breadthFistSearch_list_adjacence(int Nbsommet){
        
         V = Nbsommet;
         l = new std::vector<Succ>[Nbsommet];
     
    };
   

    void add_edges(int x, int y, int w){

        l[x].push_back({y,w});

    };

    void display_graph(){

        for(int i = 0; i < V; i ++){
            std::cout << i  << " --> " << " " ;
            for (Succ el : l[i])
            {
                std::cout << "succ: "<< el.succ << " "  << "weight: " << el.weight << " " ;
            
            };

            std::cout << std::endl;
        };


    };




    void breadthFistSearch(){
    int  prec; 
    int Lenght;
    int compteur;
    int Nodes[V];
    int orderVisit[V];
    int dist[V];
    int visit[V];
    int increment = 0;
    std::queue<int>QNbNode;

    std::cout << "V" << V << std::endl;
    

    
    
    for(int i = 0; i < V + 1; i++){
        Nodes[i] = i;
        visit[i] = 0; 
        orderVisit[i] = 0;

    } 
    
    QNbNode.push(0);
    visit[0] = 1;
    Lenght = QNbNode.size();
    while (Lenght > 0 && increment < 5){
    prec = QNbNode.front();
    std::cout << "prec: " << prec   << std::endl;


    Lenght = QNbNode.size();
    std::cout << "Longueur: " << Lenght   << std::endl;
    QNbNode.pop();

    for (Succ el : l[prec]){
        compteur = el.succ; 

        if(visit[el.succ] < 1){
            visit[el.succ] = 1;
            increment++;
            orderVisit[increment] = el.succ;
            QNbNode.push(el.succ);



        }

     
      };


    std::cout << "incrementation: " << increment<< std::endl;

    
   



 

    };

    std::cout << "Le résultat du parcours en largeur est: "; 
   

for(int i = 0; i < V + 1; i++){
    std::cout << orderVisit[i] << " ";
}
std::cout << std::endl;
};




    void display_circuit(std::vector<int> circuit){
    for(int i = 0; i < circuit.size(); i++){
    std::cout << circuit[i] << " ";
    }
    std::cout<< std::endl;
};

};