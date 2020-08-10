package me.SomePineaple.Game.Entities;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

import me.SomePineaple.Game.Launcher;

public class Obstacles implements Runnable{

	Random rand = new Random();

	public int ObstacleY = 0;
	public int ObstacleSize = 50;
	
	public int ObstacleX = rand.nextInt(Launcher.width - ObstacleSize);
	
	private Thread thread;

	public void run() {

		UpdatePos(3);

	}

	public boolean CollisionChecker(int px, int py) {

		if (ObstacleX >= px && ObstacleX < px + Player.PlayerSize && ObstacleY >= py
				&& ObstacleY < py + Player.PlayerSize) {

			return true;
		}
		if (px >= ObstacleX && px < ObstacleX + ObstacleSize && py >= ObstacleY && py < ObstacleY + ObstacleSize) {
			return true;
		}

		return false;

	}

	public void start() {
		this.thread = new Thread();
		thread.start();
	}

	public void UpdatePos(int x) {
		ObstacleY += x;
	}

	public void DrawObstacle(Graphics g) {

		g.setColor(Color.black);
		g.fillRect(ObstacleX, ObstacleY, ObstacleSize, ObstacleSize);

	}

	public int GetObstaclePos() {
		return ObstacleY;
	}
	
}
