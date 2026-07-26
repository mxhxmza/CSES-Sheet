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

    string n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n.size() + 1, vector<int>(m.size() + 1, 0));
    
    for(int i = 1; i <= n.size(); i++){ //remove all letters from n
        dp[i][0] = 1 + dp[i-1][0]; 
    }
    for(int j = 1; j <= m.size(); j++){//add all letters into n
        dp[0][j] = 1 + dp[0][j-1]; 
    }
    for(int i = 1; i <= n.size(); i++){
        for(int j = 1; j <= m.size(); j++){
                if (n[i-1] != m[j-1])
                    //remove or add(after letter) or replace
                    dp[i][j] = min({1 + dp[i-1][j], 1 + dp[i][j-1], 1 + dp[i-1][j-1]});
                else
                    dp[i][j] = dp[i-1][j-1];
        }
    }
    cout << dp[n.size()][m.size()];
    return 0;
}
