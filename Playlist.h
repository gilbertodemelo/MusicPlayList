//
// Created by Gilberto De Melo Junior on 2024-06-27.
//

#ifndef MUSICPLAYLIST_PLAYLIST_H
#define MUSICPLAYLIST_PLAYLIST_H

#include <iostream>
#include "Song.h"
using namespace std;


class Playlist {

private:

    class Node {

    public:
        Song value;
        Node *next;

        Node(Song v) : value(v), next(NULL) {}
    };

    Node *head;
    Node *tail;
    int count;

public:

    // Constructor
    Playlist() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    // Methods
    int size();
    bool isEmpty();
    void addSongToEnd(string, string);
    void addSongToStart(string, string);
    void insertAtPosition(string, string, int);
    void removeByTitle(string);
    void displayList();
    Playlist reversePlayList();
    Song searchByTitle(string);
};


#endif //MUSICPLAYLIST_PLAYLIST_H
