#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x,y) cout << (#x) << " is " << (x) << " | " << (#y) << " is " << (y) << endl
#define watch3(x,y,z) cout << (#x) << " is " << (x) << " | " << (#y) << " is " << (y) << " | " << (#z) << " is " << (z) << endl
#define watch4(x,y,z,a) cout << (#x) << " is " << (x) << " | " << (#y) << " is " << (y) << " | " << (#z) << " is " << (z) << " | " << (#a) << " is " << (a) << endl

template<typename OutStream, typename T>
OutStream& operator<< (OutStream& out, const vector<T>& v)
{
    for (auto const& tmp : v)
        out << tmp << " ";
    out << endl;
    return out;
}


void test_case() {
	int n; cin >> n;
	vector<int>arr(n, 0); 
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int maxval = arr[n-1];
	int dp[n]; memset(dp, 0, sizeof(dp));

	cout << arr << endl;

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		auto it = lower_bound(arr.begin(), arr.begin()+i-1, arr[i]-maxval);
		int dis = distance(arr.begin(), it);
		watch4(i, arr[i], dp[i], dis);
		if (*it > arr[i]-maxval) {
			if (it == arr.begin()) {
				cout << " hit 1 " << endl;
				dp[i] = max(dp[i-1], 1);
			} else {
				cout << " hit 2 " << endl;
				int idx = distance(arr.begin(), it)-1;
				dp[i] = max(1+dp[idx], dp[i-1]);
			}
		} else {
			cout << " hit 3 " << endl;
			dp[i] = max(1+dp[dis], dp[i-1]);
		}
	}
	cout << dp[n-1] << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		test_case();
	}
}