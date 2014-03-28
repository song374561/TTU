package homework;
import javax.swing.*;
import java.awt.Color;
import java.awt.Graphics;

public class Draw_Sine_and_Cosine_Line extends JFrame{
	public Draw_Sine_and_Cosine_Line()
	{
		add(new Draw());
	}
	public static void main(String[] args)
	{
		Draw_Sine_and_Cosine_Line frame = new Draw_Sine_and_Cosine_Line();
		frame.setTitle("Draw Sine and Cosine Line");
		frame.setSize(400,200);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		frame.setVisible(true);
	}
	class Draw extends JPanel
	{
		protected void paintComponent(Graphics g)
		{
			super.paintComponent(g);
			int x[]=new int[350],y[]=new int[350];
			g.drawLine(0, getHeight()/2, getWidth(), getHeight()/2);//xRay
			g.drawLine(getWidth(),getHeight()/2,getWidth()-30,getHeight()/2-10);//xRayN
			g.drawLine(getWidth(), getHeight()/2, getWidth()-30, getHeight()/2+10);//xRayS
			
			g.drawLine(getWidth()/2, 0, getWidth()/2, getHeight());//yRay
			g.drawLine(getWidth()/2, 0, getWidth()/2-10, 30+10);//yRayW
			g.drawLine(getWidth()/2, 0, getWidth()/2+10, 30+10);//yRayE
			
			g.drawString("-2\u03c0", 80, 100);
			g.drawString("-\u03c0", 140, 100);
			g.drawString("\u03c0",240,100);
			g.drawString("2\u03c0",280,100);
			g.drawString("X",30,100);
			g.drawString("Y",200,20);
			g.setColor(Color.red);
			for (int i = -170 ; i <= 170 ; i++)
			{
				x[i+170] = i+193;
				y[i+170] = 80-(int)(50 * Math.sin((i/100.0)*2*Math.PI));
			}
			g.drawPolyline(x,y,340);
			
			g.setColor(Color.blue);
			for (int i = -170 ; i <= 170 ; i++)
			{
				x[i+170] = i+193;
				y[i+170] = 80-(int)(50 * Math.cos((i/100.0)*2*Math.PI));
			}
			g.drawPolyline(x,y,340);
		}
	}
}
