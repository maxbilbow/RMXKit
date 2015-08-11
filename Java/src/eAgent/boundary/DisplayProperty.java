package eAgent.boundary;

import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

import eAgent.concept.Concept;
import eAgent.concept.Customer;
import eAgent.concept.Property;

/**
 * @author max
 * This class, which needs to be finished, displayes a photo and information about a selected property 
 * from the property search. <br>
 * The idea is that this can then be printed for the customer.
 *
 */
@SuppressWarnings("serial")
public class DisplayProperty extends JFrame {
JPanel addressPanel, contactPanel, picturePanel, pricePanel, prefsPanel, mainPanel;
Property property;
Customer customer;
final int PIC = 0, PRICE = 1, ADD = 2, PREF = 3, CONTACT = 4;
JTextArea[] ta;

	/**
	 * @param property The property selected by the user
	 * @param customer The customer associated with that property
	 * @throws ClassCastException if property and customer are entered the wrong way round into the constructor
	 * 
	 */
	public DisplayProperty(Object property, Object customer) throws ClassCastException{
		this.property = (Property) property;
		this.customer = (Customer) customer;
		init();
		arrangeComponents();
		pack();
		setVisible(true);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}
	
	/**
	 * Initiates variables
	 */
	private void init(){
		ta = new JTextArea[CONTACT+1];
		addressPanel = new JPanel();
		contactPanel = new JPanel();
		picturePanel = new JPanel();
		pricePanel = new JPanel();
		prefsPanel = new JPanel();
		mainPanel = new JPanel();
	}
	
	/**
	 * Arranges components in GUI
	 */
	private void arrangeComponents(){
		mainPanel.setLayout(new BoxLayout(mainPanel,BoxLayout.Y_AXIS));
		mainPanel.add(picturePanel);
		mainPanel.add(pricePanel);
		mainPanel.add(addressPanel);
		mainPanel.add(prefsPanel);
		mainPanel.add(contactPanel);
		add(mainPanel);
		
		displayPicture();
		displayPrice();
		displayAddress();
		displayPrefs();
		displayContact();
	}
	
	/**
	 * Organises the price area
	 */
	private void displayPrice() {
		// TODO Auto-generated method stub
		ta[PRICE] = new JTextArea();
		pricePanel.add(ta[PRICE]);
	}

	/**
	 * Organises the Property picture area
	 */
	private void displayPicture() {
		// TODO Auto-generated method stub
		
	}

	/**
	 * Organises the Contact information area
	 */
	private void displayContact() {
		String s = customer.getName().toString() + customer.getContactInfo().toString();
		ta[CONTACT] = new JTextArea(s);	
		contactPanel.add(ta[CONTACT]);
	}

	/**
	 * Organises the Address area
	 */
	private void displayAddress(){
		ta[ADD] = new JTextArea(property.getAddress().toString());
		addressPanel.add(ta[ADD]);
	}
	
	/**
	 * Organises the Information area
	 */
	private void displayPrefs(){
		ta[PREF] = new JTextArea(property.getPrefs().toString());
		prefsPanel.add(ta[PREF]);
	}
	
	/**
	 * Main method for testing this class
	 * @param args
	 */
	public static void main(String[] args){
		Property p = new Property();
		p.set(Concept.FRONT,true);
		@SuppressWarnings("unused")
		DisplayProperty dp = new DisplayProperty(p, new Customer(1,"max","Bilbow"));
	}
}
