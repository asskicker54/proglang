package figure.circle;

import figure.Figure;
import static java.lang.Math.PI;

public class Circle implements Figure {
    private double r;
    
    public Circle(double r) throws Exception {
        if(r <= 0) {
            throw new Exception("Invalid Radius");
        }
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
