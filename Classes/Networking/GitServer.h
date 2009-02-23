/*

File: GitServer.h
Abstract: A Git server that listens on .

Version: 1.5

*/

#import <Foundation/Foundation.h>

//CLASSES:

@class GitServer;

//ERRORS:

NSString * const GitServerErrorDomain;

typedef enum {
    kGitServerCouldNotBindToIPv4Address = 1,
    kGitServerCouldNotBindToIPv6Address = 2,
    kGitServerNoSocketsAvailable = 3,
} GitServerErrorCode;

//PROTOCOLS:

@protocol GitServerDelegate <NSObject>
@optional
- (void) serverDidEnableBonjour:(GitServer*)server withName:(NSString*)name;
- (void) server:(GitServer*)server didNotEnableBonjour:(NSDictionary *)errorDict;
- (void) didAcceptConnectionForServer:(GitServer*)server inputStream:(NSInputStream *)istr outputStream:(NSOutputStream *)ostr;
@end

//CLASS INTERFACES:

@interface GitServer : NSObject {
@private
	id _delegate;
    uint16_t _port;
	CFSocketRef _ipv4socket;
	NSNetService* _netService;
}
	
- (BOOL)start:(NSError **)error;
- (BOOL)stop;
- (BOOL) enableBonjourWithDomain:(NSString*)domain applicationProtocol:(NSString*)protocol name:(NSString*)name; //Pass "nil" for the default local domain - Pass only the application protocol for "protocol" e.g. "myApp"
- (void) disableBonjour;

@property(assign) id<GitServerDelegate> delegate;

+ (NSString*) bonjourTypeFromIdentifier:(NSString*)identifier;

@end
