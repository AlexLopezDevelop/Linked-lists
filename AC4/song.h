//
//  song.h
//  AC4
//
//  Created by Alex Lopez on 11/04/2019.
//  Copyright © 2019 Alex Lopez. All rights reserved.
//

#ifndef song_h
#define song_h

#define MAX_STRING  100


typedef struct {
    char name [MAX_STRING];
    int seconds;
} Song;


Song CLI_create_song();


#endif /* song_h */
