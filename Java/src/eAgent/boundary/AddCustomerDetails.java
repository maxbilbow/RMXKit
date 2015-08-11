/**
 * 
 */
package eAgent.boundary;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import com.jgoodies.forms.layout.CellConstraints;
import com.jgoodies.forms.layout.FormLayout;

import eAgent.EZ;
import eAgent.EasyPanel;

/**
 * @author max innactive GUI for the AddCustomerDetails use case
 */
@SuppressWarnings("serial")
public class AddCustomerDetails extends EasyPanel {

	JPanel inputPanel, namePanel, buttonPanel, checkBoxPanel;

	protected Object[][] fields;

	String[] labels = { "Title", "Forname(s)", "Sirname", "Address1",
			"Address2", "Address3", "Address4", "Post Code", "Day", "Evening",
			"Mobile", "Email" };

	protected JCheckBox buy, sell, rent, lease;

	protected final String[] titles = { "", "Mr", "Ms", "Miss", "Mrs", "Sir",
			"Other" };

	/**
	 * @fields
	 */
	public static final int TITLE = 0, FORNAME = 1, SNAME = 2, ADD1 = 3,
			ADD2 = 4, ADD3 = 5, ADD4 = 6, POST = 7, DAY = 8, EVE = 9, MOB = 10,
			EMAIL = 11;

	/**
	 * Creates a AddCustomerDetails to add a new customer
	 */
	public AddCustomerDetails() {
		try {
			arrangeComponents();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			println("arrangeComponents Error: " + e);
		}
	}

	/**
	 * Aranges the components
	 */
	protected void arrangeComponents() {
		// TODO Auto-generated method stub
		fields = new Object[12][3];
		setLayout(new BorderLayout());

		try {
			CreateInputPanel();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			println("CreateInputPanel Error: " + e);
		}

		add(inputPanel, BorderLayout.CENTER);
	}

	/**
	 * Creates all the labels and forms for GUI
	 */
	public void CreateFields() {
		// Create JLabels
		for (int i = 0; i < labels.length; ++i) {
			int width;
			if (i == TITLE)
				width = 3;
			else if (i == FORNAME)
				width = 8;
			else if (i == SNAME)
				width = 10;
			else
				width = 13;
			fields[i][LABEL] = new JLabel(labels[i]);
			fields[i][TEXT_FIELD] = new JTextField(width);
			if (i == TITLE)
				fields[i][COMBO] = new JComboBox(titles);
			else
				fields[i][COMBO] = null;
		}

		// Create title Combo box
		getTF(TITLE).setEditable(false);

		// Create Action listener for titles
		getTitleCB().addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				if ((getTitleCB().getSelectedIndex() == titles.length - 1))
					getTF(TITLE).setEditable(true);
				else {
					getTF(TITLE).setEditable(false);
					getTF(TITLE).setText("");
				}
			}
		});
	}

	/**
	 * Creates the JPanel holding name details
	 */
	public void createNamePanel() {
		namePanel = new JPanel();
		FormLayout nameLayout = new FormLayout(
				// strict layout of form components
				"0dlu , pref , 4dlu , pref , 4dlu , pref , 6dlu, pref , 4dlu , pref , 6dlu , pref , 4dlu, pref, 0dlu ",
				"0dlu , pref, 10dlu ");
		// nameLayout.setRowGroups(new int[][] {{2,4,6,8,10,12,14}});
		namePanel.setLayout(nameLayout);
		CellConstraints con = new CellConstraints();
		namePanel.add(getLabel(TITLE), con.xy(2, 2));
		namePanel.add(getTitleCB(), con.xy(4, 2));
		namePanel.add(getTF(TITLE), con.xy(6, 2));
		namePanel.add(getLabel(FORNAME), con.xy(8, 2));
		namePanel.add(getTF(FORNAME), con.xy(10, 2));
		namePanel.add(getLabel(SNAME), con.xy(12, 2));
		namePanel.add(getTF(SNAME), con.xy(14, 2));

	}

	/**
	 * Creates the main form of the GUI
	 */
	public void CreateInputPanel() {
		inputPanel = new JPanel();
		CreateFields();

		FormLayout layout = new FormLayout(
				// strict layout of form components
				"20dlu , pref , 6dlu , pref , 30dlu , pref , 6dlu, pref , 20dlu, 0dlu",
				"10dlu , pref , 4dlu , pref , 4dlu , pref , 4dlu, pref , 4dlu , pref , 4dlu , pref , 4dlu, pref, 15dlu");
		CellConstraints con = new CellConstraints();

		inputPanel.setLayout(layout);

		createNamePanel();

		// Line 1
		inputPanel.add(namePanel, con.xyw(2, 2, 9));

		// col 1
		int row = 4, col1 = 2, col2 = 4;
		for (int f = ADD1; f <= fields.length - 1; ++f) {
			if (f == DAY) {
				row = 4;
				col1 = 6;
				col2 = 8;
			}
			try {
				inputPanel.add(getLabel(f), con.xy(col1, row));
				inputPanel.add(getTF(f), con.xy(col2, row));
				row += 2;
			} catch (Exception e) {
				println("label loop error: " + e);
			}

		}

		createCheckBoxes();
		inputPanel.add(checkBoxPanel, con.xyw(2, 14, 9));

	}

	/**
	 * Creates check boxes for form
	 */
	public void createCheckBoxes() {
		checkBoxPanel = new JPanel(new FlowLayout());
		buy = new JCheckBox("buy");
		sell = new JCheckBox("sell");
		rent = new JCheckBox("rent");
		lease = new JCheckBox("loan");

		checkBoxPanel.add(new JLabel("Looking to: "));
		checkBoxPanel.add(buy);
		checkBoxPanel.add(sell);
		checkBoxPanel.add(rent);
		checkBoxPanel.add(lease);
	}

	/**
	 * @return forname Text Field for reference
	 */
	public JTextField getFornameTF() {
		return (JTextField) fields[FORNAME][TEXT_FIELD];
	}

	/**
	 * @return surname Text Field for reference
	 */
	public JTextField getSirnameTF() {
		return (JTextField) fields[SNAME][TEXT_FIELD];
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.awt.Component#setEnabled(boolean)
	 */
	public void setEnabled(boolean e) {
		enabled = e;
		for (int i = 0; i < fields.length; ++i)
			getTF(i).setEnabled(e);
		getTitleCB().setEnabled(e);
		buy.setEnabled(e);
		sell.setEnabled(e);
		rent.setEnabled(e);
		lease.setEnabled(e);
	}

	/**
	 * @param i
	 * @return Returns the text from a specific field i.
	 */
	public String getText(int i) {
		if (i == TITLE) {
			String title;
			if (getTitleCB().getSelectedIndex() == titles.length - 1) // tthe
				// location
				// of
				// "Other"
				// in
				// JComboBox
				title = getTF(i).getText();
			else
				title = String.valueOf(getTitleCB().getSelectedItem());
			return title;
		} else
			return getTF(i).getText();
	}

	/**
	 * @return title field text
	 */
	public String getTitle() {
		String title = getText(TITLE);
		if (title.equals(""))
			title = (String) getTitleCB().getSelectedItem();
		return title;

	}

	/**
	 * @param f
	 *            determins which field.
	 * @return requested text field
	 */
	public JTextField getTF(int f) {
		try {
			return (JTextField) fields[f][TEXT_FIELD];
		} catch (Exception e) {
			println("GetTF() error: " + e);
			return new JTextField(String.valueOf(e));
		}
	}

	/**
	 * @param f
	 *            determins which field.
	 * @return requested JLabel
	 */
	public JLabel getLabel(int f) {
		try {
			return (JLabel) fields[f][LABEL];
		} catch (Exception e) {
			println("GetLabel() error: " + e);
			return new JLabel(String.valueOf(e));
		}
	}

	/**
	 * @return title JComboBox
	 */
	public JComboBox getTitleCB() {
		return (JComboBox) fields[TITLE][COMBO];
	}

	/**
	 * @param n
	 *            determins which field.
	 * @param s
	 *            the text to imput into that field
	 * @return
	 */
	public boolean setText(int n, String s) {
		if (n == TITLE) {
			for (int i = 0; i < titles.length; ++i) {
				// Set Title combo Box appropriately
				if ((s.equals(""))
						|| (s.equalsIgnoreCase(String.valueOf(getTitleCB()
								.getItemAt(i))))) {
					getTitleCB().setSelectedIndex(i);
					break;
				} else if (i == titles.length - 1) {
					getTitleCB().setSelectedIndex(i);
					break;
				}
			}
		}
		getTF(n).setText(s);
		return true;
	}

	/**
	 * Method to test this GUI
	 */
	public static void main(String[] args) {
		EZ.test(new AddCustomerDetails());
	}
}
