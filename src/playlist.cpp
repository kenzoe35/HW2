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
    if (m_count >= m_capacity || track.title.empty()) {
        return false;
    }

    // Add track to the end of the array and increment count
    m_tracks[m_count] = track;
    m_count++;

    return true;
}

int Playlist::size() const {
    // TODO: implement size
    return m_count;
}

Duration Playlist::total_length() const {
    // TODO: implement total_length
    Duration total;

    if (m_count == 0) {
        return total;
    }

    for (int i = 0; i < m_count; i++) {
        total = total + m_tracks[i].length;
    }

    return total;
}
const Track* Playlist::find_track(const std::string& title) const {
    // TODO: implement find_track
    return nullptr;
}