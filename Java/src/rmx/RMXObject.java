package rmx;

import java.util.LinkedList;
import java.util.Dictionary;

public class RMXObject extends EventListener implements KeyValueObserver, IEventListener {
	private Dictionary<String, Object> values;// = new Dictionary<String, Object> ();
	private LinkedList<KeyValueObserver> observers = new LinkedList<KeyValueObserver> ();


	/// <summary>
	/// Gets a value indicating whether this <see cref="RMX.ASingleton`1"/> add to global listeners.
	/// </summary>
	/// <value><c>true</c> if add to global listeners; otherwise, <c>false</c>.</value>
	private boolean addToGlobalListeners() { 
//			System.Type classType = this.GetType();
//			foreach (string vMethod in ListenerMethods) {
//				MethodInfo method = classType.GetMethod (vMethod);
//				if (method.DeclaringType != typeof(RMXObject)) 
//					return true;
//			}
			return true;
	}

	public RMXObject() {
		this.awake();
	}
	protected void awake() {
		if (this.addToGlobalListeners())
			NotificationCenter.addListener(this);
	}

//	protected virtual void OnDestroy() {
//		Notifications.RemoveListener (this);
//	}

//	protected void willBeginEvent(IEvent theEvent){
//		NotificationCenter.EventWillStart (theEvent);
//	}
//
//	protected void didUpdateEvent(IEvent theEvent) {
//		NotificationCenter.EventWillStart (theEvent);
//	}
//
//	protected void didFinishEvent(IEvent theEvent){
//		NotificationCenter.EventDidEnd (theEvent);
//	}
//
//	protected void didCauseEvent(IEvent theEvent){
//		NotificationCenter.EventDidOccur (theEvent);
//	}
//
//	protected void willBeginEvent(IEvent theEvent, object info){
//		NotificationCenter.EventWillStart (theEvent, info);
//	}
//	
//	protected void DidUpdateEvent(IEvent theEvent, object info) {
//		NotificationCenter.EventWillStart (theEvent, info);
//	}
//	
//	protected void DidFinishEvent(IEvent theEvent, object info){
//		NotificationCenter.EventDidEnd (theEvent, info);
//	}
//
//	protected void DidCauseEvent(IEvent theEvent, object info){
//		NotificationCenter.EventDidOccur (theEvent, info);
//	}
//
//	protected void WillChangeValueForKey(string key){
//		foreach (KeyValueObserver observer in observers) {
//			observer.OnValueForKeyWillChange(key, values[key]);
//		}
//	}
//	
//	protected void DidChangeValueForKey(string key) {
//		foreach (KeyValueObserver observer in observers) {
//			observer.OnValueForKeyDidChange(key, values[key]);
//		}
//	}
//
//	public virtual void setValue(string forKey, object value) {
//		if (values[forKey] != value) {
////			DidChangeValueForKey(forKey); ??
//			values[forKey] = value;
//			DidChangeValueForKey(forKey);
//		}
//	}

	public Object getValue(String forKey) {
		return this.values.get(forKey);
	}

	public void AddObserver(KeyValueObserver observer) {
		if (!this.observers.contains(observer))
			this.observers.add(observer);
	}

	public void RemoveObserver(KeyValueObserver observer) {
		if (observers.contains(observer))
			observers.remove(observer);
	}


//	public void OnValueForKeyWillChange(String key, Object value) {}
//	public void OnValueForKeyDidChange (String key, Object value) {}

	protected static String[] ListenerMethods = {
		"OnEvent",
		"OnEventDidStart",
		"OnEventDidEnd"
	};


	@Override
	public void OnEventDidStart(String theEvent, Object args){
		String arg = args != null ? args.toString() : "N/A";
        System.out.println(this.name() + " => Event Started: " + theEvent + ", with args: " + arg);
    }
	
	@Override
	public void OnEventDidEnd(String theEvent, Object args){
		String arg = args != null ? args.toString() : "N/A";
        System.out.println(this.name() + " => Event Ended: " + theEvent + ", with args: " + arg);
    }
	
	@Override
	public void SendMessage(String message, Object args){
		String arg = args != null ? args.toString() : "N/A";
        System.out.println(this.name() + " => Message Received: " + message + ", with args: " + arg);
    }
	
	public static boolean OneIn10() {
			return true;//TODO Random(0,10) == 1;
	}
	

	@Override
	public String name() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void OnValueForKeyWillChange(String key, Object value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void OnValueForKeyDidChange(String key, Object value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public EventListener clone() {
		// TODO Auto-generated method stub
		return null;
	}
}
