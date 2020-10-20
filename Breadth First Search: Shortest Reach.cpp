#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        int nodes, edges, start;
        cin >> nodes >> edges;
        vector<int>edge[nodes+1];
        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        cin >> start;
        vector<bool> vis(nodes+1,false);
        vector<int>distances(nodes+1);
        for (int i = 1; i <= nodes; i++)
        {
            distances[i] = -1;
        }
        queue<int> Q;
        Q.push(start);
        vis[start] = true;
        distances[start] = 0;
        while (!Q.empty())
        {
            int p = Q.front();
            Q.pop();
            int dist = 0;
            for (int i = 0; i < edge[p].size(); i++) {
                if (!vis[edge[p][i]]) {
                    distances[edge[p][i]] = distances[p] + 6;
                    Q.push(edge[p][i]);
                    vis[edge[p][i]] = true;
                }
            }
        }
        for (int i = 1; i <= nodes; i++)
        {
            if (i == start) continue;
            cout << distances[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
