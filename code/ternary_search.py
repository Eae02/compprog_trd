def ternarySearch(a, b, f):
	assert a <= b
	while b - a >= 5:
		mid = (a + b) // 2
		if f(mid) < f(mid+1): # <= for last index
			a = mid 
		else:
			b = mid + 1
	#for i in range(b, a-1, -1): to get last index
	for i in range(a+1, b+1):
		if f(a) < f(i):
			a = i
	return a
