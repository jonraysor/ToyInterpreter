//
//  Lexer.hpp
//  Interpreter
//
//  Created by Jonathan Raysor on 12/2/19.
//  Copyright © 2019 Jonathan Raysor. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp

#include <stdio.h>
#include <regex>
#include "Tokenizer.hpp"
#include <string>

class Lexer{
  
private:
    deque<pair<string,string>> tokens;
    
public:
    Lexer(vector<string> tokenized);
    pair<string,string> nextToken();
    deque<pair<string,string>> getTokens();
    void printTokens();
};

#endif /* Lexer_hpp */
