package rmx;

public interface KeyValueObserver {
	void OnValueForKeyWillChange(String key, Object value);
	void OnValueForKeyDidChange(String key, Object value);
}
