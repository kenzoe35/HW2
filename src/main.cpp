#include <iostream>
#include "playlist.h"
#include "track.h"
#include "duration.h"

int main() { 
	// Create a playlist with a maximum of 4 tracks
	Playlist p(4);

	// Create an array of 5 tracks
	Track tracks[5] = {
		Track("Midnight Drive", Duration(3, 42)),
		Track("Neon Rain", Duration(4, 5)),
		Track("Static", Duration(2, 58)),
		Track("Low Tide", Duration(5, 11)),
		Track("Overflow", Duration(3, 30))
	};

	// Add each track into playlist and print whether it was added or refused
	for (int i = 0; i < 5; ++i) {
		if (p.add_track(tracks[i])) {
			std::cout << "Added " << tracks[i].title << " (" << tracks[i].length << ")\n";
		}
		else {
			std::cout << "Refused " << tracks[i].title << " (playlist full)\n";
		}
	}

	// Print track count and total length
	std::cout << "Tracks: " << p.size() << "\n";
	std::cout << "Total length: " << p.total_length() << "\n";

	// Find "Static"
	const Track* found = p.find_track("Static");
	if (found != nullptr) {
		std::cout << "Found \"" << found->title << "\" at " << found->length << "\n";
	}

	// Look up a title that is not there
	std::string missing_title = "Missing";
	if (p.find_track(missing_title) == nullptr) {
		std::cout << "\"" << missing_title << "\" is not in the playlist.\n";
	}
	return 0; 
}
