/*
 * Copyright 2010 Ullrich Schäfer, Gernot Poetsch for SoundCloud Ltd.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 *
 * For more information and documentation refer to
 * http://soundcloud.com/api
 * 
 */


#define appDelegate ((iPhoneTestAppDelegate *)[[UIApplication sharedApplication] delegate])

@class iPhoneTestAppViewController;
@class SCAccount;

@interface iPhoneTestAppDelegate : NSObject <UIApplicationDelegate, SCSoundCloudAPIAuthenticationDelegate> {
    UIWindow *window;
    iPhoneTestAppViewController *viewController;
    SCAccount *scAccount;
    
    id accountsChangeObserver;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet iPhoneTestAppViewController *viewController;
@property (nonatomic, retain) SCAccount *scAccount;

@end

