package me.SomePineaple.Game;

import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

public class Display {

	private JFrame frame;
	private Canvas canvas;

	private String title;

	private int width, height;

	public Display(String title, int width, int height) {

		this.title = title;

		this.width = width;
		this.height = height;

		createDisplay();

	}

	private void createDisplay() {

		File InputFile = new File("res/icon.jpg");
		
		BufferedImage icon = new BufferedImage(255, 255, BufferedImage.TYPE_INT_RGB);
		
		frame = new JFrame(title);
		frame.setSize(width, height);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		frame.setResizable(false);
		frame.setFocusable(false);
		
		try {
			icon = ImageIO.read(InputFile);
			frame.setIconImage(icon);
		} catch (IOException e) {
			System.out.println("UNABLE TO READ ICON IMAGE");
			e.printStackTrace();
		}

		canvas = new Canvas();
		canvas.setPreferredSize(new Dimension(width, height));
		canvas.setMaximumSize(new Dimension(width, height));
		canvas.setMinimumSize(new Dimension(width, height));
		canvas.setFocusable(true);

		frame.add(canvas);
		frame.pack();
	}

	public Canvas getCanvas() {
		return canvas;
	}

	public JFrame GetFrame() {
		return frame;
	}
	
}
