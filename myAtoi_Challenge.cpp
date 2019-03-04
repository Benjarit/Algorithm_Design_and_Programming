



class Solution {
/*

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

*/
	
	
	
	
public:
    int myAtoi(string str) {
     
        size_t front_space = str.find_first_not_of(' ');
        if(front_space == string::npos){
            return 0;
        }
        size_t trailing_space = str.find_last_not_of(' ');
        str = str.substr(front_space,(trailing_space-front_space)+1);

        bool neg = false;
        if(str[0] == '-'){
            neg = true;
            str = str.substr(1);
        }else if(str[0] == '+'){
            str = str.substr(1);
        }
        else if(str[0] > '9' || str[0] < '0'){
            return 0;
        }

        double result = 0;
        int i = 0;
        while(i < str.size() && str[i] >= '0' && str[i] <= '9'){
            result = result * 10 + (str[i] - '0');
            i++;
        }
        
        if(neg){
            result = -result;
        }
        if(result > INT_MAX ){
            return INT_MAX ;
        }
        if (result < INT_MIN ){
		    return INT_MIN ;
        }
        return (int)result;
    }
};
