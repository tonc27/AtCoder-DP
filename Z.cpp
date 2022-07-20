#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 2;
typedef long long ll;

int n, x[MAXN * 5];
ll dp[MAXN], h[MAXN], C;
set<int> s;

int main(){
	cin >> n >> C;
	for(int i = 0; i < n; ++i) cin >> h[i];
	s.insert(h[n - 1]);
	x[h[n - 1]] = n - 1;
	for(int i = n - 2; i >= 0; --i){
		int idx = x[*s.lower_bound(h[i])];
		dp[i] = dp[idx] + (h[idx] - h[i]) * (h[idx] - h[i]) + C;
		int lo = 0, hi = h[n - 1];
		while(lo < hi){
			int mid = (lo + hi + 1) >> 1;
			int idx = x[*s.lower_bound(mid)];
			if(-2LL * h[idx] * mid + dp[idx] + h[idx] * h[idx] < -2LL * h[i] * mid + dp[i] + h[i] * h[i]){
				hi = mid - 1;
			}
			else lo = mid;
		}
		while(*s.begin() <= lo){
			s.erase(s.begin());
			if(s.empty()) break;
		}
		s.insert(lo);
		x[lo] = i;
	}
	cout << dp[0];
	return 0;
}
