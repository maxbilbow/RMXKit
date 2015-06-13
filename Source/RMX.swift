//
//  RMX.swift
//  RattleGL
//
//  Created by Max Bilbow on 17/03/2015.
//  Copyright (c) 2015 Rattle Media. All rights reserved.
//

import Foundation
import SceneKit

//public typealias RMXNode = SCNNode
public typealias AiBehaviour = (AnyObject!) -> Void

public enum AiState { case MOVING, TURNING, IDLE }
public enum PoppyState: Int32 { case IDLE = 1, READY_TO_CHASE , CHASING, FETCHING }
public enum RMXSpriteType: Int { case  AI = 0, PLAYER, BACKGROUND, PASSIVE, ABSTRACT, KINEMATIC, CAMERA }
public enum ShapeType: Int { case CUBE , SPHERE, CYLINDER,  OILDRUM, BOBBLE_MAN, LAST,ROCK,SPACE_SHIP, PILOT,  PLANE, FLOOR, DOG, AUSFB,PONGO, NULL, SUN, CAMERA }
public enum KeyboardType { case French, UK, DEFAULT }

@available(OSX 10.10, *)
public struct RMX {

    static var COUNT: Int = 0
}


public protocol RMXObject {
    var name: String? { get }
    var rmxID: Int? { get }
    var uniqueID: String? { get }
    var print: String { get }
    
}


public struct RMKeyValue {
    static let name   = "name"
    static let Sprite = "Sprite"
    static let Health = "health"
    static let Points = "points"
    static let Kills  = "kills"
    static let Deaths = "deaths"
}



