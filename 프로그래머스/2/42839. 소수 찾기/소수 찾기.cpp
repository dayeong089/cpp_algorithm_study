#include <string>
#include <vector>
#include <set>

using namespace std;

bool visited[7];
set<int> prime;

bool isprime(int x)
{
    if(x < 2) return false;
    bool check = true;
    for(int i=2; i*i<=x; i++)
    {
        if(x % i == 0) 
        {
            check = false;
            break;
        }
    }
    return check;
}

void func(int idx, int len, string numbers, string x)
{
    if(x.size() > len) return;
    if(x != "" && isprime(stoi(x))) prime.insert(stoi(x));
    
    for(int i=0; i<len; i++)
    {
        if(visited[i]) continue;;
        visited[i] = true;
        func(idx+1, len, numbers, x+numbers[i]);
        visited[i] = false;
    }
}

int solution(string numbers) {
    for(int i=0; i<numbers.size(); i++) visited[i] = false;
    func(0, numbers.size(), numbers, "");
    return prime.size();
}