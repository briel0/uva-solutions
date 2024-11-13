#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> sieve(){
    int N = 1e6;
    vector<int> ans, marca(N, 1);
    marca[0] = marca[1] = 0;
    for(int i = 2; i < N; i++){
        if(marca[i]){
            ans.push_back(i);
            for(int j = 2 * i; j < N; j += i){
                marca[j] = 0;
            }
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> control;
    int limite = 1e12;
    vector<int> primes = sieve();
    for(int &x : primes){
        for(int i = x * x; i <= limite; i *= x){
            control.push_back(i);
        }
    }
    int n;
    cin >> n;
    sort(control.begin(), control.end());
    while(n--){
        int a, b;
        cin >> a >> b;
        int l = lower_bound(control.begin(), control.end(), a) - control.begin();
        int r = upper_bound(control.begin(), control.end(), b) - control.begin();
        cout << r - l << '\n';
    }
}
