#include <iostream>
using namespace std;

int main()
{
    int now_time, now_minute, after_time, after_minute, cook_time;

    cin >> now_time >> now_minute >> cook_time;

    after_minute = now_minute + cook_time;
    after_time = (now_time + (after_minute/60)) % 24;
    after_minute = after_minute % 60;

    cout << after_time << " " << after_minute << endl;

    return 0;
}