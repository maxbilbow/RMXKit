package eAgent.boundary;

import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * @author max NOT in use but may be re-written to display information, inc
 *         picture, of one property from a search selection.
 */
@SuppressWarnings("serial")
public class ConfirmActionFrame extends JFrame {

	protected JButton save, discard, cancel;

	JPanel buttonPanel, mainPanel, qPanel;

	JLabel question;

	public ConfirmActionFrame(String title) {
		super(title);
		init("What you gonna do, huh?", "Save", "Discard", "Cancel");
	}

	public void init(String q, String s, String d, String c) {
		qPanel = new JPanel();
		question = new JLabel(q);
		save = new JButton(s);
		discard = new JButton(d);
		cancel = new JButton(c);
		buttonPanel = new JPanel();
		mainPanel = new JPanel();
		createButtons();
		arrangeComponents();
	}

	private void arrangeComponents() {

		qPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
		qPanel.add(question);
		mainPanel.setLayout(new GridLayout(2, 1));
		mainPanel.add(qPanel);
		mainPanel.add(buttonPanel);
		add(mainPanel);
		setVisible(true);
		pack();
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}

	private void createButtons() {
		buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
		buttonPanel.add(save);
		buttonPanel.add(discard);
		buttonPanel.add(cancel);
	}

	public static void main(String[] args) {
		new ConfirmActionFrame("Stuf");
	}

}
