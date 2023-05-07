import java.lang.Math;

public class findPoint{
    public static void main(String[]args){
        double x;
        double y;
        double s;
        double x1;
        double y1;
        double nx1;
        double ny1;
        double x2;
        double y2;
        double nx2;
        double ny2;
        double b = 6.3;
        double a1 = 118.8;
        double a2 = 270;

        a1 = Math.toRadians(a1);
        a2 = Math.toRadians(a2);

        x1 = b * Math.cos(a1);
        y1 = b * Math.sin(a1);
        nx1 = y1;
        ny1 = -x1;

        x2 = b * Math.cos(a2);
        y2 = b * Math.sin(a2);
        nx2 = -y2;
        ny2 = x2;

        s = -((nx1*y2-nx1*y1-ny1*x2+ny1*x1)/(nx1*ny2-nx2*ny1));

        x = x2 + s * nx2;
        y = y2 + s * ny2;

        System.out.println(("x is ")+x);
        System.out.println(("y is ")+y);
    }
}