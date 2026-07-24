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
 
    vi steps(n+1, 1e7);
    steps[0] = 0;
    for(int i = 1; i <= n; i++){
        vi digits;
        int temp = i;
        while (temp > 0){
            digits.push_back(temp % 10);
            temp /= 10;
        }
        for(uint32_t j = 0; j < digits.size(); j++){
            if (i - digits[j] >= 0)
                steps[i] = min(1 + steps[i-digits[j]], steps[i]);
        }
        digits.clear();
    }
    cout << steps[n];
    
}
