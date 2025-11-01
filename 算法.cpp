#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long n, k, x;
vector<long long> v;

int fun(long long y) {
	long long count = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] > y) {
			if ((v[i] - y) % x == 0) {
				count += (v[i] - y) / x;
			}
			else {
				count += (v[i] - y) / x + 1;
			}
		}
	}
	if (count <= k) return 1;
	if (count > k) return -1;
}

int main() {

	long long max = 0;
	long long y;
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) {
		cin >> y;
		v.push_back(y);
		if (y > max) {
			max = y;
		}
	}
	long long left = -1 * k * x;
	long long right = max;
	long long mid;
	long long answer;
	while (left <= right) {
		mid = (left + right) / 2;
		if (fun(mid) < 0) {
			left = mid + 1;
		}
		else {
			answer = mid;
			right = mid - 1;
		}
	}
	cout << answer << endl;

	return 0;
}