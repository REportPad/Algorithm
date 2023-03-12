class Solution:
    def balancedStringSplit(self, s: str) -> int:
        d={}
        res=0
        for item in s:
            d[item]=d.get(item,0)+1
            if 'L'in d and 'R' in d and d['R']==d['L']:
                res+=1
                d={}
        return res
