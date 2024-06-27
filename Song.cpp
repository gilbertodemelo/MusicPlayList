//
// Created by Gilberto De Melo Junior on 2024-06-27.
//

#include "Song.h"

// Constructor
Song::Song(string t, string a) {
    title = t;
    artist = a;
}

// Setters
void Song::setTitle(string t) { title = t; }
void Song::setArtist(string a) { artist = a; }

// Getters
string Song::getTitle() const { return title; }
string Song::getArtist() const { return artist; }

