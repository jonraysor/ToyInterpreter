//
//  Tokenizer.hpp
//  Interpreter
//
//  Created by Jonathan Raysor on 12/2/19.
//  Copyright © 2019 Jonathan Raysor. All rights reserved.
//

#ifndef Tokenizer_hpp
#define Tokenizer_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Tokenizer{
    
private:
    vector<string> tokenized;
    string to_be_tokenized;

public:
    
    Tokenizer();
    Tokenizer(string);
    void Tokenize();
    vector<string> getTokenizedItems(); 
    
};

#endif /* Tokenizer_hpp */
