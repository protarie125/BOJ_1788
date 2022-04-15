#include <iostream>
#include <vector>
#include <map>

using namespace std;

using vi = vector<int>;
using mii = map<int, int>;

constexpr auto mod = int{ 1'000'000'000 };

mii nmemo;
int negaFibo(int n) {
	for (int i = -1; n <= i; --i) {
		nmemo[i] = (nmemo[i + 2] - nmemo[i + 1]) % mod;
	}

	return nmemo[n];
}

vi memo;
int fibo(int n) {
	for (int i = 2; i <= n; ++i) {
		memo[i] = (memo[i - 1] + memo[i - 2]) % mod;
	}

	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto ans = int{ 0 };
	if (0 == n) {
		cout << 0 << '\n' << ans;

		return 0;
	}

	auto isNega = n < 0;
	if (isNega) {
		nmemo[0] = 0;
		nmemo[1] = 1;

		ans = negaFibo(n);
	}
	else
	{
		memo = vi(n + 1, -1);
		memo[0] = 0;
		memo[1] = 1;
		ans = fibo(n);
	}

	if (0 == ans) {
		cout << 0 << '\n';
	}
	else if (ans < 0) {
		cout << -1 << '\n';
	}
	else {
		cout << 1 << '\n';
	}

	if (ans < 0) {
		ans *= -1;
	}
	cout << ans;

	return 0;
}