package eAgent.control;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Vector;

import eAgent.EAgent;
import eAgent.boundary.EditPrefsSearch;
import eAgent.concept.Concept;
import eAgent.concept.Customer;
import eAgent.concept.Preferences;
import eAgent.concept.Property;

/**
 * @author max Control class GUI for EditPreferences class, extends said class
 */
@SuppressWarnings("serial")
public class EPSControl extends EditPrefsSearch implements EAgent {
	// TODO: Make the search able to find no preference.
	Preferences p;

	Customer c;

	ActionListener a;

	/**
	 * Constructor for control GUI
	 */
	public EPSControl(Vector propList) {
		super(propList);
		p = new Preferences();
		addListeners();
	}

	/**
	 * Creates and adds listeners for GUI
	 */
	public void addListeners() {
		a = new /**
				 * @author max When triggered, the list is populated with those
				 *         properties that match the field preferences.
				 */
		ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				PSL.clearAll();
				for (int i = 0; i < propList.size(); ++i) {
					Property p = (Property) propList.get(i);
					if (compareToFields(p.getPrefs(), false)) // false because
						// this is not a
						// strict search
						PSL.addProperty(p);
				}

			}
		};

		// JComboBox
		propCombo.addActionListener(a);
		furnishedCombo.addActionListener(a);
		parkingCombo.addActionListener(a);

		// JTextField
		bedText.addActionListener(a);
		bathText.addActionListener(a);
		receptionText.addActionListener(a);

		// JCheckBox
		diningCheck.addActionListener(a);
		entranceCheck.addActionListener(a);
		frontCheck.addActionListener(a);
		gasCheck.addActionListener(a);
		doubleCheck.addActionListener(a);
		conservatoryCheck.addActionListener(a);
		ensuiteCheck.addActionListener(a);
		rearCheck.addActionListener(a);
		centralCheck.addActionListener(a);
		burglarCheck.addActionListener(a);

	}

	/**
	 * @return preferences from fields
	 */
	public Preferences getPrefs() {
		Preferences p = new Preferences();
		p.set(Concept.DINING, diningCheck.isSelected());
		p.set(Concept.ENTRANCE, entranceCheck.isSelected());
		p.set(Concept.FRONT, frontCheck.isSelected());
		p.set(Concept.GAS, gasCheck.isSelected());
		p.set(Concept.DBL_GLAZE, doubleCheck.isSelected());
		p.set(Concept.CONSERV, conservatoryCheck.isSelected());
		p.set(Concept.ENSUITE, ensuiteCheck.isSelected());
		p.set(Concept.REAR, rearCheck.isSelected());
		p.set(Concept.CENTRAL, centralCheck.isSelected());
		p.set(Concept.BURG_ALARM, burglarCheck.isSelected());
		return p;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.control.MainControl#updateDB(int)
	 */
	public Customer updateDB(Customer c) {
		try {

		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ " [updateDB()] Error: " + e);
		}
		return c;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.control.MainControl#clearForm()
	 */
	public void clearForm() {
		try {

		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ " [clearForm()] Error: " + e);
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.control.MainControl#displayInfo(java.lang.Object)
	 */
	public void displayInfo(Object o) {
		try {
			c = (Customer) o;
			setPrefs(c.getPrefs());
		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ " [displayInfo(Object)] Error: " + e);
		}
	}

	/**
	 * @param prefs
	 *            sets GUI fields to given preferences
	 */
	private void setPrefs(Preferences prefs) {
		try {
			// rent.setSelected(prefs.isRent());
			// sell.setSelected(prefs.isBuy());
			diningCheck.setSelected(prefs.is(Concept.DINING));
			entranceCheck.setSelected(prefs.is(Concept.ENTRANCE));
			frontCheck.setSelected(prefs.is(Concept.FRONT));
			gasCheck.setSelected(prefs.is(Concept.GAS));
			doubleCheck.setSelected(prefs.is(Concept.DBL_GLAZE));
			conservatoryCheck.setSelected(prefs.is(Concept.CONSERV));
			ensuiteCheck.setSelected(prefs.is(Concept.ENSUITE));
			rearCheck.setSelected(prefs.is(Concept.REAR));
			centralCheck.setSelected(prefs.is(Concept.CENTRAL));
			burglarCheck.setSelected(prefs.is(Concept.BURG_ALARM));
		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ " [setPrefs(prefs)] Error: " + e);
		}

	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.control.MainControl#displayInfo(int)
	 */
	public void displayInfo(int id) {
		try {

		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ " [displayIfo(int)] Error: " + e);
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.control.MainControl#getLabel()
	 */
	public int getLabel() {
		// TODO Auto-generated method stub
		return EP;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.EAgent#isEqualTo(java.lang.Object)
	 */
	public boolean isEqualTo(Object o) {
		try {
			Preferences p = (Preferences) ((Customer) o).getPrefs();
			return compareToFields(p, true);
		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ "[compare(obj)] Error: " + e);
		}
		return true;
	}

	/**
	 * Compares fields to given preferences. If strict == true, we are looking
	 * for an exact match<br>
	 * if strict == false, we are only looking for those preferences that were
	 * specified true.
	 * 
	 * @param p
	 * @param strict
	 * @return true if fields match.
	 */
	private boolean compareToFields(Preferences p, boolean strict) {
		Object[][] fields = {
				{ p.is(Concept.BURG_ALARM), burglarCheck.isSelected() }, // burglar
				{ p.is(Concept.CENTRAL), centralCheck.isSelected() }, //
				{ p.is(Concept.CONSERV), conservatoryCheck.isSelected() }, //
				{ p.is(Concept.DBL_GLAZE), doubleCheck.isSelected() }, //
				{ p.is(Concept.DINING), diningCheck.isSelected() }, //
				{ p.is(Concept.ENSUITE), ensuiteCheck.isSelected() }, //
				{ p.is(Concept.ENTRANCE), entranceCheck.isSelected() }, //
				{ p.is(Concept.FRONT), frontCheck.isSelected() }, //
				// { p.is(Concept.GARAGE) , garageCheck.isSelected() }, //
				{ p.is(Concept.GAS), gasCheck.isSelected() }, //
				// { p.is(Concept.PARKING) , parkingCheck.isSelected() }, //
				{ p.is(Concept.REAR), rearCheck.isSelected() }, //
		// { p.getPrice() , price.getText() }, //

		};
		if (strict) {
			for (int i = 0; i < fields.length; ++i)
				if (!fields[i][0].equals(fields[i][1]))
					return false;
		}

		else
			// if not strict
			for (int i = 0; i < fields.length; ++i)
				try { // if selected but not found in p
					if (((Boolean) fields[i][1]) && (!(Boolean) fields[i][0]))
						return false;
				} catch (ClassCastException e) {
					println((String) fields[i][1] + e);
				}
		println("match!");
		return true;
	}

}
