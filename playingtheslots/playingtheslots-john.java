import java.util.*;
public class Main {
  static class Point {
    float x, y;
    Point(float x, float y) {
      this.x = x;
      this.y = y;
    }
  }
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    Point[] points = new Point[n];
    float minOverall = Float.POSITIVE_INFINITY;

    for (int i = 0; i < n; i++) {
      points[i] = new Point(scan.nextFloat(), scan.nextFloat());
    }
    for (int i = 0; i < n; i++) {
      int i2 = (i+1)%n;
      float x0 = points[i].x;
      float y0 = points[i].y;
      float x1 = points[i2].x;
      float y1 = points[i2].y;
      
      // line in form of ax + by + c = 0
      float a = y0 - y1;
      float b = x1 - x0;
      float c = x0 * y1 - x1 * y0;

      // get dist to every point
      float maxDistFromThis = 0;
      // denominator is constant
      float denom = (float)Math.sqrt(a*a + b*b);
      for (Point p : points) {
        float dist = Math.abs(a*p.x + b*p.y + c) / denom;
        if (dist > maxDistFromThis)
          maxDistFromThis = dist;
      }
      if (maxDistFromThis < minOverall) {
        minOverall = maxDistFromThis;
      }
    }
    System.out.println(minOverall);
  }
}
