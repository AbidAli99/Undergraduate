import java.sql.*;
import java.util.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.LineBorder;

class Delivery extends JFrame
{
	JTabbedPane menu;
	JPanel pizza,pastry,drinks,confirm;
	Connection con;
	Statement stmnt;
	
	public Delivery()
	{
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost:3306/restaurant","root","shahed");
			stmnt = con.createStatement();
			stmnt.executeUpdate("TRUNCATE `temp_order`");
		}
		
		catch(SQLException e)
		{
			System.out.println("Unknown Error");
		}
		
		catch(Exception eg)
		{
			System.out.println("Unknown Error");
		}		
		
		setSize(800,800);
		setVisible(true);
		
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		
		menu = new JTabbedPane();
	
		menu.addTab("Fastfood",new JScrollPane(new FastFoodPanel(),JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));
		
		menu.addTab("Pizzas",new JScrollPane(new PizzasInfo(),JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));
		
		menu.addTab("Dessert",new JScrollPane(new DessertPage(),JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));
		
		menu.addTab("Beverage",new JScrollPane(new BeveragePanel(),JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));
		
		menu.addTab("Confirm your Order",new CheckPanel());
		
		add(menu);
	}
}