#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vi coins;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }

    long long f[x+1];
    f[0] = 0;
    for(int i = 1; i < x+1; i++){
        ll best = 1e18;
        for(int j = 0; j < n; j++){
            if (i >= coins[j]){
                ll temp;
                temp = 1 + f[i-coins[j]];
                best = min(best,temp);
            }
        }
        f[i] = best;
    }
    
    if (f[x] >= 1e18){
        cout << -1;
    }
    else{
        cout << f[x];
    }
}