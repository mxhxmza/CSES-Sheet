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

    ll n;
    cin >> n;

    long long x[n+1]; //x[i] denotes no. of possible ways to get sum i
    x[0] = 1; //base case
    ll mod = pow(10,9);

  //loop in topological order(increasing i)
    for(ll i = 1; i < n+1; i++){
        x[i] = 0; //init to 0
        for(ll j = 1; j <= 6; j++){ //each throw can have 6 outcomes
            if ( j <= i){ //cannot be negative
                x[i] += x[i-j] % (mod + 7); // add sum 
            }
        }
    }
    
    cout << x[n] % (mod + 7); //printout ans
}
