//
//  plist.c
//  AC4
//
//  Created by Alex Lopez on 11/04/2019.
//  Copyright © 2019 Alex Lopez. All rights reserved.
//

#include <stdlib.h>

#include "plist.h"


Playlist PLIST_create() {
    Playlist playlist;
    
    //Create phantom node
    playlist.first = (Node *) malloc(sizeof(Node));
    if (playlist.first == NULL) {
        // Error
    } else {
        playlist.last = playlist.first;
        playlist.last->next = NULL;
    }
    
    return playlist;
}

int PLIST_insert(Playlist * playlist, Song song) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        return 0; //Error
    } else {
        node->song = song;
        node->next = playlist->last->next;
        playlist->last->next = node;
        playlist->last = node;
    }
    
    return 1;
}

int PLIST_remove(Playlist * playlist) {
    Node * tmp = playlist->last;
    
    if (playlist->last == playlist->first->next && playlist->last->next == NULL) { // Only one node
        playlist->first->next = NULL;
        playlist->last = playlist->first;
        
    } else if (playlist->last == playlist->first->next) { // delete first node
        
        playlist->last = playlist->first;
        printf("text: %s", playlist->last->song.name);
        playlist->last->next = playlist->last->next->next;
        playlist->last = playlist->last->next;
        free(tmp);
        
    } else if (playlist->last->next != NULL) { // Middle nodes
        
        PLIST_previous(playlist);
        playlist->last->next = playlist->last->next->next;
        free(tmp);
        
    } else { // Last node
        
        PLIST_previous(playlist); // = playlist->last -1, point to previous node
        playlist->last->next = NULL;
    }
    
    return 1;
}

int PLIST_next(Playlist * playlist) {
    if (playlist->last->next == NULL) {
        
        playlist->last = playlist->first->next;
        
    } else {
        
        playlist->last = playlist->last->next;
    }
    
    return 1;
}

void PLIST_go_last(Playlist * playlist) {
    
    if (playlist->last != NULL) {
        
        while(playlist->last->next != NULL) {
            playlist->last = playlist->last->next;
        }
    }
}

int PLIST_previous(Playlist * playlist) {
    
    if (playlist->last == playlist->first->next) {
        PLIST_go_last(playlist);
        return 1;
    }
    
    Node* node = playlist->first;
    
    while ( node->next != playlist->last ) {
        node = node->next;
    }
    
    playlist->last = node;
    
    return 1;
}

Song PLIST_get(Playlist playlist) {
    Song song;
    
    if (playlist.last->next == NULL) {
        return song;
    }
    
    return playlist.last->next->song;
}

void PLIST_go_first(Playlist * playlist) {
    playlist->last = playlist->first;
}

int PLIST_is_empty(Playlist playlist) {
    return playlist.first->next == NULL;
}

void PLIST_destroy(Playlist * playlist) {
    PLIST_go_first(playlist);
    
    while (!PLIST_is_empty(*playlist)) {
        PLIST_remove(playlist);
    }
    
    free(playlist->first); // Delete phantom
    playlist->first = playlist->last = NULL;
}
