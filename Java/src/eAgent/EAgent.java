package eAgent;

import eAgent.concept.Customer;

/**
 * @author max Interface class that is shared by most use-case GUIs. <br>
 *         It also contains a lot of universal constants for the system.
 */
public interface EAgent {
	public static final Object[] OPTIONS = { "SAVE", "DISCARD", "CANCEL" };

	public static final int SAVE = 0, DISCARD = 1, CANCEL = 2, TAB_CHANGED = 3,
			DISPLAY_PRESSED = 4, CLEAR_PRESSED = 5, NEW_CUST_CHECKED = 6, 
			DELETE_PRESSED = 8, CANCEL_PRESSED = 9;

	public static final int NO_LABEL = 0, ACD = 1, EP = 2, EPD = 3;

	public static final String[] description = { "unknown", "ACDControl",
			"EPControl", "PDControl" };

	int label = NO_LABEL;

	/**
	 * @return int NO_LABEL = 0, ACD = 1, EP = 2, EPD = 3 depending on which
	 *         Control Class it is <br>
	 *         Used for referencing
	 */
	public int getLabel();

	/**
	 * @param custID -
	 *            Calls the class's method for updating that particular entry
	 *            <br>
	 *            in both the java object and the Database.<br>
	 *            <br>
	 *            Once this has been done, the main GUI will refresh the main
	 *            Customer Vector from the Database
	 */
	public Customer updateDB(Customer c);

	/**
	 * Calls the class's method to clear all fields in the GUI
	 */
	public void clearForm();

	/**
	 * @param o -
	 *            Usually a Customer object. <br>
	 *            This method displays the information the Customer object in
	 *            it's relevant fields
	 */
	public void displayInfo(Object o);

	/**
	 * @param id
	 *            <br>
	 *            Calls a method to display info directly from database
	 */
	public void displayInfo(int id);

	/**
	 * @param o
	 * @return true if an object's details match those in the fields of the
	 *         relecant GUI.
	 */
	public boolean isEqualTo(Object o);
}
