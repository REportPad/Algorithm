# Answer 1
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        m = dict(zip(indices, s))
        s = ''
        for i in range(len(m)):
            s += m.get(i)
        return s
        
 
#Answer 2
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        t = [""] * len(s)
        for i, j in enumerate(indices):
            t[j] = s[i]
        return "".join(t)
