import java.util.Scanner;

class sodasurpler {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int e = s.nextInt();
        int f = s.nextInt();
        int c = s.nextInt();

        int numBottles = e + f;
        int numDrinks = 0;
        while (numBottles >= c) {
            int exchange = numBottles / c;
            numBottles -= exchange * c;
            numDrinks += exchange;
            numBottles += exchange;
        }
        System.out.println(numDrinks);
    }
}
