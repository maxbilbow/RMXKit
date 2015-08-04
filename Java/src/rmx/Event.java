//package rmx;
//
//public class Event implements IEvent {
//	private String _type;
//	
//	@Override
//	public String type() {
//		return _type;
//	}
//	
//	private EventStatus _status;
//	
//	@Override
//	public EventStatus status() {
//		return _status;
//	}
//
//	public Event(String type) {
//		this._type = type;
//		this._status = EventStatus.Idle;
//	}
//
//	@Override
//	public boolean IsType(IEvent theEvent) {
//		// TODO Auto-generated method stub
//		return theEvent.type() == this.type();
//	}
//
//	@Override
//	public boolean HasStatus(EventStatus status) {
//		return this.status() == status;
//	}
//
//	@Override
//	public boolean setStatus(EventStatus status) {
//		this._status = status;
//		return true;
//	}
//
//
//}