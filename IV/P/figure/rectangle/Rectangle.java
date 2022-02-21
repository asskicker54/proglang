package figure.rectangle;

import figure.Figure;

public class Rectangle implements Figure {
    private double a;
    private double b;
    Rectangle(double a, double b) throws Exception {
        if (a <= 0 || b <= 0) {
            throw new Exception("Invalid rectangle sizes"); 
        }
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