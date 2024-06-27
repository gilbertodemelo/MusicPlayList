//
// Created by Gilberto De Melo Junior on 2024-06-27.
//

#ifndef MUSICPLAYLIST_SONG_H
#define MUSICPLAYLIST_SONG_H

#include <iostream>
using namespace std;

class Song {

private:
    string title;
    string artist;

public:
    // Constructor
    Song(string t, string a);

    // Setters
    void setTitle(string);
    void setArtist(string);

    // Getters
    string getTitle() const;
    string getArtist() const;
};


#endif //MUSICPLAYLIST_SONG_H
