//
//  main.c
//  AC4
//
//  Created by Alex Lopez on 11/04/2019.
//  Copyright © 2019 Alex Lopez. All rights reserved.
//

#include <stdio.h>

//Including Modular Files
#include "cli.h"
#include "plist.h"
#include "song.h"


int main() {
    
    Song song;
    Playlist playlist;
    
    int option;
    
    
    playlist = PLIST_create();
    
    do {
        option = CLI_menu();
        
        switch (option) {
            case CLI_MENU_ADD_SONG:
                
                song = CLI_create_song(); // Get Song data from user
                
                PLIST_insert(&playlist, song);
                
                printf("\nNow Playing: '%s' [%d seconds]\n\n", playlist.last->song.name, playlist.last->song.seconds);
                
                break;
                
            case CLI_MENU_REMOVE_CURRENT_SONG:
                
                if (playlist.last == playlist.first) { // Empty
                    
                    printf("\nEmpty nothing to delete\n\n");
                    break;
                    
                }
                
                    printf("\n'%s' removed.\n", playlist.last->song.name, playlist.last->song.seconds);
                    
                    PLIST_remove(&playlist);
                    
                    if (playlist.last == playlist.first) { // Empty
                        
                        printf("\nEmpty\n\n");
                        
                    } else {
                        
                        printf("\nNow Playing: '%s' [%d seconds]\n\n", playlist.last->song.name, playlist.last->song.seconds);
                    }
                
                break;
                
            case CLI_MENU_PLAY_NEXT_SONG:
                
                if (playlist.last == playlist.first) { // Empty
                    
                    printf("\nEmpty nothing to play\n\n");
                    break;
                    
                }
                    
                    PLIST_next(&playlist);
                    
                    printf("\nNow Playing: '%s' [%d seconds]\n\n", playlist.last->song.name, playlist.last->song.seconds);
                
                break;
                
            case CLI_MENU_PLAY_PREVIOUS_SONG:
                
                if (playlist.last == playlist.first) { // Empty
                    
                    printf("\nEmpty nothing to play\n\n");
                    break;
                    
                }
                    
                    PLIST_previous(&playlist);
                    
                    printf("\nNow Playing: '%s' [%d seconds]\n\n", playlist.last->song.name, playlist.last->song.seconds);

                
                break;
                
            case CLI_MENU_EXIT:
                printf("Bye!\n");
                break;
        }
        
    } while(option != CLI_MENU_EXIT);
    
    return 1;
}
