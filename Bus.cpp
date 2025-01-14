#include <iostream>
#include <string>
#include <vector>
#include "Time_.h"
using namespace std;

class Bus {
    vector<string> stations;
    Time_ start;
    Time_ end;
    int duration;
    int relax;

public:
    Bus(vector<string> stations, Time_ start, Time_ end, int duration, int relax)
        : stations(stations), start(start), end(end), duration(duration), relax(relax) {}

    void addStation(int number, string name) {
        if (number >= 0 && number <= stations.size()) {
            stations.insert(stations.begin() + number, name);
        }
    }

    void delStation(int number) {
        if (number >= 0 && number < stations.size()) {
            stations.erase(stations.begin() + number);
        }
    }

    void showInfo() const {
        cout << "Bus Route Information:" << endl;
        cout << "Start Time: ";
        start.showTime();
        cout << "End Time: ";
        end.showTime();
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Relax Time: " << relax << " minutes" << endl;
        cout << "Stations: ";
        for (const auto& station : stations) {
            cout << station << " ";
        }
        cout << endl;
    }

    void printSchedule() const {
        cout << "Daily Schedule:" << endl;
        Time_ currentTime = start;
        while (currentTime < end) {
            currentTime.showTime();
            currentTime += duration;
            if (currentTime < end) {
                currentTime.showTime();
            }
            currentTime += relax;
        }
    }
};

int main() {
    Bus b1({ "Saltivka", "Istorychnyi Musei", "Pivdennyi Voksal" }, Time_(6, 0), Time_(11, 0), 30, 10);

    b1.showInfo();
    b1.printSchedule();

    return 0;
}
