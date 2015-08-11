package eAgent.concept;

/**
 * @author max parent class for all concept classes. Contains useful fields and
 *         methods.
 * 
 */
public class Concept {

	public static final String[] COL_NAMES = { "Title", "Forname(s)",
			"Sirname", "Address1", "Address2", "Address3", "Address4",
			"Post Code", "Day", "Evening", "Mobile", "Email",

			"Garage", "parking", "garden", "dining room", "entrance", "front",
			"gas", "conservatory", "ensuite", "rear", "central", "Alarmed",
			"dblGlazing", "Price", "Max Price", "Min Price", "Buying",
			"Selling", "Rending", "Leasing" };

	public static final int CUST_ID = -1, PROP_ID = -2,

	TITLE = 0, NAME = 1, SNAME = 2,

	ADD1 = 3, ADD2 = 4, ADD3 = 5, ADD4 = 6, POST = 7,

	DAY = 8, EVE = 9, MOB = 10, EMAIL = 11,

	// prefs
			DINING = 15, ENTRANCE = 16, FRONT = 17, GAS = 18, CONSERV = 19,
			ENSUITE = 20, REAR = 21, CENTRAL = 22, BURG_ALARM = 23,
			DBL_GLAZE = 24, PRICE = 25, MAX_PRICE = 26, MIN_PRICE = 27,
			BUY = 28, SELL = 29, RENT = 30, LEASE = 31, PARKING = 32,
			FURNISHED = 33, TYPE = 34, BED = 35, BATH = 36, REC = 37,

			ARRAY_SIZE = REC + 1, FIRST_PREF = DINING, LAST_PREF = REC,
			FIRST_BOOL_PREF = DINING, LAST_BOOL_PREF = DBL_GLAZE,
			FIRST_COMBO = PARKING, LAST_COMBO = TYPE, FIRST_INT = BED,
			LAST_INT = REC;

	protected Object[] data;

	/**
	 * Constructor initialises all possible variables
	 */
	public Concept() {
		data = new Object[ARRAY_SIZE];
		int i = 0;
		while (i < data.length) {
			data[i] = new Object();
			if ((i <= FIRST_COMBO)&&(i<=LAST_INT))
				data[i]=0;
			++i;
		}
	}

	/**
	 * getter for all variables
	 * 
	 * @param i
	 *            determins which variable
	 * @return
	 */
	public Object get(int i) {
		return data[i];
	}

	/**
	 * getter for all variables
	 * 
	 * @param i
	 *            determins which variable.
	 * @param o
	 *            is the object to be set to.
	 * @return
	 */
	public boolean set(int i, Object o) {
		data[i] = o;
		return false;
	}

	/**
	 * getter for labels correspondong to variables for fields.
	 * 
	 * @param i
	 *            determins which label
	 * @return
	 */
	public static String getColName(int i) {
		return COL_NAMES[i];
	}

	/**
	 * @param i
	 * @return true if field i is an address field
	 */
	protected boolean isAddress(int i) {
		if ((i >= ADD1) && (i <= POST))
			return true;
		else
			return false;
	}

	/**
	 * @param i
	 * @return true if field i is a boolean preference field
	 */
	protected boolean isBoolPref(int i) {
		if ((i >= FIRST_BOOL_PREF) && (i <= LAST_BOOL_PREF))
			return true;
		else
			return false;
	}

	/**
	 * @param i
	 * @return true if field i is a preference field
	 */
	protected boolean isPref(int i) {
		if ((i >= FIRST_PREF) && (i <= LAST_PREF))
			return true;
		else
			return false;
	}

	/**
	 * @param i
	 * @return true if field i is a customer or property id field
	 */
	protected boolean isID(int i) {
		if ((i == CUST_ID) || (i == PROP_ID))
			return true;
		else
			return false;
	}

	/**
	 * @param i
	 * @return true if object is a combo box
	 */
	protected boolean isCombo(int i) {
		if ((i >= FIRST_COMBO) || (i <= LAST_COMBO))
			return true;
		else
			return false;
	}

	/**
	 * @param i
	 * @return true if referenced object is an integer in preferences
	 */
	protected boolean isIntPref(int i) {
		if ((i >= FIRST_INT) || (i <= LAST_INT))
			return true;
		else
			return false;
	}
}