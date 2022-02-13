abstract class Figure {
    protected final double PI = 3.1415926535897932384626433832795;
    public abstract double calcArea();
    public abstract double calcPer();
}

class Rectangle extends Figure {
    private double a;
    private double b;
    Rectangle(double a, double b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public double calcArea() {
        return a * b;
    }

    public double calcPer() {
        return 2* (a + b);
    }
}

class Triangle extends Figure {
    private double a;
    private double b;
    private double c;

    Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public double calcPer() {
        return a + b + c;
    }

    public double calcArea() {
        double p = calcPer()/2;
        return Math.sqrt(p*(p-a)*(p-b)*(p-c));
    }
}

class Circle extends Figure {
    private double r;

    Circle(double r) {
        this.r = r;
    }

    @Override
    public double calcArea() {
        return PI * r * r;
    }

    public double calcPer() {
        return 2 * PI * r;
    }
}