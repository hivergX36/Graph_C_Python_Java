public class Main {
    public static void main(String[] args) {
        Max_coupling max_coupling = new Max_coupling("data2.txt");
        max_coupling.displayResidualGraphAndMaxFlow();
        max_coupling.solve();
        max_coupling.displayResidualGraphAndMaxFlow();
    }
}
