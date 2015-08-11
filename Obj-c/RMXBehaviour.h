//
//  Behaviour.hpp
//  RMXKit
//
//  Created by Max Bilbow on 31/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Behaviour_hpp
#define Behaviour_hpp


#endif /* Behaviour_hpp */


//#define _(x) #x

/*!
 *   @author Max Bilbow, 15-08-04 16:08:16
 *
 *     
 *
 *   @since <#0.1#>
 */
@protocol RMXBehaviour


@property BOOL enabled;


- (id)initWithName:(NSString*)name;

@optional
///	Awake is called when the script instance is being loaded.
- (void)awakeWithArgs:(void*)args;
///	This function is called every fixed framerate frame, if the MonoBehaviour is enabled.
- (void)fixedUpdate:(void*)args;
/// LateUpdate is called every frame, if the Behaviour is enabled.
- (void)lateUpdate:(void*)args;
/// Callback for setting up animation IK (inverse kinematics).
- (void)onAnimatorIK:(void*)args;
///	Callback for processing animation movements for modifying root motion.
- (void)onAnimatorMove:(void*)args;
///	Sent to all game objects when the player gets or loses focus.
- (void)onApplicationFocus:(void*)args;
/// Sent to all game objects when the player pauses.
- (void)onApplicationPause:(void*)args;
/// Sent to all game objects before the application is quit.
- (void)onApplicationQuit:(void*)args;
///	If OnAudioFilterRead is implemented, Unity will insert a custom filter into the audio DSP chain.
- (void)onAudioFilterRead:(void*)args;
///	OnBecameInvisible is called when the renderer is no longer visible by any camera.
- (void)onBecameInvisible:(void*)args;
/// OnBecameVisible is called when the renderer became visible by any camera.
- (void)onBecameVisible:(void*)args;
/// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
- (void)onCollisionEnter:(void*)args;
/// Sent when an incoming collider makes contact with this object's collider (2D physics only).
- (void)onCollisionEnter2D:(void*)args;
///	OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
- (void)onCollisionExit:(void*)args;
/// Sent when a collider on another object stops touching this object's collider (2D physics only).
- (void)onCollisionExit2D:(void*)args;
/// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
- (void)onCollisionStay:(void*)args;
///	Sent each frame where a collider on another object is touching this object's collider (2D physics only).
- (void)onCollisionStay2D:(void*)args;
/// Called on the client when you have successfully connected to a server.
- (void)onConnectedToServer:(void*)args;
/// OnControllerColliderHit is called when the controller hits a collider while performing a Move.
- (void)onControllerColliderHit:(void*)args;
///	This function is called when the MonoBehaviour will be destroyed.
- (void)onDestroy:(void*)args;
/// This function is called when the behaviour becomes disabled :(void*)args; or inactive.
- (void)onDisable:(void*)args;
/// Called on the client when the connection was lost or you disconnected from the server.
- (void)onDisconnectedFromServer:(void*)args;
/// Implement OnDrawGizmos if you want to draw gizmos that are also pickable and always drawn.
- (void)onDrawGizmos:(void*)args;
/// Implement this OnDrawGizmosSelected if you want to draw gizmos only if the object is selected.
- (void)onDrawGizmosSelected:(void*)args;
/// This function is called when the object becomes enabled and active.
- (void)onEnable:(void*)args;
/// Called on the client when a connection attempt fails for some reason.
- (void)onFailedToConnect:(void*)args;
/// Called on clients or servers when there is a problem connecting to the MasterServer.
- (void)onFailedToConnectToMasterServer:(void*)args;
/// OnGUI is called for rendering and handling GUI events.
- (void)onGUI:(void*)args;
/// Called when a joint attached to the same game object broke.
- (void)onJointBreak:(void*)args;
///	This function is called after a new level was loaded.
- (void)onLevelWasLoaded:(void*)args;
/// Called on clients or servers when reporting events from the MasterServer.
- (void)onMasterServerEvent:(void*)args;
///	OnMouseDown is called when the user has pressed the mouse button while over the GUIElement or Collider.
- (void)onMouseDown:(void*)args;
/// OnMouseDrag is called when the user has clicked on a GUIElement or Collider and is still holding down the mouse.
- (void)onMouseDrag:(void*)args;
/// Called when the mouse enters the GUIElement or Collider.
- (void)onMouseEnter:(void*)args;
/// Called when the mouse is not any longer over the GUIElement or Collider.
- (void)onMouseExit:(void*)args;
/// Called every frame while the mouse is over the GUIElement or Collider.
- (void)onMouseOver:(void*)args;
/// OnMouseUp is called when the user has released the mouse button.
- (void)onMouseUp:(void*)args;
/// OnMouseUpAsButton is only called when the mouse is released over the same GUIElement or Collider as it was pressed.
- (void)onMouseUpAsButton:(void*)args;
/// Called on objects which have been network instantiated with Network.Instantiate.
- (void)onNetworkInstantiate:(void*)args;
/// OnParticleCollision is called when a particle hits a collider.
- (void)onParticleCollision:(void*)args;
/// Called on the server whenever a new player has successfully connected.
- (void)onPlayerConnected:(void*)args;
/// Called on the server whenever a player disconnected from the server.
- (void)onPlayerDisconnected:(void*)args;
/// OnPostRender is called after a camera finished rendering the scene.
- (void)onPostRender:(void*)args;
/// OnPreCull is called before a camera culls the scene.
- (void)onPreCull:(void*)args;
/// OnPreRender is called before a camera starts rendering the scene.
- (void)onPreRender:(void*)args;
/// OnRenderImage is called after all rendering is complete to render image.
- (void)onRenderImage:(void*)args;
/// OnRenderObject is called after camera has rendered the scene.
- (void)onRenderObject:(void*)args;
/// Used to customize synchronization of variables in a script watched by a network view.
- (void)onSerializeNetworkView:(void*)args;
/// Called on the server whenever a Network.InitializeServer was invoked and has completed.
- (void)onServerInitialized:(void*)args;
/// This function is called when the list of children of the transform of the GameObject has changed.
- (void)onTransformChildrenChanged:(void*)args;
/// This function is called when the parent property of the transform of the GameObject has changed.
- (void)onTransformParentChanged:(void*)args;
/// OnTriggerEnter is called when the Collider other enters the trigger.
- (void)onTriggerEnter:(void*)args;
/// Sent when another object enters a trigger collider attached to this object (2D physics only).
- (void)onTriggerEnter2D:(void*)args;
/// OnTriggerExit is called when the Collider other has stopped touching the trigger.
- (void)onTriggerExit:(void*)args;
/// Sent when another object leaves a trigger collider attached to this object (2D physics only).
- (void)onTriggerExit2D:(void*)args;
/// OnTriggerStay is called once per frame for every Collider other that is touching the trigger.
- (void)onTriggerStay:(void*)args;
/// Sent each frame where another object is within a trigger collider attached to this object (2D physics only).
- (void)onTriggerStay2D:(void*)args;
/// This function is called when the script is loaded or a value is changed in the inspector (Called in the editor only).
- (void)onValidate:(void*)args;
/// OnWillRenderObject is called once for each camera if the object is visible.
- (void)onWillRenderObject:(void*)args;
/// Reset to default values.
- (void)reset:(void*)args;
/// Start is called on the frame when a script is enabled just before any of the Update methods is called the first time.
- (void)start:(void*)args;
/// Update is called every frame, if the MonoBehaviour is enabled.
- (void)update:(void*)args;
///	Awake is called when the script instance is being loaded.
    
@end
