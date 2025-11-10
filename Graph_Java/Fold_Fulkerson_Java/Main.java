
public class Main {
    public static void main(String[] args) {
        Fold_Fulkerson fold_Fulkerson = new Fold_Fulkerson("data2.txt");
        fold_Fulkerson.displayResidualGraphAndMaxFlow();
        fold_Fulkerson.resolve();
        fold_Fulkerson.displayResidualGraphAndMaxFlow();
    }
}
    
