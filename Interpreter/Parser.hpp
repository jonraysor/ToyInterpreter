//
//  Parser.hpp
//  Interpreter
//
//  Created by Jonathan Raysor on 12/15/19.
//  Copyright © 2019 Jonathan Raysor. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include "Lexer.hpp"
#include <unordered_map>
#include <deque>

class Parser{
  
private:
    
    deque<pair<string,string>> symbolTable;
    pair<string,string> currentToken;
    unordered_map<string, int> mappings;

public:
    
    Parser(deque<pair<string,string>>);
    void get_token();
    void match_type(string);
    void assign();
    void process();
    unordered_map<string, int> getMappings();
    int exp_prime();
    int exp();
    int term();
    int term_prime();
    int fact();
    
};


#endif /* Parser_hpp */
