#pragma once

// tokens for variable / math operations
#define TOKEN_ASSIGN "="
#define TOKEN_ADD "+"
#define TOKEN_SUB "-"
#define TOKEN_DIVIDE "/"
#define TOKEN_MULTIPLY "*"

// tokens for boolean algebra & conditions
#define TOKEN_TRUE "True"
#define TOKEN_FALSE "False"
#define TOKEN_IF "if"
#define TOKEN_ELSE "else"
#define TOKEN_COMPARE_EQUALS "=="
#define TOKEN_COMPARE_NOT_EQUALS "!="
#define TOKEN_COMPARE_BIGGER ">"
#define TOKEN_COMPARE_SMALLER "<"
#define TOKEN_COMPARE_BIGGER_EQUALS ">="
#define TOKEN_COMPARE_SMALLER_EQUALS "<="
#define TOKEN_AND "and"
#define TOKEN_OR "or"
#define TOKEN_NOT "not"

// tokens for iteration
#define TOKEN_WHILE "while"

// tokens for priority
#define TOKEN_OPEN_BRACKET "("
#define TOKEN_CLOSE_BRACKET ")"

enum TokenPurpose
{
    Arithmetic,    // math operations
    BooleanLogic,  // boolean algebra & conditions
    Comparison,    // comparison operators
    ControlFlow,   // if else conditions
    Iteration,     // loops
    Assignment,    // variable assignment
    Priority,      // Priority setting
    Name           // identifiers (variable & function names)
};