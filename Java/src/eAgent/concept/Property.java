/*
 * Created by jhs4mjb for project SE24 on 09-Feb-2006
 */

package eAgent.concept;



/**
 * @author max
 * Concept class for a property @extends Concept
 */
public class Property extends Concept {

  int id, custID; // for database?
  Address address;
  Date availableFrom;
  Preferences prefs;
  
  /**
 * Constructor initialises variables.
 */
public Property()
  {
    address = new Address();
    availableFrom = new Date();
    prefs = new Preferences();
  }

  /* (non-Javadoc)
 * @see eAgent.concept.Concept#get(int)
 */
public Object get(int i){
	  if (isAddress(i))
		  return address.get(i);
	  else if (isPref(i))
		  return prefs.get(i);
	  else if (isID(i))
		  if (i==CUST_ID)
			  return custID;
		  else 
			  return id;
	  else{
		  System.out.println("Property Concetp get(i) Error: "+i);
		  return null;
	  }	  
  }
  
/**
 * @return preferences object
 */
public Preferences getPrefs() {
	return prefs;
}

/* (non-Javadoc)
 * @see eAgent.concept.Concept#set(int, java.lang.Object)
 */
public boolean set(int i, Object o){
	if (isPref(i))
		return prefs.set(i,o);
	else if (isID(i)){
		if (i==CUST_ID)
			custID = (Integer) o;
		else
			id = (Integer) o;
		return true;
	}
	else if (isAddress(i))
		return address.set(i,o);
	else
		return false;
}


/**
   * Getter for property address
   *
   * @return
   */
  
  public Address getAddress()
  {
    return address;
  }

  
  /**
   * Sets Address from database
   *
   * @param
   */
  
  public void setAddress(Address address)
  {
    this.address = address;
  }
  

  
  /**
   * Getter for available from date
   *
   * @return
   */
  
  public Date getAvailableFrom()
  {
    return availableFrom;
  }
  
  /**
   * Setter for available from date
   *
   * @param
   */
  
  public void setAvailableFrom(Date availableFrom)
  {
    this.availableFrom = availableFrom;
  }
  

  /* (non-Javadoc)
 * @see java.lang.Object#toString()
 */
public String toString()
  {
    String s = "";
    s += "Property id: " + id;
    s += address;
    s += "Available From: " + availableFrom;
    s += '\n';
    return s;
  }

/**
 * Setter for preferences (Property Information)<br>
 * sets to a preferences object
 * 
 * @param prefs
 */
public void setPrefs(Preferences prefs) {
	 this.prefs = prefs;
	
}

/* (non-Javadoc)
 * @see eAgent.concept.Preferences#getPrice()
 */
public int getPrice() {
	return prefs.getPrice(Concept.PRICE);
}

/* (non-Javadoc)
 * @see eAgent.concept.Preferences#setPrice(int)
 */
public void setPrice(int price) {
	prefs.setPrice(Concept.PRICE,price);
}

}
