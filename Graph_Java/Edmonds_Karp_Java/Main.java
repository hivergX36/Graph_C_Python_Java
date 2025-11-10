public class Main {
    public static void main(String[] args) {
        EdmondsKarp edmondskarp = new EdmondsKarp("data.txt");
        edmondskarp.solve();
        edmondskarp.displayResidualGraphAndMaxFlow();
    }
}
