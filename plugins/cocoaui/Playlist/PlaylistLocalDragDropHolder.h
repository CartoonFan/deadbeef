//
//  PlaylistLocalDragDropHolder.h
//  DeaDBeeF
//
//  Created by Alexey Yakovenko on 2/1/20.
//  Copyright © 2020 Alexey Yakovenko. All rights reserved.
//

#include "deadbeef.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PlaylistLocalDragDropHolder
    : NSObject <NSPasteboardReading, NSPasteboardWriting, NSSecureCoding>

@property(nonatomic) NSInteger playlistIdx;
@property(nonatomic) NSArray *itemsIndices;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithSelectedItemsOfPlaylist:(ddb_playlist_t *)playlist;

@end

NS_ASSUME_NONNULL_END
