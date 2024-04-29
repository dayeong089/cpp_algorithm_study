#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> umap1;
    unordered_map<int, string> umap2;
    
    for(int i=0; i<players.size(); i++)
    {
        umap1[players[i]] = i+1;
        umap2[i+1] = players[i];
    }
    
    for(int i=0; i<callings.size(); i++)
    {
        string front_player = umap2[umap1[callings[i]]-1];
        umap1[callings[i]]--;
        umap1[front_player]++;
        umap2[umap1[callings[i]]] = callings[i];
        umap2[umap1[front_player]] = front_player;
    }
    
    for(int i=0; i<umap2.size(); i++)
    {
        answer.push_back(umap2[i+1]); 
    }
    
    return answer;
}