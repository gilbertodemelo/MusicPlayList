#include <iostream>
#include "Playlist.h"
using namespace std;

int main() {

    Playlist *pl = new Playlist();

    pl->addSongToEnd("Espresso", "Sabrina Carpenter");
    pl->addSongToEnd("Cruel Summer", "Taylor Swift");
    pl->addSongToStart("Standing Next to You", "Jung Kook");
    pl->insertAtPosition("Alcohol Free", "Twice", 2);
    pl->insertAtPosition("Windy Summer", "Anri", 3);

    pl->displayList();

    pl->removeByTitle("Cruel Summer");

    pl->displayList();

}
