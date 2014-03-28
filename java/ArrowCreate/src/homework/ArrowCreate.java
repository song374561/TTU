package homework;

import javax.swing.*;
import java.util.*;
import java.awt.*;

public class ArrowCreate extends JFrame 
{
	public ArrowCreate()
	{
		add(new Draw());
	}
	public static void main(String[] args) 
	{
		ArrowCreate frame = new ArrowCreate();
		frame.setTitle("Arrow Create");
		frame.setSize(400, 400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	public class Draw extends JPanel
	{
		protected void paintComponent(Graphics g)
		{
			Random ran = new Random();
			int x1 = ran.nextInt(getWidth()/2);
			int x2 = ran.nextInt(getWidth()/2);
			int y1 = ran.nextInt(getHeight()/2);
			int y2 = ran.nextInt(getHeight()/2);
			g.setColor(Color.black);
			drawArrowLine(x1,y1,x2,y2,g);
			g.drawString("x1 = "+x1+" y1 = "+y1+" x2 = "+x2+" y2 = "+y2, getWidth()/2, getHeight()-10);
		}
	}
	public static void drawArrowLine(int x1, int y1, int x2, int y2, Graphics g)
	{
		if (x1-x2 == 0)
			x1+=10;
		double length = Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		int choosex=0, choosey=0;
		g.drawLine(x1,y1,x2,y2);
		
		if (x1 < x2 && y1 > y2)
		{
			choosex = x2;
			choosey = y2;
			g.drawLine(choosex,choosey,(int)(choosex-(1/Math.sqrt(18))*length),(int)(choosey+(1/Math.sqrt(648)*length)));
			g.drawLine(choosex, choosey, (int)(choosex-(1/Math.sqrt(648)*length)), (int)(choosey+(1/Math.sqrt(18))*length));
		}
		else if (x2 < x1 && y1 < y2)
		{
			choosex = x1;
			choosey = y1;
			g.drawLine(choosex,choosey,(int)(choosex-(1/Math.sqrt(18))*length),(int)(choosey+(1/Math.sqrt(648)*length)));
			g.drawLine(choosex, choosey, (int)(choosex-(1/Math.sqrt(648)*length)), (int)(choosey+(1/Math.sqrt(18))*length));
		}
		else if (x1 < x2 && y1 < y2)
		{
			choosex = x1;
			choosey = y1;
			g.drawLine(choosex, choosey, (int)(choosex+30), (int)(choosey+5));
			g.drawLine(choosex, choosey, (int)(choosex+5), (int)(choosey+30));
		}
		else if (x2 < x1 && y2 < y1)
		{
			choosex = x2;
			choosey = y2;
			g.drawLine(choosex, choosey, (int)(choosex+30), (int)(choosey+5));
			g.drawLine(choosex, choosey, (int)(choosex+5), (int)(choosey+30));
		}
		
	}

}

