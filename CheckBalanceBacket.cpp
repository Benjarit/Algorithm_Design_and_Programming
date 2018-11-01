/******************************************************************************

                                   Benjarit Hotra
      Program checks for wheater an input string has a balance number of curry {}
      
                            Time complexity of the operation
                                        O(N)

*******************************************************************************/

#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool isBalancePar(string);
int main()
{
    string result;
    string testString = "{sdssdff{sdfd{}fsdfd}ssdfds}";
    regex charDel("[^{}]|");
    
    regex_replace(back_inserter(result), testString.begin(), testString.end(), charDel, "");
    if(isBalancePar(result)){
        cout << "Balance!!" << endl;
    }else{
        cout << "Not Balance!!" << endl;
    }
    
    return 0;
}
bool isBalancePar(string par){
    if(par.size() == 0 || par.size() == 1){
      return false; 
    }else if (par.size() == 2){
        if(par[0] == '{' && par[1] == '}'){
            return true;
        }
        return false;
    }
    /* This will create *Short-circuit* as second condition will not be evaluated */
    // return false && (isBalancePar(par.substr(1,par.size()-2)));
    return (par[0] == '{' && par[par.size()-1] == '}') && (isBalancePar(par.substr(1,par.size()-2)));
}
