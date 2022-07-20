#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 43046722;
typedef long long ll;

int n, a[16][16];
ll dp[MAXN], cnt[(1 << 16) + 2];
bool bio[MAXN];
vector<int> v[16];

ll solve(int mask){
	if(bio[mask]) return dp[mask];
	bio[mask] = 1;
	int cmask = mask;
	for( ; cmask; cmask = (cmask - 1) & mask){
		dp[mask] = max(dp[mask], cnt[cmask] + solve(mask ^ cmask));
	}
	return dp[mask];
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i < (1 << n); ++i){
		v[__builtin_popcount(i)].push_back(i);
	}
	for(int i = 1; i <= n; ++i){
		for(int x : v[i]){
			int idx = 0;
			for(int j = 0; j < n; ++j){
				if(x & (1 << j)){
					idx = j; break;
				}
			}
			ll cur = 0;
			for(int j = idx + 1; j < n; ++j){
				if(x & (1 << j)){
					cur += a[idx][j];
				}
			}
			cnt[x] = cnt[x ^ (1 << idx)] + cur;
		}
	}
	cout << solve((1 << n) - 1);
	return 0;
}
