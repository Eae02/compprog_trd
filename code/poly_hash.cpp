using lll = __int128_t;
ll P = 12233720368547789LL;
ll B = 260;
struct PolyHash {
	vector<ll> hashes, ex;
	PolyHash(const string& s) : hashes(s.size()), ex(s.size() + 1) {
		hashes[0] = s[0] + 1;
		ex[0] = 1; ex[1] = B;
		for (size_t i = 1; i < s.size(); i++) {
			hashes[i] = ((hashes[i - 1] * B) % P + s[i] + 1) % P;
			ex[i + 1] = (ex[i] * B) % P;
		}
	}
	ll hash(ll lo, ll hi) {
		if (lo == 0) return hashes[hi];
		return (hashes[hi] - ((lll)hashes[lo - 1] * ex[hi - lo]) % P + P) % P;
	}
};
