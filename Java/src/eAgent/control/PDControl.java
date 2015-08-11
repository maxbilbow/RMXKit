package eAgent.control;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Vector;

import eAgent.EAgent;
import eAgent.boundary.EditPropertyDetails;
import eAgent.concept.Address;
import eAgent.concept.Concept;
import eAgent.concept.Customer;
import eAgent.concept.Preferences;
import eAgent.concept.Property;

/**
 * @author max This class is the control class for the Property Details GUI and
 *         extends said class
 */
@SuppressWarnings("serial")
public class PDControl extends EditPropertyDetails implements EAgent {

	Property prop;

	Customer c;

	int lastIndex, thisIndex;

	/**
	 * constructs control GUI
	 */
	public PDControl() {
		lastIndex = thisIndex = a1.getSelectedIndex();
		prop = new Property();
		c = new Customer();
		propList = new Vector();
		addListeners();
	}

	/**
	 * creates and adds actionListeners to GUI
	 */
	public void addListeners() {
		a1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent E) {
				lastIndex = thisIndex;
				thisIndex = a1.getSelectedIndex();
				if ((lastIndex != thisIndex) && (thisIndex != -1)) {
					println("address has Changed");
					try {
						Address tmp = (Address) ((Property) propList
								.get(thisIndex)).getAddress();
						setAddress(tmp);
					} catch (Exception e) {
						println("ItemListener Error: " + e);
					}
				} else
					println("address has NOT changed");
			}
		});

		sameAdd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					setAddress((Address) c.getAddress());
				} catch (Exception e) {
					print("Chck box action listener error: " + e);
				}

			}
		});
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.control.MainControl#updateDB(int)
	 */
	@SuppressWarnings("unchecked")
	public Customer updateDB(Customer custID) {
		// TODO: update DB code
		try {
			String newAdd = (String) a1.getSelectedItem();
			System.out.print(newAdd);
			a1.addItem(newAdd);
			prop.set(Concept.CUST_ID, custID.get(Concept.CUST_ID));
			prop.setAddress(new Address(newAdd, a2.getText(), a3.getText(), a4
					.getText(), pc.getText()));
			// TODO: setPrefs(these prefs);
			propList.add(prop);
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
			setAddress("", "", "", "", "");
			diningCheck.setSelected(false);
			entranceCheck.setSelected(false);
			frontCheck.setSelected(false);
			gasCheck.setSelected(false);
			doubleCheck.setSelected(false);
			conservatoryCheck.setSelected(false);
			ensuiteCheck.setSelected(false);
			rearCheck.setSelected(false);
			centralCheck.setSelected(false);
			burglarCheck.setSelected(false);
		} catch (Exception e) {
			System.out.println(description[getLabel()]
					+ " [clearForm()] Error: " + e);
		}

	}

	/**
	 * @param prop
	 *            Sets the property details of the GUI tho those in the given
	 *            property object
	 */
	public void setPrefs(Property prop) {
		try {
			Preferences prefs = prop.getPrefs();
			// rent.setSelected(prop.getPrefs().isRent());
			// sell.setSelected(prop.getPrefs().isBuy());
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
					+ " [setPrefs()] Error: " + e);
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
			propList = c.getProperties();
			try {
				prop = (Property) propList.get(0);
				// TODO: loop to add addresses to dropdown menu
				a1.removeAllItems();
				this.setAddress(prop.getAddress());
				this.setPrefs(prop);
				for (int i = 0; i < propList.size(); ++i)
					a1.addItem(((Property) propList.get(i)).get(Concept.ADD1));
			} catch (Exception e) {
				System.out.println("No Stored Addresses");
			}
		} catch (Exception e) {
			println(description[getLabel()] + " [displayInfo()] Error: " + e);
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
					+ " [displayInfor(int)] Error: " + e);
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.control.MainControl#getLabel()
	 */
	public int getLabel() {
		// TODO Auto-generated method stub
		return EPD;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.EAgent#isEqualTo(java.lang.Object)
	 */
	public boolean isEqualTo(Object o) {
		// TODO Auto-generated method stub
		try {
			Property p = (Property) ((Vector) ((Customer) o).getProperties())
					.get(a1.getSelectedIndex());
			return compareToFields(p);
		} catch (Exception e) {
			if (a1.getSelectedIndex() != -1)
				println(description[getLabel()] + "[isEqualTo(obj)] Error: "
						+ a1.getSelectedIndex() + " :: " + e);
			return true;
		}

	}

	/**
	 * Compares state of fields to current property to see if a change has been
	 * made
	 * 
	 * @param p
	 * @return true if fields match property
	 * @throws Exception
	 */
	private boolean compareToFields(Property p) throws Exception {
		Object[][] fields = {
				{ p.get(Concept.ADD1), (String) a1.getSelectedItem() }, // add1
				{ p.get(Concept.ADD2), a2.getText() }, // add2
				{ p.get(Concept.ADD3), a3.getText() }, // add3
				{ p.get(Concept.ADD4), a4.getText() }, // add4
				{ p.get(Concept.POST), pc.getText() }, // postcode
				{ p.getPrefs().is(Concept.BURG_ALARM),
						burglarCheck.isSelected() }, // burglar
				{ p.getPrefs().is(Concept.CENTRAL), centralCheck.isSelected() }, //
				{ p.getPrefs().is(Concept.CONSERV),
						conservatoryCheck.isSelected() }, //
				{ p.getPrefs().is(Concept.DBL_GLAZE), doubleCheck.isSelected() }, //
				{ p.getPrefs().is(Concept.DINING), diningCheck.isSelected() }, //
				{ p.getPrefs().is(Concept.ENSUITE), ensuiteCheck.isSelected() }, //
				{ p.getPrefs().is(Concept.ENTRANCE), entranceCheck.isSelected() }, //
				{ p.getPrefs().is(Concept.FRONT), frontCheck.isSelected() }, //
				// { p.is(Concept.GARAGE) , garageCheck.isSelected() }, //
				{ p.getPrefs().is(Concept.GAS), gasCheck.isSelected() }, //
				// { p.is(Concept.PARKING) , parkingCheck.isSelected() }, //
				{ p.getPrefs().is(Concept.REAR), rearCheck.isSelected() }, //
		// { p.getPrefs().getPrice() , price.getText() }, //

		};

		for (int i = 0; i < fields.length; ++i)
			if (!fields[i][0].equals(fields[i][1])) {
				println(fields[i][0] + " != " + fields[i][1]);
				return false;
			}
		return true;
	}

}
