//
//  node.h
//  AC4
//
//  Created by Alex Lopez on 11/04/2019.
//  Copyright © 2019 Alex Lopez. All rights reserved.
//

#ifndef node_h
#define node_h

#include "song.h"


typedef struct _node {
    Song song;
    struct _node *next;
} Node;


#endif /* node_h */
