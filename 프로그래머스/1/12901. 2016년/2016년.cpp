#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    vector<int> day = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> week = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    
    int total = 3;
    for(int i=1; i<a; i++) total += day[i];
    total += b;
    
    return week[total % 7];
}