#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 2;
const int MOD = 1e9 + 7;

int h, w, n, dp[MAXN], fact[MAXN], r[MAXN], c[MAXN];
bool bio[MAXN];

int ad(int a, int b){ return (a + b >= MOD)? a + b - MOD : a + b; }
int sub(int a, int b){ return (a - b < 0) ? a - b + MOD : a - b; }
int mul(int a, int b){ return (long long) a * b % MOD; }
int kv(int a){ return mul(a, a); }
int pot(int a, int b){ return (b == 0) ? 1 : (b & 1) ? mul(a, kv(pot(a, b/2))) : kv(pot(a, b/2)); }
int _div(int a, int b){ return mul(a, pot(b, MOD - 2)); }
int povrh(int a, int b){ return _div(fact[a], mul(fact[a - b], fact[b])); }

int solve(int x){
	if(bio[x]) return dp[x];
	bio[x] = 1;
	dp[x] = povrh(r[x] + c[x] - 2, r[x] - 1);
	for(int i = 0; i < n; ++i){
		if(i == x) continue;
		if(r[i] <= r[x] && c[i] <= c[x]){
			dp[x] = sub(dp[x], mul(solve(i), povrh(r[x] + c[x] - r[i] - c[i], r[x] - r[i])));
		}
	}
	return dp[x];
}

int main(){
	fact[0] = 1;
	for(int i = 1; i < MAXN; ++i){
		fact[i] = mul(i, fact[i - 1]);
	}
	cin >> h >> w >> n;
	for(int i = 0; i < n; ++i){
		cin >> r[i] >> c[i];
	}
	r[n] = h; c[n] = w;
	cout << solve(n);
	return 0;
}
