#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>res;
        if(matrix.empty())
            return res;
        int begRow = 0;
        int begCol = 0;
        int endRow = matrix.size() - 1;
        int endCol = matrix[0].size() - 1;
        while(begRow <= endRow && begCol <= endCol)
        {
            for(int col = begCol; col <= endCol; col++)
            {
                res.push_back(matrix[begRow][col]);
            }
            for(int row = begRow + 1; row <= endRow; row++)
            {
                res.push_back(matrix[row][endCol]);
            }
            for(int col = endCol - 1; col >= begRow; col--)
            {
                res.push_back(matrix[endRow][col]);
            }
            for(int row = endRow -1; row > begRow; row--)
            {
                res.push_back(matrix[row][begCol]);
            }
            begRow += 1;
            begCol += 1;
            endRow -= 1;
            endCol -= 1;
        }
        return res;
    }
};
main()
{
	vector<vector<int> >ivec;
	for(int i = 1; i <= 5; i++)
	{
		vector<int>temp;
		temp.push_back(i);
		ivec.push_back(temp);
	}
	Solution s;
	vector<int>res;
	res = s.printMatrix(ivec);
}
