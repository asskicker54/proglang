public class Cylinder {
    private double h;
    private Figure base;

    Cylinder(double h, Figure base) {
        this.h = h;
        this.base = base;
    }

    public double calcVolume() {
        return h * base.calcArea();
    }
}
