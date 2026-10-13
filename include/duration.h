#pragma once
Duration(int minutes = 0, int seconds = 0);
int total_seconds() const;

Duration operator+(const Duration& other) const;

bool operator==(const Duration& other) const;

std::ostream& operator<<(std::ostream& out, const Duration& d);   // free function
