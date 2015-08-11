package eAgent.boundary;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.util.Vector;

import javax.swing.JList;
import javax.swing.JScrollPane;

import eAgent.EasyPanel;

/**
 * @author max This creates a generic list of String data to display as a GUI
 *         <br>
 *         It is the Parant class for CustomerList and PropertySearchList.
 */
@SuppressWarnings("serial")
public class GenericList extends EasyPanel {

	Vector data = new Vector();

	JScrollPane scroll;

	JList list;

	int width = 200;

	Object[][] S;

	public static final int ID = 0;

	/**
	 * @param data
	 *            Constructor <br>
	 *            Creates a vector out of String array and initialises the JList
	 *            with that Vector.
	 */
	public GenericList(Object[][] data) {
		try {
			arrangeComponents(data);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * Constructor <br>
	 * initialises JList with empty Vector.
	 */
	public GenericList() {
		list = new JList(this.data);
		try {
			arrangeComponents(new Object[10][3]);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			print(e);
		}
	}

	/**
	 * @param data
	 *            Enters new Object Array into Vector
	 */
	@SuppressWarnings("unchecked")
	public void buildVector(Object[] data) {
		this.data.removeAllElements();
		for (int i = 0; i < data.length; ++i)
			this.data.add(data[i]);
		list.setListData(this.data);
	}

	/**
	 * Builds the data Vector using current data array
	 */
	@SuppressWarnings("unchecked")
	public void buildVector() {
		data.removeAllElements();
		for (int i = 0; i < S.length; ++i)
			addString(i);
		list.setListData(data);
	}

	/**
	 * @param i
	 *            Adds the String in index i of the data array to the vector.
	 */
	@SuppressWarnings("unchecked")
	public void addString(int i) {
		data.add((String) S[i][1]);
		list.setListData(data);
	}

	/**
	 * @param n
	 *            removes matching string from vector
	 */
	public void removeString(String n) {
		data.removeElement(n);
		list.setListData(data);
	}

	/**
	 * Arranges the graphical appearance of this GUI
	 */
	public void arrangeComponents(Object[][] S) throws Exception {
		this.S = S;
		buildVector();
		scroll = new JScrollPane();
		scroll.getViewport().setView(list);
		scroll.setPreferredSize(new Dimension(width, 0));
		setLayout(new BorderLayout());
		add(scroll, BorderLayout.CENTER);
	}

	/**
	 * @return JList for referencing
	 */
	public JList getList() {
		return list;
	}

	/**
	 * @return Data Vector for referencing
	 */
	public Vector getData() {
		return data;
	}

	/**
	 * @param N
	 * @param SN
	 *            rebuilds list with new String arrays
	 */
	public void setNames(Object[][] data) {
		S = data;
		buildVector();
	}

	/**
	 * @param i
	 * @return - gets ID at position i in vector
	 */
	public int getId(int i) {
		return (Integer) S[i][ID];
	}

	/**
	 * @param id
	 * @return Array index of data with specific id
	 */
	public int findIndex(Integer id) {
		for (int i = 0; i < S.length; ++i) {
			if (id.equals((Integer) S[i][ID]))
				return i;
		}
		println(id);
		return -1;
	}
}
