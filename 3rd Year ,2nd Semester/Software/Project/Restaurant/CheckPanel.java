import java.sql.*;
import java.util.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.LineBorder;

class CheckPanel extends JPanel implements ActionListener
{
	JButton check,cancel;
	Connection con;
	Statement stmnt;
	
	public CheckPanel()
	{
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost:3306/restaurant","root","shahed");
			stmnt = con.createStatement();
		}
		
		catch(SQLException e)
		{
			System.out.println("Unknown Error");
		}
		
		catch(Exception eg)
		{
			System.out.println("Unknown Error");
		}		
		
		setLayout(new FlowLayout(FlowLayout.CENTER,50,50));
		
		check = new JButton("Check Order");
		cancel = new JButton("Cancel Order");
		
		add(check);
		add(cancel);
		
		check.addActionListener(this);
		cancel.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent a)
	{
		if(a.getSource() == check)
		{
			ConfirmFood o = new ConfirmFood();
		}
		else
		{
			try
			{
				
				//Window window = SwingUtilities.getWindowAncestor(this);
				//window.dispose();
				//HomeDelivery s = new HomeDelivery();
				int ans = JOptionPane.showConfirmDialog(null," Are you sure ?",null, JOptionPane.YES_NO_OPTION);
				
				if (ans == JOptionPane.YES_OPTION)
				{
					stmnt.executeUpdate("TRUNCATE `temp_order`");
					JOptionPane.showMessageDialog(null," Order cancelled !!! ");
				}
			}
			
			catch(SQLException e)
			{
			    System.out.println("Unknown Error");
			}
			
			catch(Exception eg)
			{
				System.out.println("Unknown Error");
			}
		}
	}
}