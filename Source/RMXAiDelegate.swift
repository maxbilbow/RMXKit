//
//  RMXAiDelegate.swift
//  AiScene
//
//  Created by Max Bilbow on 08/06/2015.
//  Copyright (c) 2015 Rattle Media. All rights reserved.
//

import Foundation





@available(OSX 10.10, *)
public protocol RMXAiDelegate : NSObjectProtocol {
    var state: String? { get }
    var args: [RMXSpriteType] { get }
    var pawnLogic: [AiBehaviour] { get }
    var pawn: RMXPawn { get }
    init(pawn: RMXPawn)
    func run(sender: AnyObject?, updateAtTime time: NSTimeInterval) -> Void
    func getTarget(args: RMXSpriteType ...) -> RMXPawn?
}

@available(OSX 10.10, *)
class RMXAi : NSObject, RMXAiDelegate {
    
    private var _state: String?
    
    func setState(state: String?) {
        self._state = state
    }
    
    var state: String? {
        return self.state
    }
    
    var world: RMXWorld {
        return self.pawn.world
    }
    
    var args: [RMXSpriteType] {
        return [ RMXSpriteType.PASSIVE ]
    }
    
    var pawnLogic: [AiBehaviour] {
        return self.pawn.logic
    }
    
    private var _pawn: RMXPawn
    
    var pawn: RMXPawn {
        return _pawn
    }
    
    required init(pawn: RMXPawn) {
        _pawn = pawn
        super.init()
    }
    
    func getTarget(args: RMXSpriteType ...) -> RMXPawn? {
        return RMXAi.randomSprite(self.world, not: self.pawn, type: args.count == 0 ? self.args : args)
    }
    
    func run(sender: AnyObject?, updateAtTime time: NSTimeInterval) {
//        if !self.sprite.paused {
            for logic in self.pawnLogic {
                logic(self.pawn)
            }
//            self.pawn.timer?.activate(sender)
//        }
    }
    
    class func randomSprite(world: RMXWorld, not: RMXPawn, type: [RMXSpriteType]?) -> RMXPawn? {
        if let types = type {
            let array: Array<AnyObject> = world.pawns.filter { (child) -> Bool in
                for type in types {
                    if (child as? RMXPawn)?.type == type && (child as? RMXPawn)?.rmxID != not.rmxID {
                        return true
                    }
                }
                return false
            }
            return array.count == 0 ? nil : array[random() % array.count] as? RMXPawn
        }
        return nil
    }
    
}