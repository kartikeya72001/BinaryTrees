#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1000001;

void update(int i, int add, vector<int> &BIT)
{
	while (i > 0 && i < BIT.size())
	{
		BIT[i] += add;
		i = i + (i & (-i));
	}
}

int sum(int i, vector<int> &BIT)
{
	int ans = 0;
	while (i > 0)
	{
		ans += BIT[i];
		i = i - (i & (-i));
	}

	return ans;
}

int findKthSmallest(int k, vector<int> &BIT)
{
	int l = 0;
	int h = BIT.size();
	while (l < h)
	{
		int mid = (l + h) / 2;
		if (k <= sum(mid, BIT))
			h = mid;
		else
			l = mid + 1;
	}

	return l;
}

void insertElement(int x, vector<int> &BIT)
{
	update(x, 1, BIT);
}

void deleteElement(int x, vector<int> &BIT)
{
	update(x, -1, BIT);
}

int findRank(int x, vector<int> &BIT)
{
	return sum(x, BIT);
}

int main()
{
	vector<int> BIT(MAX_VAL);
	insertElement(20, BIT);
	insertElement(50, BIT);
	insertElement(30, BIT);
	insertElement(40, BIT);

	cout << "2nd Smallest element is "
		 << findKthSmallest(2, BIT) << endl;

	cout << "Rank of 40 is "
		 << findRank(40, BIT) << endl;

	deleteElement(40, BIT);

	cout << "Rank of 50 is "
		 << findRank(50, BIT) << endl;

	return 0;
}
