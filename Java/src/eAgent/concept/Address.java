/*
 * Created by jhs4mjb for project SE24 on 09-Feb-2006
 */

package eAgent.concept;

/**
 * @author max Concept class for an Address
 */
public class Address extends Concept {

	String address, postCode;

	/**
	 * @param line1
	 * @param line2
	 * @param line3
	 * @param line4
	 * @param postCode
	 * 
	 * Creates a specific address
	 */
	public Address(String line1, String line2, String line3, String line4,
			String postCode) {
		this.line1 = line1;
		this.line2 = line2;
		this.line3 = line3;
		this.line4 = line4;
		this.postCode = postCode;
	}

	/**
	 * creates an empty address
	 */
	public Address() {
		line1 = "";
		line2 = "";
		line3 = "";
		line4 = "";
		postCode = "";
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.concept.Concept#get(int)
	 */
	public String get(int i) {
		switch (i) {
		case ADD1:
			return line1;
		case ADD2:
			return line2;
		case ADD3:
			return line3;
		case ADD4:
			return line4;
		case POST:
			return postCode;
		}

		return null;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.concept.Concept#set(int, java.lang.Object)
	 */
	public boolean set(int i, Object s) {
		switch (i) {
		case ADD1:
			line1 = (String) s;
			return true;
		case ADD2:
			line2 = (String) s;
			return true;
		case ADD3:
			line3 = (String) s;
			return true;
		case ADD4:
			line4 = (String) s;
			return true;
		case POST:
			postCode = (String) s;
			return true;
		}
		return false;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		String s = "";
		s += "Address1: " + get(ADD1) + '\n';
		s += "Address2: " + get(ADD2) + '\n';
		s += "Address3: " + get(ADD3) + '\n';
		s += "Address4: " + get(ADD4) + '\n';
		s += "Post Code: " + get(POST) + '\n';
		return s;
	}

	/**
	 * Tests this class.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		Address A = new Address("line1", "2", "3", "4", "postcode");
		System.out.print(A);
	}

}
