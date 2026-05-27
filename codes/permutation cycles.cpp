#include <vector>
using std::vector;

int count_cycles(vector<int>& p){
    int n = p.size();
    vector<int> vis(n,0);
    int cyclesno = 0;
    vector<vector<int>> cycles;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;

        cyclesno++;
        int j = i;
        vector<int> temp;
        while(!vis[j]){
            temp.push_back(j);
            vis[j] = 1;
            j = p[j] - 1;   // because permutation is 1..n
        }
    }

    return cyclesno;
}
