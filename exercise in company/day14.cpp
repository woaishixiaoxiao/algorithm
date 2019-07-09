/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ�
�������鳤�ȵ�һ�룬������2����������������0��
*/

/*���� �������� ֱ��������ķ�������*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int sz = numbers.size();
        if( sz == 0 ) return 0;
        int num = numbers[0], count = 1;
        for(int i = 1; i < sz; i++) {
            if( !count ) {
                num = numbers[i];
                count = 1;
                continue;
            }
            if( num == numbers[i] ) {
                count++;
            }else {
                count--;
            }
        }
        if( !count ) return 0;
        count = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if( num == numbers[i] ) count++;
        }
        if( count > ( sz /2 ) ) return num;
        return 0;
    }
};
 
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
