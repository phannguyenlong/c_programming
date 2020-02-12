#include <iostream>
#include <iomanip> // manipulate output to correct form
using namespace std;
// this excercise to learn about operator overloading
const int HOUR_MAX = 23;
const int MINUTE_MAX = 59;

class Time {
    private:
        int hour;
        int minute;
    public:
        Time(int time = 0)
        : hour(time/100), minute(time%100) {};
        Time(Time& anotherTime)
        : hour(anotherTime.hour), minute(anotherTime.minute) {};
        void display() {
            cout << setw(2) << setfill('0') << hour << ":" << setw(2) << minute << endl; // limit of each output 2 space
        }
        // these are operator overloading
        Time operator+=(int add_minute) { 
            int t = minute + add_minute;
            this->minute = t % (MINUTE_MAX + 1);
            this->hour += t / (MINUTE_MAX + 1);
            this->hour = this->hour % (HOUR_MAX + 1); // in case go to next day
            return *this;
        }
        // ++x is prefixed nên sẽ + 1 trước rồi chạy code
        Time operator ++() {
            if (++minute == MINUTE_MAX) {
                minute = 0;
                hour++;
            }
            return *this;
        }
        // x++ is postfixed nên sẽ chạy dòng code xong mới + 1
        Time operator++ (int) {
            Time copy(*this); // make a copy cause postfixed run after line done
            ++(*this);
            return copy;
        }
};

int main() {
    Time time1(145);
    Time time2(time1);
    // operator overloading
    (++time1).display();       // 01:46
    (time2++).display();       // 01:45
    time2.display();           // 01:46
    (time1 += 20).display();   // 02:06
    time1.display();           // 02:06
}