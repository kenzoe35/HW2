#pragma once
explicit Playlist(int capacity);

~Playlist();

bool add_track(const Track& track);

int size() const;

Duration total_length() const;

const Track* find_track(const std::string& title) const;

