#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int x, int y, vector<vector<int>> &computers)
{
    queue<int> q;
    q.push(y);
    computers[x][y] = 0;
    computers[y][x] = 0;
    
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int i=0; i<computers[cur].size(); i++)
        {
            if(computers[cur][i])
            {
                computers[cur][i] = 0;
                computers[i][cur] = 0;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++)
    {
        for(int j=0; j<computers[0].size(); j++)
        {
            if(computers[i][j])
            {
                bfs(i, j, computers);
                answer++;
            }
        }
    }
    
    return answer;
}