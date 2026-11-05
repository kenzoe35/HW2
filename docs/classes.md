Duration:

- m_total_seconds: stored the combined duration as single integer of total seconds

In-variants: 
total_seconds can never be negative; any negative values that pass during construction return as 0

+ Duration: constructor that builds duration based off two parameters, minutes and seconds
+ total_seconds: getter for m_total_seconds
+ operator+: adds two duration
+ operator==+: compares and sees if two duration are equal
+ operator<<: function that formats the output as m:ss

Playlist:

- m_tracks: dynamic array pointer for the structure Tracks
- m_count: current number of tracks stored
- m_capacity: the max number of tracks allowed in a playlist

In-variants:
The capacity is always at least 1 (a value below 1 because 1)
The track count cannot exceed the capacity; active tracks are stored starting from 0

+ Playlist: Constructor with capacity safeguard
+ ~Playlist: Destructor that cleans up tracks with the delete[]
+ add_track: Adds a track if it doesn't go past capacity
+ size: Returns the number of tracks in a given playlist
+ total_length: Returns sum of track durations in a playlist using operator+
+ find_track: Searches track by title
