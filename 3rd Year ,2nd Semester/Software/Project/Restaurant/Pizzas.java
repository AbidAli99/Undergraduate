import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class Pizzas extends Delivery 
{
JButton b = new JButton("ADD");

	public Pizzas()
	{
		setSize(1000,1000);
		setVisible(true);
		setLayout(null);
		
		b.setBounds(110,100,100,30);
	
		add(b);
		}
		}