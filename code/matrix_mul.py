def matmul(a, b):
    res = [[0] * len(a) for i in range(len(a))]
    for i in range(len(a)):
        for j in range(len(a)):
            for k in range(len(a)):
                res[i][j] += a[i][k] * b[k][j]
    return res
