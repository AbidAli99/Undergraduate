
package virtualbloodbank;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.Border;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
public class Developers {
    JFrame frameDevelopers = new JFrame("Developers Information");
    
    private final ImageIcon icon;    
    private final JPanel panelMain;    
    private final JButton btnOk;
    private final JTextArea taDev1, taDev2, taDev3, taDev4, taCntct1, taCntct2, taCntct3, taCntct4;
    private final JLabel lblDev1, lblDev2,lblDev3, lblDev4, lblCntct1, lblCntct2, lblCntct3, lblCntct4;
    
    private final Color clrYellow = new Color(240, 230, 170);
    private final Color clrBlue = new Color(15, 70, 140);

    public Developers() {
        //adding image for icon
        icon = new ImageIcon(getClass().getResource("images/info_icon.png"));
        frameDevelopers.setIconImage(icon.getImage());                          //setting window icon

        //setting up the frame
        frameDevelopers.setSize(1125, 400);
        frameDevelopers.setLayout(new BorderLayout());                          //frame layout: Border Layout
        frameDevelopers.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);      //setting default close operation
        frameDevelopers.setLocationRelativeTo(null);                            //to center the window
        frameDevelopers.setResizable(false);                                    //disable window resize
        
        //setting up the panel 
        
        panelMain = new JPanel();
        panelMain.setBackground(clrYellow);                                     //background color: Yellow
        panelMain.setLayout(null);
        
        Border margin = new EmptyBorder(10, 10, 10, 10);                        //create margin for titled border
        Border blueline = BorderFactory.createLineBorder(clrBlue);              //create line for titled border
        
        TitledBorder ttlDevInfo = BorderFactory.createTitledBorder(blueline);   //create titled border
        ttlDevInfo.setTitle(" Developers ");                                    //set title
        ttlDevInfo.setTitleColor(clrBlue);                                      //title color: Blue

        panelMain.setBorder(new CompoundBorder(margin, ttlDevInfo));            //set border(outer border: margin, inner border: title)
        panelMain.setBackground(clrYellow);                                     //background color: Yellow
        panelMain.setPreferredSize(new Dimension(600, 400));                    //setting panel size
        
        //1st Developer
        lblDev1 = new JLabel("Developer 1:");
        lblDev1.setBounds(30, 40, 100, 20);
        panelMain.add(lblDev1);
        
        taDev1 = new JTextArea();
        taDev1.setBounds(30, 65, 250, 150);
        taDev1.setLineWrap(true);
        taDev1.setBorder(blueline);
        taDev1.setEditable(false);
        taDev1.setText("Samun Islam Ahmed\n"
        + "ID: 2019380182\n"
        + "Department: CST\n"
        + "Northwestern Polytechnical University, China.");
        panelMain.add(taDev1);
        
        //2nd Developer
        lblDev2 = new JLabel("Developer 2:");
        lblDev2.setBounds(300, 40, 100, 20);
        panelMain.add(lblDev2);
        
        taDev2 = new JTextArea();
        taDev2.setBounds(300, 65, 250, 150);
        taDev2.setLineWrap(true);
        taDev2.setBorder(blueline);
        taDev2.setEditable(false);
        taDev2.setText("Ahmed Tufahel\n"
        + "ID: 2019380181\n"
        + "Department: CST\n"
        + "Northwestern Polytechnical University, China.");
        panelMain.add(taDev2);
        
        
        //3rd Developer
        lblDev3 = new JLabel("Developer 3:");
        lblDev3.setBounds(570, 40, 100, 20);
        panelMain.add(lblDev3);
        
        taDev3 = new JTextArea();
        taDev3.setBounds(570, 65, 250, 150);
        taDev3.setLineWrap(true);
        taDev3.setBorder(blueline);
        taDev3.setEditable(false);
        taDev3.setText("Abid ali\n"
        + "ID: 2019380141\n"
        + "Department: CST\n"
        + "Northwestern Polytechnical University, China.");
        panelMain.add(taDev3);
        
        
        
        //4th Developer       
        lblDev4 = new JLabel("Developer 4:");
        lblDev4.setBounds(840, 40, 100, 20);
        panelMain.add(lblDev4);
        
        taDev4 = new JTextArea();
        taDev4.setBounds(840, 65, 250, 150);
        taDev4.setLineWrap(true);
        taDev4.setBorder(blueline);
        taDev4.setEditable(false);
        taDev4.setText("Tafsir Mubtasim Mahmood\n"
        + "ID: 2019380179\n"
        + "Department: CST\n"
        + "Northwestern Polytechnical University, China.");
        panelMain.add(taDev4);
        
        
        
        
        
        //Contact of all developers
        
        lblCntct1 = new JLabel("Contact:");
        lblCntct1.setBounds(30, 220, 100, 20);
        panelMain.add(lblCntct1);
        
        taCntct1 = new JTextArea();
        taCntct1.setBounds(30, 245, 250, 50);
        taCntct1.setLineWrap(true);
        taCntct1.setBorder(blueline);
        taCntct1.setEditable(false);
        taCntct1.setText("Mobile: +8801789277277\n"
        + "Email: samun.islam777@gmail.com");
        panelMain.add(taCntct1);
        
        lblCntct2 = new JLabel("Contact:");
        lblCntct2.setBounds(300, 220, 100, 20);
        panelMain.add(lblCntct2);
        
        taCntct2 = new JTextArea();
        taCntct2.setBounds(300, 245, 250, 50);
        taCntct2.setLineWrap(true);
        taCntct2.setBorder(blueline);
        taCntct2.setEditable(false);
        taCntct2.setText("Mobile: +8801762226539\n"
        + "Email: tufumiya95@gmail.com");
        panelMain.add(taCntct2);
        
        
        
        lblCntct3 = new JLabel("Contact:");
        lblCntct3.setBounds(570, 220, 100, 20);
        panelMain.add(lblCntct3);
        
        taCntct3 = new JTextArea();
        taCntct3.setBounds(570, 245, 250, 50);
        taCntct3.setLineWrap(true);
        taCntct3.setBorder(blueline);
        taCntct3.setEditable(false);
        taCntct3.setText("Mobile: +8615578292637\n"
        + "Email: abiduu354@gmail.com");
        panelMain.add(taCntct3);
        
        
        
        
        lblCntct4 = new JLabel("Contact:");
        lblCntct4.setBounds(840, 220, 100, 20);
        panelMain.add(lblCntct4);
        
        taCntct4 = new JTextArea();
        taCntct4.setBounds(840, 245, 250, 50);
        taCntct4.setLineWrap(true);
        taCntct4.setBorder(blueline);
        taCntct4.setEditable(false);
        taCntct4.setText("Mobile: +8801718271052\n"
        + "Email: tafsir.mahmood7@gmail.com");
        panelMain.add(taCntct4);
        
        
        
              
        btnOk = new JButton("OK");
        btnOk.setBackground(clrBlue);                                           //button background color: Red
        btnOk.setForeground(Color.white);                                       //button text color: White
        btnOk.setCursor(new Cursor(Cursor.HAND_CURSOR));                        //set button cursor
        btnOk.setBounds(520, 310, 80, 25);
        panelMain.add(btnOk);
        
        //after clicking this button this window will be closed
        btnOk.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                frameDevelopers.dispose();
            }
        });
        
        //panel work done
        
        frameDevelopers.add(panelMain, BorderLayout.CENTER);
        //make frame visible
        frameDevelopers.setVisible(true);
    }
    
}
