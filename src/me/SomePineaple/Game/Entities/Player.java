package me.SomePineaple.Game.Entities;

import me.SomePineaple.Game.GameRenderer;
import me.SomePineaple.Game.Launcher;

public class Player implements Runnable {

	public int PlayerX = Launcher.width / 2;
	public static int PlayerSize = 50;
	public int PlayerY = Launcher.height - PlayerSize * 2;

	private GameRenderer game;

	public Player(GameRenderer game) {
		this.game = game;
	}

	private Thread thread;

	@Override
	public void run() {

		if (game.GetKeyGrabber().a | game.GetKeyGrabber().left) {
			PlayerX -= 3;
		}

		if (game.GetKeyGrabber().d | game.GetKeyGrabber().right) {
			PlayerX += 3;
		}
		
		if (PlayerX < 0 || PlayerX > Launcher.width - PlayerSize) {
			PlayerX = Launcher.width / 2;
		}

	}

	public void start() {
		this.thread = new Thread();
		thread.start();
	}

	public synchronized void stop() {
		try {
			thread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public void MoveLeft() {
		PlayerX = PlayerX - PlayerSize;
	}

	public void MoveRight() {
		PlayerX = PlayerX + PlayerSize;
	}
	
}
