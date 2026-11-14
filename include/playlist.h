#pragma once
#include "track.h"
#include "duration.h"

class Playlist {
public:
    // your constructor, destructor, add_track, size, total_length, find_track
    explicit Playlist(int capacity);

    ~Playlist();

    bool add_track(const Track& track);

    int size() const;

    Duration total_length() const;

    const Track* find_track(const std::string& title) const;

    // Copy these two lines exactly. Copying is not covered yet; deleting
    // them keeps two Playlists from sharing one array and freeing it twice.
    Playlist(const Playlist&) = delete;
    Playlist& operator=(const Playlist&) = delete;

private:
    Track* tracks_;
    int count_;
    int capacity_;
};


