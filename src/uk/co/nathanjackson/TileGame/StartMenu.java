package uk.co.nathanjackson.TileGame;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFrame;

public class StartMenu {
	
	public void StartGame () {
		
		GameRenderer game = new GameRenderer("ItS A GaMME", Launcher.width, Launcher.height);
		game.start();
	}
	
	public void StartDisplay () {
		
		File InputFile = new File("res/icons.png");
		
		BufferedImage icon = new BufferedImage(255, 255, BufferedImage.TYPE_INT_RGB);
		
		JFrame f=new JFrame();//creating instance of JFrame  
	    
		JButton b=new JButton("PRESS TO LAUNCH");//creating instance of JButton  
		
		b.setBounds(125, 230, 150, 40);//x axis, y axis, width, height  
		b.setBackground(Color.GRAY);
		
		b.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				StartGame();
				
			}
		});
		
		try {
			icon = ImageIO.read(InputFile);
			f.setIconImage(icon);
		} catch (IOException e) {
			System.out.println("UNABLE TO READ ICON IMAGE");
			e.printStackTrace();
		}
		
		f.add(b);
		f.setTitle("Launch the GAAME");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setBackground(Color.GRAY);
		f.setSize(400,500);
		f.setLayout(null);  
		f.setVisible(true);
		
	}
	
	 
	
}
