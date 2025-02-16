#pragma once

#include <iostream>
#include <vector>
#include "pythonStructureOutlines.h"
#include "token.h"
#include <algorithm>

class Tokenizer
{
private:
    // allowed tokens list
    std::vector<std::string> tokenStrings =
    {
        // variable / Math operations
        TOKEN_ASSIGN, TOKEN_ADD, TOKEN_SUB, TOKEN_DIVIDE, TOKEN_MULTIPLY,

        // boolean algebra & conditions
        TOKEN_TRUE, TOKEN_FALSE, TOKEN_IF, TOKEN_ELSE,
        TOKEN_COMPARE_EQUALS, TOKEN_COMPARE_NOT_EQUALS,
        TOKEN_COMPARE_BIGGER, TOKEN_COMPARE_SMALLER,
        TOKEN_COMPARE_BIGGER_EQUALS, TOKEN_COMPARE_SMALLER_EQUALS,
        TOKEN_AND, TOKEN_OR, TOKEN_NOT,

        // iteration
        TOKEN_WHILE,

        // priority
        TOKEN_OPEN_BRACKET, TOKEN_CLOSE_BRACKET
    };

    bool isToken(const std::string suspectedSubstring);
    TokenPurpose getTokenPurpose(const std::string tokenString) const;
    Token* getImmediateMatch(const std::string line);

public:
    // ctor / dtor
    Tokenizer();
    virtual ~Tokenizer();

	std::vector<Token> tokenize(const std::string line);
};