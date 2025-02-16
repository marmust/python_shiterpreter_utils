#pragma once

#include <iostream>
#include "pythonStructureOutlines.h"

class Token
{
private:
	std::string _tokenText;
	TokenPurpose _tokenPurpose;

public:
	// ctor / dtor
	Token(std::string tokenText, TokenPurpose tokenPurpose);
	virtual ~Token();

	// getters
	std::string getTokenText() const;
	TokenPurpose getTokenPurpose() const;
};