#include "playlist.h"

Playlist::Playlist(int capacity) {
    // TODO: implement constructor
    if (capacity < 1) {
        m_capacity = 1;
    }
    else {
        m_capacity = capacity;
    }
    m_tracks = new Track[m_capacity];
    m_count = 0;
}

Playlist::~Playlist() {
    // TODO: implement destructor
    delete[] m_tracks;
}

bool Playlist::add_track(const Track& track) {
    // TODO: implement add_track
    return false;
}

int Playlist::size() const {
    // TODO: implement size
    return 0;
}

Duration Playlist::total_length() const {
    // TODO: implement total_length
    return Duration();
}

const Track* Playlist::find_track(const std::string& title) const {
    // TODO: implement find_track
    return nullptr;
}