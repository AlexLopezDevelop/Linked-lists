//
//  song.c
//  AC4
//
//  Created by Alex Lopez on 11/04/2019.
//  Copyright © 2019 Alex Lopez. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "song.h"


Song createSong(char name[MAX_STRING], int duration) {
    Song song;
    
    strcpy(song.name, name);
    song.seconds = duration;
    
    return song;
}

Song CLI_create_song() {
    char nameSong [MAX_STRING];
    int durationSong;
    
    printf("\nEnter the song's name: ");
    scanf("%s", &nameSong);
    printf("Enter the song's duration: ");
    scanf("%d", &durationSong);
    
    return createSong(nameSong, durationSong);
}

