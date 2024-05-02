#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

char alpha[5] = {'A', 'E', 'I', 'O', 'U'};
unordered_map<string, int> umap;
int order = 0;

void dfs(int x, string str)
{
    if(x == 5) return;
    for(int i=0; i<5; i++)
    {
        umap[str + alpha[i]] = ++order;
        dfs(x+1, str + alpha[i]);
    }
}

int solution(string word) {
    dfs(0, "");
    return umap[word];
}