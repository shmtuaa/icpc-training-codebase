#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f, MOD = 998244353;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define endl '\n'

// ——————————————————————————————————————————————————————————————————————————————————————————————————————
// ——————————————————————————————————————————————————————————————————————————————————————————————————————
// ——————————————————————————————————————————————————————————————————————————————————————————————————————
// ——————————————————————————————————————————————————————————————————————————————————————————————————————
void solve() {
    int n;
    ll a[200010]{};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans= 0 ;
    for(int i=1; i <= n ; i++) ans+=max(0ll,a[i-1]-a[i]);
    cout<<ans<<endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
