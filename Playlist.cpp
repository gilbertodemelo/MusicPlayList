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
    if (index < 1 || index > size() + 1) {
        cout << "Invalid index." << endl;
        return;
    }

    // Create song object
    Song newSong(t, a);
    Node* newNode = new Node(newSong);

    if (index == 1) {
        // Insert at the head
        newNode->next = head;
        head = newNode;
    } else {
        Node* nodePtr = head;
        for (int pos = 1; pos < index - 1; pos++) {
            if (nodePtr->next == nullptr)
                break;
            nodePtr = nodePtr->next;
        }
        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
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
        int number = 1;
        while(nodePtr != nullptr) {
            cout << "\n" << number << ".Title: " << nodePtr->value.getTitle() << "\n" << "  Artist: " << nodePtr->value.getArtist() << endl;
            nodePtr = nodePtr->next;
            number++;
        }
        cout << "\n";
    }

}


Playlist Playlist::reversePlayList() {

    Playlist *reverse = new Playlist();

    Node *nodePtr = head;
    while(nodePtr) {
        reverse->addSongToStart(nodePtr->value.getTitle(), nodePtr->value.getArtist());
        nodePtr = nodePtr->next;
    }

    return *reverse;

}
