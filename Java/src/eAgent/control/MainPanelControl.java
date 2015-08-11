/**
 * Created by jhs4mjb for project se20-Lab3 on 11-Nov-2005
 **/

package eAgent.control;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Vector;

import javax.swing.JOptionPane;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import eAgent.Database;
import eAgent.EAgent;
import eAgent.boundary.DisplayProperty;
import eAgent.boundary.MainPanel;
import eAgent.concept.Concept;
import eAgent.concept.Customer;
import eAgent.concept.Property;

/**
 * @author max The main conrol class for the system. Extends MainPanel boundary
 *         class which extends JPanel
 */
@SuppressWarnings("serial")
public class MainPanelControl extends MainPanel {
	boolean cancelChange;

	Customer thisCustomer, lastCustomer;

	/**
	 * Constructor organised GUI components
	 */
	public MainPanelControl() {
		createListeners();
		thisCustomer = new Customer();
		lastCustomer = new Customer();
		setEnabled(false);
	}

	/**
	 * retrieves customers from database
	 * 
	 */
	@SuppressWarnings("unchecked")
	protected void importCustomers() {
		try {
			customers = Database.importCustomers();
			 if (customers.isEmpty())
			   customers.add(new Customer(-1,"","Empty"));
		} catch (Exception e) { // Builds random customer list if can't connect
			// to database.
			println("ImportCustomers Error: " + e);
			super.importCustomers();
		}
	}

	/**
	 * Whenever the database is updated, this method is called to ensure that
	 * our working lists are consistant with it.
	 */
	public void reBuildLists() {
			CS.clearAll();
			importCustomers();
			buildList();
			CL.reBuild(NAMES);
			try {
			EPS.setPropList(propList);
		} catch (Exception e) {
			println("reBuildLists Error: " + e);
		}
	}

	/**
	 * Creates all Listeners that are not already present within nested objects
	 */
	public void createListeners() {

		KeyListener shortList = new /**
									 * Seaches for customer details as Customer
									 * name is typed into Customer id field
									 */
		KeyListener() {
			public void keyTyped(KeyEvent arg0) {
			}

			public void keyPressed(KeyEvent arg0) {
			}

			public void keyReleased(KeyEvent arg0) {
				String s1 = CS.getNameText().getText();
				String s2 = CS.getSurnameText().getText();
				try {
					CL.compare(s1, s2);
				} catch (Exception e) {
					println("Compare name Error: " + e);
				}
			}
		};

		KeyListener findById = new /**
									 * Seaches for customer details as Customer
									 * id is typed into Customer id field
									 */
		KeyListener() {
			public void keyTyped(KeyEvent arg0) {
			}

			public void keyPressed(KeyEvent arg0) {
			}

			public void keyReleased(KeyEvent arg0) {
				Object i = CS.getUseridText().getText();
				try {
					CL.compare(i);
				} catch (Exception e) {
					println("compare id Error: " + e);
				}
			}
		};

		CS.getUseridText().addKeyListener(findById);

		CS.getNameText().addKeyListener(shortList);

		CS.getSurnameText().addKeyListener(shortList);

		CS.getNewCustomer().addActionListener(new /**
													 * If new customer check box
													 * has been selected this
													 * will prepare the fields
													 * for new information.
													 */
		ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (CS.getNewCustomer().isSelected()) {
					if (isChangeMade())
						hesitate(EAgent.NEW_CUST_CHECKED);
					else
						discardChanges(EAgent.NEW_CUST_CHECKED);
					if (!ACD.isEnabled()) ACD.setEnabled(true);
					clearAllExcept(tabs.getSelectedIndex());
				}
			}
		});

		CL.getList().addListSelectionListener(new /**
													 * gets customer id and name
													 * for display and puts them
													 * into text fields next to
													 * display button.
													 */
		ListSelectionListener() {
			public void valueChanged(ListSelectionEvent arg0) {
				int i = CL.getList().getSelectedIndex();
				int j = CL.findIndex((String) CL.getData().get(i));
				CS.getUseridText().setText(
						String.valueOf(String.valueOf(((Customer) customers
								.get(j)).get(Concept.CUST_ID))));
				CS.getNameText().setText(CL.getN(j));
				CS.getSurnameText().setText(CL.getSN(j));
				CS.getDisplay().setEnabled(true);
			}
		});

		CL.getList().addMouseListener(new /**
											 * Displays customer details from
											 * list on double click
											 */
		MouseListener() {

			public void mouseClicked(MouseEvent arg0) {
				if (arg0.getClickCount() == 2) {
					if (CS.getDelete().isEnabled()==false) CS.getDelete().setEnabled(true);
					if (isChangeMade()) {
						hesitate(EAgent.DISPLAY_PRESSED);

					} else
						discardChanges(EAgent.DISPLAY_PRESSED);
				}

			}

			public void mousePressed(MouseEvent arg0) {

			}

			public void mouseReleased(MouseEvent arg0) {
				// TODO Auto-generated method stub

			}

			public void mouseEntered(MouseEvent arg0) {
				// TODO Auto-generated method stub

			}

			public void mouseExited(MouseEvent arg0) {
				// TODO Auto-generated method stub

			}

		});

		/*
		 * Button Listeners
		 */
		CS.getDisplay().addActionListener(new /**
												 * Displays information for
												 * selected customer. <br>
												 * Hesitates if a change has
												 * occurred.
												 * 
												 */
		ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (CS.getDelete().isEnabled()==false) CS.getDelete().setEnabled(true);
				if (isChangeMade()) {
					hesitate(EAgent.DISPLAY_PRESSED);

				} else
					discardChanges(EAgent.DISPLAY_PRESSED);
			}
		});

		CS.getDelete().addActionListener(new /**
												 * Deletes Customer if delete
												 * button pressed
												 * 
												 */
		ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				hesitate(EAgent.DELETE_PRESSED);
			}
		});

		addEdit.addActionListener(new /**
										 * Updates customer details when button
										 * is pressed.
										 */
		ActionListener() {
			public void actionPerformed(ActionEvent event) {
				updateCustomer(thisCustomer);
				changed.setVisible(false); // TODO: something with this.
			}
		});

		clr.addActionListener(new /**
									 * Clears fields but hesitates if changes
									 * have been made.
									 * 
									 * Hesitates if a change has occurred.
									 */
		ActionListener() {
			public void actionPerformed(ActionEvent e) {
//				if (isChangeMade())
//					hesitate(EAgent.CLEAR_PRESSED);
//				else
					discardChanges(EAgent.CLEAR_PRESSED);
			}
		});

		cancel.addActionListener(new /**
										 * restores fields to state before
										 * changes were made to them.
										 */
		ActionListener() {
			public void actionPerformed(ActionEvent event) {
				if (isChangeMade())
					resetFormHesitate();
				else
					cancel();
			}
		});

		// Tabs
		tabs.addChangeListener(new /**
									 * Listens for tab changes. Hesitates if
									 * changes have been made to fields. <br>
									 * Hesitates if a change has occurred.
									 */
		ChangeListener() {
			public void stateChanged(ChangeEvent arg0) {
				if (isChangeMade()) {
					if (!cancelChange)
						hesitate(EAgent.TAB_CHANGED);

				} else
					discardChanges(EAgent.TAB_CHANGED);
			}

		});

		// Property Search Listener
		EPS.getList().addMouseListener(new /**
											 * Looks up property details if user
											 * double clicks on a list item.
											 */
		MouseListener() {

			public void mouseClicked(MouseEvent arg0) {
				if (arg0.getClickCount() == 2) {
					try {
						Vector data = findIndex(EPS.getIDs());
						new DisplayProperty(data.get(0), data.get(1));
					} catch (Exception e) {
						println(e);
					}
				}
				// TODO: New pop-up printable house and contact details window

			}

			public void mousePressed(MouseEvent arg0) {

			}

			public void mouseReleased(MouseEvent arg0) {
				// TODO Auto-generated method stub

			}

			public void mouseEntered(MouseEvent arg0) {
				// TODO Auto-generated method stub

			}

			public void mouseExited(MouseEvent arg0) {
				// TODO Auto-generated method stub

			}

		});

	}

	protected void clearAllExcept(int selectedIndex) {
		for (int i = 0; i < tabs.getTabCount(); ++i)
			if (i != selectedIndex)((EAgent) tabs.getComponent(i)).clearForm();
	}

	/**
	 * @param ids,
	 *            the ids of property and customer
	 * @return vector conatining those objects
	 * @throws Exception
	 */
	@SuppressWarnings("unchecked")
	public Vector findIndex(int[] ids) throws Exception {
		Vector data = new Vector();
		Property p = new Property();
		Customer c = new Customer();
		for (int i = 0; i < customers.size(); ++i) {
			c = (Customer) customers.get(i);
			if ((Integer) c.get(Concept.CUST_ID) == ids[0]) {
				// index[0] = (Integer) ((Customer)
				// customers.get(i)).get(Concept.CUST_ID);
				println("cID: " + i);
				for (int j = 0; j < c.getProperties().size(); ++j)
					p = (Property) c.getProperties().get(j);
				if ((Integer) p.get(Concept.PROP_ID) == ids[0])
					break;
				break;
			}
		}
		data.add(p);
		data.add(c);
		return data;
	}

	/**
	 * Used to display all information, on a seleted customer, accross all tabs.
	 * 
	 */
	public void displayAll() {
		try {
			for (int i = 0; i < tabs.getTabCount(); ++i)
				((EAgent) tabs.getComponentAt(i)).displayInfo(thisCustomer);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println(e);
		}
	}

	/**
	 * Cancels any changes made on a tab and restores saved information
	 * 
	 */
	public void cancel() {
		((EAgent) tabs.getSelectedComponent()).displayInfo(thisCustomer);
	}

	/**
	 * Clears all fields on a tab.
	 * 
	 */
	public void clearSelectedTab() {
		((EAgent) tabs.getSelectedComponent()).clearForm();
	}

	/**
	 * Used when the "new entry" box is checked This method clears all fields in
	 * all tabs
	 */
	public void clearAll() {
		for (int i = 0; i < tabs.getTabCount(); ++i)
			((EAgent) tabs.getComponent(i)).clearForm();
	}

	/**
	 * @return false if the customer details feature no name. If true, the
	 *         customer will be updated <br>
	 *         and if 'new customer' is checked, A new entry will be created
	 *         under that name.
	 */
	@SuppressWarnings("unchecked")
	public boolean updateCustomer(Customer c) {
		String n = ACD.getFornameTF().getText(), sn = ACD.getSirnameTF()
				.getText();
		if (ACD.isNameEmpty()) {
			println("name must be filled!");
			return false;
		} else {
			if (CS.getNewCustomer().isSelected()) {
				addNewCustomer(n, sn);
			}
			// customer = (Customer) c; TODO:delete
			lastCustomer = thisCustomer;
			thisCustomer = ((EAgent) tabs.getSelectedComponent()).updateDB(c);
			CS.setFields(String.valueOf(thisCustomer.get(Concept.CUST_ID)), n,
					sn);
			addToDB(thisCustomer);
			// TODO: reload customer vector from database using overridden
			// import cusomer method called in reBuildLists()
			return true;

		}
	}

	/**
	 * @return true if changes have been made to fields but not saved.
	 */
	public boolean isChangeMade() {
		changeMade = !((EAgent) tabs.getComponent(thisTab))
				.isEqualTo(thisCustomer);
		return changeMade;
	}

	/**
	 * Promts user to confirm intentions when adding a new customer. <br>
	 * Both name fields must not be empty to save a new customer.
	 * 
	 * @param n
	 *            name
	 * @param sn
	 *            surname
	 * 
	 */
	// TODO: FIx Jlist Bug
	@SuppressWarnings("unchecked")
	private void addNewCustomer(String n, String sn) {
		try {
			int newCustId = -1;
			for (int i=0;i<customers.size();++i){
				int temp = (Integer) ((Customer) customers.get(i)).get(Concept.CUST_ID);
				if (newCustId < temp)
					newCustId = temp;
			}
			newCustId++;
			Object[] options = { "OK", "CANCEL" };
			if (JOptionPane.showOptionDialog(null, "Add new customer?",
					"Warning", JOptionPane.DEFAULT_OPTION,
					JOptionPane.WARNING_MESSAGE, null, options, options[0]) == JOptionPane.OK_OPTION) {
				println(newCustId);
				lastCustomer = thisCustomer;
				thisCustomer = new Customer();
				thisCustomer = ((EAgent) tabs.getComponent(thisTab))
						.updateDB(thisCustomer);
				thisCustomer.set(Concept.CUST_ID, newCustId);
				customers.addElement(thisCustomer);
				println(((Customer) customers.lastElement()).getName()
						+ String.valueOf(customers.size()));
				addToDB(thisCustomer);
				CS.getNewCustomer().setSelected(false);
				CS.setEnabled(true);
			} else
				println("cancel");
		} catch (Exception e) {
			println("addNewCustomer Error: " + e);
		}
	}
	
	private void resetFormHesitate() {
		try {
			Object[] options = { "OK", "CANCEL" };
			if (JOptionPane.showOptionDialog(null, "Discard Changes?",
					"Warning", JOptionPane.DEFAULT_OPTION,
					JOptionPane.WARNING_MESSAGE, null, options, options[0]) == JOptionPane.OK_OPTION) {
				cancel();
			} 
		} catch (Exception e) {
			println("resetFormHesitate Error: " + e);
		}
	}

	/**
	 * @param i
	 *            determins whether a new tab was selected, new data entered or
	 *            clear button pressed The database is then updated.
	 */
	public void saveChanges(int i) {
		switch (i) {
		case EAgent.TAB_CHANGED:
			thisTab = tabs.getSelectedIndex();
			lastCustomer = thisCustomer;
			thisCustomer = ((EAgent) tabs.getComponent(thisTab))
					.updateDB(thisCustomer);
			addToDB(lastCustomer);
			setEnabled(true);
			changeMade = false;
			break;
		case EAgent.DISPLAY_PRESSED:
			updateCustomer(lastCustomer);
			lastCustomer = thisCustomer;
			thisCustomer = (Customer) customers.get(CL.getList()
					.getSelectedIndex());
			addToDB(lastCustomer);
			displayAll();
			CS.getDisplay().setEnabled(false);
			setEnabled(true);
			if (!CS.isEnabled()) { //unchecks new customer box
			    CS.setEnabled(true);
			    CS.getNewCustomer().setSelected(false);
			    }
			break;
		case EAgent.NEW_CUST_CHECKED:
		case EAgent.CLEAR_PRESSED:
			lastCustomer = thisCustomer;
			thisCustomer = ((EAgent) tabs.getComponent(thisTab))
					.updateDB(thisCustomer);
			addToDB(lastCustomer);
			clearSelectedTab();
			setEnabled(true);
			break;
		
		}
	}

	/**
	 * @param i
	 *            determins whether a new tab was selected, new data entered or
	 *            clear button pressed changes are then ignored
	 */
	protected void discardChanges(int i) {
		switch (i) {
		case EAgent.TAB_CHANGED:
			((EAgent) tabs.getComponent(thisTab)).displayInfo(thisCustomer);
			thisTab = tabs.getSelectedIndex();
			setEnabled(true);
			break;
		case EAgent.DISPLAY_PRESSED:
			lastCustomer = thisCustomer;
			thisCustomer = (Customer) customers.get(CL.getList()
					.getSelectedIndex());
			displayAll();
			CS.getDisplay().setEnabled(false);
			setEnabled(true);
			if (!CS.isEnabled()) { //unchecks new customer box
			    CS.setEnabled(true);
			    CS.getNewCustomer().setSelected(false);
			    }
			break;
		case EAgent.CLEAR_PRESSED:
			clearSelectedTab();
			break;
		case EAgent.NEW_CUST_CHECKED:
			if (!CS.isEnabled()) { //unchecks new customer box
			    CS.setEnabled(true);
			    CS.getNewCustomer().setSelected(false);
			    }
			break;
		}
	}

	/**
	 * @param i
	 *            determins whether a new tab was selected, new data entered or
	 *            clear button pressed Nothing changed
	 */
	public void cancelChanges(int i) {
		switch (i) {
		case EAgent.DISPLAY_PRESSED:
		if (!CS.isEnabled()) { //unchecks new customer box
		    CS.setEnabled(true);
		    CS.getNewCustomer().setSelected(false);
		    }
		case EAgent.TAB_CHANGED:
			cancelChange = true;
			tabs.setSelectedIndex(thisTab);
			cancelChange = false;
			break;
		case EAgent.NEW_CUST_CHECKED:
			CS.setEnabled(true);
			CS.getNewCustomer().setSelected(false);
			break;
		}
	}

	/**
	 * If fields have been altered, the GUI hesitates and asks the user what to
	 * do with the new data. Options are SAVE, DISCARD, and CANCEL.
	 * 
	 * @param i
	 *            determins whether a new tab was selected, new data entered or
	 *            clear button pressed
	 */
	protected void hesitate(int i) {
		if (i == EAgent.DELETE_PRESSED) {
			lastCustomer = thisCustomer;
			thisCustomer.set(Concept.CUST_ID, Integer.valueOf(CS
					.getUseridText().getText()));
			deleteFromDB(thisCustomer);
			clearAll();
			changeMade = false;
		} else
			switch (JOptionPane.showOptionDialog(null,
					"Save changes and continue?", "Warning",
					JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE,
					null, EAgent.OPTIONS, EAgent.OPTIONS[0])) {
			case EAgent.SAVE:
				saveChanges(i);
				break;
			case EAgent.DISCARD:
				discardChanges(i);
				break;
			case EAgent.CANCEL:
				cancelChanges(i);
				break;
			}
	}

	/**
	 * Deletes a Customer from the database
	 * 
	 * @param c
	 */
	protected void deleteFromDB(Customer c) {
		try {
			Object[] options = { "OK", "CANCEL" };
			if (JOptionPane.showOptionDialog(null, "Delete Customer:\n"+c.getRef(),
					"Warning", JOptionPane.DEFAULT_OPTION,
					JOptionPane.WARNING_MESSAGE, null, options, options[0]) == JOptionPane.OK_OPTION) {			 
			Database.remFromDatabase(Database.CUSTOMER, (Integer) c
					.get(Concept.CUST_ID));
			reBuildLists();
			}
		} catch (Exception e) {
			println("deleteError: " + e);
		}
	}

	/**
	 * Deletes a Property from the database
	 * 
	 * @param p
	 */
	protected void deleteFromDB(Property p) {
		try {
			Database.remFromDatabase(Database.PROPERTY, (Integer) p
					.get(Concept.PROP_ID));
			reBuildLists();
		} catch (Exception e) {
			println("deleteError: " + e);
		}
	}

	/**
	 * Adds a Customer to the database
	 * 
	 * @param c
	 */
	protected void addToDB(Customer c) {
		try {
			Database.writeToDatabase(c);
			reBuildLists();
		} catch (Exception e) {
			println("deleteError: " + e);
		}
	}

}
