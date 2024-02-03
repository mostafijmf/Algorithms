//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// } Driver Code Ends
class Solution {
  public:
    bool vis[10000];
    vector<int> bfs(int v, vector<int> adj[])
    {
        queue<int> q;
        q.push(v);
        vis[v] = true;
        vector<int> ans;
        while(!q.empty())
        {
            int par = q.front();
            ans.push_back(par);
            q.pop();
            for(int child: adj[par])
            {
                if(!vis[child])
                {
                    vis[child] = true;
                    q.push(child);
                }
            }
        }
        return ans;
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        memset(vis, false, sizeof(vis));
        vector<int> ans = bfs(0, adj);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends