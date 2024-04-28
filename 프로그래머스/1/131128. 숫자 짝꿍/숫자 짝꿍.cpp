#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr1[10];
int arr2[10];
int dup[20];

string solution(string X, string Y) {
    string answer = "";
    
    for(int i=0; i<10; i++) arr1[i] = arr2[i] = dup[i] = 0;
    for(char c : X) arr1[c-'0']++;
    for(char c : Y) arr2[c-'0']++;
    for(int i=0; i<10; i++) dup[i] = min(arr1[i], arr2[i]);
    for(int i=9; i>=0; i--) 
    {
        for(int j=dup[i]; j>0; j--) answer += i+'0';
    }
    
    if(answer[0] == '0') answer = "0";
    if(answer == "") answer = "-1";
    
    return answer;
}