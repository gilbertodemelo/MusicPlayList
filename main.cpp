#include <iostream>
#include "Playlist.h"
using namespace std;

int main() {

    Playlist *pl = new Playlist();

    pl->addSongToEnd("Espresso", "Sabrina Carpenter");

    pl->displayList();

}
