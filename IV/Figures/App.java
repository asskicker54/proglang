package Figures;


public class App {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle(10, 4);
        Circle c = new Circle(3);
        Triangle t = new Triangle(3, 4, 5);
        VolumetricFigure v = new VolumetricFigure(4, rect);

        System.out.println(rect.calcArea());
        System.out.println(rect.calcPer());
        System.out.println(c.calcArea());
        System.out.println(c.calcPer());
        System.out.println(t.calcArea());
        System.out.println(t.calcPer());
        System.out.println(v.calcArea());
    }
}
