//
//  cli.c
//  AC4
//
//  Created by Alex Lopez on 11/04/2019.
//  Copyright © 2019 Alex Lopez. All rights reserved.
//

#include "cli.h"


int CLI_menu() {
    
    // Inicialize variables
    int option;
    
    
    //Print menu
    printf("\n_.- ESDM Music -._\n\n");
    printf("1. Add Song\n");
    printf("2. Remove Current Song\n");
    printf("3. Play Next Song\n");
    printf("4. Play Previous Song\n");
    printf("\n");
    printf("5. Salir\n");
    printf("\n");
    printf("Enter an option: ");
    //User selected option
    scanf("%d", &option);
    
    
    return option;
}
