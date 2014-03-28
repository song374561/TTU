package homework;
import javax.swing.*;

import java.awt.*;

public class Smile extends JFrame{
	public Smile()
	{
		add(new Draw());
	}
	public static void main(String[] args)
	{
		Smile frame = new Smile();
		frame.setTitle("Smile");
		frame.setSize(309, 330);
		frame.setLocationRelativeTo(null);
		frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	public class Draw extends JPanel
	{
		protected void paintComponent(Graphics g)
		{
			int i = 150;
			int x[]={i,i-35,i+35};
			int y[]={i-20,i+70-20,i+70-20};
			g.drawArc(0, 0, 300, 300, 0, 360);
			g.drawArc(50, 70, 60, 40, 0, 360);
			g.drawArc(190, 70, 60, 40, 0, 360);
			g.drawArc(75, 170, 150, 80, 200, 145);
			g.drawPolygon(x, y, 3);
			g.fillArc(60,70,40,40,0,360);
			g.fillArc(200,70,40,40,0,360);
		}
	}
}
