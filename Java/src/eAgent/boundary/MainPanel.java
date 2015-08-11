/**
 * Created by jhs4mjb for project se20-Lab3 on 11-Nov-2005
 **/

package eAgent.boundary;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import eAgent.EasyPanel;
import eAgent.TestClass;
import eAgent.concept.Concept;
import eAgent.concept.Customer;
import eAgent.control.ACDControl;
import eAgent.control.EPSControl;
import eAgent.control.PDControl;

/**
 * @author max Main GUI that groups together all use case GUIs
 */
@SuppressWarnings("serial")
public class MainPanel extends EasyPanel {

	JPanel main, searchPanel, buttonPanel;

	JTable SR;

	protected ACDControl ACD;

	protected EPSControl EPS;

	protected PDControl PD;

	protected SearchCustomer CS;

	protected JTabbedPane tabs;

	protected JButton addEdit, cancel, clr;

	protected CustomerList CL;

	protected JLabel changed = new JLabel("*"); // shows if changes have been

	// made

	final int USER_ID = 0, FORNAME = 1, SURNAME = 2;

	protected Object[][] NAMES;

	protected Vector customers, propList;

	protected int thisCustomer, lastCustomer, thisTab;

	protected boolean changeMade = true;

	/**
	 * Constructs inactive GUI
	 */
	public MainPanel() {
		arrangeComponents();
	}

	/**
	 * Skeletern method for obtaining customer list
	 */
	@SuppressWarnings("unchecked")
	protected void importCustomers() {
		customers = TestClass.createCustomers((int) (100 * Math.random()));
	}

	/**
	 * Builds a list of names and sirnames out of the customers vector<br>
	 * These can then be used to build the list that is visible on the left.
	 */
	public void buildList() { 
		try {
		propList = PropertySearchList.createPropertyList(customers);
		NAMES = new Object[customers.size()][3];
		for (int i = 0; i < customers.size(); ++i) {
			Customer temp = (Customer) customers.get(i);
			NAMES[i][CustomerList.ID] = (Integer) temp.get(Concept.CUST_ID);
			NAMES[i][CustomerList.NAME] = (String) temp.get(Concept.NAME);
			NAMES[i][CustomerList.SNAME] = (String) temp.get(Concept.SNAME);
		}
		} catch (Exception e){
			println("buldList Error: "+e);
		}
	}

	/**
	 * Arranges the GUIs and wraps some in tabs
	 * 
	 */
	protected void arrangeComponents() {
		importCustomers();
		buildList();
		ACD = new ACDControl();
		EPS = new EPSControl(propList);
		PD = new PDControl();
		CL = new CustomerList(NAMES);
		CS = new SearchCustomer();
		CS.getDisplay().setEnabled(false);
		tabs = new JTabbedPane();

		searchPanel = new JPanel();

		createButtons();
		tabs.addTab("Customer Details", ACD);
		tabs.addTab("Preferences", EPS);
		tabs.addTab("Property Details", PD);
		// tabs.addTab("Property Search Panel",PSP);

		setLayout(new BorderLayout());
		add(CS, BorderLayout.NORTH);
		add(CL, BorderLayout.WEST);
		add(tabs, BorderLayout.CENTER);
		add(buttonPanel, BorderLayout.SOUTH);
		thisTab = tabs.getSelectedIndex();

	}

	/**
	 * Creates Buttons and creates action listeners for them.
	 */
	public void createButtons() {
		addEdit = new JButton("Update"); // Displays query results in the
		// table
		clr = new JButton("Clear"); // Clears previous query
		cancel = new JButton("Cancel"); // Prints tabled results to terminal
		// Add buttons to JPanel using FlowLayout
		buttonPanel = new JPanel();
		buttonPanel.setLayout(new FlowLayout());
		buttonPanel.add(changed);
		buttonPanel.add(addEdit);
		buttonPanel.add(clr);
		buttonPanel.add(cancel);

	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.awt.Component#setEnabled(boolean)
	 */
	public void setEnabled(boolean e) {
		enabled = e;
		ACD.setEnabled(e);
	}

	/**
	 * @param args
	 *            Method for Testing GUI
	 */
	public static void main(String[] args) {
		JFrame F = new JFrame();
		MainPanel P = new MainPanel();
		F.add(P);
		F.setVisible(true);
		F.pack();
		F.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	}

}
