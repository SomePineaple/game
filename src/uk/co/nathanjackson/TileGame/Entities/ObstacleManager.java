package uk.co.nathanjackson.TileGame.Entities;

import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Random;

import uk.co.nathanjackson.TileGame.Launcher;

public class ObstacleManager implements Runnable {

	public ArrayList<Obstacles> ObstaclesList = new ArrayList<Obstacles>();

	private Thread thread;

	private double delay;

	private Random rand = new Random();
	private double IsDelay = rand.nextDouble();

	public int Score = 0;

	public void start() {
		thread = new Thread();
		thread.start();
		ObstaclesList.add(new Obstacles());

	}

	public void ObstacleListController() {

		IsDelay = rand.nextDouble();
		delay = 0.01 + (0.001 * Score);

		if (ObstaclesList.size() < 60 && IsDelay < delay) {

			ObstaclesList.add(new Obstacles());

		}

		for (int f = 0; f < ObstaclesList.size(); f++) {
			if (ObstaclesList.get(f).GetObstaclePos() > Launcher.height) {

				Score++;
				ObstaclesList.remove(f);

			}
		}
	}

	public boolean ObstacleCollideChecker(int px, int py) {

		for (int i = 0; i < ObstaclesList.size(); i++) {
			if (ObstaclesList.get(i).CollisionChecker(px, py))
				return true;

		}

		return false;

	}

	public void run() {

		ObstacleListController();
		for (int ree = 0; ree < ObstaclesList.size(); ree++) {

			ObstaclesList.get(ree).run();

		}

	}

	public void stop() {
		try {
			thread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
			System.out.println("Failed to close Obstacle Manager thread");
			System.exit(1);
		}
	}

	public void ObstalceRenderer(Graphics g) {

		for (int s = 0; s < ObstaclesList.size(); s++) {

			ObstaclesList.get(s).DrawObstacle(g);

		}

	}

}
