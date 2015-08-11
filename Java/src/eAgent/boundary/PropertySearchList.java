package eAgent.boundary;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.util.Vector;

import javax.swing.JList;
import javax.swing.JScrollPane;

import eAgent.concept.Concept;
import eAgent.concept.Customer;
import eAgent.concept.Property;

/**
 * @author max Dipslays properties that are added to it. Used when searching
 *         with respect to customer preferences.
 */
@SuppressWarnings("serial")
public class PropertySearchList extends GenericList {

	public static final int PROP_ID = 1, READ = 2;

	protected int[] info = { Concept.CUST_ID, Concept.PROP_ID, Concept.ADD1,
			Concept.POST, Concept.PRICE };

	Vector id;

	int count;

	/**
	 * Constructor for list
	 */
	public PropertySearchList() {
		data = new Vector();
		id = new Vector();
		arrangeComponents();
	}

	/**
	 * Arranges the components of the GUI
	 */
	@SuppressWarnings("unchecked")
	private void arrangeComponents() {
		data.add("Hello");
		list = new JList(data);
		scroll = new JScrollPane();
		scroll.getViewport().setView(list);
		scroll.setPreferredSize(new Dimension(500, 500));
		setLayout(new BorderLayout());
		add(scroll, BorderLayout.CENTER);
	}

	/**
	 * Removes all info from the list
	 */
	public void clearAll() {
		data.removeAllElements();
		id.removeAllElements();
		list.setListData(data);
		count = 0;
	}

	/**
	 * @param o
	 *            Creates a string from the object o which is added to the list.
	 *            <br>
	 *            Customer and property ID are added to a seperate vector so
	 *            that the relevant information can be referenced
	 */
	@SuppressWarnings("unchecked")
	protected void addString(Object[] o) {
		String s = String.valueOf(o[0])+", "+String.valueOf(o[1]);
		int[] ids = new int[2];
		for (int i = 0; i < o.length; ++i) {
			if (i < READ)
				ids[i] = (Integer) o[i];
			else
				s += ", " + String.valueOf(o[i]);
		}
		data.add(new String(s));
		println(s + " Size: " + data.size());
		list.setListData(data);
		id.add(ids);
		count++;
	}

	/**
	 * @param p
	 *            Adds the relevant property information in p to an information
	 *            Object array, pInfo
	 */
	public void addProperty(Property p) {
		try {
			Object[] pInfo = new Object[info.length];
			for (int i = 0; i < pInfo.length; ++i)
				pInfo[i] = p.get(info[i]);
			addString(pInfo);
		} catch (Exception e) {
			println("here: " + e);
		}

	}

	/**
	 * @return Customer and property ID of selected index in the list.
	 */
	public int[] getIDs() {
		return (int[]) id.get(list.getSelectedIndex());
	}

	@SuppressWarnings("unchecked")
	public static Vector createPropertyList(Vector c) {
		Vector propList = new Vector();
		for (int i = 0; i < c.size(); ++i) {
			Vector p = ((Customer) c.get(i)).getProperties();
			for (int j = 0; j < p.size(); ++j)
				propList.add(p.get(j));
		}
		return propList;
	}
}
