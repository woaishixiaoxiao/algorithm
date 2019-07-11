/*
��n����Ʒ�������и��Ե�����ͼ�ֵ�����и��������ı���������ñ�����װ�����Ʒ�������ļ�ֵ�ܺͣ�
Ϊ���㽲�����⣬���潲�������Ӿ����þ�������ִ��룬����eg��number��4��capacity��8
i����Ʒ��ţ�	1	2	3	4
w�������		2	3	4	5
v����ֵ��		3	4	5	6
1��ʹ�ö�ά��̬�滮��dp[n][m]��n����ǰn����Ʒ��m�������������ɵ�������������ֵ 
2�� dp[i][j]����ǰҪ�ŵ�n����Ʒ�������������ɵ���������j  ���ֵ��d[i-1]�й�ϵ
2.1����ǰ����Ʒ��W�����j��Ҫ����d[i][j] = d[i-1][j]����϶������ʣ�ѡi-1����Ʒ����ֵ����Ҳ��һ����d[i-1][j]��������û������Ҫע�����d[i][j]�������ǰi��������Ϊj������ֵ����������ǰn���������Ϊm������ֵ�����Բ�ɵ������ⲻ��������Ϊi��ʱ�����ǰi����ʱ�����Ը���������е�˳����û�й�ϵ�ġ� 
2.2�� ��ǰ����Ʒ��WС��J��Ҳ���ǵ�ǰ����Ʒi���Բ��ȥ����ô�����ļ�ֵ��V = d[i-1][j-w(i)] + v(j)��������ʽ�������ֿ��ܣ�һ���ǲ���ȡ������Ʒ��һ������Ҫȡ������Ʒ����ǰ�ķŽ�ȥ(���������������ӣ�a b�������������һ��a�ˣ���b��ʱ��Ҫô��aȡ������b�Ž�ȥ��Ҫô��abһ��Ž�ȥ)�����ϵ�ǰ�����������max(d[i-1][j], d[i-1][j-w(i)] + v(j)))
3����Ʒ��˳������Ľ���޹�ϵ
*/
#include<iostream>
#include<vector>
using namespace std;
#define MAXCOL 1000
#define MAXROW 1000
int main() {
	vector<vector<int>>thing;
	int num;
	int limit_w;
	int w, v;
	cin >> limit_w;
	cin>>num;
    thing.push_back({0,0});
	for(int i = 0; i < num; ++i) {
		cin >> w >> v;
		vector<int>tmp;
		tmp.push_back(w);
		tmp.push_back(v);
		thing.push_back(tmp);
	}
	int dp[MAXROW][MAXCOL] = {0}; //dp[0][j] dp[i][0]������0
	for(int i = 1; i <= num; ++i) {
		for(int j = 1; j <= limit_w; ++j) {
			int curr_w = thing[i][0];
			if(curr_w > j) {
				dp[i][j] = dp[i-1][j];
			}else {
				int last_v = dp[i-1][j - curr_w] + thing[i][1];
				dp[i][j] = dp[i-1][j] > last_v? dp[i-1][j] : last_v;
			}
		}
	}
	cout<<dp[num][limit_w];
}

