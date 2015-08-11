/*
 * Created by jhs4mjb for project SE24 on 09-Mar-2006
 */

package eAgent.control;

import eAgent.EAgent;
import eAgent.EZ;
import eAgent.boundary.AddCustomerDetails;
import eAgent.concept.Address;
import eAgent.concept.Concept;
import eAgent.concept.Customer;

/**
 * @author max Control class GUI for AddCustomerDetails use-case class, extends
 *         said class.
 */
@SuppressWarnings("serial")
public class ACDControl extends AddCustomerDetails implements EAgent {

	Customer customer;

	/**
	 * constructor initiates customer object.
	 */
	public ACDControl() {
		customer = new Customer();
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.control.MainControl#updateDB(int)
	 */
	public Customer updateDB(Customer c) {
		try {
			customer = c;
			customer.setName(getText(TITLE), getText(FORNAME), getText(SNAME));
			customer.setAddress(new Address(getText(ADD1), getText(ADD2),
					getText(ADD3), getText(ADD4), getText(POST)));
			customer.setContactInfo(getText(DAY), getText(EVE), getText(MOB),
					getText(EMAIL));
			customer.setStatus(buy.isSelected(), sell.isSelected(), rent
					.isSelected(), lease.isSelected());
			print(customer);
			return customer;
		} catch (Exception e) {
			System.out.println(description[getLabel()] + "[updateDB()] Error: "
					+ e);
		}
		return c;

	}

	/**
	 * @return true if no name or surname entered in fields
	 */
	public boolean isNameEmpty() {
		String name = (getText(FORNAME) + getText(SNAME));
		name.replace(" ", "");
		if (name.length() == 0)
			return true;
		else
			return false;

	}

	/**
	 * Resets all values in the form
	 */
	public void clearForm() {
		try {
			getTitleCB().setSelectedIndex(0);
			for (int i = 0; i < fields.length; ++i)
				setText(i, "");
			buy.setSelected(false);
			sell.setSelected(false);
			rent.setSelected(false);
			lease.setSelected(false);
		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ "[clearForm()] Error: " + e);
		}
	}

	/**
	 * A method for quickly entering details into all fields of the form, Useful
	 * for testing.
	 */
	public void displayInfo(Object o) {
		try {
			this.customer = (Customer) o;
			// set other fields
			setText(TITLE, (String) customer.get(Concept.TITLE));
			setText(FORNAME, (String) customer.get(Concept.NAME));
			setText(SNAME, (String) customer.get(Concept.SNAME));
			setText(ADD1, (String) customer.get(Concept.ADD1));
			setText(ADD2, (String) customer.get(Concept.ADD2));
			setText(ADD3, (String) customer.get(Concept.ADD3));
			setText(ADD4, (String) customer.get(Concept.ADD4));
			setText(POST, (String) customer.get(Concept.POST));
			setText(DAY, (String) customer.get(Concept.DAY));
			setText(EVE, (String) customer.get(Concept.EVE));
			setText(MOB, (String) customer.get(Concept.MOB));
			setText(EMAIL, (String) customer.get(Concept.EMAIL));
			buy.setSelected((Boolean) customer.get(Concept.BUY));
			sell.setSelected((Boolean) customer.get(Concept.SELL));
			rent.setSelected((Boolean) customer.get(Concept.RENT));
			lease.setSelected((Boolean) customer.get(Concept.LEASE));
		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ "[displayInfo()] Error: " + e);
		}
	}

	/**
	 * @return Customer for reference
	 */
	public Customer getCustomer() {
		return customer;
	}

	/**
	 * @param c
	 *            sets this customer to given Customer
	 */
	public void setCustomer(Customer c) {
		try {
			customer = c;
		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ "[setCustomer()] Error: " + e);
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
					+ "[displayInfo(int id)] Error: " + e);
		}
		// TODO Auto-generated method stub

	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.control.MainControl#getLabel()
	 */
	public int getLabel() {
		// TODO Auto-generated method stub
		return ACD;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.EAgent#isEqualTo(java.lang.Object)
	 */
	public boolean isEqualTo(Object o) {
		// TODO Auto-generated method stub
		try {
			// boolean equalTo = true;
			Customer c = (Customer) o;
			return compareToFields(c);
		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ "[equals(obj)] Error: " + e);
		}
		return false;
	}

	/**
	 * @param c
	 * @return true if the customer c matches the details in GUI fields
	 */
	private boolean compareToFields(Customer c) {
		Object[][] fields = { { c.get(Concept.TITLE), getText(TITLE) },// title
				{ c.get(Concept.NAME), getText(FORNAME) }, // forname
				{ c.get(Concept.SNAME), getText(SNAME) }, // surname
				{ c.get(Concept.ADD1), getText(ADD1) }, // add1
				{ c.get(Concept.ADD2), getText(ADD2) }, // add2
				{ c.get(Concept.ADD3), getText(ADD3) }, // add3
				{ c.get(Concept.ADD4), getText(ADD4) }, // add4
				{ c.get(Concept.POST), getText(POST) }, // postcode
				{ c.get(Concept.DAY), getText(DAY) }, // tell1
				{ c.get(Concept.EVE), getText(EVE) }, // tell2
				{ c.get(Concept.MOB), getText(MOB) }, // tell3
				{ c.get(Concept.EMAIL), getText(EMAIL) }, // email
				{ c.get(Concept.BUY), buy.isSelected() }, // buy
				{ c.get(Concept.SELL), sell.isSelected() }, // sell
				{ c.get(Concept.RENT), rent.isSelected() }, // rent
				{ c.get(Concept.LEASE), lease.isSelected() }, // lease
		};

		for (int i = 0; i < fields.length; ++i)
			if (!fields[i][0].equals(fields[i][1])) {
				println(fields[i][0] + " != " + fields[i][1]);
				return false;
			}
		return true;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.boundary.AddCustomerDetails#main(java.lang.String[])
	 */
	public static void main(String[] args) {
		EZ.test(new ACDControl());
	}
}
