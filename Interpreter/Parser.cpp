//
//  Parser.cpp
//  Interpreter
//
//  Created by Jonathan Raysor on 12/15/19.
//  Copyright © 2019 Jonathan Raysor. All rights reserved.
//

#include "Parser.hpp"
#include <deque>
#include <iostream>

using namespace std;

// build a symbol table based off of the tokens passed from the lexer
Parser::Parser(deque<pair<string,string>> tokens){
    
   symbolTable = tokens;
    
}

// retrieve tokens from the symbol table in the proper order
// which is why we are taking tokens from the front
// then removing the token from the front to move along
void Parser::get_token(){
    
    currentToken = symbolTable.front();
    symbolTable.pop_front();
    
}

// check to make sure the current token matches the type we are expecting
void Parser::match_type(string token){
    
    if(token == currentToken.first){
        get_token();
    }
    
    else{
        cout << "Expected: " << token << " Given: " << currentToken.first << "." << endl;
        exit(1);
    }
}

// this is where we will process each line of code inputted by the user
void Parser::process(){
    
        get_token();
    
        if(currentToken.first == "identifier"){
            string token = currentToken.second;
            match_type("identifier");
            match_type("equals");
            int num = exp();
            mappings[token] = num;
            match_type("semi");
        }
    
        else{
            cout << "error" << endl;
        }
}

// return all the identifiers with their values
unordered_map<string, int> Parser::getMappings(){
    
    return mappings;

}

// exp_prime is used to determine if we need to manipulate our given value
int Parser:: exp_prime(){
    if(currentToken.first == "plus"){
        match_type("plus");
        return exp();
    }
    if(currentToken.first == "minus"){
        match_type("minus");
        return -exp();
    }
    return 0;
}

// here we finally execute our expression and manipulate any values that have been specified
int Parser::exp(){

        int num = term();
        if (currentToken.first == "plus" || currentToken.first == "minus"){
            num += exp_prime();
        }
        return num;
        }

// here we determine if any term needs to be multiplied
int Parser::term_prime(){

    match_type("multiply");
    return term();

}

// here we make execution on our term and check whether or not multiplication is needed.
int Parser::term(){

    int num = fact();

    if(currentToken.first == "multiply"){
        num *= term_prime();
    }
    return num;
}

// finally we build up a final expression based off of all the given rules from the grammar
int Parser::fact() {
    if(currentToken.first == "left") {
        match_type("left");
        int num = exp();
        match_type("right");
        return num;
    }
    else if(currentToken.first == "minus") {
        match_type("minus");
        return -fact();
    }
    else if(currentToken.first == "plus") {
        match_type("plus");
        return fact();
    }
    else if(currentToken.first == "literal") {
        int num = stoi(currentToken.second);
        match_type("literal");
        return num;
    }
    else if(currentToken.first == "identifier") {
        if(mappings.find(currentToken.second) == mappings.end()) {
            cout << "Variable " << currentToken.second << " was not found.\n"; exit(-1);
        }
        string value = currentToken.second;
        match_type("identifier");
        return mappings[value];
    }
    return 0;
}


