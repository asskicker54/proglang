package volumetricFigure.prism;

import figure.Figure;
import volumetricFigure.VolumetricFigure;

public class Prism implements VolumetricFigure{
    private double h;
    private Figure base;

    public Prism(double h, Figure base) throws Exception {
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