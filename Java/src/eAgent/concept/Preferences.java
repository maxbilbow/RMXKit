package eAgent.concept;

/**
 * @author max
 * 
 * This class originally contained a huge amount of getters and setters. It now
 * contains just 4 methods.<br>
 * It extends the concept class and do the correct fields can be got and set
 * with integer parameters
 * @extends Concept
 * 
 */
public class Preferences extends Concept {

	int maxPrice, minPrice, price;

	/**
	 * Setter for any price integer
	 * 
	 * @param price
	 *            The price to set.
	 */
	public void setPrice(int i, int price) {
		data[i] = price;
	}

	/**
	 * getter for boolean preferences
	 * 
	 * @param i
	 * @return
	 */
	public boolean is(int i) {
		return (Boolean) data[i];

	}

	/**
	 * Getter for any price integer
	 * 
	 * @param i
	 * @return
	 */
	public int getPrice(int i) {
		return (Integer) data[i];
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.concept.Concept#set(int, java.lang.Object)
	 */
/*	public boolean set(int i, Object o) {
		if (isIntPref(i)){
			setPrice(i, (Integer) o);
			return true;
		}
		if (isBoolPref(i)){
			data[i] = (Boolean) o;
			return true;
		} 
		return false;
	}
	*/
	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	public String toString(){
		int i = FIRST_BOOL_PREF;
		int count = 0;
		String s = "";
		if ((Boolean)get(i))
			s += COL_NAMES[i];
		while (i<LAST_BOOL_PREF){
			if ((Boolean)get(i))
				s += " :: "+COL_NAMES[i];
			if (count==4)
				s += '\n';
			count++;
			i++;
		}
		return s;
		
	}

}
