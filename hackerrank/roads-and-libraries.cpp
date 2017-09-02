#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<int> g[], vector<bool>& visited, int s, int& count) {
    visited[s] = true;
    count++;
    for(int i=0; i < g[s].size(); i++) {
        if(!visited[g[s][i]]) {
            dfs(g,visited,g[s][i],count);
        }
    }
}

long getCost(const vector<int> g[], int n, int c_lib, int c_roads) {
    vector<bool> visited(n,false);
    long total=0;
    for(int i=0; i < n; i++) {
        int count = 0;
        if(!visited[i]) {
            dfs(g,visited,i,count);
            total += (count-1) * c_roads + c_lib;
        }
    }
    return total;
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n, m, c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;
        vector<int> *g = new vector<int>[n];
        for(int i=0, x, y; i < m; i++) {
            cin >> x >> y;
            g[x-1].push_back(y-1);
            g[y-1].push_back(x-1);
        }
        if(c_lib <= c_road) {
            cout << (long)n * c_lib << endl;
        }
        else {
            cout << getCost(g,n,c_lib,c_road) << endl;
        }
    }
    return 0;
}