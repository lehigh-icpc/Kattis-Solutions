import java.util.HashMap;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    HashMap<String, Integer> vars = new HashMap<>();
    Scanner s = new Scanner(System.in);

    while (s.hasNextLine()) {
      String[] line = s.nextLine().split(" ");

      if (line[0].equals("define")) {
        int val = Integer.parseInt(line[1]);
        vars.put(line[2], val);
        continue;
      } else if (line[0].equals("eval")) {
        if (!vars.containsKey(line[1]) || !vars.containsKey(line[3])) {
          System.out.println("undefined");
          continue;
        }
        int a = vars.get(line[1]);
        int b = vars.get(line[3]);
        if (line[2].equals("<")) {
          System.out.println(a < b);
        } else if (line[2].equals(">")) {
          System.out.println(a > b);
        } else {
          System.out.println(a == b);
        }
      }
    }
  }
}
