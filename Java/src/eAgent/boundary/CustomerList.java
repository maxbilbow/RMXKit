package eAgent.boundary;

/**
 * @author max This GUI extends the Generic list to provide a list of names that
 *         can be<br>
 *         easily searched through by either first or second names
 */
@SuppressWarnings("serial")
public class CustomerList extends GenericList {

	public static final int NAME = 1, SNAME = 2;

	/**
	 * @param n
	 * @param sn
	 *            Takes two String arrays to create list of first and second
	 *            names
	 */
	public CustomerList(Object[][] data) {
		try {
			arrangeComponents(data);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * @param S
	 *            Rebuilds the list with new data S
	 */
	public void reBuild(Object[][] S) {
		this.S = S;
		buildVector();
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see eAgent.boundary.GenericList#addString(int)
	 */
	@SuppressWarnings("unchecked")
	public void addString(int i) {
		data.add(new String(S[i][NAME] + " " + S[i][SNAME]));
		list.setListData(data);
	}

	/**
	 * Compares what is typed into search fields with what is in the list.
	 * fields that dont match are removed.
	 * 
	 * @param text1 -
	 *            the letters to compare to first names
	 * @param text2 -
	 *            the letters to compare to second names
	 */
	public void compare(String text1, String text2) throws Exception {
		String s;
		buildVector();
		for (int i = 0; i < S.length; ++i) {
			String n = (String) S[i][NAME], sn = (String) S[i][SNAME];
			if ((n.length() >= text1.length())
					&& (sn.length() >= text2.length())) {
				s = n.substring(0, text1.length()) + " "
						+ sn.substring(0, text2.length());
				if (!s.equalsIgnoreCase(text1 + " " + text2))
					removeString(n, sn);
			} else
				removeString(n, sn);
		}

	}

	/**
	 * @param id
	 * @throws Exception
	 *             displays entry with customer ID i
	 */
	public void compare(Object id) throws Exception {
		try {
			int index = findIndex(Integer.valueOf((String) id));
			data.removeAllElements();
			if (index != -1)
				addString(S[index][NAME], S[index][SNAME]);
			else
				list.setListData(data);
		} catch (NumberFormatException e) {
			print("compare customer list Error: " + e);
			buildVector();
		}

	}

	/**
	 * @param n
	 * @param sn
	 *            Adds name to vector
	 */
	@SuppressWarnings("unchecked")
	public void addString(Object n, Object sn) {
		data.add(n + " " + sn);
		list.setListData(data);
	}

	/**
	 * @param n
	 * @param sn
	 *            removes matching name from vector
	 */
	public void removeString(Object n, Object sn) {
		data.remove(n + " " + sn);
		list.setListData(data);
	}

	/**
	 * @param i
	 * @return - gets forname at position i
	 */
	public String getN(int i) {
		return (String) S[i][NAME];
	}

	/**
	 * @param i
	 * @return - gets surname at position i
	 */
	public String getSN(int i) {
		return (String) S[i][SNAME];
	}

	/**
	 * @param s
	 * @return integer reference of name in list
	 * @return -1 if no match found.
	 */
	public int findIndex(String s) {
		for (int i = 0; i < S.length; ++i) {
			if (s.equalsIgnoreCase(S[i][NAME] + " " + S[i][SNAME]))
				return i;
		}
		return -1;
	}

}
