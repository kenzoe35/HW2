#pragma once
class Duration {
public:
    // your constructor, total_seconds, operator+, operator==
private:
    int total_seconds_;
};

struct Track {
    std::string title;
    Duration length;
};

class Playlist {
public:
    // your constructor, destructor, add_track, size, total_length, find_track

    // Copy these two lines exactly. Copying is not covered yet; deleting
    // them keeps two Playlists from sharing one array and freeing it twice.
    Playlist(const Playlist&) = delete;
    Playlist& operator=(const Playlist&) = delete;

private:
    Track* tracks_;
    int count_;
    int capacity_;
};
