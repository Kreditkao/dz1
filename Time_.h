#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Time_ {
    int hours;
    int minutes;
    bool format; // true = UTC (24-hours), false = AM/PM (12-hours)

public:
    Time_() {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);
        hours = ltm.tm_hour;
        minutes = ltm.tm_min;
        format = true;
    }

    Time_(int hours, int minutes, bool format = true)
        : hours(hours), minutes(minutes), format(format) {}

    void setHour(int hours) { this->hours = hours; }
    int getHour() const { return hours; }
    void setMinutes(int minutes) { this->minutes = minutes; }
    int getMinutes() const { return minutes; }
    void setFormat(bool format) { this->format = format; }
    bool getFormat() const { return format; }

    void showTime() const {
        if (format) {
            // 24-hour format
            cout << setw(2) << setfill('0') << hours << ":"
                << setw(2) << setfill('0') << minutes << endl;
        }
        else {
            // 12-hour format
            bool pm = hours >= 12;
            int displayHour = hours % 12;
            if (displayHour == 0) displayHour = 12;
            cout << setw(2) << setfill('0') << displayHour << ":"
                << setw(2) << setfill('0') << minutes
                << (pm ? " PM" : " AM") << endl;
        }
    }

    void addMinutes(int mins) {
        minutes += mins;
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
            if (hours >= 24) {
                hours %= 24;
            }
        }
    }

    bool operator<(const Time_& other) const {
        if (hours < other.hours) return true;
        if (hours == other.hours && minutes < other.minutes) return true;
        return false;
    }

    Time_& operator+=(int mins) {
        addMinutes(mins);
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Time_& t) {
        t.showTime();
        return os;
    }

    friend istream& operator>>(istream& is, Time_& t) {
        cout << "Enter hours: ";
        is >> t.hours;
        cout << "Enter minutes: ";
        is >> t.minutes;
        cout << "Enter format (1 for 24-hour, 0 for 12-hour): ";
        is >> t.format;
        return is;
    }
};
