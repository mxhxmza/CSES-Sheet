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

    int n;
    cin >> n;

    vector<string> grid;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        grid.push_back(temp);
    }

    vector<vector<ll>> paths(n, vector<ll>(n, 0));
    if (grid[0][0] == '.')
        paths[0][0] = 1;
    else{
        paths[0][0] = 0;
        cout << 0;
        return 0;
    }
    ll mod = 1000000007;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == 0 && j == 0) continue;
            if (grid[i][j] == '.'){
                if (i > 0) paths[i][j] = (paths[i][j] + paths[i-1][j]) % mod;
                if (j > 0) paths[i][j] = (paths[i][j] + paths[i][j-1]) % mod;
            }
            else{
                paths[i][j] = 0;
            } 
        }
    }
    cout << paths[n-1][n-1];
    return 0;
}
