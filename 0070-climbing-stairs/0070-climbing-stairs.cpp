class Solution {
public:
    int climbStairs(int n) {
        if (n==1 || n==2 )
            return n;
        int oneStepBefore=1, twoStepBefore=2;
        int result;
        for(int i=3; i<=n; i++){
            result = oneStepBefore + twoStepBefore;
            oneStepBefore = twoStepBefore;
            twoStepBefore = result;
        }
        return result;
    }
};

// 1: 1 way
// 2: (1+1), (2) 2 ways
// 3: (1+1+1) (2+1) (1+2) 3 ways

// 4: (1*4) (2*2) (2+1+1) (1+2+1) (1+1+2) ()
// at n: (n-1) + (n-2)