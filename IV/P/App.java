import figure.circle.Circle;
import volumetricFigure.prism.Prism;

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

        Prism cyl;

        try{
            cyl = new Prism(5, c);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return;
        }

        System.out.println(cyl.calcVolume());
    }
}
