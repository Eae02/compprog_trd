using lll = __int128_t;
ll P = 12233720368547789LL;
ll B = 260;
struct PolyHash {
	vector<ll> hashes, ex;
	PolyHash(const string& s) : hashes(s.size() + 1), ex(s.size() + 1) {
		hashes[0] = 1; ex[0] = 1; ex[1] = B;
		for (size_t i = 0; i < s.size(); i++) {
			hashes[i + 1] = ((hashes[i] * B) % P + s[i] + 1) % P;
			ex[i + 1] = (ex[i] * B) % P;
		}
	}
	ll hash(ll lo, ll hi) {
		return ((lll)hashes[hi] - (lll)hashes[lo] * (lll)ex[hi - lo] % P + P) % P;
	}
};
