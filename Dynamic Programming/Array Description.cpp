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

    int n, m;
    cin >> n >> m;

    ll mod = 1000000007;

    vi nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<vll> count(n, vector<ll>(m+1, 0));

    if (nums[0] != 0){
        count[0][nums[0]] = 1;
    }
    else{
        for(int j = 1; j <= m; j++){
            count[0][j] = 1;
        }
    }

    for(int i = 1; i < n; i++){
        if (nums[i] == 0){
            for(int j = 1; j <= m; j++){

                if (j - 1 >= 1)
                    count[i][j] = (count[i][j] + count[i-1][j-1]) % mod;

                count[i][j] = (count[i][j] + count[i-1][j]) % mod;

                if (j + 1 <= m)
                    count[i][j] = (count[i][j] + count[i-1][j+1]) % mod;
            }
        }
        
        else{

            if (nums[i] - 1 >= 1)
                count[i][nums[i]] = (count[i][nums[i]] + count[i-1][nums[i] - 1]) % mod;

            count[i][nums[i]] = (count[i][nums[i]] + count[i-1][nums[i]]) % mod;

            if (nums[i] + 1 <= m)
                count[i][nums[i]] = (count[i][nums[i]] + count[i-1][nums[i] + 1]) % mod;
        }
    }
    
    ll total = 0;
    for (int i = 1; i<=m; i++)
        total = (total + count[n-1][i]) % mod;
    cout << total;
    return 0;
}
