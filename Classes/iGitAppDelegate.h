//
//  iGitAppDelegate.h
//  iGit
//
//  Created by Scott Chacon on 8/14/08.
//  Copyright __MyCompanyName__ 2008. All rights reserved.
//

#import <UIKit/UIKit.h>

@class iGitViewController;

@interface iGitAppDelegate : NSObject <UIApplicationDelegate> {
	IBOutlet UIWindow *window;
	IBOutlet iGitViewController *viewController;
	IBOutlet GitServer			*_server;
	NSInputStream*		_inStream;
	NSOutputStream*		_outStream;
	BOOL				_inReady;
	BOOL				_outReady;	
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) iGitViewController *viewController;
-(void) setup;

@end

