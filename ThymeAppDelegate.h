//
//  ThymeAppDelegate.h
//  Thyme
//
//  Created by João Moreno on 2/8/10.
//

#import <Cocoa/Cocoa.h>
#import "DDHotKeyCenter.h"
#import "Stopwatch.h"

@interface ThymeAppDelegate : NSObject <NSApplicationDelegate, NSUserNotificationCenterDelegate, StopwatchDelegate>
{
    // Timer
    Stopwatch* stopwatch;
    
    // Hotkeys
    DDHotKeyCenter *hotKeyCenter;
    
    // Interface
    NSWindow *window;
    NSPersistentStoreCoordinator *persistentStoreCoordinator;
    NSManagedObjectModel *managedObjectModel;
    NSManagedObjectContext *managedObjectContext;
    
    NSStatusItem *statusItem;
    NSMenu *menu;
    NSMenuItem *startStopItem;
    NSMenuItem *resetItem;
    
    NSMenuItem *sessionsMenuSeparator;
    NSMenuItem *sessionsMenuClearItem;
    NSMutableArray *sessionsMenuItems;
}

@property(nonatomic, retain) Stopwatch *stopwatch;

@property(retain) DDHotKeyCenter *hotKeyCenter;

@property(nonatomic, retain) IBOutlet NSWindow *window;
@property(nonatomic, retain, readonly) IBOutlet NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property(nonatomic, retain, readonly) IBOutlet NSManagedObjectModel *managedObjectModel;
@property(nonatomic, retain, readonly) IBOutlet NSManagedObjectContext *managedObjectContext;

@property(retain) NSStatusItem *statusItem;
@property(nonatomic, retain) IBOutlet NSMenu *menu;
@property(nonatomic, retain) IBOutlet NSMenuItem *startStopItem;
@property(nonatomic, retain) IBOutlet NSMenuItem *resetItem;

@property(nonatomic, retain) NSMenuItem *sessionsMenuSeparator;
@property(nonatomic, retain) NSMenuItem *sessionsMenuClearItem;
@property(nonatomic, retain) NSMutableArray *sessionsMenuItems;

- (void)startWithNotification:(Boolean)notification;
- (void)pauseWithNotification:(Boolean)notification;
- (void)toggleWithNotification:(Boolean)notification;
- (void)stopWithNotification:(Boolean)notification;

- (IBAction)saveAction:sender;
- (IBAction)startStop:(id)sender;
- (IBAction)reset:(id)sender;

@end