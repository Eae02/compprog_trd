from math import inf
def floydWarshall(m): # m[i][j] should be inf if i and j are not adjacent
	for i in range(len(m)):
		m[i][i] = min(m[i][i], 0)
	for k in range(len(m)):
		for i in range(len(m)):
			for j in range(len(m)):
				if m[i][k] != inf and m[k][j] != inf:
					m[i][j] = min(m[i][j], max(m[i][k] + m[k][j], -inf))
	#only needed if weights can be negative:
	for k in range(len(m)):
		if m[k][k] < 0:
			for i in range(len(m)):
				for j in range(len(m)):
					if m[i][k] != inf and m[k][j] != inf:
						m[i][j] = -inf
