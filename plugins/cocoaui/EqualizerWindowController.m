//
//  EqualizerWindowController.m
//  DeaDBeeF
//
//  Created by Alexey Yakovenko on 1/29/20.
//  Copyright © 2020 Alexey Yakovenko. All rights reserved.
//

#import "EqualizerWindowController.h"
#import "PropertySheetViewController.h"
#include "deadbeef.h"

extern DB_functions_t *deadbeef;

@interface EQPropertySheetDataSource : NSObject<PropertySheetDataSource>

@property (nonatomic,unsafe_unretained,readonly) ddb_dsp_context_t *supereq;

@end

@implementation EQPropertySheetDataSource

- (NSString *)propertySheet:(PropertySheetViewController *)vc configForItem:(id)item {
    return @"property \"\" hbox[19] hmg fill expand border=0 spacing=8 height=200;\n"
    "property \"Preamp\" vscale[20,-20,0.5] vert 0 0;\n"
    "property \"55 Hz\" vscale[20,-20,0.5] vert 1 0;\n"
    "property \"77 Hz\" vscale[20,-20,0.5] vert 2 0;\n"
    "property \"110 Hz\" vscale[20,-20,0.5] vert 3 0;\n"
    "property \"156 Hz\" vscale[20,-20,0.5] vert 4 0;\n"
    "property \"220 Hz\" vscale[20,-20,0.5] vert 5 0;\n"
    "property \"311 Hz\" vscale[20,-20,0.5] vert 6 0;\n"
    "property \"440 Hz\" vscale[20,-20,0.5] vert 7 0;\n"
    "property \"622 Hz\" vscale[20,-20,0.5] vert 8 0;\n"
    "property \"880 Hz\" vscale[20,-20,0.5] vert 9 0;\n"
    "property \"1.2 kHz\" vscale[20,-20,0.5] vert 10 0;\n"
    "property \"1.8 kHz\" vscale[20,-20,0.5] vert 11 0;\n"
    "property \"2.5 kHz\" vscale[20,-20,0.5] vert 12 0;\n"
    "property \"3.5 kHz\" vscale[20,-20,0.5] vert 13 0;\n"
    "property \"5 kHz\" vscale[20,-20,0.5] vert 14 0;\n"
    "property \"7 kHz\" vscale[20,-20,0.5] vert 15 0;\n"
    "property \"10 kHz\" vscale[20,-20,0.5] vert 16 0;\n"
    "property \"14 kHz\" vscale[20,-20,0.5] vert 17 0;\n"
    "property \"20 kHz\" vscale[20,-20,0.5] vert 18 0;\n";
}

- (ddb_dsp_context_t *)supereq {
    ddb_dsp_context_t *dsp = deadbeef->streamer_get_dsp_chain ();
    while (dsp) {
        if (!strcmp (dsp->plugin->plugin.id, "supereq")) {
            return dsp;
        }
        dsp = dsp->next;
    }

    return NULL;
}

- (NSString *)propertySheet:(PropertySheetViewController *)vc valueForKey:(NSString *)key def:(NSString *)def item:(id)item {
    ddb_dsp_context_t *eq = self.supereq;
    if (!eq) {
        return def;
    }

    char str[200];
    eq->plugin->get_param (eq, key.intValue, str, sizeof (str));
    return [NSString stringWithUTF8String:str];
}

- (void)propertySheet:(PropertySheetViewController *)vc setValue:(NSString *)value forKey:(NSString *)key item:(id)item {
    ddb_dsp_context_t *eq = self.supereq;
    if (!eq) {
        return;
    }

    eq->plugin->set_param (eq, key.intValue, value.UTF8String);
    deadbeef->streamer_dsp_chain_save ();
}

- (void)propertySheetBeginChanges {
}

- (void)propertySheetCommitChanges {
}

@end

#pragma mark -

@interface EqualizerView : NSView

@property (nonatomic) NSSize calculatedSize;

@end

@implementation EqualizerView

- (NSSize)intrinsicContentSize {
    return self.calculatedSize;

}

@end

#pragma mark -

@interface EqualizerWindowController ()

@property (strong) IBOutlet PropertySheetViewController *propertySheetViewController;

@property (nonatomic) EQPropertySheetDataSource *propertySheetDataSource;

@property (weak) IBOutlet EqualizerView *equalizerView;

@property (nonatomic) BOOL enabled;

@end

@implementation EqualizerWindowController

- (void)windowDidLoad {
    [super windowDidLoad];

    self.propertySheetViewController.labelFontSize = 10;
    self.propertySheetViewController.contentFontSize = 11;
    self.propertySheetViewController.unitSpacing = 4;
    self.propertySheetViewController.autoAlignLabels = NO;
    self.propertySheetViewController.labelFixedWidth = 120;
    self.propertySheetDataSource = [EQPropertySheetDataSource new];
    self.propertySheetViewController.dataSource = self.propertySheetDataSource;

    self.equalizerView.calculatedSize = self.propertySheetViewController.calculatedSize;
    [self.equalizerView invalidateIntrinsicContentSize];

    [self willChangeValueForKey:@"enabled"];
    [self didChangeValueForKey:@"enabled"];
}

- (IBAction)zeroAllAction:(id)sender {
    for (int i = 0; i < 19; i++) {
        [self.propertySheetDataSource propertySheet:self.propertySheetViewController setValue:@"0" forKey:[NSString stringWithFormat:@"%d", i] item:nil];
    }
    [self.propertySheetViewController reload];
}

- (IBAction)zeroPreampAction:(id)sender {
    [self.propertySheetDataSource propertySheet:self.propertySheetViewController setValue:@"0" forKey:@"0" item:nil];
    [self.propertySheetViewController reload];
}

- (IBAction)zeroBandsAction:(id)sender {
    for (int i = 1; i < 19; i++) {
        [self.propertySheetDataSource propertySheet:self.propertySheetViewController setValue:@"0" forKey:[NSString stringWithFormat:@"%d", i] item:nil];
    }
    [self.propertySheetViewController reload];
}

- (void)setEnabled:(BOOL)enabled {
    ddb_dsp_context_t *eq = self.propertySheetDataSource.supereq;
    if (!eq) {
        return;
    }

    eq->enabled = enabled;
}

- (BOOL)enabled {
    ddb_dsp_context_t *eq = self.propertySheetDataSource.supereq;
    if (!eq) {
        return NO;
    }

    return eq->enabled;
}

@end
