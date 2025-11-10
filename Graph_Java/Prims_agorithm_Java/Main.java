public class Main {
    public static void main(String[] args) {
        Prims prims = new Prims("data.txt");
      
        prims.resolve();
        prims.displayPath();
    }
}
    