package IV.Figures;

public class VolumetricFigure {
    private Figure base;
    private double h;

    VolumetricFigure(double h, Figure base) {
        this.base = base;
        this.h = h;
    }

    public double calcArea() {
        return h * base.calcArea();
    }
}
