#include <iostream>
#include <algorithm>
using namespace std;
int cd, n, heap[10000];
void sfc(int d)
{
    int now, next;
    heap[++cd] = d;
    now = cd;
    while (now > 1)
    {
        next = now >> 1;
        if (heap[now] >= heap[next])
            return;
        swap(heap[now], heap[next]);
        now = next;
    }
}
int get()
{
    int now, next, res;
    res = heap[1];
    heap[1] = heap[cd--];
    now = 1;
    while (now * 2 <= cd)
    {
        next = now * 2;
        if (next < cd && heap[next + 1] < heap[next])
            next++;
        if (heap[now] <= heap[next])
            return res;
        swap(heap[now], heap[next]);
        now = next;
    }
    return res;
}
void work()
{
    int i, x, y, ans = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        sfc(x);
    }
    for (i = 1; i < n; i++)
    {
        x = get();
        y = get();
        ans += x + y;
        sfc(x + y);
    }
    cout << ans << endl;
}
int main()
{
    work();
    return 0;
}