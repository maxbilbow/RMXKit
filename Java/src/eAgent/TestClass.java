package eAgent;

import java.util.Vector;

import eAgent.concept.Address;
import eAgent.concept.Concept;
import eAgent.concept.Customer;
import eAgent.concept.Preferences;
import eAgent.concept.Property;

/**
 * @author max This Class creates random custoimer details from given constant
 *         Arrays.<br>
 *         This class can be used to generate information to populate the
 *         initial database.
 */
public class TestClass extends Concept {
	final static int NUMBER = 0, LETTER = 1, NUMBER_OR_LETTER = 2;

	public static Vector customers = new Vector();

	static final String[] titles = { "The Delightable", "Mr", "Ms", "Miss",
			"Mrs", "Sir", "Other" };

	static final String[] names = { "Max", "Tom", "Tony", "bill", "Bob",
			"frank", "Jake", "Elvin", "Robin", "Edwood" };

	static final String[] snames = { "Bilbow", "Tompson", "Esquire", "Evans",
			"Sinatra", "The Peg", "Robinson", "Woodwood", "scott", "James" };

	static final String[] addresses = { "penshe", "THe burns", "Wiltshire",
			"Shabba", "shinto", "bum", "heath", "welbottom", "fishy tree",
			"houseBake", "Another word", "Lancs" };

	static final String chars = "abcdefghijklmnopqrstuvwxyz0123456789";

	static int prop_count;

	public TestClass() {
		createCustomers(1);
		System.out.print(customers.get(0));
	}

	/**
	 * Creates random customer details <br>
	 * 
	 * @param n
	 *            specifies the number of customers to create
	 * @return Vector containing customer details.
	 */
	@SuppressWarnings("unchecked")
	public static Vector createCustomers(int n) {
		prop_count = 0;
		for (int i = 0; i < n; ++i) {
			Customer temp = new Customer();
			temp.set(CUST_ID,i);
			temp.set(Concept.TITLE, titles[randomInt(titles.length - 1)]);
			temp.set(Concept.NAME, names[randomInt(names.length - 1)]);
			temp.set(Concept.SNAME, snames[randomInt(snames.length - 1)]);

			temp.set(DAY,randomTelNo());
			temp.set(EVE,randomTelNo());
			temp.set(MOB,randomTelNo());
			temp.set(EMAIL,generateEmail(temp));

			temp.setAddress(new Address(
					addresses[randomInt(addresses.length - 1)],
					addresses[randomInt(addresses.length - 1)],
					addresses[randomInt(addresses.length - 1)],
					addresses[randomInt(addresses.length - 1)],
					randomPostCode()));

			temp.setStatus(TorF(), TorF(), TorF(), TorF());

			try {
				temp.setPrefs(randomPrefs());
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				EZ.println("TestClass.setPrefs Error: "+e1);
			}

			try {
				temp.setProperties(randomProps(randomInt(10), (Integer) temp.get(CUST_ID)));
			} catch (Exception e) {
				// TODO Auto-generated catch block
				System.out.println("TestClass.setProperties Error: "+e);
			}
			customers.add(temp);
		}
		return customers;
	}
	
	
	public static void createCustomers() {
		int n = 50;
		prop_count = 0;
		for (int i = 0; i < n; ++i) {
			Customer temp = new Customer();
			temp.set(CUST_ID,i);
			temp.set(Concept.TITLE, titles[randomInt(titles.length - 1)]);
			temp.set(Concept.NAME, names[randomInt(names.length - 1)]);
			temp.set(Concept.SNAME, snames[randomInt(snames.length - 1)]);

			temp.set(DAY,randomTelNo());
			temp.set(EVE,randomTelNo());
			temp.set(MOB,randomTelNo());
			temp.set(EMAIL,generateEmail(temp));

			temp.setAddress(new Address(
					addresses[randomInt(addresses.length - 1)],
					addresses[randomInt(addresses.length - 1)],
					addresses[randomInt(addresses.length - 1)],
					addresses[randomInt(addresses.length - 1)],
					randomPostCode()));

			temp.setStatus(TorF(), TorF(), TorF(), TorF());

			try {
				temp.setPrefs(randomPrefs());
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				EZ.println("TestClass.setPrefs Error: "+e1);
			}

			try {
				temp.setProperties(randomProps(randomInt(10), (Integer) temp.get(CUST_ID)));
			} catch (Exception e) {
				// TODO Auto-generated catch block
				System.out.println("setProperties (in TestClass) Error: "+e);
			}
			Database.writeToDatabase(temp);
			
		}
	}
	
	/**
	 * Creates some random properties
	 * 
	 * @param n
	 *            specifies how many properties to create
	 * @return Vector containing n properties
	 * @throws Exception
	 */
	@SuppressWarnings("unchecked")
	private static Vector randomProps(int n, int cId) throws Exception {
		Vector temp = new Vector();
		for (int count = 0; count < n; ++count) {
			Property p = new Property();
			p.set(PROP_ID, prop_count);
			p.set(CUST_ID, cId);
			prop_count++;
			p.setAddress(new Address(
					addresses[randomInt(addresses.length - 1)],
					addresses[randomInt(addresses.length - 1)],
					addresses[randomInt(addresses.length - 1)],
					addresses[randomInt(addresses.length - 1)],
					randomPostCode()));
			// p.setAvailableFrom(new
			// Date(randomInt(28),randomInt(11)+1,randomInt(2)+2006));

			p.setPrice(randomInt(1000) * 10000);
			p.setPrefs(randomPrefs());
			temp.add(p);
		}
		return temp;
	}

	/**
	 * Generates random preferences
	 * 
	 * @return Preferences
	 */
	private static Preferences randomPrefs() throws Exception {
		Preferences prefs = new Preferences(); 
		for (int i = FIRST_BOOL_PREF; i <= LAST_BOOL_PREF; ++i) {
			//EZ.print(i);
			prefs.set(i, TorF());
		}
		prefs.set(PRICE, 1000 + randomInt(1000));
		prefs.set(MIN_PRICE, 100 + randomInt(1000));
		prefs.set(MAX_PRICE, 1000 + randomInt(1000));
		return prefs;
	}

	/**
	 * @return true or false
	 */
	private static boolean TorF() {
		return (Math.random() > 0.5) ? true : false;
	}

	/**
	 * @return String of random charactors that resemble a post code
	 */
	private static String randomPostCode() {
		String s = "";
		s += randomChar(LETTER);
		s += randomChar(NUMBER_OR_LETTER);
		s += randomChar(NUMBER);
		s += " ";
		s += randomChar(NUMBER);
		s += randomChar(LETTER);
		s += randomChar(LETTER);
		return s;
	}

	/**
	 * @param i
	 * @return random letter or numeber
	 */
	private static char randomChar(int i) {
		char c = ' ';
		switch (i) {
		case LETTER:
			c = chars.charAt(randomInt(26));
			break;
		case NUMBER_OR_LETTER:
			c = chars.charAt(randomInt(chars.length() - 1));
			break;
		case NUMBER:
			c = chars.charAt(25 + randomInt(10));
			break;
		}
		return Character.toUpperCase(c);
	}

	/**
	 * @param temp -
	 *            Takes Customer object
	 * @return String - an email address made up of the customer's name
	 *         [at]hotmail.com
	 */
	private static String generateEmail(Customer temp) {
		return temp.get(Concept.NAME) + "_" + temp.get(Concept.SNAME)
				+ "@hotmail.com";
	}

	/**
	 * @return String - random telephone number
	 */
	private static String randomTelNo() {
		return String.valueOf("0" + randomInt(1000) + " "
				+ String.valueOf(randomInt(1000)) + " "
				+ String.valueOf(randomInt(1000)));
	}

	/**
	 * @param i -
	 *            Maximum number
	 * @return random integer
	 */
	private static int randomInt(int i) {
		int a = (int) Math.round(i * Math.random());
		return a;

	}

	/**
	 * @param args
	 *            Test method
	 */
	public static void main(String[] args) {
		createCustomers();
	}
}
