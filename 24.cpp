#include<bits/stdc++.h>
#define rep(i, l, r) for(register int i = l; i < r; i++)
#define hrp(i, l, r) for(register int i = l; i <= r; i++)
#define rev(i, r, l) for(register int i = r; i >= l; i--)
#ifdef LOCAL
#define D(x) printf("%.3f\n", x);
#define R(x, l) cout<<"R: Array "<<#x<<endl; rep(i, 0, l) cout<<' '<<i<<':'<<*(x+i)<<endl;
#else
#define D(x)
#define R(X, l)
#endif
#define pb push_back
#define int ll
#define eps 0.05
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template<typename tn> inline tn next(void);
template<typename tn> inline ostream& operator << (ostream& os, const vector<tn>& v);
inline int _max(int cnt, ...);
inline int _min(int cnt, ...);
double w[8];
inline double work(double a, int ope, double b)
{
	switch(ope)
	{
		case 0: return a+b;
		case 1: return a-b;
		case 2: return a*b;
		case 3: return !b ? -19260817 : a/b;
		default: assert(false);
	}
}
inline char to(int ope)
{
	switch(ope)
	{
		case 0: return '+';
		case 1: return '-';
		case 2: return '*';
		case 3: return '/';
	}
}
inline void output(double a, int o1, double b, int o2, double c, int o3, double d, bool t)
{
	char u1 = to(o1), u2 = to(o2), u3 = to(o3);
	double mid1, mid2;
	if (t) mid1 = work(a, o1, b), mid2 = work(mid1, o2, c), printf("%.2f%c%.2f=%.2f\n%.2f%c%.2f=%.2f\n%.2f%c%.2f=24\n",
	max(a, b), u1, min(a, b), mid1,
	max(mid1, c), u2, min(mid1, c), mid2,
	max(mid2, d), u3, min(mid2, d));
	else mid1 = work(a, o1, b), mid2 = work(c, o3, d), printf("%.2f%c%.2f=%.2f\n%.2f%c%.2f=%.2f\n%.2f%c%.2f=24\n",
	max(a, b), u1, min(a, b), mid1,
	max(c, d), u3, min(c, d), mid2,
	max(mid1, mid2), u2, min(mid1, mid2));
	exit(0);
}
signed main(void)
{
	#ifdef LOCAL
//		freopen("C:\\Users\\Joeon\\Desktop\\IN.txt", "r", stdin);
//		freopen("C:\\Users\\Joeon\\Desktop\\OUT.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	double minLess = 1000;
	rep(i, 0, 4) cin>>w[i];
	sort(w, w+4);
	int q, t, e, r;
	do
	{
		double a = w[0], b = w[1], c = w[2], d = w[3];
		rep(i, 0, 4) rep(j, 0, 4) rep(k, 0, 4)
		{
			if (-eps <= work(work(work(a, i, b), j, c), k, d)-24 && work(work(work(a, i, b), j, c), k, d)-24 <= eps) output(a, i, b, j, c, k,  d, 1);
			else if (-eps <= work(work(a, i, b), j, work(c, k, d))-24 && work(work(a, i, b), j, work(c, k, d))-24 <= eps) output(a, i, b, j, c, k, d, 0);
		}
	} while(next_permutation(w, w+4));
	cout<<"No answer!"<<endl;
	return 0;
}
template<typename tn> inline tn next(void)
{
	tn k;
	cin>>k;
	return k;
}
template<typename tn> inline ostream& operator << (ostream& os, const vector<tn>& v)
{
	rep(i, 0, v.size()) os<<v[i]<<' ';
	return os;
}
inline int _max(int cnt, ...)
{
	int mx = -1e18;
	va_list l;
	va_start(l, cnt);
	while(cnt--) mx = max(mx, va_arg(l, int));
	va_end(l);
	return mx;
}
inline int _min(int cnt, ...)
{
	int mn = 1e18;
	va_list l;
	va_start(l, cnt);
	while(cnt--) mn = min(mn, va_arg(l, int));
	va_end(l);
	return mn;
}
