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

    ll mod = pow(10,9);
    mod += 7;

    vector<ll> f(x+1, 0);
    f[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if (i - coins[j] >= 0){
                f[i] += f[i - coins[j]] % mod;
            }
        }
    }
    cout << f[x] % mod;
