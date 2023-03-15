// // 树状数组

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 20;
// int tree[N];

// int lowbit(int i) // lowbit 操作
// {
//     return i & (-i);
// }
// // 单点修改
// void update(int i, int x)
// {
//     for (int pos = i; pos < N; pos += lowbit(pos))
//         tree[pos] += x;
// }

// // 求前n项和
// int query(int n)
// {
//     int ans = 0;
//     for (int pos = n; pos; pos -= lowbit(pos)) 
//         ans += tree[pos];
//     return ans;
// }


// // 区间查询代码
// int query(int a, int b)
// {
//     return query(b) - query(a - 1);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         int x;
//         cin >> x;
//         update(i, x);
//     }
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int a, b;
//         cin >> a >> b;
//         cout << query(a, b) << '\n';
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int tree[N];
int lowbit(int x)
{
    return (-x) & x;
}

void update(int i, int x)
{
    for (int pos = i; pos < N; pos += lowbit(pos))
        tree[pos] += x;
}

int pre(int n)
{
    int res = 0;
    for (int pos = n; pos; pos -= lowbit(pos))
        res += tree[pos];
    return res;
}

int query(int a, int b)
{
    return pre(b) - pre(a - 1);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }

    // 以下代码用于询问
    int q; cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << '\n';
    }
    return 0;
}
