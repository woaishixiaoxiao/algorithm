/*����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣*/
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
        	if( temp % 2 ) {    //��������涼��ȡ��������� 
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
