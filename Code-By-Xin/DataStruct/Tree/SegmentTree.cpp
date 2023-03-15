// 线段树
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
// tree —— 线段树， lazy —— 懒标记， update —— 更新任务，change —— 存放更新任务的值
int arr[N], tree[4 * N], lazy[4 * N], update[4 *N], change[4 * N], n;

// 构建线段树 —— 递归构建
// 在数组 l 到 r 的范围内构造线段树， pos代表这个线段树的下标
void build(int l, int r, int pos)
{
    if (l == r) {
        tree[pos] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, pos << 1);
    build(mid + 1, r, pos << 1 | 1);
    tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
}

// pushdown方法的作用是下发线段树pos结点上的lazy标记和update标记，把lazy标记给pos的子结点
// pos 是这个结点， ln是这个结点左孩子的数量， rn是这个结点右孩子的数量
void pushdown(int pos, int ln, int rn)
{
    if (update[pos]) {
        // 需要更新
        update[pos << 1] = true;
        update[pos << 1 | 1] = true;
        change[pos << 1] = change[pos];
        change[pos << 1 | 1] = change[pos];
        lazy[pos << 1] = 0;
        lazy[pos << 1 | 1] = 0;
        tree[pos << 1] = change[pos] * ln;
        tree[pos << 1 | 1] = change[pos] * rn;
        update[pos] = false;
    }
    
    if (lazy[pos]) { // 如果lazy标记不为0
        lazy[pos << 1] += lazy[pos];
        tree[pos << 1] += lazy[pos] * ln;
        lazy[pos << 1 | 1] += lazy[pos];
        tree[pos << 1 | 1] += lazy[pos] * rn;
        lazy[pos] = 0; // lazy 标记清零
    }
}

// 我要把数组 l 到 r 范围内所有的数改成c
// cl 和 cr 代表目前递归的范围
// pos 代表线段树的结点
void upDate(int l, int r, int c, int cl, int cr, int pos)
{
    if (l <= cl && cr <= r) { // 全部盖住 
        update[pos] = true;
        change[pos] = c;
        tree[pos] = c * (cr - cl + 1);
        lazy[pos] = 0; // 取消lazy
        return;
    }

    // 如果没有被完全覆盖住
    int mid = (cl + cr) >> 1;
    // 下发给子结点
    pushdown(pos, mid - cl + 1, cr - mid);
    if (l <= mid) upDate(l, r, c, cl, mid, pos << 1);
    if (r > mid) upDate(l, r, c, mid + 1, cr, pos << 1 | 1);
    tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];   
}

// 在 数组 l 和 r 范围内 每个元素都增加 c
// cl 和 cr 代表任务范围, pos 代表线段树下标
void add(int l, int r, int c, int cl, int cr, int pos)
{
    if (l <= cl && cr <= r) {// 当前 cl 和 cr 被完美覆盖
        tree[pos] += (cr - cl + 1) * c;
        lazy[pos] += c; // 打上lazy标记
        return;
    }  

    // 如果没有被完美覆盖，那任务就需要下发到pos的子结点
    int mid = (cl + cr) >> 1;
    pushdown(pos, mid - cl + 1, cr - mid); // 开始下发到子结点
    if (l <= mid) // 如果 l <= mid 代表左侧需要有这个标记
        add(l, r, c, cl, mid, pos << 1);
    if (r > mid) // 这里是 > 不是 >=
        add(l, r, c, mid + 1, cr, pos << 1 | 1); 
    // 左右孩子做完任务后，更新一下我tree的信息
    tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
}


// query 任务 —— 询问 数组 l 到 r 的总和
int query(int l, int r, int cl, int cr, int pos)
{
    if (l <= cl && cr <= r) return tree[pos];
    int mid = (cl + cr) >> 1;
    pushdown(pos, mid - cl + 1, cr - mid);
    int res = 0;
    if (l <= mid) res += query(l, r, cl, mid, pos << 1);
    if (r > mid) res += query(l, r, mid + 1, cr, pos << 1 | 1);
    return res;
}


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int start = 1, end = n, root = 1; // root是树根
    
    build(start, end, root);
    for (int i = 1; i <= n; i++) cout << query(i, i, start, end, root) << ' '; 
    cout << '\n';

    int a, b, c; 
    
    
    cin >> a >> b; //先询问 a 和 b 之前的数的和
    cout << query(a, b, start, end, root) << '\n';


    cin >> a >> b >> c; // a 和 b 中所有元素加上c
    add(a, b, c, start, end, root);
    cin >> a >> b; //再来询问
    cout << query(a, b, start, end, root) << '\n';
    for (int i = 1; i <= n; i++) cout << query(i, i, start, end, root) << ' ';
    cout << '\n';

    cin >> a >> b >> c; // a 和 b 所有元素都变成 c
    upDate(a, b, c, start, end, root);
    cin >> a >> b;
    cout << query(a, b, start, end, root) << '\n';
    for (int i = 1; i <= n; i++) cout << query(i, i, start, end, root) << ' ';
    cout << '\n';

    return 0;
}
