//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
//计算机中负数就是补码 所以不用自己在去将n转换为二进制补码，另外sizeof得到的
//字节，不是位数，而且这道题也可以不用位数的方法。
class Solution {
public:
     int  NumberOf1(int n) {
         
         int count = 0;
         int sz = sizeof(int);
         for(int i = 0;i < 8 * sz; i++) {
             if( ( n & ( 1 << i) ) ) count++;
         }
        /*int count = 0;
        int flag = 1;
        while (flag != 0) {
            if ((n & flag) != 0) {
                count++;
            }
            flag = flag << 1;
        }*/
        return count;
     }
};

//最佳方法
//无论负数的补码还是正数的源码，-1 都是最后一位1变为0，1的右边变为0。而且与运算
//是不分正负数的运算的。所以最后一位高位也是会算入其中的
class Solution {
public:
     int  NumberOf1(int n) {
		 int count = 0;
		 while( n ) {
			 n = n & ( n - 1 );
			 count++;
		 }
		 return count;
     }
};