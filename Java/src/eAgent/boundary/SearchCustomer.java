package eAgent.boundary;

/*
 * SE24 Larks Project
 * Search Customer Details form
 * Writen by Richard Scoones
 */

import javax.swing.*;

import eAgent.EasyPanel;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SearchCustomer extends EasyPanel {

	/**
	 * An information entry panel to search for a customer <br>
	 * Forname, Surname or Customer ID can be used
	 */

	private static final long serialVersionUID = 1L;

	JButton display, delete;

	JLabel userid, name, surname;

	protected JTextField useridText, titleText, nameText, initialText,
			surnameText;

	JTable searchTable;

	protected JCheckBox newCustomer;

	/**
	 * Constructor - runs the
	 * 
	 * @arangeComponents method
	 */
	public SearchCustomer() {
		arangeComponents();
	}

	/**
	 * Arranges the GUI components
	 */
	public void arangeComponents() {
		userid = new JLabel("User ID");
		useridText = new JTextField(10);
		name = new JLabel("Name");
		nameText = new JTextField(15);
		surname = new JLabel("Surname");
		surnameText = new JTextField(15);
		display = new JButton("Display");
		delete = new JButton("Delete");
		delete.setEnabled(false);
		newCustomer = new JCheckBox("New Entry");
		newCustomer.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (newCustomer.isSelected())
					setEnabled(false);
				else
					setEnabled(true);
			}
		});

		setLayout(new FlowLayout());
		add(userid);
		add(useridText);
		add(name);
		add(nameText);
		add(surname);
		add(surnameText);
		add(display);
		add(delete);
		add(newCustomer);
	}

	/**
	 * @return neCustomer JCheckBox for referencing
	 */
	public JCheckBox getNewCustomer() {
		return newCustomer;
	}

	/**
	 * @param setEnabled
	 *            <br>
	 *            sets all fields editable true or false
	 */
	public void setEnabled(boolean enabled) {
		useridText.setEditable(enabled);
		nameText.setEditable(enabled);
		surnameText.setEditable(enabled);
		super.setEnabled(enabled);
	}
	

	/**
	 * @param id
	 * @param name
	 * @param surname
	 * 
	 * <br>
	 * Sets all fields
	 */
	public void setFields(String id, String name, String surname) {
		useridText.setText(id);
		nameText.setText(name);
		surnameText.setText(surname);
	}

	/**
	 * @return Display button for referencing
	 */
	public JButton getDisplay() {
		return display;
	}

	/**
	 * @return true if new customer box is checked
	 */
	public boolean isNewSelected() {
		return newCustomer.isSelected();
	}

	
	/**
	 * @param b
	 *            if true:<br>
	 *            sets neCustomer check box selected and all fields unEditable.m
	 *            And vice-versa
	 */
	public void setNewSelected(boolean b) {
		newCustomer.setSelected(b);
		setEnabled(!b);
	}

	/**
	 * @return NameTesT JTextField for referencing
	 */
	public JTextField getNameText() {
		return nameText;
	}

	/**
	 * @return surnameText JTextField for referencing
	 */
	public JTextField getSurnameText() {
		return surnameText;
	}

	/**
	 * @return userIDText JTextField for referencing
	 */
	public JTextField getUseridText() {
		return useridText;
	}

	/**
	 * @param args
	 *            Method for testing this GUI
	 */
	public static void main(String[] args) {
		JFrame X = new JFrame("Seach Customer");
		SearchCustomer x = new SearchCustomer();
		X.add(x);
		X.setVisible(true);
		X.pack();
		X.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	/**
	 * @return Returns the delete.
	 */
	public JButton getDelete() {
		return delete;
	}

	public void clearAll() {
		useridText.setText("");
		nameText.setText("");
		surnameText.setText("");
	}

}
