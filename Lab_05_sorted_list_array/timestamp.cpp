#include<iostream>
using namespace std;


class TimeStamp {
    friend bool operator==(TimeStamp a, TimeStamp b) {
        return a.hours == b.hours && a.minutes == b.minutes && a.seconds == b.seconds;
    }
    friend bool operator!=(TimeStamp a, TimeStamp b) {
        return a.hours != b.hours || a.minutes != b.minutes || a.seconds != b.seconds;
    }
    friend bool operator>(TimeStamp a, TimeStamp b) {
        if (a.hours > b.hours)
            return true;
        else if (a.hours == b.hours && a.minutes > b.minutes)
            return true;
        else if (a.hours == b.hours && a.minutes == b.minutes && a.seconds > b.seconds)
            return true;
        return false;
    }
    friend bool operator<(TimeStamp a, TimeStamp b) {
        if (a.hours < b.hours)
            return true;
        else if (a.hours == b.hours && a.minutes < b.minutes)
            return true;
        else if (a.hours == b.hours && a.minutes == b.minutes && a.seconds < b.seconds)
            return true;
        return false;
    }


private:
    int seconds, minutes, hours;
public:
    TimeStamp() {}
    TimeStamp(int s, int m, int h) {
        seconds = s;
        minutes = m;
        hours = h;
    }
    void print() {
        cout << seconds << ":" << minutes << ":" << hours;
    }
};
