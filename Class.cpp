/******************************************************************************

                              

*******************************************************************************/

#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
class Family{
    private:
        int houseHoldSize;
        string parent1;
        string parent2;
    
    public:
        
        void setParent1(string);
        void setParent2(string);
        void setHouseHoldSize(int);
        int getHouseHoldSize();
};
void Family::setHouseHoldSize(int houseHoldSize){
    this->houseHoldSize = houseHoldSize;
}
void Family::setParent1(string parent1){
    this->parent1 = parent1;
}
void Family::setParent2(string parent2){
    this->parent2 = parent2;
}
int Family::getHouseHoldSize(){
    return this->houseHoldSize;
}

int main()
{
    Family fam;
    fam.setHouseHoldSize(6);
    cout << fam.getHouseHoldSize() << endl;

    return 0;
}
