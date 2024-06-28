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

void Playlist::insertAtPosition(string t, string a, int index) {

    if (index <= 0 || index > size()) {
        cout << "Invalid index." << endl;
    } else {

        // Create song object
        Song newSong(t, a);

        Node *newNode;
        Node *nodePtr;
        int pos = 1;

        newNode = new Node(newSong);

        if(isEmpty()) {
            addSongToStart(t, a);
        } else {

            nodePtr = head;
            while(nodePtr->next &&  pos < index) {
                nodePtr = nodePtr->next;
                pos++;
            }

            newNode->next = nodePtr->next;
            nodePtr->next = newNode;
        }



    }
    count++;
}

void Playlist::removeByTitle(string title) {

    if(isEmpty()) {
        cout << "Empty list." << endl;
    } else {

        Node *nodePtr = head;
        Node *temp = nullptr;

        while (nodePtr->next && nodePtr->next->value.getTitle() != title)
            nodePtr = nodePtr->next;

        temp = nodePtr->next;
        nodePtr->next = nodePtr->next->next;
        temp = nullptr;

    }
    count--;
}


void Playlist::displayList() {

    if(isEmpty()) {
        cout << "Empty list." << endl;
    } else {
        Node *nodePtr = head;
        while(nodePtr != nullptr) {
            cout << "Title: " << nodePtr->value.getTitle() << "\n" << "Artist: " << nodePtr->value.getArtist() << endl;
            nodePtr = nodePtr->next;
        }
        cout << "\n";
    }

}
