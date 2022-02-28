import figure.circle.Circle;
//import figure.rectangle.Rectangle;
//import figure.triangle.Triangle;
import cylinder.Cylinder;

public class App {
    public static void main(String[] args) {
        Circle c;

        try {
            c = new Circle(10);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return;
        }

        System.out.println(c.calcPer());

        Cylinder cyl;

        try{
            cyl = new Cylinder(5, c);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return;
        }

        System.out.println(cyl.calcVolume());
    }
}
