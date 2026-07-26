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
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int>b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    //declare dp array[suffix version]
    vector<vi> dp(n+1, vi(m+1, 0));


    for(int i = n-1; i >=0 ; i--){
        for(int j = m-1; j >= 0; j--){
            if (a[i] == b[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    cout << dp[0][0] << "\n";

    //parent pointers;
    vector<int> parent;
    //traverse parent pointers
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if (a[i] == b[j]){
            parent.push_back(a[i]);
            i++;
            j++;
        }
        else{
            if (dp[i+1][j] >= dp[i][j+1])
                i++;
            else
                j++;
        }
    }

    for(auto x: parent){
        cout << x << " ";
    }
    return 0;
}
