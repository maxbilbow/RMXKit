package eAgent;

import javax.swing.JPanel;

/**
 * @author max
 * @extends JPanel and is a parent class for all classes based on JPanel. <br>
 *          This provides some basic common structure for all GUI classes.
 */
@SuppressWarnings("serial")
public class EasyPanel extends JPanel {
	protected boolean enabled;

	public static final int LABEL = 0, TEXT_FIELD = 1, COMBO = 2;

	/**
	 * @param o
	 *            prints input to terminal on new line.
	 */
	public static void println(Object o) {
		System.out.println(String.valueOf(o));
	}

	/**
	 * @param o
	 *            prints input to terminal on new line.
	 */
	public static void print(Object o) {
		System.out.print(String.valueOf(o));
	}

	/**
	 * @return Returns the enabled.
	 */
	public boolean isEnabled() {
		return enabled;
	}

	/**
	 * @param enabled
	 *            The enabled to set.
	 */
	public void setEnabled(boolean enabled) {
		this.enabled = enabled;
	}
}
