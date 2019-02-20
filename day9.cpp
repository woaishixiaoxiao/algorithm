//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
class Solution {
public:
    double Power(double base, int exponent) {
    	bool is_positive = true;
    	double positive_res;
    	if( exponent == 0 ) return 1;
    	double limit = 0.00000001;
    	if( abs( exponent - 0 ) < limit ) {
    		return 0;
		}
    	if( base > 0 ) {
    		is_positive = false;
    		base = 0 - base;
		}
		positive_res = pow(base, exponent);
		if( exponent / 2 && !is_positive ) {
			return 0 - positive_res;
		}else {
			return positive_res;
		}
    }
};

