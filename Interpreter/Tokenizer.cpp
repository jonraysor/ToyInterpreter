//
//  Tokenizer.cpp
//  Interpreter
//
//  Created by Jonathan Raysor on 12/2/19.
//  Copyright © 2019 Jonathan Raysor. All rights reserved.
//

#include "Tokenizer.hpp"

// Default constructor incase a parameter isnt passed
Tokenizer::Tokenizer(){
    
    to_be_tokenized = string();
    
}

// constructor if string is passed in to be tokenized
Tokenizer::Tokenizer(const string original_string){
    
    to_be_tokenized = original_string;
    
}

// where the tokenization will happen
void Tokenizer::Tokenize(){
    
    string temp = string();
    string semi = ";";
    
    for (char& c : to_be_tokenized){
        
        if (c != ' ' && c != ';')
           temp += c;
        if (c == ' '){
           tokenized.push_back(temp);
            temp.clear();
        }
        
        if (c == ';'){
            tokenized.push_back(temp);
            tokenized.push_back(semi);
            temp.clear();
            
        }
    }
}

// return all the tokenized items when requested
vector<string> Tokenizer::getTokenizedItems(){
    
    return tokenized;

}
