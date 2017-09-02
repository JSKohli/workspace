#include <iostream>
#include <vector>

using namespace std;

void get_node_count(const vector<vector<int>>& g, vector<int>& node_count, int s) {
    if(g[s].size() == 0) {
        node_count[s] = 1;
    }
    else {
        for(int i=0; i < g[s].size(); i++) {
            get_node_count(g,node_count,g[s][i]);
            node_count[s] += node_count[g[s][i]];
        }
        // for the root in subtree
        node_count[s]++;
    }
}

// ans = max number of branches that can be cut
// to get a forest of trees with even number of nodes
int get_ans(const vector<vector<int>>& g) {
    vector<int> node_count(g.size(),0);
    get_node_count(g,node_count,0);
    int ans=0;
    for(int i=1; i < node_count.size(); i++) {
        if(!(node_count[i] & 1)) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int>());
    for(int i=0; i < m; i++) {
        cin >> v >> u;
        g[u-1].push_back(v-1);
    }
    /*for(int i=0; i < n; i++) {
        cout << i+1 << ": ";
        for(int j=0; j < g[i].size(); j++) {
            cout << g[i][j]+1 << " ";
        }
        cout << endl;
    }*/
    cout << get_ans(g);
    return 0;
}