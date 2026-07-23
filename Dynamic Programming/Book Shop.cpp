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

    vi price(n);
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    vi pages(n);
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    vector<int> maxpages(x+1, 0);
    
    for(int j = 0; j < n; j++){ //process each book 1 by 1
        for(int i = x; i >= price[j]; i--){
            maxpages[i] = max(maxpages[i], pages[j] + maxpages[i-price[j]]);
        }
    }

    cout << maxpages[x];
    return 0;
}
