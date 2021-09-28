while (lo < hi) {
	ll mid = lo + (hi - lo) / 2;
	if (f(mid)) // f should be false, then true
		hi = mid;
	else
		lo = mid + 1;
}
//lo is now the first index where f is true
