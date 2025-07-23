#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N], visited, ordem;

void dfs(int v, bool flag){
    visited[v] = 1;
    for(int &x : adj[v]){
        if(!visited[x]){
            dfs(x, flag);
        }
    }
    if(flag){
        ordem.push_back(v);
    }
}

void work(){
    int n, m;
    cin >> n >> m;
    ordem.clear();
    for(int i = 1; i <= n; i++){
        adj[i].clear();
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    visited.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, 1);
        }
    }

    int ans = 0;
    visited.assign(n + 1, 0);
    reverse(ordem.begin(), ordem.end());

    for(int &x : ordem){
        if(!visited[x]){
            dfs(x, 0);
            ans++;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        work();
    }
}
