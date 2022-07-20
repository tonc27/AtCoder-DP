#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int ad(int a, int b){ return (a + b >= MOD) ? a + b - MOD : a + b; }
int mul(int a, int b){ return (long long) a * b % MOD; }

int n, ans;
long long k;
struct Matrix{
	int x[51][51];
} b, cur;

void cp(Matrix& a, Matrix b){
	Matrix t;
	memset(t.x, 0, sizeof t.x);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				t.x[i][j] = ad(t.x[i][j], mul(a.x[i][k], b.x[k][j]));
			}
		}
	}
	swap(a, t);
}

int main(){
	cin >> n >> k, --k;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> b.x[i][j];
			cur.x[i][j] = b.x[i][j];
		}
	}
	for( ; k; k >>= 1LL){
		if(k & 1LL){
			cp(cur, b);
		}
		cp(b, b);
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			ans = ad(ans, cur.x[i][j]);
		}
	}
	cout << ans;
	return 0;
}
