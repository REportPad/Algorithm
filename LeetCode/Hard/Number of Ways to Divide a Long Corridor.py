MOD = 10**9+7
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        n=len(corridor)
        if n == 1:
            return 0
        if n == 2:
            if corridor[0] == "S" and corridor[1] == "S":
                return 1
            return 0
        if n == 3:#sss sps ssp pss ,pps ppp
            cnt=0
            for c in corridor:
                if c == "S":
                    cnt+=1
            if cnt == 2:
                return 1
            return 0
        if n == 4:#sss sps ssp pss ,pps ppp
            cnt=0
            for c in corridor:
                if c == "S":
                    cnt+=1
            if cnt%2 == 1:#1,3
                return 0
            elif cnt == 2 or cnt == 4:
                return 1
        if n == 5:
            cnt=0
            for c in corridor:
                if c == "S":
                    cnt+=1
            if cnt%2 == 1:#1,3,5
                return 0
            elif cnt == 2:
                return 1
            elif cnt == 4:#ssssp, sssps sspss
                if corridor[2] == "P":
                    return 2
                return 1
        #n>=6
        cnt=0
        for c in corridor:
            if c == "S":
                cnt+=1
        if cnt == 0:
            return 0
        if cnt%2 == 1:#1,3,5,7...
            return 0
        elif cnt == 2 or cnt == n:
            return 1
        #cnt=4,6,8,10,...
        cnt_s=0
        cnt_p=0
        ans = 1
        for c in corridor:
            if cnt_s < 2:
                if c == "S":
                    cnt_s+=1
                if cnt_s == 2 and c == "P":
                    cnt_p+=1
            elif cnt_s == 2:
                if c == "S":
                    cnt_s += 1
                elif c == "P":
                    cnt_p += 1
            elif cnt_s == 3:
                if c == "S":
                    cnt_s+=1
                    if cnt_p > 0:
                        ans *= (cnt_p+1)
                    cnt_s = 2
                    cnt_p = 0
            elif cnt_s == 4:#ss[p..p]ss
                if cnt_p > 0:
                    ans *= (cnt_p+1)
                cnt_s = 2
                cnt_p = 0
            # print("c,ans,cnt_p,cnt_s:",c,ans,cnt_p,cnt_s)

        if cnt_p > 0 or ans > 1:
            return ans%MOD#
        return 1
