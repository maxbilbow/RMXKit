package eAgent;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Vector;

import javax.swing.JOptionPane;

import eAgent.concept.Address;
import eAgent.concept.Concept;
import eAgent.concept.Customer;
import eAgent.concept.Property;

/**
 * @author Tom Rawcliffe
 *
 */
public class Database {
	public static final int CUSTOMER = 0, PROPERTY = 1;
	private String databaseName;
	private Connection connection;
	
	
	public Database(String name) throws ClassNotFoundException, SQLException{
		
		Class.forName("org.postgresql.Driver");
		databaseName = name;
	    connection = DriverManager.getConnection("jdbc:postgresql://csdbdev.leeds.ac.uk/" + name, name,name + name);

	}
	
	public String getDBName(){
		return databaseName;
	}
	
	public void setDBName(String name){
		databaseName = name;
	}
	
	public ResultSet runSql(String query){
		Statement statment;
		try {
			statment = connection.createStatement();
			return statment.executeQuery(query);
		} catch (SQLException e) {
			System.out.println("Error Connecting to database: "+e);
			e.printStackTrace();
			return null;
		}
		
	}
	
	public boolean executeSql(String query){
		try{
			Statement statement = connection.createStatement();
			statement.executeQuery(query);
			return true;
		}catch (ClassCastException e){
			System.out.println("executeSql Error: "+e);
			return false;
		} catch (SQLException e) {
			return true;
		}
	}
	
	public static void main(String[] args){
		
		Database db;
		try {
			db = new Database("se24_lark");
		} catch (Exception e) {
			db = null;
			System.out.println("Error Connecting to database: "+e);
			System.exit(1);
		}
		String query = JOptionPane.showInputDialog("Enter SQL query");
		
		//query = "DROP TABLE property;";
		
		/*query = "CREATE TABLE property (" +
				"ID int," +
				"Address1 varchar (50)," +
				"Address2 varchar (30)," +
				"Address3 varchar (30)," +
				"Address4 varchar (30)," +
				"Postcode varchar (10)," +
				"Price int," +
				"PropertyType int," +
				"Furnished int," +
				"Parking int," +
				"NoBed int," +
				"NoBath int," +
				"NoRec int," +
				"DRoom boolean," +
				"EHall boolean," +
				"FGarden boolean," +
				"Gas boolean," +
				"DGlazing boolean," +
				"Cons boolean," +
				"Ensuite boolean," +
				"RGarden boolean," +
				"CHeating boolean," +
				"Alarm boolean," +
				"PROP_ID int);";*/
		
		/*query = "CREATE TABLE owns (" +
				"CUST int," +
				"PROP int)";   DROPPED*/
		
		//query = "DROP TABLE customers;";
		
		/*query = "CREATE TABLE customers (" +
				"ID int," +
				"Title varchar (8)," +
				"FirstName varchar (30)," +
				"LastName varchar (30)," +
				"Address1 varchar (50)," +
				"Address2 varchar (30)," +
				"Address3 varchar (30)," +
				"Address4 varchar (30)," +
				"Postcode varchar (10)," +
				"DayNo varchar (15)," +
				"EveNo varchar (15)," +
				"MobNo varchar (15)," +
				"EMail varchar (30)," +
				"StatusBuy boolean," +
				"StatusSell boolean," +
				"StatusRent boolean," +
				"StatusLoan boolean," +
				"PropertyType int," +
				"Furnished int," +
				"Parking int," +
				"NoBed int," +
				"NoBath int," +
				"NoRec int," +
				"DRoom boolean," +
				"EHall boolean," +
				"FGarden boolean," +
				"Gas boolean," +
				"DGlazing boolean," +
				"Cons boolean," +
				"Ensuite boolean," +
				"RGarden boolean," +
				"CHeating boolean," +
				"Alarm boolean);";*/
		ResultSet results = db.runSql(query);
		
		  // Display results
		  try{
	      int columns = results.getMetaData().getColumnCount();
	      System.out.println(columns);
	      while (results.next()) {
	        for (int i = 1; i <= columns; ++i) {
	          if (i > 1)
	            System.out.print(", ");
	          System.out.print(results.getString(i));
	        }
	        System.out.println();
	      }
		 }catch(SQLException e){
			System.out.println("Error in SQL: "+e);
			System.exit(1);
		 }
	      
	}

	/**
	 * retrieves customers from database
	 * 
	 */

	@SuppressWarnings("unchecked")
	public static Vector importCustomers() {
		// TODO: the following method should gather data from the database
		
		Vector customers = new Vector();
		
		try {
			Database db = new Database("se24_lark");
			
			ResultSet results = db.runSql("SELECT * FROM customers;");
			
			while (results.next()) {
		        Customer temp = new Customer();
		        
				temp.set(Concept.CUST_ID, results.getInt(1));
				temp.set(Concept.TITLE, results.getString(2));
				temp.set(Concept.NAME, results.getString(3));
				temp.set(Concept.SNAME, results.getString(4));

				temp.set(Concept.DAY,results.getString(10));
				temp.set(Concept.EVE,results.getString(11));
				temp.set(Concept.MOB,results.getString(12));
				temp.set(Concept.EMAIL,results.getString(13));
				temp.setAddress(new Address(
						results.getString(5),
						results.getString(6),
						results.getString(7),
						results.getString(8),
						results.getString(9)));
				
				//EZ.print(2);
				
				temp.set(Concept.BUY,results.getBoolean(14));
				
				temp.set(Concept.SELL,results.getBoolean(15));
				temp.set(Concept.RENT,results.getBoolean(16));
				temp.set(Concept.LEASE,results.getBoolean(17));
				
				//EZ.print(3);
				//Preferences prefs = new Preferences();
				
				//prefs.set(Concept.PARKING,results.getInt("Parking"));
				temp.set(Concept.REAR,results.getBoolean(31));
				//EZ.print(4);
				temp.set(Concept.DINING,results.getBoolean(24));
				temp.set(Concept.ENTRANCE,results.getBoolean(25));
				temp.set(Concept.FRONT,results.getBoolean(26));
				temp.set(Concept.GAS,results.getBoolean(27));
				temp.set(Concept.CONSERV,results.getBoolean(29));
				temp.set(Concept.ENSUITE,results.getBoolean(30));
				temp.set(Concept.CENTRAL,results.getBoolean(32));
				temp.set(Concept.BURG_ALARM,results.getBoolean(33));
				temp.set(Concept.DBL_GLAZE,results.getBoolean(28));
		
				/*DINING = 15, ENTRANCE = 16,
			FRONT = 17, GAS = 18, CONSERV = 19, ENSUITE = 20, REAR = 21,
			CENTRAL = 22, BURG_ALARM = 23, DBL_GLAZE = 24, PRICE = 25,
			MAX_PRICE = 26, MIN_PRICE = 27, BUY = 28, SELL = 29, RENT = 30,
			LEASE = 31, PARKING = 32, FURNISHED = 33, TYPE = 34,
			BED = 35, BATH = 36, REC = 37,*/
				
				//temp.setPrefs(prefs);
				
				ResultSet link = db.runSql("SELECT * FROM property WHERE ID =" + (Integer)temp.get(Concept.CUST_ID));
				
				Vector props = new Vector ();
				
				while (link.next()){
					Property p = new Property();
					p.set(Concept.PROP_ID, link.getInt("PROP_ID"));
					p.set(Concept.CUST_ID, link.getInt("ID"));
					p.setAddress(new Address(
							link.getString("Address1"),
							link.getString("Address2"),
							link.getString("Address3"),
							link.getString("Address4"),
							link.getString("Postcode")));
					
					p.set(Concept.PRICE,link.getInt(7));
					//prefs = new Preferences();
					
					//prefs.set(Concept.PARKING,results.getInt("Parking"));
					p.set(Concept.REAR,results.getBoolean(21));
					p.set(Concept.DINING,results.getBoolean(14));
					p.set(Concept.ENTRANCE,results.getBoolean(15));
					p.set(Concept.FRONT,results.getBoolean(16));
					p.set(Concept.GAS,results.getBoolean(17));
					p.set(Concept.CONSERV,results.getBoolean(19));
					p.set(Concept.ENSUITE,results.getBoolean(20));
					p.set(Concept.CENTRAL,results.getBoolean(22));
					p.set(Concept.BURG_ALARM,results.getBoolean(23));
					p.set(Concept.DBL_GLAZE,results.getBoolean(18));
					//prefs.set(Concept.BUY,results.getBoolean("StatusBuy"));
					//prefs.set(Concept.SELL,results.getBoolean("StatusSell"));
					//prefs.set(Concept.LEASE,results.getBoolean("StatusLoan"));
					//prefs.set(Concept.RENT,results.getBoolean("StatusRent"));
					
					System.out.println("Dining: "+p.get(Concept.DINING));
					
					
					//p.setPrefs(prefs);
					props.add(p);
				}
					
				
				
				temp.setProperties(props);
				
				
		        customers.add(temp);
			}
			
			
		}catch (Exception e) {
			
			JOptionPane.showMessageDialog(null,
				    "Error  Connecting To Database: "+e,
				    "Data error",
				    JOptionPane.ERROR_MESSAGE);
			e.printStackTrace();
			System.err.println("Error Connecting to database: "+e);
			customers = TestClass.createCustomers((int) (100 * Math.random()));
		}
		
		
		return customers;
	}

	/**
	 * @param c
	 * @return
	 * 
	 * This needs to be finished.<br>
	 * 
	 * The method takes a customer to be updated to the database. It should compare 
	 * the customer id to those in the list. If there is a match, that customer will
	 * be updated by the new one. Otherwise a new customer is added.
	 *
	 */
	public static boolean writeToDatabase(Customer c){
		boolean ret;
		try{
			Database db = new Database ("se24_lark");
			ResultSet isThere = db.runSql("SELECT * FROM Customers WHERE ID =" + (Integer) c.get(Concept.CUST_ID) + ";" );

			if (isThere.getRow() > 0)
				remFromDatabase(CUSTOMER, (Integer)c.get(Concept.CUST_ID));
			
			ret = db.executeSql("INSERT INTO customers VALUES (" +
					(Integer) c.get(Concept.CUST_ID) + 
					",'" + c.get(Concept.TITLE) + 
					"','" + c.get(Concept.NAME) +
					"','" + c.get(Concept.SNAME) +
					"','" + c.get(Concept.ADD1) +
					"','" + c.get(Concept.ADD2) +
					"','" + c.get(Concept.ADD3) +
					"','" + c.get(Concept.ADD4) +
					"','" + c.get(Concept.POST) +
					"','" + c.get(Concept.DAY) +
					"','" + c.get(Concept.EVE) +
					"','" + c.get(Concept.MOB) +
					"','" + c.get(Concept.EMAIL) +
					"','" + c.getStatus().buying +
					"','" + c.getStatus().selling +
					"','" + c.getStatus().renting +
					"','" + c.getStatus().leasing +
					"'," + 0 +
					"," + 0 +
					"," + 0 +
					"," + 0 +
					"," + 0 +
					"," + 0 +
					",'" + c.get(Concept.DINING) +
					"','" + c.get(Concept.ENTRANCE) +
					"','" + c.get(Concept.FRONT) +
					"','" + c.get(Concept.GAS) +
					"','" + c.get(Concept.DBL_GLAZE) +
					"','" + c.get(Concept.CONSERV) +
					"','" + c.get(Concept.ENSUITE) +
					"','" + c.get(Concept.REAR) +
					"','" + c.get(Concept.CENTRAL) +
					"','" + c.get(Concept.BURG_ALARM) +
					"')");
			Vector props = c.getProperties();
			System.out.println(props.size());
			for (int i = 0; i < props.size(); i++)
			{
				System.out.println("test");
				Property p = (Property) props.get(i);
				
				
						String x = "INSERT INTO property VALUES (" +
						(Integer) c.get(Concept.CUST_ID) + 
						",'" + p.get(Concept.ADD1) +
						"','" + p.get(Concept.ADD2) +
						"','" + p.get(Concept.ADD3) +
						"','" + p.get(Concept.ADD4) +
						"','" + p.get(Concept.POST) +
						"'," + (Integer)p.get(Concept.PRICE) +
						"," + 0 +
						"," + 0 +
						"," + 0 +
						"," + 0 +
						"," + 0 +
						"," + 0 +
						",'" + p.get(Concept.DINING) +
						"','" + p.get(Concept.ENTRANCE) +
						"','" + p.get(Concept.FRONT) +
						"','" + p.get(Concept.GAS) +
						"','" + p.get(Concept.DBL_GLAZE) +
						"','" + p.get(Concept.CONSERV) +
						"','" + p.get(Concept.ENSUITE) +
						"','" + p.get(Concept.REAR) +
						"','" + p.get(Concept.CENTRAL) +
						"','" + p.get(Concept.BURG_ALARM) +
						"','" + p.get(Concept.PROP_ID) +
						"');";
						System.err.println(x);
						ret = db.executeSql(x);
			}
			
			
			
			ret = db.executeSql("");

		}catch (Exception e){
			e.printStackTrace();
			System.out.println("Error Writing Data: "+e);
			return false;
		}
		
		System.out.println("Writing information to database");
		return ret;	
	}
	
	/**
	 * Removes a customer or property from database.
	 * 
	 * @param type fields in this class dictate whether it is a property or customer to be deleted.
	 * @param id the id for that customer or property
	 * @return true if successful
	 */
	public static boolean remFromDatabase(int type, int id){
		try{
			Database db = new Database("se24_lark");
		
			switch (type){
			case CUSTOMER:
				db.executeSql("DELETE FROM customers WHERE ID =" + id );
				db.executeSql("DELETE FROM property WHERE ID = " + id);
				break;
			case PROPERTY:
				db.executeSql("DELETE FROM property WHERE PROP_ID =" + id );
				break;
			}
			
		}catch(Exception e){
			System.out.println("remFromDatabase Error: "+e);
			return false;
		}
		System.out.println("Deleted property or customer");
		return true;	
	}
	
	
}
