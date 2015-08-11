package eAgent.boundary;

/*
 *Created by Bhavisa Patel
 *PropertyDetails.java v1.1
 */

import java.awt.BorderLayout;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JCheckBox;

import com.jgoodies.forms.layout.CellConstraints;
import com.jgoodies.forms.layout.FormLayout;

import eAgent.EZ;
import eAgent.EasyPanel;

/**
 * @author max This GUI is the superclass for both propertyDetails and
 *         customerPreferences GUIs <br>
 *         that are both made up of very similar parts.
 * 
 */
@SuppressWarnings("serial")
public class PreferencesPanel extends EasyPanel {

	JButton saveButton, resetButton;

	JPanel selectPanel, ticksPanel, buttonPanel, prefsPanel;

	protected JComboBox address, propCombo, furnishedCombo, parkingCombo;

	protected JCheckBox rent, sell, diningCheck, entranceCheck, frontCheck,
			gasCheck, doubleCheck, conservatoryCheck, ensuiteCheck, rearCheck,
			centralCheck, burglarCheck;

	JLabel showLabel, propType, furnished, parking, bedLabel, bathLabel,
			receptionLabel;

	protected JTextField bedText, bathText, receptionText;

	/**
	 * Constructor for class
	 */
	public PreferencesPanel() {
		try {
			arrangeComponents();
		} catch (Exception e) {
			print(e);
		}
	}

	/**
	 * Arranges GUI structure
	 */
	private void arrangeComponents() throws Exception {
		prefsPanel = new JPanel();
		createSelectPanel();
		prefsPanel.add(selectPanel);
		createTicksPanel();
		prefsPanel.add(ticksPanel);
		setLayout(new BorderLayout());
		add(prefsPanel, BorderLayout.NORTH);
	}

	/**
	 * Creates individual preferece fields
	 */
	public void createPrefs() {
		propType = new JLabel("Property Type");
		String[] propList = { "Flat", "Terraced", "Detached", "Semi-Detached" };
		propCombo = new JComboBox(propList);
		furnished = new JLabel("Furnished");
		String[] furnishedList = { "No", "Fully Furnished", "Semi-Furnished" };
		furnishedCombo = new JComboBox(furnishedList);
		parking = new JLabel("Parking");
		String[] parkingList = { "No", "Garage", "Off-Road Parking",
				"Rear Parking" };
		parkingCombo = new JComboBox(parkingList);

		bedLabel = new JLabel("No of Bedrooms");
		bedText = new JTextField(3);
		bathLabel = new JLabel("No of Bathrooms");
		bathText = new JTextField(3);
		receptionLabel = new JLabel("No of Reception Rooms");
		receptionText = new JTextField(3);
	}

	/**
	 * Organises preferences panel
	 */
	public void createSelectPanel() {
		createPrefs();
		FormLayout prefsLayout = new FormLayout(
				"10dlu, pref, 4dlu, pref, 4dlu, pref, 4dlu, pref, 10dlu",
				"10dlu, pref, 4dlu, pref, 4dlu, pref, 10dlu ");
		CellConstraints con = new CellConstraints();
		selectPanel = new JPanel();
		selectPanel.setLayout(prefsLayout);

		selectPanel.add(propType, con.xy(2, 2));
		selectPanel.add(furnished, con.xy(2, 4));
		selectPanel.add(parking, con.xy(2, 6));

		selectPanel.add(propCombo, con.xy(4, 2));
		selectPanel.add(furnishedCombo, con.xy(4, 4));
		selectPanel.add(parkingCombo, con.xy(4, 6));

		selectPanel.add(bedLabel, con.xy(6, 2));
		selectPanel.add(bathLabel, con.xy(6, 4));
		selectPanel.add(receptionLabel, con.xy(6, 6));

		selectPanel.add(bedText, con.xy(8, 2));
		selectPanel.add(bathText, con.xy(8, 4));
		selectPanel.add(receptionText, con.xy(8, 6));
	}

	/**
	 * Creates check boxes in panel
	 */
	public void createTicks() {
		diningCheck = new JCheckBox("Dining Room");
		entranceCheck = new JCheckBox("Entrance Hall");
		frontCheck = new JCheckBox("Front Garden");
		gasCheck = new JCheckBox("Gas");
		doubleCheck = new JCheckBox("Double Glazing");
		conservatoryCheck = new JCheckBox("Conservatory");
		ensuiteCheck = new JCheckBox("Ensuite Facilities");
		rearCheck = new JCheckBox("Rear Garden");
		centralCheck = new JCheckBox("Central Heating");
		burglarCheck = new JCheckBox("Burglar Alarm");
	}

	/**
	 * Organises check boxes in panel
	 */
	public void createTicksPanel() {
		createTicks();
		FormLayout ticksLayout = new FormLayout(
				"10dlu, pref, 4dlu, pref, 10dlu",
				"10dlu, pref, 4dlu, pref, 4dlu, pref, 4dlu, pref, 4dlu, pref, 10dlu ");
		CellConstraints con = new CellConstraints();
		ticksPanel = new JPanel();
		ticksPanel.setLayout(ticksLayout);

		ticksPanel.add(diningCheck, con.xy(2, 2));
		ticksPanel.add(entranceCheck, con.xy(2, 4));
		ticksPanel.add(frontCheck, con.xy(2, 6));
		ticksPanel.add(gasCheck, con.xy(2, 8));
		ticksPanel.add(doubleCheck, con.xy(2, 10));
		ticksPanel.add(conservatoryCheck, con.xy(4, 2));
		ticksPanel.add(ensuiteCheck, con.xy(4, 4));
		ticksPanel.add(rearCheck, con.xy(4, 6));
		ticksPanel.add(centralCheck, con.xy(4, 8));
		ticksPanel.add(burglarCheck, con.xy(4, 10));
	}

	/**
	 * @param args
	 *            Simple Testing method for this GUI
	 */
	public static void main(String[] args) {
		EZ.test(new PreferencesPanel());
	}
}
