/*
 * Created by jhs4mjb for project SE24 on 09-Feb-2006
 */

package eAgent.concept;

import java.util.Vector;



/**
 * Customer class extends Concept class.
 *
 * @author jhs4mjb
 * @version
 */

public class Customer extends Concept{

  private int id; // for database?
  Name name;
  Address address;
  ContactInfo contactInfo;
  Status status;
  Preferences prefs; 
  Vector properties;
  
  /**
   * Constructor to create customer with just a name and an ID.
 * @param id
 * @param n
 * @param sn
 */
public Customer(int id, String n, String sn){
    init();
    this.id = id;
    name.forname = n;
    name.sirname = sn;
  }
  
  /**
 * Constructor
 */
public Customer()
  {
    init();
  }
 
  /**
 * Initialises variables
 */
public void init(){
	  name = new Name();
	  address = new Address();
	  contactInfo = new ContactInfo();
	  status = new Status();
	  properties = new Vector();
	  prefs = new Preferences();
  }
  
  /* (non-Javadoc)
 * @see eAgent.concept.Address#get(int)
 */
public Object get(int i) {
	//if (isPref(i))
		//return prefs.get(i);
	if (isAddress(i))
		return address.get(i);
	else {
		switch (i){
		case CUST_ID:
			return id;
		case TITLE:
			return name.title;
		case NAME:
			return name.forname;
		case SNAME:
			return name.sirname;
		case BUY:
			return status.buying;
		case SELL:
			return status.selling;
		case RENT:
			return status.renting;
		case LEASE:
			return status.leasing;
		case DAY:
			return contactInfo.dayNo;
		case EVE:
			return contactInfo.eveNo;
		case MOB:
			return contactInfo.mobNo;
		case EMAIL:
			return contactInfo.email;

		}
		return null;
	}
}

/**
 * Setter for any variable for the customer Object. 
 * 
 * @param i determins which variable will be set
 * @param s sets the variable
 * @return true if all is well.
 */
public boolean set(int i, Object s) {
	if (isPref(i))
		return prefs.set(i,s);
	if (isAddress(i))
		return address.set(i,s);
	else {
		switch (i){
		case CUST_ID:
			id = (Integer) s;
			return true;
		case TITLE:
			name.title = (String) s;
			return true;
		case NAME:
			name.forname = (String) s;
			return true;
		case SNAME:
			name.sirname = (String) s;
			return true;
		case DAY:
			contactInfo.dayNo = (String) s;
			return true;
		case EVE:
			contactInfo.eveNo = (String) s;
			return true;
		case MOB:
			contactInfo.mobNo = (String) s;
			return true;
		case EMAIL:
			contactInfo.email = (String) s;
			return true;
		case BUY:
			status.buying = (Boolean) s;
			return true;
		case SELL:
			status.selling = (Boolean) s;
			return true;
		case RENT:
			status.renting = (Boolean) s;
			return true;
		case LEASE:
			status.leasing = (Boolean) s;
			return true;
		}
		return false;
	}
}


/**
 * Adds a property to the Cutomer's property list Vector
 * @param p a property object
 * @return true if all is well.
 */
@SuppressWarnings("unchecked")
public boolean addProperty(Property p)
  {
	  return properties.add(p);
  }
  
  /**
   * Removes a property from a customer's property list Vector.
 * @param i index of property
 */
public void remProperty(int i)
  {
	  properties.removeElementAt(i);
  }
  
/**
 * Removes a specific property from the Cutomer's property list Vector
 * @param p a property object to be removed
 * @return true if all is well.
 */
public boolean remProperty(Property p)
  {
	  return properties.removeElement(p);
  }
  
  
  
  /**
   * Getter for Customer prefs
 * @return preferences object
 */
public Preferences getPrefs() {
	return prefs;
}


/**
 * Setter fot customer prefs
 * @param prefs a preferences object
 */
public void setPrefs(Preferences prefs) {
	this.prefs = prefs;
}

/**
 * Getter for customer property List
 * @return Vector of properties
 */
public Vector getProperties() {
	return properties;
}


/**
 * Sets the customer property list
 * @param properties vector
 */
public void setProperties(Vector properties) {
	this.properties = properties;
}

  
  
  
  /**
	 * getter for address
	 * 
	 * @return
	 */

	public Address getAddress() {
		return address;
	}

  
  
  /**
	 * Setter for address, sets address object.
	 * 
	 * @param
	 */
  
  public void setAddress(Address address)
  {
    this.address = address;
  }

  
  
  /**
   * Getter fot ContactInfo
   *
   * @return
   */
  
  public ContactInfo getContactInfo()
  {
    return contactInfo;
  }

  
  
  /**
   * Setter for ContactInfo
   *
   * @param ContactInfo object
   */
  
  public void setContactInfo(ContactInfo contactInfo)
  {
    this.contactInfo = contactInfo;
  }

  /**
   * Setter for ContactInfo, takes 4 parameters.
 * @param a
 * @param b
 * @param c
 * @param d
 */
public void setContactInfo(String a, String b, String c, String d)
  {
    this.contactInfo = new ContactInfo(a,b,c,d);
  }
  
  
  /**
   * getter for Name
   *
   * @return
   */
  
  public Name getName()
  {
    return name;
  }
  /**
   * Setter for name object, takes a name object
   *
   * @param
   */
  
  public void setName(Name name)
  {
    this.name = name;
  }

  /**
   * Setter for name object. Takes  spectific name values.
 * @param title
 * @param first
 * @param sirname
 */
public void setName(String title, String first, String sirname)
  {
    this.name = new Name(title,first,sirname);
  }
  /**
   * Getter for customer status
   *
   * @return
   */
  
  public Status getStatus()
  {
    return status;
  }

  
  
  /**
   * Sets status
   *
   * @param a status object
   */
  
  public void setStatus(Status status)
  {
    this.status = status;
  }

  /**
   * Sets status to specific parameters
 * @param b
 * @param s
 * @param r
 * @param l
 * 
 */
public void setStatus(boolean b, boolean s, boolean r, boolean l)
  {
    this.status = new Status(b,s,r,l);
  }
  
  /* (non-Javadoc)
 * @see java.lang.Object#toString()
 */
public String toString()
  {
    String s = "";
    s += "Customer id: " + id + '\n';
    s += name;
    s += address;
    s += contactInfo;
    s += status;
    return s;
  }

public String getRef(){
	return "ID: "+id+", Name: "+name.toString();
}

  /**
   * Tests the Customer class
   *
   * @param args
   */
  public static void main(String[] args)
  {
    // TODO Auto-generated method stub
    Customer A = new Customer();
    System.out.print(A);
  }


/**
 * @author max
 * inner class of Customer. 
 */
public class Name {
  String title, forname, sirname;
  
  /**
   * Constructor for new name
 * @param title
 * @param forname
 * @param sirname
 */
public Name(String title, String forname, String sirname)
  {
    this.title = title;
    this.forname = forname;
    this.sirname = sirname;
  }
  
  /**
 * Constructor creates empty name.
 */
public Name()
  {
    title = forname = sirname = "";
  }

  
  /* (non-Javadoc)
 * @see java.lang.Object#toString()
 */
public String toString()
  {
    String s = "";
    s += title + " " + title + forname + " " + sirname + '\n';
    return s;
  }

}

/**
 * @author max
 *inner clase containing contact information on customer.
 */
public class ContactInfo {
  
  private String dayNo, eveNo, mobNo, email;
  
  /**
   * Constructor creates specific contact information
 * @param dayNo
 * @param eveNo
 * @param mobNo
 * @param email
 */
public ContactInfo(String dayNo, String eveNo, String mobNo, String email)
  {
    this.dayNo = dayNo;
    this.eveNo = eveNo;
    this.mobNo = mobNo;
    this.email = email;
  }
  
  /**
 * Constructor -  creates empty contact information.
 */
public ContactInfo()
  {
    dayNo = eveNo = mobNo = email = "";
  }

 
  
  /* (non-Javadoc)
 * @see java.lang.Object#toString()
 */
public String toString()
  {
    String s = "";
    s += dayNo + '\n';
    s += eveNo + '\n';
    s += mobNo + '\n';
    s += email + '\n';
    return s;
  }
  
}

/**
 * @author max
 * Status object to indicate whether a customer is buying, selling, renting or leasing
 */
public class Status {
  
  public boolean buying, selling, renting, leasing;
  
  /**
   * Constructor sets a specific status
 * @param buying
 * @param selling
 * @param renting
 * @param leasing
 */
public Status(boolean buying, boolean selling, boolean renting, boolean leasing)
  {
    this.buying = buying;
    this.selling = selling;
    this.renting = renting;
    this.leasing = leasing;
  }

  /**
 * Constructor for default status. All variables == false.
 */
public Status()
  {
    buying = selling = renting = leasing = false;
  }
  

  
  /* (non-Javadoc)
 * @see java.lang.Object#toString()
 */
public String toString()
  {
    String s = "";
    if(buying) s+= "buying, "; else s += "not Buying,";
    if(selling) s += "selling, "; else s += "not selling, ";
    if(renting) s += "renting, "; else s += "not renting, ";
    if(leasing) s += "leasing\n"; else s += "not leasing\n";
    return s;
  }
  


}

}
