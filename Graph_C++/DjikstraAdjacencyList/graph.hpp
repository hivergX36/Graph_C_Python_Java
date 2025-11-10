
class Edge{
    public:

    int pred, succ;
};



class Succ{

    public: 

    int succ, weight;
};


struct list_adjacence{

    public:
    int V;
    std::vector<Succ>*l;


    list_adjacence(int Nbsommet){
        
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




    void djikstra(list_adjacence graph){
    int  prec; 
    int  Distsucc;
    int  distance;
    int  Lenght;
    int Nodes[V];
    int chemin[V];
    int dist[V];
    int visit[V];
    std::queue<int>QNbNode;

    for(int i = 0; i < V + 1; i++){
        Nodes[i] = i;
        dist[i] =  1000000;
        chemin[i] = 1000000;
        visit[i] = 0;

    };
    
    dist[0] = 0;
    chemin[0] = 0;
    QNbNode.push(Nodes[0]);
    Lenght = QNbNode.size();
    
    while (Lenght > 0)
    {
    prec = QNbNode.front();
    visit[prec] = 1;
    std::cout << "Le predecesseur est: " << prec << " " << std::endl;
    QNbNode.pop();

    for (Succ el : graph.l[prec])
    {
        if(visit[el.succ] < 1){
        std::cout << "le successeur est: " << el.succ << std::endl;
  
        Distsucc = dist[el.succ];
        distance = dist[prec] + el.weight;

        if(distance < Distsucc) {
            dist[el.succ] = distance;
            chemin[el.succ] = prec;
            if(el.succ < V){
            QNbNode.push(el.succ);
            };
        };
        };
    Lenght = QNbNode.size();
    }

    for(int i = 0; i < V + 1; i++){
        std::cout << chemin[i] << " ";
    }

     std::cout << std::endl;
 
    

};
    };



    void display_circuit(std::vector<int> circuit){
    for(int i = 0; i < circuit.size(); i++){
    std::cout << circuit[i] << " ";
    }
    std::cout<< std::endl;
};

};