#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1; i<=number; i++)
    {
        int num=0, j;
        for(j=1; j*j<i; j++)
        {
            if(i % j == 0) num+=2;
        }
        if(j*j == i) num++;
        if(num > limit) num = power;
        answer += num;
    }
    return answer;
}