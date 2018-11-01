/******************************************************************************

                                   Benjarit Hotra
      Program checks for wheater an input strign has a balance number of curry {}

*******************************************************************************/

#include <iostream>
#include <cstdlib>    /* srand, rand */
#include <ctime>
#include <stack>
#include <string>
using namespace std;

bool isBalancePar(string);
int main()
{
    string par = "{{}}";
    if(isBalancePar(par)){
        cout << "Balance!!" << endl;
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
    /* NOTE: This will create *Short-circuit* as second condition will not be evaluated */
    // return false && (isBalancePar(par.substr(1,par.size()-2)));
    return (par[0] == '{' && par[par.size()-1] == '}') && (isBalancePar(par.substr(1,par.size()-2)));
}
