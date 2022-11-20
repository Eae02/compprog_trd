constexpr ll M = 998244353, root = 62;
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % M, e /= 2)
		if (e & 1) ans = ans * b % M;
	return ans;
}
void fft(vector<ll> &a) {
	ll n = a.size(), L = 31 - __builtin_clz(n);
	static vector<ll> rt(2, 1);
	for (static ll k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, M >> s)};
		for (ll i = k; i < 2 * k; i++)
			rt[i] = rt[i / 2] * z[i & 1] % M;
	}
	vector<ll> rev(n);
	for (ll i = 0; i < n; i++)
		rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	for (ll i = 0; i < n; i++)
		if (i < rev[i])
			swap(a[i], a[rev[i]]);
	for (ll k = 1; k < n; k *= 2)
		for (ll i = 0; i < n; i += 2 * k) for (ll j = 0; j < k; j++) {
			ll z = rt[j + k] * a[i + j + k] % M, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? M : 0);
			ai += (ai + z >= M ? z - M : z);
		}
}
vector<ll> conv(const vector<ll> &a, const vector<ll> &b) {
	if (a.empty() || b.empty()) return {};
	ll s = (ll)(a.size() + b.size()) - 1;
	ll B = 32 - __builtin_clz(s);
	ll n = 1 << B;
	ll inv = modpow(n, M - 2);
	vector<ll> L(a), R(b), out(n);
	L.resize(n); R.resize(n);
	fft(L); fft(R);
	for (ll i = 0; i < n; i++)
		out[-i & (n - 1)] = (ll)L[i] * R[i] % M * inv % M;
	fft(out);
	return { out.begin(), out.begin() + s };
}
