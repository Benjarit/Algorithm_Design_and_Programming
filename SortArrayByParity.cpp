
/*
  *
  * Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
  *
  * You may return any answer array that satisfies this condition.
  * 
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result;
        for(int x = 0; x < A.size(); x++){
            if( A[x]%2 == 0 ){
               result.push_back(A[x]);
            }
        }
        for(int x = 0; x < A.size(); x++){
            if( A[x]%2 != 0 ){
               result.push_back(A[x]);
            }
        }
        return result;
    }
};
