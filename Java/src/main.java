import rmx.RMXObject;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		NotificationCenter.init();
		RMXObject o = new RMXObject();
		o.OnEventDidEnd("Im and event", null);
		System.out.println("Hello, world");
//		o.StartListening();
//		NotificationCenter.eventDidOccur("Hello! Im an event!", null);
	}

}
