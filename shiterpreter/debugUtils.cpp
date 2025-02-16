#pragma once

#include "debugUtils.h"

// fuinction to print a vector of tokens in a nice format
// input: vec of tokens
// output: none
void printTokenVector(const std::vector<Token> tokenVector)
{
	std::cout << START_TEXT;

	for (auto iterator = tokenVector.begin(); iterator != tokenVector.end(); iterator++)
	{
		std::cout << (*iterator).getTokenText() << STANDARD_SPLITTER;
	}

	std::cout << END_TEXT << std::endl;
}