package uk.co.nathanjackson.TileGame;

public class Launcher {

	public static int width = 1200;
	public static int height = 750;

	public static void main(String[] args) {
		GameRenderer game = new GameRenderer("ITS A GAME", width, height);
		game.start();
	}
}
