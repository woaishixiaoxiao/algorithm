/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ�
�������鳤�ȵ�һ�룬������2����������������0��
*/

class Solution {
public:
    bool compare(int a, int b) {
        return a < b;
    }
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int number,count,size;
        count = 1;
        size = numbers.size();
        if( numbers.empty() ) return 0;
        sort( numbers.begin(), numbers.end(), compare);
        number = numbers[0];
        for(int i = 1;i < size; i++) {
            if( numbers[i] == number ) {
                count++;
            }else {
                if( count > (size / 2) ) {
                    return number;
                }else {
                    count = 1;
                    number = numbers[i];
                }
            }
        }
        if( count > (size / 2) ) return number;
        return 0;
    }
};
