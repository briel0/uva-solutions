#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int N = 2e5 + 1, lg = 30;
vector<pair<int, int>> adj[N];
vector<int> depth, dist;
int lca[N][lg];

void busca(int v, int pai){
    for(auto &[x, value] : adj[v]){
        if(x == pai){
            continue;
        }
        if(dist[x] == -1){
            dist[x] = dist[v] + value;
            busca(x, v);
        }
    }    
}

void dfs(int v, int pai){
    lca[v][0] = pai;
    for(int i = 1; i < lg; i++){
        if(lca[v][i - 1] != -1){
            lca[v][i] = lca[lca[v][i - 1]][i - 1];
        }
    }
    for(auto &[x, _] : adj[v]){
        if(x == pai){
            continue;
        }
        depth[x] = depth[v] + 1;
        dfs(x, v);
    }
}
 
int uac(int a, int b){
    if(depth[b] > depth[a]){
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for(int i = 0; i < lg; i++){
        if(diff & (1 << i)){
            a = lca[a][i];
        }
    }
    for(int i = lg - 1; i >= 0; i--){
        if(lca[a][i] != lca[b][i]){
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    if(a == b){
        return a;
    }
    return lca[a][0];
}
 
void work(int n){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    for(int i = 0; i < n; i++){
        adj[i].clear();
    }

    depth.assign(n + 1, 0);

    for(int i = 1, p, l; i < n; i++){
        cin >> p >> l;
        adj[i].push_back({p, l});
        adj[p].push_back({i, l});
    }

    for(int i = 0; i < lg; i++){
        for(int j = 0; j <= n; j++){
            lca[j][i] = -1;
        }
    }
 
    dfs(0, 0);
 
    dist.assign(n + 1, -1);
    
    dist[0] = 0;

    busca(0, 0);

    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        int a = uac(u, v);

        int ans = dist[u] + dist[v] - 2 * dist[a];

        cout << ans;
        cout << (q ? ' ' : '\n');
    }
}

signed main(){
    int n;
    while(cin >> n && n){
        work(n);
    }
    cout << flush;
}
