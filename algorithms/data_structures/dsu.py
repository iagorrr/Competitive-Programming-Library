"""
    Disjoint
    Set 
    Union 
"""
class DSU:
    def __init__(self, n):
        self.n = n
        self.p = [x for x in range(0, n+1)]
        self.size = [0 for i in range(0, n+1)]
    def find_set(self, x): # log n
        if self.p[x] == x:
            return x
        else:
            self.p[x] = self.find_set(self.p[x])
            return self.p[x]
    def same_set(self, x, y): # log n
        return bool(self.find_set(x) == self.find_set(y))
    def union_set(self, x, y): # log n
        px = self.find_set(x)
        py = self.find_set(y)

        if px == py:
            return
         
        size_x = self.size[px]
        size_y = self.size[py]

        if size_x > size_y:
            self.p[py] = self.p[px]
            self.size[px] += self.size[py]
        else:
            self.p[px] = self.p[py]
            self.size[py] += self.size[px]

