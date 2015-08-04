package rmx;

public interface IEventListener {
//	void OnEvent(String theEvent, Object args);
	void OnEventDidStart(String theEvent, Object args);
	void OnEventDidEnd(String theEvent, Object args);
	void SendMessage(String message, Object sendMessageOptions);
	String name();// = "";
}
