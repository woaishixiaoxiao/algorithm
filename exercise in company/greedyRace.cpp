/*
�����Ŀ̰�ĵı������ڣ�*���ֻ���а���Ӯ��������ó��������ƴ����������������ȵ����Ŀ������̶���������ս����
̰�Ĳ��ԣ�
1�������ɵ�������������������������߱ȡ�
����Ϊ������ɵı����ܿ��ܾ�Ӯ�����ˣ��������߱ȣ�
2�������ɵ���������������������������ɵ�������������������ȡ�
���������е���Ӯ�����������������������ʧ��С�ģ��������ĺ����ȣ�
3������ȣ���Ƚ���ɵ��������������������
���������������������������߱ȡ�
����ɵ��������Ȼ��Ӯһ����Ӯ������������������϶�Ҳ���и������ȣ�����ѡ��С�ı�����á���
������������ɵ�������������������ȣ�ע������ս����ȵ����������������䣩��
���������е�������ɵ���������ˣ�������ƥ����䣬ѡ�������ģ��ɵ������������
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
using namespace std;
//����ķ�������ȷ������˳���ˣ�Ȼ����ݶԷ�����˳���϶�Ӧ��������� 
int greedy_race(vector<int> &myself, vector<int> &other) {
	int fin_score = 0;
	int i, j, k ,t;
	i = j = 0;
	k = t = myself.size() - 1;
	while(i <= k) {
		cout << k << " " << myself[k] <<endl;
		cout<<t<<" "<<other[t]<<endl;
		cout<<i<<" "<<myself[i]<<endl;
		cout<<j<<" "<<other[j]<<endl;
		if(myself[k] > other[t]) {
			fin_score += 1;
			--k;
			--t;
		}else if(myself[k] < other[t]) {
			fin_score -= 1;
		 	++i;
		 	--t;
		}else {
			if(myself[i] > other[j]) {
				++i;
				++j;
				fin_score += 1;
			}else {
				if(myself[i] < other[t]) {
					fin_score -= 1;
				}
				++i;
				--t;
			}
		}
		cout<<fin_score<<endl<<endl;
	}
	return fin_score;
}

int main() {
	vector<int> myself;
	vector<int> other;
	int res;
    int num, speed;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin>>speed;
        myself.push_back(speed);
    }
    for(int i = 0; i < num; i++) {
        cin>>speed;
        other.push_back(speed);
    }
	sort(myself.begin(), myself.end());
	sort(other.begin(), other.end()); 
	if((res = greedy_race(myself, other)) > 0) {
        cout<<"YES";
    }else {
        cout<<"NO";
    }
    cout << endl;
    cout<<res;
}


