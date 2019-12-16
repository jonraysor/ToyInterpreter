//
//  main.cpp
//  Interpreter
//
//  Created by Jonathan Raysor on 12/2/19.
//  Copyright © 2019 Jonathan Raysor. All rights reserved.
//

#include <iostream>
#include "Tokenizer.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"



int main(int argc, const char * argv[]) {

    cout << "Enter commands below" << endl << "Enter exit() to exit the interpreter" << endl << endl;
    
    string input;
    getline(cin, input);

    while (input != "exit()"){
    
        Tokenizer token(input);
        
        token.Tokenize();
        
        Lexer lexed(token.getTokenizedItems());
        
        Parser parsed(lexed.getTokens());
        parsed.process();
    
        for (auto i : parsed.getMappings()){

            cout << i.first << "=" << i.second << endl;
        
        }
        getline(cin, input);
    }
    return 0;
}
