import java.util.*;


public class Metaprogramming {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		HashMap<String, Integer> vars = new HashMap<>();
		while(s.hasNext()) {
			String line = s.nextLine();
			String[] linee = line.split(" ", 10);
			if(linee[0].equals("define")) {
				int val = Integer.parseInt(linee[1]);
				String name = linee[2];
				vars.put(name, val);
			} else if (linee[0].equals("eval")) {
				String name1 = linee[1];
				String name2 = linee[3];
				if(!(vars.containsKey(name1) && vars.containsKey(name2))) {
					System.out.println("undefined");
					continue;
				}
				int val1 = vars.get(name1);
				int val2 = vars.get(name2);
				if(linee[2].equals(">")) {
					if(val1 > val2) {
						System.out.println("true");
					} else {
						System.out.println("false");
					}
				} else if(linee[2].equals("=")) {
					if(val1 == val2) {
						System.out.println("true");
					} else {
						System.out.println("false");
					}
				} else {
					if(val1 < val2) {
						System.out.println("true");
					} else {
						System.out.println("false");
					}
				}
			}
		}
	}
}
