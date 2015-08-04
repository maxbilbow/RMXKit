//
//  RMXNotificationCenter.hpp
//  RMXKit
//
//  Created by Max Bilbow on 28/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef RMXNotificationCenter_cpp
#define RMXNotificationCenter_cpp

//#include <stdio.h>
//#import <list>
//#import <vector>



#endif /* RMXNotificationCenter_cpp */

#define EVENT_STATUS_IDLE       0ui
#define EVENT_STATUS_ACTIVE     1ui
#define EVENT_STATUS_COMPLETE   2ui
#define EVENT_STATUS_FAILURE    3ui


#import "LinkedList.hpp"
#import "Dictionary.hpp"
#import "EventListener.hpp"
#import "Behaviour.hpp"
namespace rmx {
    
    class NotificationCenter {
    public:
        typedef void * EventArgs;
        typedef std::string EventType;
        typedef unsigned short EventStatus;
    private:
        LinkedList<EventListener> * listeners;
        
        LinkedList<Behaviour> * behaviours;
        
        Dictionary<EventType, EventStatus> * events;

        NotificationCenter();

    public:
        
        static NotificationCenter * current();
        
        static bool hasListener(EventListener * listener);
        
        static void reset(EventType theEvent);
        
        static void addListener(EventListener * listener);
        
        static EventListener * removeListener(EventListener * listener);
        
        static EventStatus statusOf(EventType theEvent);
        
        static bool isIdle(EventType theEvent);
        
        static bool isActive(EventType theEvent) ;
        
        static void eventDidOccur(EventType e) {
            eventDidOccur (e, nullptr);
        }
        
        static void eventDidOccur(EventType theEvent, EventArgs o);
        
        static bool isComplete(EventType theEvent);
        
        static bool didFail(EventType theEvent);
        
        static void eventWillStart(EventType theEvent) {
            eventWillStart (theEvent, nullptr);
        }
        
        static void eventWillStart(EventType theEvent, EventArgs o);

        
        static void eventDidEnd(EventType theEvent) {
            eventDidEnd (theEvent, nullptr);
        }
        
        static void eventDidEnd(EventType theEvent, EventArgs o);
        
        static void notifyListeners(std::string message);
        
        ///	Awake is called when the script instance is being loaded.
        static void Awake();
        ///	This function is called every fixed framerate frame, if the MonoBehaviour is enabled.
        static void FixedUpdate();
        /// LateUpdate is called every frame, if the Behaviour is enabled.
        static void LateUpdate();
        /// Callback for setting up animation IK (inverse kinematics).
        static void OnAnimatorIK();
        ///	Callback for processing animation movements for modifying root motion.
        static void OnAnimatorMove();
        ///	Sent to all game objects when the player gets or loses focus.
        static void OnApplicationFocus();
        /// Sent to all game objects when the player pauses.
        static void OnApplicationPause();
        /// Sent to all game objects before the application is quit.
        static void OnApplicationQuit();
        ///	If OnAudioFilterRead is implemented, Unity will insert a custom filter into the audio DSP chain.
        static void OnAudioFilterRead();
        ///	OnBecameInvisible is called when the renderer is no longer visible by any camera.
        static void OnBecameInvisible();
        /// OnBecameVisible is called when the renderer became visible by any camera.
        static void OnBecameVisible();
        /// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
        static void OnCollisionEnter();
        /// Sent when an incoming collider makes contact with this object's collider (2D physics only).
        static void OnCollisionEnter2D();
        ///	OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
        static void OnCollisionExit();
        /// Sent when a collider on another object stops touching this object's collider (2D physics only).
        static void OnCollisionExit2D();
        /// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
        static void OnCollisionStay();
        ///	Sent each frame where a collider on another object is touching this object's collider (2D physics only).
        static void OnCollisionStay2D();
        /// Called on the client when you have successfully connected to a server.
        static void OnConnectedToServer();
        /// OnControllerColliderHit is called when the controller hits a collider while performing a Move.
        static void OnControllerColliderHit();
        ///	This function is called when the MonoBehaviour will be destroyed.
        static void OnDestroy();
        /// This function is called when the behaviour becomes disabled (); or inactive.
        static void OnDisable();
        /// Called on the client when the connection was lost or you disconnected from the server.
        static void OnDisconnectedFromServer();
        /// Implement OnDrawGizmos if you want to draw gizmos that are also pickable and always drawn.
        static void OnDrawGizmos();
        /// Implement this OnDrawGizmosSelected if you want to draw gizmos only if the object is selected.
        static void OnDrawGizmosSelected();
        /// This function is called when the object becomes enabled and active.
        static void OnEnable();
        /// Called on the client when a connection attempt fails for some reason.
        static void OnFailedToConnect();
        /// Called on clients or servers when there is a problem connecting to the MasterServer.
        static void OnFailedToConnectToMasterServer();
        /// OnGUI is called for rendering and handling GUI events.
        static void OnGUI();
        /// Called when a joint attached to the same game object broke.
        static void OnJointBreak();
        ///	This function is called after a new level was loaded.
        static void OnLevelWasLoaded();
        /// Called on clients or servers when reporting events from the MasterServer.
        static void OnMasterServerEvent();
        ///	OnMouseDown is called when the user has pressed the mouse button while over the GUIElement or Collider.
        static void OnMouseDown();
        /// OnMouseDrag is called when the user has clicked on a GUIElement or Collider and is still holding down the mouse.
        static void OnMouseDrag();
        /// Called when the mouse enters the GUIElement or Collider.
        static void OnMouseEnter();
        /// Called when the mouse is not any longer over the GUIElement or Collider.
        static void OnMouseExit();
        /// Called every frame while the mouse is over the GUIElement or Collider.
        static void OnMouseOver();
        /// OnMouseUp is called when the user has released the mouse button.
        static void OnMouseUp();
        /// OnMouseUpAsButton is only called when the mouse is released over the same GUIElement or Collider as it was pressed.
        static void OnMouseUpAsButton();
        /// Called on objects which have been network instantiated with Network.Instantiate.
        static void OnNetworkInstantiate();
        /// OnParticleCollision is called when a particle hits a collider.
        static void OnParticleCollision();
        /// Called on the server whenever a new player has successfully connected.
        static void OnPlayerConnected();
        /// Called on the server whenever a player disconnected from the server.
        static void OnPlayerDisconnected();
        /// OnPostRender is called after a camera finished rendering the scene.
        static void OnPostRender();
        /// OnPreCull is called before a camera culls the scene.
        static void OnPreCull();
        /// OnPreRender is called before a camera starts rendering the scene.
        static void OnPreRender();
        /// OnRenderImage is called after all rendering is complete to render image.
        static void OnRenderImage();
        /// OnRenderObject is called after camera has rendered the scene.
        static void OnRenderObject();
        /// Used to customize synchronization of variables in a script watched by a network view.
        static void OnSerializeNetworkView();
        /// Called on the server whenever a Network.InitializeServer was invoked and has completed.
        static void OnServerInitialized();
        /// This function is called when the list of children of the transform of the GameObject has changed.
        static void OnTransformChildrenChanged();
        /// This function is called when the parent property of the transform of the GameObject has changed.
        static void OnTransformParentChanged();
        /// OnTriggerEnter is called when the Collider other enters the trigger.
        static void OnTriggerEnter();
        /// Sent when another object enters a trigger collider attached to this object (2D physics only).
        static void OnTriggerEnter2D();
        /// OnTriggerExit is called when the Collider other has stopped touching the trigger.
        static void OnTriggerExit();
        /// Sent when another object leaves a trigger collider attached to this object (2D physics only).
        static void OnTriggerExit2D();
        /// OnTriggerStay is called once per frame for every Collider other that is touching the trigger.
        static void OnTriggerStay();
        /// Sent each frame where another object is within a trigger collider attached to this object (2D physics only).
        static void OnTriggerStay2D();
        /// This function is called when the script is loaded or a value is changed in the inspector (Called in the editor only).
        static void OnValidate();
        /// OnWillRenderObject is called once for each camera if the object is visible.
        static void OnWillRenderObject();
        /// Reset to default values.
        static void Reset();
        /// Start is called on the frame when a script is enabled just before any of the Update methods is called the first time.
        static void Start();
        /// Update is called every frame, if the MonoBehaviour is enabled.
        static void Update();

        
    };
}

