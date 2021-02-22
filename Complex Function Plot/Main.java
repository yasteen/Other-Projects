import javax.swing.JFrame;

public class Main {

	public static void main(String[] args) {
		JFrame frame = new JFrame("Complex Function Grapher");
		Draw d = new Draw();
		frame.add(d);
		frame.setVisible(true);
		frame.setSize(Draw.MAX_X, Draw.MAX_Y);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
