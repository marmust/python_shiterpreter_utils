#include "tokenizer.h"

// ctor
// input: none
// output: none
Tokenizer::Tokenizer()
{
	// nothing to init
}

// dtor
// input: none
// output: none
Tokenizer::~Tokenizer()
{
	// nothing to delete
}

// "main" function of this class. takes in string, returns vector of token classes (broken up string)
// input: string to tokenize
// output: vector of token objects
std::vector<Token> Tokenizer::tokenize(std::string line)
{
	int currentChar = 0;
	std::string currentSubstring = "";
	std::vector<Token> tokenizedResult;

	// consume the line until nothing is left
	while (line.size() != 0)
	{

		// run a few chars forward to parse current token (loop stops by break not by condition)
		while (true)
		{
			currentChar++;

			// compare current substring to all possible tokens and see if it matches
			currentSubstring = line.substr(0, currentChar);

			auto iterator = std::find(this->tokenStrings.begin(), this->tokenStrings.end(), currentSubstring);

			if (iterator != this->tokenStrings.end())
			{
				// if it passes, means we just matched a token, snip it off and add to vector
				Token* newToken = new Token(currentSubstring, Name);
				tokenizedResult.push_back(*newToken);

				// shorten line string
				line = line.substr(currentChar, line.size());

				currentSubstring = "";
				currentChar = 0;

				break;
			}
		}
	}

	return tokenizedResult;
}