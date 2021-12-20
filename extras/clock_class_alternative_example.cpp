#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Clock{
public:
    Clock(int hour, int minute);
    void tick_tock();
    void print() const;
    int fetch_hour() const;
    int fetch_minutes() const;

private:
    int minutes_since_midnight_;
};

int main()
{
    Clock time(23, 59);
    time.print();
    time.tick_tock();
    time.print();
}

Clock::Clock(int hour, int minute):
    minutes_since_midnight_(60*hour + minute)
{

}

void Clock::tick_tock()
{
    ++minutes_since_midnight_;
    if(minutes_since_midnight_ >= 24*60)
        minutes_since_midnight_ = 0;
}

void Clock::print() const
{
    cout << setfill('0') << fetch_hour() << "." << setw(2) << fetch_minutes() << endl;
}

int Clock::fetch_hour() const
{
    return minutes_since_midnight_ / 60;
}

int Clock::fetch_minutes() const
{
    return minutes_since_midnight_ % 60;
}
