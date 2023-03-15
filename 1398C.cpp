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
    string x;
    int s[100010]{}, a[100010]{};
    cin >> n >> x;
    map<int, int> k;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = x[i - 1] - '0';
        s[i] = s[i - 1] + a[i];
        k[s[i]-i]++;
    }
    ll ans = 0;
    for (auto it: k) {
        if (it.first == 0) ans += 1ll*it.second * (it.second + 1) / 2;
        else ans += 1ll*it.second * (it.second - 1) / 2;
        //cout << ans << ' ';
    }
    cout << ans << endl;
    //cout<<sum<<endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();//again?
    }
    return 0;
}