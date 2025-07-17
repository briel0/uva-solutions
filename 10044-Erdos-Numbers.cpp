#include <bits/stdc++.h>
using namespace std;
#define int long long

void work(){
    int m, p;
    cin >> m >> p;
    string x;
    getline(cin, x);

    map<string, int> control = {{"Erdos P.", 0}};

    int index = 1, N = 1e5 + 1;

    vector<int> adj[N];

    for(int i = 0; i < m; i++){
        string temp;
        getline(cin, temp);

        int cnt = 0;
        string atual = "", nome = "";

        vector<int> todos;

        for(int j = 0; j < temp.size(); j++){
            if(temp[j] == ',' || temp[j] == ':'){
                nome = nome + atual;
                if(cnt % 2){
                    if(nome[0] == ' '){
                        nome = nome.substr(1);
                    }
                    if(control.find(nome) == control.end()){
                        control[nome] = index++;
                    }
                    todos.push_back(control[nome]);
                    nome = "";
                }
                
                atual = "";
                cnt++;

                if(temp[j] == ':'){
                    break;
                }
            }
            else{
                atual += temp[j];
            }
        }
        for(int &y : todos){
            for(int &w : todos){
                if(y == w){
                    continue;
                }
                adj[y].push_back(w);
                adj[w].push_back(y);
            }
        }

    }

    vector<int> dist(index + 1, LLONG_MAX);

    dist[0] = 0;

    queue<int> fila;
    fila.push(0);
    while(!fila.empty()){
        int v = fila.front();
        fila.pop();
        for(int &x : adj[v]){
            if(dist[v] + 1 < dist[x]){
                dist[x] = dist[v] + 1;
                fila.push(x);
            }
        }
    }

    for(int i = 1; i < p + 1; i++){
        string temp;
        getline(cin, temp);

        string original = temp;

        for(int j = 0; j < temp.size(); j++){
            if(temp[j] == ','){
                temp.erase(j, 1);
                break;
            }
        }

        cout << original << ' ';
        if(control.find(temp) == control.end() || dist[control[temp]] == LLONG_MAX){
            cout << "infinity\n";
        }
        else{
            cout << dist[control[temp]] << '\n';
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Scenario " << i << '\n';
        work();
    }
}
