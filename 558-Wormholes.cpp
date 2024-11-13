#include <bits/stdc++.h>
using namespace std;
#define int long long

void work(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    int x = -1;
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    for(int i = 0; i < n; i++){
        x = -1;
        for(auto &[b, c] : adj[i]){
            if(dist[b] > dist[i] + c){
                dist[b] = dist[i] + c;
                x = b;
            }
        }
    }
    cout << (x == -1 ? "not possible\n" : "possible\n");
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        work();
    }

}
