#include "playlist.h"
#include  <iostream>

Playlist::Playlist(int capacity) {
    if (capacity < 1) {
        capacity_ = 1;
    }
    else {
        capacity_ = capacity;
    }
    tracks_ = new Track[capacity_];
    count_ = 0;
}

Playlist::~Playlist() {
    delete[] tracks_;
}

bool Playlist::add_track(const Track& track) {
    if (count_ >= capacity_ || track.title.empty()) {
        return false;
    }

    tracks_[count_] = track;
    count_++;

    return true;
}

int Playlist::size() const {
    return count_;
}

Duration Playlist::total_length() const {
    Duration total;

    if (count_ == 0) {
        return total;
    }

    for (int i = 0; i < count_; i++) {
        total = total + tracks_[i].length;
    }

    return total;
}

const Track* Playlist::find_track(const std::string& title) const {
    for (int i = 0; i < count_; i++) {
        if (tracks_[i].title == title) {
            return &tracks_[i];
        }
    }
    return nullptr;
}