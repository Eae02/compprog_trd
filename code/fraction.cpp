struct fraction {
	__int128_t e, d;
	fraction(__int128_t E, __int128_t D = 1) : e(E), d(D) {
		if (d < 0) { e = -e; d = -d; }
	}
	bool operator<(fraction o) const { return e * o.d < o.e * d; }
	bool operator==(fraction o) const { return e * o.d == o.e * d; }
	fraction operator*(fraction o) const { return fraction(e * o.e, d * o.d); }
	fraction operator+(fraction o) const { return fraction(e * o.d + o.e * d, d * o.d); }
};
