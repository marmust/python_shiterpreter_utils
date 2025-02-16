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

// function to check if a substring matches to a token
// input: substring to check if its a token
// output: bool: true->is a perfect match for a token false->not a perfect match for a token
bool Tokenizer::isToken(const std::string suspectedSubstring)
{
	auto iterator = std::find(this->tokenStrings.begin(), this->tokenStrings.end(), suspectedSubstring);

	if (iterator != this->tokenStrings.end())
		return true;
	
	return false;
}

// function to translate a token string into its corresponding TokenPurpose type
// input: token string
// output: its purpose from enum
TokenPurpose Tokenizer::getTokenPurpose(const std::string tokenString) const
{
	// "self explanatory" ahh code
	if (tokenString == TOKEN_ASSIGN) return Assignment;
	if (tokenString == TOKEN_ADD || tokenString == TOKEN_SUB ||
		tokenString == TOKEN_MULTIPLY || tokenString == TOKEN_DIVIDE)
		return Arithmetic;

	if (tokenString == TOKEN_TRUE || tokenString == TOKEN_FALSE ||
		tokenString == TOKEN_AND || tokenString == TOKEN_OR ||
		tokenString == TOKEN_NOT)
		return BooleanLogic;

	if (tokenString == TOKEN_IF || tokenString == TOKEN_ELSE)
		return ControlFlow;

	if (tokenString == TOKEN_COMPARE_EQUALS || tokenString == TOKEN_COMPARE_NOT_EQUALS ||
		tokenString == TOKEN_COMPARE_BIGGER || tokenString == TOKEN_COMPARE_SMALLER)
		return Comparison;

	if (tokenString == TOKEN_WHILE)
		return Iteration;

	return Name;
}

// "main" function of this class. takes in string, returns vector of token classes (broken up string)
// input: string to tokenize
// output: vector of token objects
std::vector<Token> Tokenizer::tokenize(const std::string line)
{
	int currentChar = 0;
	std::vector<Token> tokenizedResult;
	std::string lineCopy = line;

	// consume the line until nothing is left
	while (lineCopy.size() != 0)
	{
		// get the next token in line
		Token* currentImmediateToken = this->getImmediateMatch(lineCopy);
		tokenizedResult.push_back(*currentImmediateToken);

		// snip away the found token's length from lineCopy
		lineCopy = lineCopy.substr(currentImmediateToken->getTokenText().size(), lineCopy.size());
	}

	return tokenizedResult;
}

// function to return the token or whatever the fuck substring before the next token
// input: line to evaluate for immediate token or "whatever the fuck" sequence
// output: Token object containing either an immediate token or the "whatever the fuck" substring
Token* Tokenizer::getImmediateMatch(const std::string line)
{
	std::string currentSubstring = "";
	int currentChar = 0;

	// check if the string starts with a known token
	for (auto iterator = this->tokenStrings.begin(); iterator != this->tokenStrings.end(); iterator++)
	{
		if (line.rfind(*iterator, 0) == 0) // use black magic + blood sacrifice in background to check if `line` starts with `token`
		{
			return new Token(*iterator, this->getTokenPurpose(*iterator));
		}
	}

	// iterate through the string, collecting "whatever the fuck"-belonging characters
	while (currentChar < line.size())
	{
		currentSubstring += line[currentChar];

		// check if the next character starts a valid token
		for (auto iterator = this->tokenStrings.begin(); iterator != this->tokenStrings.end(); iterator++)
		{
			if (line.substr(currentChar + 1).rfind(*iterator, 0) == 0) // does the rest of the string start with a token? idk lets find out
			{
				return new Token(currentSubstring, this->getTokenPurpose(currentSubstring));
			}
		}

		currentChar++;
	}

	// if no token found, return the entire string (unlikely, but still handled)
	return new Token(currentSubstring, this->getTokenPurpose(currentSubstring));
}