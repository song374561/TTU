package homework;
import javax.swing.*;
import java.awt.*;

public class PieChart extends JFrame{
	public PieChart()
	{
		add(new Draw());
	}
	public static void main(String[] args)
	{
		PieChart frame = new PieChart();
		frame.setTitle("PieChart");
		frame.setSize(400, 400);
		frame.setLocationRelativeTo(null);
		frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	public class Draw extends JPanel
	{
		protected void paintComponent(Graphics g)
		{
			g.setColor(Color.red);
			g.fillArc(100, 50,200,200,0,72);
			g.setColor(Color.blue);
			g.fillArc(100, 50, 200, 200, 72, 36);
			g.setColor(Color.orange);
			g.fillArc(100, 50, 200, 200, 216, 144);
			g.setColor(Color.green);
			g.fillArc(100, 50, 200, 200, 108, 108);
			g.setColor(Color.black);
			g.drawString("Projects -- 20%", 270, 80);
			g.drawString("Quizzes -- 10%", 190, 40);
			g.drawString("Midterms -- 30%", 80, 120);
			g.drawString("Final -- 40%", 200, 200);
		}
	}
}
