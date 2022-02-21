package figure.triangle;

import figure.Figure;

public class Triangle implements Figure  {
    private double a;
    private double b;
    private double c;

    Triangle(double a, double b, double c) throws Exception {
        if(a <= 0 || b <= 0 || c <= 0) {
            throw new Exception("Invalid Triangle Sizes");
        }
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