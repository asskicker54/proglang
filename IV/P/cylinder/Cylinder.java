package cylinder;

import figure.Figure;

public class Cylinder {
    private double h;
    private Figure base;

    public Cylinder(double h, Figure base) throws Exception {
        if(h <= 0 ) {
            throw new Exception("Ivalid height");
        } else {
        this.h = h;
        this.base = base;
        }
    }

    public double calcVolume() {
        return h * base.calcArea();
    }
}