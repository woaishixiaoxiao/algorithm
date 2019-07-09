#include<iostream>
#include<vector>
using namespace std;
vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int>res;
    if(matrix.empty()){
        return res;
    }
    if(matrix[0].empty()){
        return res;
    }
    int rows=matrix.size();
    int cols=matrix[0].size();
    int row1=0,col1=0;
    int row2=rows-1,col2=cols-1;
    int row,col;
    while((row1<=row2)&&(col1<=col2)){
        row=row1;
        for(col=col1;col<=col2;col++){
            res.push_back(matrix[row][col]);
        }
        col=col2;
        for(row=row1+1;row<=row2;row++){
            res.push_back(matrix[row][col]);
        }
        row=row2;
        if(row1!=row2){
        	for(col=col2-1;col>=col1;col--){
            	res.push_back(matrix[row][col]);
        	}
		}

        col=col1;
        if(col1!=col2){
        	for(row=row2-1;row>row1;row--){
            	res.push_back(matrix[row][col]);
        	}
		}
        row1+=1;
        col1+=1;
        row2-=1;
        col2-=1;
    }
    return res;
}
main(){
	vector<vector<int> >matrix={{1,2,3,4,5}};
	vector<int>res=printMatrix(matrix);
	for(auto e:res){
		cout<<e<<" ";
	}
	cout<<endl;
}
