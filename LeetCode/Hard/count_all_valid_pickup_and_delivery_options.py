class Solution:
    def countOrders(self, n: int) -> int:
        if n == 1:
            return 1

        f = [1,6]
        for i in range(2,n+1):
            f[1] = f[0]*(i*(2*i-1))
            f[0] = f[1]
        return f[1]%(10**9+7)
