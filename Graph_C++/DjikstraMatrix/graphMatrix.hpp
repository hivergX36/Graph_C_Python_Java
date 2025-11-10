#include<vector> 


class Edges
{
    public: 

    int x,y,p; 
};



struct Fold_Fulkerson{
    
    
    int Nbsommet;
    std::vector<float> *Matrice; 



    Fold_Fulkerson(int V){
    Nbsommet = V;
    Matrice = new std::vector<float>[Nbsommet]; 
    
    for(int i = 0; i < Nbsommet;i++){
        for(int j = 0; j < Nbsommet ; j++){
            Matrice[i].push_back(0);
            }
        }
    }

/* On ajoute le poidds à l'arrete correspondante */  
    void add_edge(int x, int y, float p){

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

    void FoldFulkerson(){
        int prec; 
        int succ; 
        int pds_succ; 
        int dist = 0;
        int Nodes[Nbsommet];
        int chemin[Nbsommet];
        int distance[Nbsommet];
        int lenght;  
        std::queue<int> file; 

        file.push(0);
        
        for(int i = 0; i < Nbsommet; i++){
            Nodes[i] = i;
            distance[i] = 100000;
            chemin[i] = 0;

        }
        
        distance[0] = 0;
        file.push(0);
        lenght = file.size();

        while(lenght > 0){
            prec = file.front();
            std::cout << "Le predecesseur est: " << prec << " " << std::endl;
            file.pop();
            for(int i = 0; i < Nbsommet; i++){
                if (Matrice[prec][i] > 0){
                    succ = i; 
                    pds_succ = Matrice[prec][i];
                    std::cout << "le successeur est: " << succ << std::endl;
                    std::cout << "le poids du sucesseur est: " << pds_succ << std::endl;
                    dist = distance[prec] + succ; 
                    std::cout  << "la distance du calcul est: " << dist << std::endl;
                    if(dist < distance[succ]){

                        distance[succ] = dist;
                        chemin[succ] = prec; 
                        file.push(i);
                        }
                    }
                lenght = file.size();
                std::cout << "La longueur de la pile est: " << lenght << std::endl;
            };
        for(int i = 0; i < Nbsommet; i++)
        {
        
        std::cout << chemin[i] << " ";
            
        }; 
        std::cout<< std::endl;

    };

    };
};

