#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 2;
const int OFF = (1 << 19);
typedef long long ll;
const ll inf = (1LL << 60);

int n, m;
vector<pair<int, int> > r[MAXN];
ll tour[OFF], prop[OFF];

void propaj(int x, bool prenesi){
	tour[x] += prop[x];
	if(prenesi){
		prop[x*2+1] += prop[x];
		prop[x*2+2] += prop[x];
	}
	prop[x] = 0;
}

ll f(int x, int l, int r, int ql, int qr){
	propaj(x, l != r);
	if(ql <= l && r <= qr) return tour[x];
	if(ql > r || l > qr) return -inf;
	int mid = (l + r) >> 1;
	return max(f(x*2+1, l, mid, ql, qr), f(x*2+2, mid+1, r, ql, qr));
}
void upd(int x, int l, int r, int ql, int qr, ll val){
	propaj(x, l != r);
	if(ql <= l && r <= qr){
		prop[x] += val;
		propaj(x, l != r);
		return ;
	}
	if(ql > r || l > qr) return ;
	int mid = (l + r) >> 1;
	upd(x*2+1, l, mid, ql, qr, val);
	upd(x*2+2, mid+1, r, ql, qr, val);
	tour[x] = max(tour[x*2+1], tour[x*2+2]);
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int ql, qr, val;
		cin >> ql >> qr >> val;
		r[qr].push_back({ql, val});
	}
	for(int i = 1; i <= n; ++i){
		ll val = f(0, 0, n, 0, i - 1);
		upd(0, 0, n, i, i, val);
		for(pair<int, int> p : r[i]){
			upd(0, 0, n, p.first, i, p.second);
		}
	}
	cout << f(0, 0, n, 0, n);
	return 0;
}
