package eAgent;

import java.awt.Component;

import javax.swing.JFrame;

/**
 * @author max
 * Simply a class with methods to perform a lot of repetative testing tasks.
 */
public class EZ {

	public static void println(Object o) {
		System.out.println(String.valueOf(o));
	}

	public static void print(Object o) {
		System.out.println(String.valueOf(o));
	}

	public static void test(Object o) {
		JFrame F = new JFrame("Test Your GUI");
		try {
			F.add((Component) o);
			F.setVisible(true);
			F.pack();
			F.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			print("main error: ");
			println(e);
		}
	}
}
