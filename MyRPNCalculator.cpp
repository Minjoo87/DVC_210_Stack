// Programmer: Minjoo Kim
// Programmer's ID: 1581736

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Stack.h"

int main(){
    
    cout << "Programmer: Minjoo Kim\n";
    cout << "Programmer's ID: 1581736\n";
    cout << "File: " << __FILE__ << endl;
    
    Stack<string> mainStack;
    string input = "";
    Stack<string> mainCopyStack = mainStack;
    
    while(true){
        cout << "Enter: ";
        
        while (!mainCopyStack.empty()) {
            cout << mainCopyStack.peek() << " ";
            mainCopyStack.pop();
        }
        
        cin >> input;
        if(input == "Q" || input == "q"){
            break;
        }
        
        if (!(input == "+" || input == "*" || input == "/" || input == "-")) {
            mainStack.push(input);
        }else{
            if (mainStack.size() > 1) {
                double val1 = atof(mainStack.peek().c_str());
                mainStack.pop();
                double val2 = atof(mainStack.peek().c_str());
                mainStack.pop();
                double result = 0.0;
                
                if(input == "+"){
                    result = val1 + val2;
                }
                else if(input == "*"){
                    result = val1 * val2;
                }
                else if(input == "-"){
                    result = val2 - val1;
                }
                else if(input == "/"){
                    result = val2 / val1;
                }
                
                ostringstream strs;
                strs << result;
                mainStack.push(strs.str());
            }
        }
        mainCopyStack = mainStack;
    }
}
