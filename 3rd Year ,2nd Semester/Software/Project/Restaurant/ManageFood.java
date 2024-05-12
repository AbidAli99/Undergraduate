import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.*;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

import com.mysql.cj.x.protobuf.MysqlxCrud.Update;

import net.proteanit.sql.DbUtils;

import java.awt.ScrollPane;
import java.awt.event.ActionEvent;

class ManageFood extends JFrame implements ActionListener{

	JFrame frame;
	JTable table;
	JButton b1= new JButton();
	JButton b2= new JButton();
	JButton b3= new JButton();
	JButton b4= new JButton();
	JButton u = new JButton();
	JButton c = new JButton();

	JTextField tf1;
	JTextField tf2;
	JTextField tf3;
	JTextField tf4;

	public ManageFood() {
		getContentPane().setBackground(new Color(255, 248, 220));
		getContentPane().setForeground(new Color(0, 0, 0));
			
		setSize(884,561);
		setVisible(true);
		getContentPane().setLayout(null);
		setBackground(new Color(255, 235, 205));
		
		b1 = new JButton("Fastfood");
		b1.setForeground(new Color(0, 0, 0));
		b1.setBackground(new Color(188, 143, 143));
		b1.addActionListener(this);
		b1.setFont(new Font("Bell MT", Font.BOLD, 13));
		b1.setBounds(347, 40, 88, 42);
		getContentPane().add(b1);
		
		b2 = new JButton("Pizza");
		b2.setBackground(new Color(188, 143, 143));
		b2.addActionListener(this);
		b2.setFont(new Font("Bell MT", Font.BOLD, 13));
		b2.setBounds(473, 40, 88, 42);
		getContentPane().add(b2);
		
		b3 = new JButton("Dessert");
		b3.setBackground(new Color(188, 143, 143));
		b3.addActionListener(this);
		b3.setFont(new Font("Bell MT", Font.BOLD, 13));
		b3.setBounds(604, 40, 88, 42);
		getContentPane().add(b3);
		
		b4 = new JButton("Bevarage");
		b4.setBackground(new Color(188, 143, 143));
		b4.addActionListener(this);
		b4.setFont(new Font("Bell MT", Font.BOLD, 13));
		b4.setBounds(730, 40, 88, 42);
		getContentPane().add(b4);
		
		u = new JButton("UPDATE");
		u.setBackground(new Color(230, 230, 250));
		u.addActionListener(this);
		u.setFont(new Font("Dialog", Font.BOLD, 15));
		u.setBounds(149, 434, 100, 42);
		getContentPane().add(u);
		
		c = new JButton("clear");
		c.addActionListener(this);
		c.setFont(new Font("Dialog", Font.PLAIN, 15));
		c.setBackground(new Color(230, 230, 250));
		c.setBounds(41, 434, 80, 42);
		getContentPane().add(c);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(332, 112, 501, 378);
		getContentPane().add(scrollPane);
		
		table = new JTable();
		scrollPane.setViewportView(table);

		JLabel l1 = new JLabel("Modify Food Info");
		l1.setForeground(new Color(128, 0, 0));
		l1.setFont(new Font("Candara", Font.BOLD | Font.ITALIC, 24));
		l1.setHorizontalAlignment(SwingConstants.CENTER);
		l1.setBounds(66, 112, 194, 35);
		getContentPane().add(l1);
		
		setBackground(new Color(255, 235, 205));
		JLabel l2 = new JLabel("Food ID");
		l2.setFont(new Font("Verdana", Font.PLAIN, 15));
		l2.setBounds(40, 166, 61, 35);
		getContentPane().add(l2);
		
		JLabel l3 = new JLabel("Name");
		l3.setFont(new Font("Verdana", Font.PLAIN, 15));
		l3.setBounds(60, 230, 51, 35);
		getContentPane().add(l3);
		
		JLabel l4 = new JLabel("Price");
		l4.setFont(new Font("Verdana", Font.PLAIN, 15));
		l4.setBounds(66, 296, 51, 35);
		getContentPane().add(l4);
		
		JLabel l5 = new JLabel("Category");
		l5.setFont(new Font("Verdana", Font.PLAIN, 15));
		l5.setBounds(41, 362, 70, 35);
		getContentPane().add(l5);
		
		tf1 = new JTextField();
		tf1.setBounds(124, 171, 150, 28);
		getContentPane().add(tf1);
		tf1.setColumns(10);
		getContentPane().add(tf1);
		
		tf2 = new JTextField();
		tf2.setColumns(10);
		tf2.setBounds(124, 235, 150, 28);
		getContentPane().add(tf2);
		
		tf3 = new JTextField();
		tf3.setColumns(10);
		tf3.setBounds(124, 301, 150, 28);
		getContentPane().add(tf3);
		
		tf4 = new JTextField();
		tf4.setColumns(10);
		tf4.setBounds(124, 367, 150, 28);
		getContentPane().add(tf4);
	
	}

	
	public void connectTable(String sql) {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/restaurant","root","shahed");
			Statement stmnt = con.createStatement();
			ResultSet rs = stmnt.executeQuery(sql);
			table.setModel(DbUtils.resultSetToTableModel(rs));

		} catch (Exception e2) {
			e2.printStackTrace();
		}
	}
	
	
	public void connectUpdate(String sql) {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/restaurant","root","shahed");
			PreparedStatement pst = con.prepareStatement(sql);
			pst.execute();
			JOptionPane.showMessageDialog(null, "Data Updated");
			pst.close();
		} catch (Exception e2) {
			e2.printStackTrace();
		}
	}
	
	
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == b1)
		{
			String sql = "SELECT Food_Id, Name, Price, Category FROM Fastfood";
			connectTable(sql);
		}
		
		
		else if(e.getSource() == b2)
		{
			String sql = "SELECT Food_Id, Name, Price, Category FROM Pizza";
			connectTable(sql);
		}
		
		else if(e.getSource() == b3)
		{
			String sql = "SELECT Food_Id, Name, Price, Category FROM Dessert";
			connectTable(sql);
		}
		
		else if(e.getSource() == b4)
		{
			String sql = "SELECT Food_Id, Name, Price, Category FROM Bevarage";
			connectTable(sql);		
		}
		
		else if(e.getSource() == u)
		{
			if(tf1.getText().equals("") || tf2.getText().equals("") || tf3.getText().equals("") || tf4.getText().equals("")) {
					JOptionPane.showMessageDialog(null, "Please fill complete information!");
			}
			else if(tf4.getText().equals("fastfood") || tf4.getText().equals("fastfood")) {
				String sql = "UPDATE `Fastfood` SET `Food_Id` = '"+tf1.getText()+"', `Name` = '"+tf2.getText()+"', `Price` = '"+tf3.getText()+"', `Category` = '"+tf4.getText()+"' WHERE `fastfood`.`Food_Id` = '"+tf1.getText()+"'";
				connectUpdate(sql);
			}
			else if(tf4.getText().equals("Pizza") || tf4.getText().equals("pizza")) {
				String sql = "UPDATE `pizza` SET `Food_Id` = '"+tf1.getText()+"', `Name` = '"+tf2.getText()+"', `Price` = '"+tf3.getText()+"', `Category` = '"+tf4.getText()+"' WHERE `pizza`.`Food_Id` = '"+tf1.getText()+"'";
				connectUpdate(sql);
			}
			else if(tf4.getText().equals("Dessert") || tf4.getText().equals("dessert")) {
				String sql = "UPDATE `dessert` SET `Food_Id` = '"+tf1.getText()+"', `Name` = '"+tf2.getText()+"', `Price` = '"+tf3.getText()+"', `Category` = '"+tf4.getText()+"' WHERE `dessert`.`Food_Id` = '"+tf1.getText()+"'";
				connectUpdate(sql);
			}
			else if(tf4.getText().equals("Bevarage") || tf4.getText().equals("bevarage")) {
				String sql = "UPDATE `bevarage` SET `Food_Id` = '"+tf1.getText()+"', `Name` = '"+tf2.getText()+"', `Price` = '"+tf3.getText()+"', `Category` = '"+tf4.getText()+"' WHERE `bevarage`.`Food_Id` = '"+tf1.getText()+"'";
				connectUpdate(sql);
			}	
		}
		
		else if(e.getSource() == c)
		{
			tf1.setText("");
			tf2.setText("");
			tf3.setText("");
			tf4.setText("");
		}
		

	}
}
