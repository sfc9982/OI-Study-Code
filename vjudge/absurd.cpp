#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

const int p10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void work()
{
	int l, r, l1, l2;
	cin >> l >> r;
	l1 = floor(log10(l));
	l2 = floor(log10(r));
	if (l2 - l1 >= 2)
	{
		if (l / p10[l1] < 5)
			cout << 5 * p10[l1] << endl;
		else if (r / p10[l2] >= 5)
			cout << 5 * p10[l1 + 1] << endl;
		else if (l == p10[l1] * 5)
			cout << l << endl;
		else
			cout << 5 * p10[l1 + 1] << endl;
		return;
	}

	if (l2 - l1 == 1)
	{
		if (!l1)
			cout << ((l1 <= 5) ? 5 : 10) << endl;
		else if (l / p10[l1] < 5)
			cout << 5 * p10[l1] << endl;
		else if (r / p10[l2] >= 5)
			cout << 5 * p10[l2] << endl;
		else if (l / p10[l1] * p10[l1] == l)
			cout << l << endl;
		else
			cout << (l / p10[l1] + 1) * p10[l1] << endl;
		return;
	}

	if (!l1 && !l2)
	{
		cout << ((l <= 5 && r >= 5) ? 5 : l) << endl;
		return;
	}
	if (l / p10[l1] < 5 && r / p10[l2] >= 5)
	{
		cout << 5 * p10[l1] << endl;
		return;
	}
	if (l == p10[l1] * 5)
	{
		cout << 5 * p10[l1] << endl;
		return;
	}
	if (l / p10[l1] * p10[l1] == l)
	{
		cout << l << endl;
		return;
	}
	if (l / p10[l1] < r / p10[l1])
	{
		cout << (l / p10[l1] + 1) * p10[l1] << endl;
		return;
	}
	long long k, times;
	k = 0;
	times = 10;
	while (times--)
	{
		k += +l / p10[l1] * p10[l1];
		l %= p10[l1];
		r %= p10[l1];
		l1--;
		if (!l1)
		{
			cout << ((l <= 5 && r >= 5) ? 5 : l) + k << endl;
			return;
		}
		if ((l / p10[l1]) < 5 && (r / p10[l1]) >= 5)
		{
			cout << 5 * p10[l1] + k << endl;
			return;
		}
		if (l == p10[l1] * 5)
		{
			cout << 5 * p10[l1] + k << endl;
			return;
		}
		if (l / p10[l1] * p10[l1] == l)
		{
			cout << l + k << endl;
			return;
		}
		if (l / p10[l1] < r / p10[l1])
		{
			cout << (l / p10[l1] + 1) * p10[l1] + k << endl;
			return;
		}
	}
}

int main()
{
	freopen("absurd.in", "r", stdin);
	freopen("absurd.out", "w", stdout);
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		work();
	}
	//getchar();getchar();
	return 0;
}
