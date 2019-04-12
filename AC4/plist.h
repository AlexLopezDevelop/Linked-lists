//
//  plist.h
//  AC4
//
//  Created by Alex Lopez on 11/04/2019.
//  Copyright © 2019 Alex Lopez. All rights reserved.
//

#ifndef plist_h
#define plist_h

#include <stdio.h>

#include "song.h"
#include "playlist.h"


Playlist PLIST_create(void);

int PLIST_insert(Playlist *, Song);

int PLIST_remove(Playlist *);

int PLIST_next(Playlist *);

int PLIST_previous(Playlist *);

Song PLIST_get(Playlist);

void PLIST_destroy(Playlist *);


#endif /* plist_h */
