package uk.co.nathanjackson.TileGame.Entities.Control;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class KeyGrabber implements KeyListener {

	private boolean[] keys;
	public boolean left, right, a, d;

	public KeyGrabber() {

		keys = new boolean[256];

	}

	public void keyTyped(KeyEvent e) {

	}

	public void keyPressed(KeyEvent e) {

		keys[e.getKeyCode()] = true;

	}

	public void keyReleased(KeyEvent e) {

		keys[e.getKeyCode()] = false;

	}

	public void tick() {

		left = keys[KeyEvent.VK_LEFT];
		right = keys[KeyEvent.VK_RIGHT];
		a = keys[KeyEvent.VK_A];
		d = keys[KeyEvent.VK_D];

	}

}
