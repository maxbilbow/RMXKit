/*
 *  RMXKit.h
 *  RMXKit
 *
 *  Created by Max Bilbow on 28/07/2015.
 *  Copyright © 2015 Rattle Media Ltd. All rights reserved.
 *
 */
extern "C" {
#include <CoreFoundation/CoreFoundation.h>


#pragma GCC visibility push(default)

/* External interface to the RMXKit, C-based */

CFStringRef RMXKitUUID(void);

#pragma GCC visibility pop
}

#define as_string(x) #x



#import "LinkedList.h"
#import "Dictionary.h"
#import "NotificationCenter.h"
#import "Object.h"
#import "ASingleton.h"
//#import "Behaviour.hpp"

/*
 *   @author Max Bilbow, 15-08-04 16:08:32
 *
 *   @brief RMXKit.h
 *   RMXKit
 *   @since <#0.1#>
 *
 *   Created by Max Bilbow on 28/07/2015.
 *   Copyright © 2015 Max Bilbow. All rights reserved.
 *
 */