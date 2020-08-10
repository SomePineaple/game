package me.SomePineaple.Game;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import me.SomePineaple.Game.Control.KeyGrabber;
import me.SomePineaple.Game.Entities.ObstacleManager;
import me.SomePineaple.Game.Entities.Player;

public class GameRenderer implements Runnable {

	private Display GameDisplay;

	private Thread thread;

	private Player PlayerThing = new Player(this);

	public boolean running = false;

	private BufferStrategy bs;
	private Graphics g;

	public String title;

	private Font font = new Font("Monospaced", Font.PLAIN, 30);

	public int GameWidth, GameHeight;

	private ObstacleManager ObMan = new ObstacleManager();

	private KeyGrabber KeyGrabber;

	public GameRenderer(String title, int width, int height) {

		GameWidth = width;
		GameHeight = height;
		this.title = title;
		KeyGrabber = new KeyGrabber();
	}

	private void init() {

		GameDisplay = new Display(title, GameWidth, GameHeight);
		GameDisplay.getCanvas().addKeyListener(KeyGrabber);

	}

	private void onTick() {

		KeyGrabber.tick();
		PlayerThing.run();
		ObMan.run();
		if (ObMan.ObstacleCollideChecker(PlayerThing.PlayerX, PlayerThing.PlayerY)) {
			stop();
		}
		
		try {
			Thread.sleep((long) (10 - (0.01 * ObMan.Score)));
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

	}

	private void render() {
		bs = GameDisplay.getCanvas().getBufferStrategy();
		if (bs == null) {
			GameDisplay.getCanvas().createBufferStrategy(2);
			return;
		}

		g = bs.getDrawGraphics();
		g.clearRect(0, 0, GameWidth, GameHeight);
		g.setColor(Color.GRAY);
		g.fillRect(0, 0, GameWidth, GameHeight);

		
		g.setColor(Color.WHITE);
		g.fillRect(PlayerThing.PlayerX, PlayerThing.PlayerY, Player.PlayerSize, Player.PlayerSize);
		ObMan.ObstalceRenderer(g);

		g.setColor(Color.WHITE);
		g.setFont(font);
		g.drawString("Your Score is: " + ObMan.Score, 20, 40);
		
		bs.show();
		g.dispose();
	}

	public void run() {
		init();

		while (running) {
			onTick();
			render();
		}

		stop();
	}

	public synchronized void start() {
		if (running)
			return;

		running = true;
		thread = new Thread(this);
		thread.start();
		PlayerThing.start();
		ObMan.start();
	}

	public synchronized void stop() {
		if (!running)
			return;

		running = false;
		try {
			thread.join();
			PlayerThing.stop();
			ObMan.stop();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public KeyGrabber GetKeyGrabber() {
		return KeyGrabber;
	}
	
}
