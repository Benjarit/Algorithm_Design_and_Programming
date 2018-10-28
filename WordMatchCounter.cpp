/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <unordered_map>
#include <regex>
using namespace std;

int main()
{
    string output;
    unordered_map<string, int> freqWord; 
    int word_count = 0;
    regex first ("\\[|\\]|\\.|/");
    fstream myfile;
    myfile.open ("info.in");
    while (myfile >> output) {
        string result;
        regex_replace (back_inserter(result), output.begin(), output.end(), first, "");
        
        if(freqWord[result] == 0){
            freqWord[result] = 1;
        }
        else{
            freqWord[result]++;
        }
        cout << result << endl;
        word_count++;
    }
    
    
    cout << "\n============ There are " << word_count << " words in the file.=============\n";
    cout << "Result:";
    for (auto x : freqWord){
      cout << "\n============ \"" << x.first << "\" has " << x.second << " places in the file.============="; 
    }
      
    myfile.close();
    return 0;
}
