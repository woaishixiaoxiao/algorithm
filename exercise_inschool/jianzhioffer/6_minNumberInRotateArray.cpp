//�ð�ֲ��ҽ�����⣬��Ϊ��ֹ�����arr[beg]�Ǵ��ڵ���arr[end]�ģ���ʼ��Ҳ�������������
//�������м�ֻҪ����һ������>arr[beg]����ô��߷�Χ�Ϳ�����С��beg=mid(���ܼ�1����Ϊbeg��Ҫ��֤�����
//��һ�Ͳ�һ���ˣ�,�ұ�ֻҪС��arr[end]��������С�� 
//end=mid����Ϊ�����������С�������� ��arr[mid]��������ұߵ����������������������ߵ�������������ߵ�����
//����Ҳ��һ���ķ���������������Ƿ�Χ���������Ҳ�������ұߣ�����ֻ�ô����￪ʼ˳������� ,���������߲������ұ�
//��ôҲ�Ǻ�����һ���ķ��� 
#include<iostream>
#include<vector>
using namespace std;
int InorderSearch(vector<int>&rotateArray,int beg,int end){
	int res=rotateArray[beg];
	for(int i=beg+1;i<=end;i++){
		if(rotateArray[i]<rotateArray[i-1]){
			res=rotateArray[i];
			break;
		}
	}
	return res;
}
int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty()){
        return 0;
    }
    int end=rotateArray.size()-1;
    int beg=0;
    int mid;
    while((end-beg)>=2){
    	cout<<beg<<" "<<end<<endl;
        mid=(beg+end)/2;
        if((rotateArray[mid]==rotateArray[beg])&&(rotateArray[mid]==rotateArray[end])){
            return InorderSearch(rotateArray,beg,end);
        }else{
            if(rotateArray[mid]>=rotateArray[beg]){
                beg=mid;
            }else if(rotateArray[mid]<=rotateArray[end]){
                end=mid;
            }
        }
    }
    cout<<beg<<" "<<end<<endl; 
    int res;
    if((end-beg)==1){
        res=rotateArray[beg]<rotateArray[end]?rotateArray[beg]:rotateArray[end];//���Ƶ�ǰ�������Ϊ0��˳�� 
    }else{
        res=rotateArray[beg];
    }
    return res;
} 
main(){
	vector<int>ivec={3,4,5,1,2,3};
	cout<<minNumberInRotateArray(ivec);
}
