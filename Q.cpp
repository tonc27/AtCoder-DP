#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 2;
const int OFF = (1 << 19);
typedef long long ll;

int n, h[MAXN], a[MAXN];
ll tour[OFF];

ll f(int x, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return tour[x];
	if(ql > r || l > qr) return 0;
	int mid = (l + r) >> 1;
	return max(f(x*2+1, l, mid, ql, qr), f(x*2+2, mid+1, r, ql, qr));
}
void upd(int x, int l, int r, int idx, ll val){
	if(l > idx || r < idx) return ;
	if(l == r){
		tour[x] = max(tour[x], val);
		return ;
	}
	int mid = (l + r) >> 1;
	upd(x*2+1, l, mid, idx, val); upd(x*2+2, mid+1, r, idx, val);
	tour[x] = max(tour[x*2+1], tour[x*2+2]);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> h[i];
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i){
		ll val = f(0, 0, n, 0, h[i] - 1) + a[i];
		upd(0, 0, n, h[i], val);
	}
	cout << f(0, 0, n, 0, n);
	return 0;
}
