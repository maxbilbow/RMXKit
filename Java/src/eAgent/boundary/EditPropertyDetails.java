package eAgent.boundary;

/*
 *Created by Bhavisa Patel
 *PropertyDetails.java v1.1
 */

import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.BoxLayout;
import com.jgoodies.forms.layout.CellConstraints;
import com.jgoodies.forms.layout.FormLayout;

import eAgent.concept.Address;
import eAgent.concept.Concept;

/**
 * @author max Subclass of
 * @EditPreferences <br>
 *                  This is the GUI for the Customers preferences for when
 *                  searching for properties.
 */
@SuppressWarnings("serial")
public class EditPropertyDetails extends PreferencesPanel {

	JPanel addPanel;

	protected JComboBox a1;

	JLabel add4, add1, add2, add3, postcode;

	protected JTextField a4, a2, pc, a3;

	protected JButton sameAdd;

	protected Vector propList;

	/**
	 * Constructor
	 */
	public EditPropertyDetails() {
		arrangeComponents();
	}

	/**
	 * @return same address check box for referencing
	 */
	public JButton getSameAdd() {
		return sameAdd;
	}

	/**
	 * @return Address object taken from the 5 address text fields
	 */
	public Address getAddress() {
		return new Address((String) a1.getSelectedItem(), a2.getText(), a3
				.getText(), a4.getText(), pc.getText());
	}

	/**
	 * @param A
	 *            Sets the 5 Address fields from a given address
	 */
	public void setAddress(Address A) {
		a1.setSelectedItem(A.get(Concept.ADD1));
		a2.setText(A.get(Concept.ADD2));
		a3.setText(A.get(Concept.ADD3));
		a4.setText(A.get(Concept.ADD4));
		pc.setText(A.get(Concept.POST));

	}

	/**
	 * @param A1
	 * @param A2
	 * @param A3
	 * @param A4
	 * @param PC
	 *            Sets 5 address fields from 5 given Strings
	 */
	public void setAddress(String A1, String A2, String A3, String A4, String PC) {
		a1.setSelectedItem(A1);
		a2.setText(A2);
		a3.setText(A3);
		a4.setText(A4);
		pc.setText(PC);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.boundary.EditPreferences#arrangeComponents()
	 */
	private void arrangeComponents() {
		setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		createAddPanel();
		this.removeAll();
		this.setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		add(addPanel);
		add(selectPanel);
		add(ticksPanel);
	}

	/**
	 * Creates Address Fields
	 */
	public void createAddFields() {
		try {
			add4 = new JLabel("Address 4");
			a4 = new JTextField(15);
			add1 = new JLabel("Address 1");
			a1 = new JComboBox();
			add2 = new JLabel("Address 2");
			a2 = new JTextField(15);
			add3 = new JLabel("Address 3");
			a3 = new JTextField(15);
			postcode = new JLabel("Post Code");
			pc = new JTextField(15);
			a1.setEditable(true);
			sameAdd = new JButton("Contact Address");
		} catch (Exception e) {
			System.out.print(e);
		}
	}

	/**
	 * Creates and organises address Panel
	 */
	public void createAddPanel() {
		createAddFields();
		FormLayout addLayout = new FormLayout(
				"10dlu, pref, 4dlu, pref, 4dlu, pref, 10dlu",
				"10dlu, pref, 4dlu, pref, 4dlu, pref, 4dlu, pref, 4dlu, pref, 10dlu ");
		CellConstraints con = new CellConstraints();
		addPanel = new JPanel();
		addPanel.setLayout(addLayout);

		addPanel.add(add1, con.xy(2, 2));
		addPanel.add(add2, con.xy(2, 4));
		addPanel.add(add3, con.xy(2, 6));
		addPanel.add(add4, con.xy(2, 8));
		addPanel.add(postcode, con.xy(2, 10));

		addPanel.add(a1, con.xy(4, 2));
		addPanel.add(a2, con.xy(4, 4));
		addPanel.add(a3, con.xy(4, 6));
		addPanel.add(a4, con.xy(4, 8));
		addPanel.add(pc, con.xy(4, 10));

		addPanel.add(sameAdd, con.xy(6, 2));
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.boundary.EditPreferences#main(java.lang.String[])
	 */
	public static void main(String[] args) {
		JFrame X = new JFrame();
		X.add(new EditPropertyDetails());
		X.setVisible(true);
		X.pack();
		X.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
