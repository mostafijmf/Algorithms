#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> result;
    void dfs(vector<int> adj[], bool vis[], int src)
    {
        result.push_back(src);
        vis[src] = true;
        for (int child : adj[src])
        {
            if (!vis[child])
            {
                dfs(adj, vis, child);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        bool vis[V];
        memset(vis, false, sizeof(vis));
        dfs(adj, vis, 0);
        return result;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> ans = obj.dfsOfGraph(0, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}