

class Edges
{
    public: 

    int x,y,p; 
};



struct DephtFistSearchMatrix{
    
    
    int Nbsommet;
    std::vector<int> *Matrice; 



    DephtFistSearchMatrix(int V){
    Nbsommet = V;
    Matrice = new std::vector<int>[Nbsommet]; 
    
    for(int i = 0; i < Nbsommet;i++){
        for(int j = 0; j < Nbsommet ; j++){
            Matrice[i].push_back(0);
            }
        }
    }

/* On ajoute le poidds à l'arrete correspondante */  
    void add_edge(int x, int y, int p){

        Matrice[x][y] = p;

    }




    void display_matrix(){

        for(int i = 0; i < Nbsommet; i ++){
            for(int j = 0; j < Nbsommet; j++){

                std::cout << Matrice[i][j] << " "; 

            }

            std::cout <<  std::endl; 
        }

    }

    void DephtFistSearch(){
        int prec; 
        int succ; 
        int pds_succ; 
        int dist = 0;
        int Nodes[Nbsommet];
        int chemin[Nbsommet];
        int visit[Nbsommet];
        int lenght;
        int increment = 0;
  
        std::stack<int> pile; 

        pile.push(0);
        
        for(int i = 0; i < Nbsommet; i++){
            Nodes[i] = i;
             visit[i] = 0;
            chemin[i] = 0;

        }
        
        visit[0] = 1;
        pile.push(0);
        lenght = pile.size();

        while(lenght > 0){
            prec = pile.top();
            pile.pop();
            for(int i = 0; i < Nbsommet; i++){
                if (Matrice[prec][i] > 0){
                    succ = i; 
                    if(visit[succ] < 1){
                        visit[succ] = 1;
                        increment++;
                        chemin[increment] = succ; 
                        pile.push(succ);
                        }
                    }
                lenght = pile.size();
            };
       

    };

    std::cout << "Le résultat du parcours en profondeur est: "; 

     for(int i = 0; i < Nbsommet; i++)
        {
        
        std::cout << chemin[i] << " ";
            
        }; 
        std::cout<< std::endl;

    };
};
