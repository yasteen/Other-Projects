import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public class Draw extends JPanel {
	public final static int MAX_X = 800;
	public final static int MAX_Y = 800;
	float scaling_factor = .01f;
	float x, y;
	public double u, v;

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		for (int x_p = 0; x_p < MAX_X; x_p++) {
			for (int y_p = 0; y_p < MAX_Y; y_p++) {
				x = (x_p - MAX_X / 2) * scaling_factor;
				y = -(y_p - MAX_Y / 2) * scaling_factor;

				// u = Math.cos(x)*Math.cosh(y);
				// v = -Math.sin(x)*Math.sinh(y);
				
				// Enter equations here!
				u = (y * y + x * x + x) / (1 + x * x + y * y + 2 * x);
				v = y/(1+x*x+y*y+2*x);
				

				double hue;
				if (u > 0) {
					hue = Math.atan(v / (Math.sqrt(v * v + u * u) + u)) / Math.PI;
				} else if (u < 0 && v == 0) {
					hue = .5;
				} else {
					hue = Math.atan((Math.sqrt(v * v + u * u) - u) / v) / Math.PI;
				}
				float factor = 0f;
				double lightness = 1 - Math.pow(factor, Math.sqrt(v * v + u * u));
				Color c = new Color(Color.HSBtoRGB((float) hue, 1f, (float) lightness));

				g.setColor(c);
				g.drawRect(x_p, y_p, 1, 1);
			}
		}
		g.setColor(Color.BLACK);
		for (int x_l = 0; x_l < MAX_X * scaling_factor; x_l++) {
			g.drawLine(Math.round(MAX_X % (1 / scaling_factor) + x_l / scaling_factor), 0,
					Math.round(MAX_X % (1 / scaling_factor) + x_l / scaling_factor), MAX_Y);
		}
		for (int y_l = 0; y_l < MAX_Y * scaling_factor; y_l++) {
			g.drawLine(0, Math.round(MAX_Y % (1 / scaling_factor) + y_l / scaling_factor), MAX_X,
					Math.round(MAX_Y % (1 / scaling_factor) + y_l / scaling_factor));
		}
		g.fillOval(MAX_X / 2 - 5, MAX_Y / 2 - 5, 10, 10);

	}
}
