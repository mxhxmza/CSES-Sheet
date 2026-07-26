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

    // get inputs
    int a, b;
    cin >> a >> b;
    
    //if i = j, its a square so 0 moves, else we init to 1 denoting a move will take place there
    vector<vector<int>> dp(a+1, vector<int>(b+1, 1));
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if (i == j) dp[i][j] = 0;
        }
    }

    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if (i != j){
                int minnum = INT_MAX;
                //cutting along i
                for(int k = 1; k < i; k++)
                    minnum = min(minnum, dp[i-k][j] + dp[k][j]);
                //cutting along j
                    for(int k = 1; k < j; k++)
                    minnum = min(minnum, dp[i][j-k] + dp[i][k]);
                //adding min number of moves to our rectangle
                dp[i][j] += minnum;
            }
        }
    }
    cout << dp[a][b];
    return 0;
}
