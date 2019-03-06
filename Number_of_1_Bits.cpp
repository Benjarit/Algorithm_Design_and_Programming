/*
  * Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;
        while( n != 0){
            if( (n & 0x1) == 1){
               counter++; 
            }
            n >>= 1;
        }
        return counter;
    }
};
