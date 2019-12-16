//
//  Lexer.cpp
//  Interpreter
//
//  Created by Jonathan Raysor on 12/2/19.
//  Copyright © 2019 Jonathan Raysor. All rights reserved.
//

#include "Lexer.hpp"
#include <cctype>
#include <iostream>
using namespace std;

// this is where we will define each token for the parser
Lexer::Lexer(vector<string> tokenized){
    bool flag = true;
    int j = 1;
    for (auto i : tokenized){
        
        if (isalpha(i[0]) || i[0] == '_'){
               while(j < i.length() && flag == true){
                   if(isalpha(i[j]) || i[j] == '_' || isdigit(i[j])){
                       j++;
                   }
                   else{
                       flag = false;
                   }
               }
                if (flag){
                    tokens.push_back(pair<string,string>("identifier",i));
                }
        }
        else if (i[0] == '='){
               tokens.push_back(pair<string,string>("equals", i));
        }
        else if (i[0] == '-'){
           tokens.push_back(pair<string,string>("minus", i));
        }
        else if (i[0] == '+'){
           tokens.push_back(pair<string,string>("plus", i));
        }
        else if (i[0] == '*'){
           tokens.push_back(pair<string,string>("multiply", i));
        }
        else if (i[0] == '('){
           tokens.push_back(pair<string,string>("left", i));
        }
        else if (i[0] == ')'){
           tokens.push_back(pair<string,string>("right", i));
        }
        else if (i[0] == ';'){
            tokens.push_back(pair<string,string>("semi", i));
        }
        else if (i[0] == '0' && i.length() == 1){
            tokens.push_back(pair<string,string>("literal", i));
        }
        else if(i[0] >= '1' && i[0] <= '9'){
            flag = true;
            j = 1;
            while (j < i.length() && flag == true){
                if (!isdigit(i[j])){
                    flag = false;
                }
                j++;
            }
            if (flag){
                tokens.push_back(pair<string,string>("literal", i));
            }
        }
        else{
            tokens.push_back(pair<string, string>("error", "Error: Not valid input: " + i));
        }
            
    }
}

// if the user would like to print each token for debugging purposes
void  Lexer::printTokens(){
    for (auto i : tokens){
    
        cout << i.first << " " << i.second << endl;
    
    }
}

// return the double ended queue with the tokens
deque<pair<string,string>> Lexer::getTokens(){
    return tokens;
}
