// DEBUG

// D
namespace ts
{
	string toString(long long e)
	{
		bool t = 0;
		string str;
		if (e < 0) t = 1, e = -e;
		do str += '0'+e%10, e /= 10;
		while(e);
		reverse(str.begin(), str.end());
		if (t) str.insert(0, "-");
		return str += ", ";
	}
	inline string toString(string s)
	{
		return '"' + s + "\", ";
	}
	template <class T, class U> inline string toString(pair<T, U> p)
	{
		return "(" + toString(p.first) + toString(p.second) + "), ";
	}
	template <size_t N> inline string toString(bitset<N> bs)
	{
		string str;
		for (size_t i = 0; i < N; ++i) str += '0' + bs[i];
		return str += ", ";
	}
	template <class C> inline string toString(vector<C> c)
	{
		string str = "{";
		for (auto& e : c) str += toString(e);
		return str += "}, ";
	}
	template <class C> inline string toString(set<C> c)
	{
		string str = "{";
		for (auto& e : c) str += toString(e);
		return str += "}, ";
	}
	template <class C> inline string toString(queue<C> c)
	{
		string str = "{";
		for (auto& e : c) str += toString(e);
		return str += "}, ";
	}
	template <class C> inline string toString(list<C> c)
	{
		string str = "{";
		for (auto& e : c) str += toString(e);
		return str += "}, ";
	}
	template <class T, class U> inline string toString(map<T, U> c)
	{
		string str = "{";
		for (auto& e : c) str += toString(e);
		return str += "}, ";
	}
}
inline void debug(void)
{
	cerr<<'\n';
}
template <class Head, class... Tail> inline void debug(Head head, Tail... tail)
{
	cerr<<ts::toString(head);
	debug(tail...);
}

#define D(...) cerr<<"D:  ["<<#__VA_ARGS__<<"]: ", debug(__VA_ARGS__)

// R

inline void R(ll *t, ll e)
{
	ll cnt = 0;
	cout<<"R:\n\t{";
	for(ll i = 0; i < e; i++) cout<<*(t+i)<<", ";
	cout<<"}\n";
}
