#include "duration.h"
#include <iomanip>
#include <ostream>

Duration::Duration(int minutes, int seconds) {
    int total = (minutes * 60) + seconds;
    if (total < 0) {
        m_total_seconds = 0;
    }
    else {
        m_total_seconds = total;
    }
}

int Duration::total_seconds() const {
    // TODO: implement total_seconds
    return m_total_seconds;
}

Duration Duration::operator+(const Duration& other) const {
    // TODO: implement operator+
    return Duration();
}

bool Duration::operator==(const Duration& other) const {
    // TODO: implement operator==
    return m_total_seconds == other.m_total_seconds;
}

std::ostream& operator<<(std::ostream& out, const Duration& d) {
    // TODO: implement operator<<
    int minutes = d.total_seconds() / 60;
    int seconds = d.total_seconds() % 60;
    out << minutes << ":" << std::setfill('0') << std::setw(2) << seconds;
    return out;
}