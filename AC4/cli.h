//
//  cli.h
//  AC4
//
//  Created by Alex Lopez on 11/04/2019.
//  Copyright © 2019 Alex Lopez. All rights reserved.
//

#ifndef cli_h
#define cli_h

#include <stdio.h>

#include "song.h" // Struct of Song

// Menu options
#define CLI_MENU_ADD_SONG               1
#define CLI_MENU_REMOVE_CURRENT_SONG    2
#define CLI_MENU_PLAY_NEXT_SONG         3
#define CLI_MENU_PLAY_PREVIOUS_SONG     4
#define CLI_MENU_EXIT                   5

int CLI_menu(); // Get access to call the function

#endif /* cli_h */
