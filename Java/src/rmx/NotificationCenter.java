package rmx;

import java.util.Dictionary;

public class NotificationCenter {
	private static Dictionary<String,EventListener> listeners;// = new Dictionary<String,EventListener> ();

	private static Dictionary<String,IEvent> events;// = new Dictionary<IEvent,EventStatus>();






	public static boolean HasListener(EventListener listener) {
		return listeners.get(listener.name()) != null;
	}
	
	public static void Reset(IEvent theEvent) {
		if (events.get(theEvent.type()) != null)
			events.get(theEvent.type()).setStatus(EventStatus.Idle);
		else {
			theEvent.setStatus(EventStatus.Idle);
			events.put(theEvent.type(),theEvent);
		}
	}

	public static void AddListener(EventListener listener) {
		listeners.put(listener.Name) = listener;
		if (Bugger.WillLog (RMXTests.EventCenter, listener.GetType () + " was added to Listeners ("+ Listeners.Count + ")"))
			Debug.Log (Bugger.Last);
//		if (Bugger.WillLog(Testing.EventCenter, "Listeners: " + Listeners.Count))
//			Debug.Log (Bugger.Last);

	}

	public static void RemoveListener(EventListener listener) {
		if (Listeners.ContainsValue (listener))
		if (!Listeners.Remove (listener.name))
			throw new System.Exception (listener.name + " exists but could not be removed from Listeners");
	}

	public static EventStatus StatusOf(IEvent theEvent) {
		return Events.ContainsKey(theEvent) ? Events [theEvent] : EventStatus.Idle;
	}

	public static bool IsIdle(IEvent theEvent) {
		return StatusOf (theEvent) == EventStatus.Idle;
	}

	public static bool IsActive(IEvent theEvent) {
		return StatusOf (theEvent) == EventStatus.Active;
	}

	public static void EventDidOccur(IEvent e) {
		EventDidOccur (e, null);
	}

	public static void EventDidOccur(IEvent theEvent, object o) {
		var listeners = Listeners;
		Events [theEvent] = o is EventStatus ? (EventStatus) o : EventStatus.Completed;
		foreach (KeyValuePair<string, EventListener> listener in listeners) {
			listener.Value.OnEvent(theEvent,o);
		}
	}


	public static bool WasCompleted(IEvent theEvent) {
		return StatusOf (theEvent) == EventStatus.Completed;
	}

	public static void EventWillStart(IEvent theEvent) {
		EventWillStart (theEvent, null);
	}

	public static void EventWillStart(IEvent theEvent, object o) {
		if (!IsActive (theEvent)) {
			Events [theEvent] = o is EventStatus ? (EventStatus) o : EventStatus.Active;
			foreach (KeyValuePair<string, EventListener> listener in Listeners) {
				listener.Value.OnEventDidStart (theEvent, o);
			}
		}
	}
	public static void EventDidEnd(IEvent theEvent) {
		EventDidEnd (theEvent, null);
	}
	public static void EventDidEnd(IEvent theEvent, object o) {
		var listeners = Listeners;
		Events [theEvent] = Events [theEvent] = o is EventStatus ? (EventStatus) o : EventStatus.Completed;
		foreach (KeyValuePair<string, EventListener> listener in listeners) {
			listener.Value.OnEventDidEnd(theEvent,o);
		}
	}

	public static void NotifyListeners(string message) {
		foreach (KeyValuePair<string, EventListener> listener in Listeners) {
			listener.Value.SendMessage (message, SendMessageOptions.DontRequireReceiver);
		}
	}

}
