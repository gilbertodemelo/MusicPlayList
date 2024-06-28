//
// Created by Gilberto De Melo Junior on 2024-06-27.
//

#include "Playlist.h"


bool Playlist::isEmpty() {
    return count == 0;
}

int Playlist::size() {
    return count;
}

void Playlist::addSongToEnd(string t, string a) {

    // Create a new Song
    Song newSong(t, a);

    Node *newNode;
    Node *nodePtr;

    // Allocate a new node and store song info there
    // The new node already points to a null pointer
    newNode = new Node(newSong);

    if(isEmpty()) {
        head = newNode;
    } else {
        nodePtr = head;
        while(nodePtr->next) // or nodePtr->next != nullptr/NULL
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
    count++;
}

void Playlist::addSongToStart(string t, string a) {

    // Create a new Song object
    Song newSong(t, a);

    Node *newNode;

    newNode = new Node(newSong);

    if(isEmpty()) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;

    }
    count++;
}
