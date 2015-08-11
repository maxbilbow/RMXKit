package eAgent.boundary;

/**
 * 
 * @author Thomas Rawcliffe
 * 
 * 
 */

import java.awt.BorderLayout;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JTextField;

import com.jgoodies.forms.layout.CellConstraints;
import com.jgoodies.forms.layout.FormLayout;

import eAgent.EasyPanel;

/**
 * 
 * Class extends JPanel to provide a way to search for a property with in the
 * database. v1.2
 * 
 * @author scs4tar
 * 
 */
public class PropertySearchPanel extends EasyPanel {
	private static final long serialVersionUID = 1L;

	PropertySearchPanel() {
		super();
		setLayout(new BorderLayout());
		add(new PropertySearchFormPanel(), BorderLayout.WEST);
		add(new PropertySearchDisplayPanel(), BorderLayout.CENTER);
	}

	public static void main(String[] args) {
		JFrame X = new JFrame();
		X.add(new PropertySearchPanel());
		X.setVisible(true);
		X.pack();

	}

}

class PropertySearchFormPanel extends JPanel {
	private static final long serialVersionUID = 1L;

	// Define Components
	JTextField txtMinBed, txtMinBath, txtMinRec;

	JLabel lblMinBed, lblMinBath, lblMinRec, lblFurnished;

	JComboBox cmbFurnished;

	JButton searchButton;

	JCheckBox chbRent, chbBuy;

	/**
	 * 
	 * 
	 */
	PropertySearchFormPanel() {
		// Setup Layout

		FormLayout layout = new FormLayout("20dlu");
		CellConstraints con = new CellConstraints();
		setLayout(layout);

		// Initialize Components
		searchButton = new JButton("Search");

		// Configure Components

		// add Components to panel
		add(searchButton, con.xy(0, 0));
	}

}

class PropertySearchDisplayPanel extends JPanel {
	private static final long serialVersionUID = 1L;

	JTable resultsTable;

	JLabel resultsLabel;

	PropertySearchDisplayPanel() {

		setLayout(new BorderLayout());

		resultsTable = new JTable();
		resultsLabel = new JLabel("Search Results :");

		add(resultsLabel, BorderLayout.NORTH);
		add(resultsTable, BorderLayout.CENTER);

	}

}