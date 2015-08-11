package eAgent.boundary;

import java.awt.BorderLayout;
import java.util.Vector;

import javax.swing.JList;

import eAgent.EZ;
import eAgent.TestClass;

/**
 * @author max
 * @extends EdifPreferences and is parent class for EPSControl
 */
@SuppressWarnings("serial")
public class EditPrefsSearch extends PreferencesPanel {
	protected Vector propList;

	protected PropertySearchList PSL;

	/**
	 * @param propList
	 *            Constructor: takes a vector containing all properties in the
	 *            database.
	 */
	public EditPrefsSearch(Vector propList) {
		this.propList = propList;
		arrangeComponents();
	}

	/**
	 * Arranges the GUI components
	 */
	private void arrangeComponents() {
		PSL = new PropertySearchList();
		this.add(PSL, BorderLayout.CENTER);
	}

	/**
	 * @param propList
	 *            Sets the propList vector to a new list of properties
	 */
	public void setPropList(Vector propList) {
		this.propList = propList;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.boundary.GenericList#getList()
	 */
	public JList getList() {
		return PSL.getList();
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.boundary.PropertySearchList#getIDs()
	 */
	public int[] getIDs() {
		return PSL.getIDs();
	}

	/**
	 * @param args
	 *            Simple Testing method for this GUI
	 */
	public static void main(String[] args) {
		EZ.test(new EditPrefsSearch(PropertySearchList
				.createPropertyList(TestClass.createCustomers(10))));
	}

	/**
	 * @return Returns the propList.
	 */
	public Vector getPropList() {
		return propList;
	}

}
