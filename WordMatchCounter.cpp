/******************************************************************************



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
    regex slashDel("\\[|\\]|\\.|/");
    fstream myfile;
    myfile.open ("info.in");
    
    while (myfile >> output) {
        string result;
        regex_replace (back_inserter(result), output.begin(), output.end(), slashDel, "");
        
        /* 
            If key already exists in the map, then do incrementation
            If key is not in the map, then initialize mapped value to 1
        */
        if(freqWord.find(result) != freqWord.end()){
            freqWord[result]++;
        }
        else{
            freqWord[result] = 1;
        }
        cout << result << endl;
        word_count++;
    }
    
    // Printing out the result
    cout << "\n============ There are " << word_count << " words in the file.=============\n";
    cout << "Result:";
    
    cout << "\n============ There are " << freqWord.size() << " unique words in the file.=============";
    
    for (pair<string, int> x : freqWord){
      cout << "\n============ \"" << x.first << "\" has " << x.second << " places in the file.============="; 
    }
    
    myfile.close();
    return 0;
}
