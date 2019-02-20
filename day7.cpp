//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

class Solution {
public:
    int jumpFloor(int number) {
         if( number <= 2 ) {
             return number;
         }
        return jumpFloor( number -1 ) + jumpFloor( number - 2 );
    }
};

//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

class Solution {
public:
    int jumpFloorII(int number) {
        if( number <= 2 ) return number;
        vector<int>dp;
        dp.resize(number + 1);
		dp[0] = 1;
		dp[1] = 1;
        for( int i = 2; i <= number; i++ ) {
			dp[i] = 0;
			for( int j = 0; j < i; j++ ) {
				dp[i]+=dp[j];
			}
        }
        return dp[number];
    }
};

//第一个青蛙跳 F(n) = F(n-1) + F(n-2);
//第二个青蛙跳 F(n) = F(n-1) + F(n-2) + .... + F(0);  
//第一个问题 不用保存数组即可，而第二个是要保存数组的

//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//f(n) = f(n-1) + f(n-2)*2    这样子会有问题，会有重复的。 最后剩下的一块砖头有一种方式也就是F(n-1) 最后剩下的两块砖头，也仅有一种方式F(n-2) 
//虽然最后剩下的两块砖头有两种方式，但是竖着摆的方式，在F(n)中已经包含了。因为Fn(-1)中肯定有最后一块是竖着结尾的。
class Solution {
public:
    int rectCover(int number) {
        if( number <= 2 ) return number;
        int dp0, dp1, dp2;
        dp0 = 1, dp1 = 2;
        for(int i = 3; i <= number; i++) {
            dp2 = dp0 + dp1;
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp2;
    }
};