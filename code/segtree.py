class SegTree:
	def f(a, b):
		return a + b
	UNIT = 0 # neutral value for f
	
	def __init__(self, n):
		self.s = [self.UNIT] * (2 * n)
		self.n = n
	def set(self, pos, val):
		pos += self.n
		self.s[pos] = val
		while pos > 1:
			pos //= 2
			self.s[pos] = SegTree.f(self.s[pos * 2], self.s[pos * 2 + 1])
	def query(self, lo, hi): # hi not included
		ra, rb = self.UNIT, self.UNIT
		lo, hi = lo + self.n, hi + self.n
		while lo < hi:
			if lo % 2:
				ra = SegTree.f(ra, self.s[lo])
				lo += 1
			if hi % 2:
				hi -= 1
				rb = SegTree.f(self.s[hi], rb)
			lo, hi = lo // 2, hi // 2
		return SegTree.f(ra, rb)
