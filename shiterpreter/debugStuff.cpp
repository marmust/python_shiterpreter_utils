#include "debugStuff.h"

// function to translate TokenPurpose enum into a string
// input: TokenPurpose enum value
// output: normal string name
std::string tokenPurposeToString(TokenPurpose purpose)
{
    switch (purpose)
    {
    case Arithmetic:
        return "Arithmetic";
    case BooleanLogic:
        return "BooleanLogic";
    case Comparison:
        return "Comparison";
    case ControlFlow:
        return "ControlFlow";
    case Iteration:
        return "Iteration";
    case Assignment:
        return "Assignment";
    case Priority:
        return "Priority";
    case Name:
        return "Name";
    default:          
        return "GETOUT--";
    }
}

// fuinction to print a vector of tokens in a nice format
// input: vec of tokens
// output: none
void printTokenVector(const std::vector<Token> tokenVector)
{
    // another "self explanatory" ahh code
	std::cout << START_TEXT;

	for (auto iterator = tokenVector.begin(); iterator != tokenVector.end(); iterator++)
	{
		std::cout << (*iterator).getTokenText() << STANDARD_SPLITTER;
	}

	std::cout << END_TEXT << std::endl;

    std::cout << START_TEXT;

    for (auto iterator = tokenVector.begin(); iterator != tokenVector.end(); iterator++)
    {
        std::cout << tokenPurposeToString((*iterator).getTokenPurpose()) << STANDARD_SPLITTER;
    }

    std::cout << END_TEXT << std::endl;
}