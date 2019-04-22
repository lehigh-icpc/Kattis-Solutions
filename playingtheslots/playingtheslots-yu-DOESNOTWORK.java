import java.util.*;

/*
* DOES NOT WORK!!!!
*/
public class Main {
	public static class Point {
		double x;
		double y;
		Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int sides = s.nextInt();
		ArrayList<Point> points = new ArrayList<>(sides);
		double minDist = Double.MAX_VALUE;
		for(int i = 0; i < sides; i++) {
			double x = s.nextDouble();
			double y = s.nextDouble();
			points.add(new Point(x, y));
		}
		for(int i = 0; i < (sides-1); i++) {
			Point point1 = points.get(i);
			Point point2 = points.get(i+1);
			double dist2 = 0;
			if(point1.x == point2.x) {
				for(int j = 0; j < sides; j++) {
					double dist = Math.abs(point1.x - points.get(j).x);
					if(dist > dist2) {
						dist2 = dist;
					}
				}
			} else if (point1.y == point2.y) {
				for(int j = 0; j < sides; j++) {
					double dist = Math.abs(point1.y - points.get(j).y);
					if(dist > dist2) {
						dist2 = dist;
					}
				}
			} else {
				double slope = Math.abs(point2.y-point1.y) / Math.abs(point2.x-point1.x);
				double b = slope * -point1.x + point1.y;
				double inverseSlope = -1 / slope;
				for(int j = 0; j < sides; j++) {
					Point point = points.get(j);
					double b2 = point.y - inverseSlope*(point.x);
					double xCoeff = slope - inverseSlope;
					double otherCoeff = b2 - b;
					double xVal = otherCoeff / xCoeff;
					double yVal = slope * xVal + b;
					double dist = Math.sqrt(Math.pow(xVal-point.x, 2) + Math.pow(yVal-point.y, 2));
					if(dist > dist2) {
						dist2 = dist;
					}
				}
			}
			if(dist2 < minDist) {
				minDist = dist2;
			}

		}
		System.out.println(minDist);
	}
}
