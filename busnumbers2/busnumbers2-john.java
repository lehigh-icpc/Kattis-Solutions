import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int m = s.nextInt();
        
        HashSet<Integer> cubes = new HashSet<>();
        for (int i = 1; i < 80; i++) {
            cubes.add(i*i*i);
        }
        
        for (int tgt = m; tgt > 0; tgt--) {
            int matches = 0;
            for (int a : cubes) {
                if (cubes.contains(tgt - a)) {
                    matches++;
                    if (matches == 4) { // 4 because reverse is included (a,b) and (b,a)
                        System.out.println(tgt);
                        return;
                    }
                }
            }
        }
        
        System.out.println("none");
    }
}
