/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。*/
//class Solution {
//public:
#include<vector>
#include<iostream>
using namespace std;
    void reOrderArray(vector<int> &array) {
    	int temp, i, j;
        if( array.empty() ) return;
        for( i = 0 ; i < array.size(); i++ ) {
        	temp = array[i];
        	if( temp % 2 ) {    //这里和下面都是取余运算符！ 
        		for( j = i; j >= 1; j-- ) {
				    if( array[j - 1] % 2 ) {
				    	break;
					}else {
						array[j] = array[j - 1];
					}
				}
				array[j] = temp;
			}
		}
    }
int main() {
	vector<int> ivec;
	for(int i = 1; i <= 3; i++) {
		ivec.push_back(i);
	}
	reOrderArray(ivec);
	for(int i = 0; i < ivec.size(); i++) {
		cout<<ivec[i]<<" ";
	}
}
