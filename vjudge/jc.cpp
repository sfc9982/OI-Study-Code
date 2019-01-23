#include <iostream>
using namespace std;

int a[40001], n, len, x, total;

int main()
{
	cin >> n;
	a[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		x = 0;
		for (int j = 1; j <= 40000; j++)
			if (a[j] != 0 || x != 0)
			{
				a[j] = a[j] * i + x;
				x = a[j] / 10;
				a[j] %= 10;
			}
	}
	len = 40000;
	while (a[len] == 0 && len > 0)
		len--;
	for (int i = len; i >= 1; i--)
		cout << a[i];
	return 0;
}
