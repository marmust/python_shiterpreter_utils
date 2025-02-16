#include "token.h"

// ctor
// input: new token's text and type
// output: none
Token::Token(std::string tokenText, TokenPurpose tokenPurpose)
{
	this->_tokenText = tokenText;
	this->_tokenPurpose = tokenPurpose;
}

// dtor
// input: none
// output: none
Token::~Token()
{
	// nothjing to delete
}

////////// getters, self explanatory //////////

std::string Token::getTokenText() const
{
	return this->_tokenText;
}

TokenPurpose Token::getTokenPurpose() const
{
	return this->_tokenPurpose;
}