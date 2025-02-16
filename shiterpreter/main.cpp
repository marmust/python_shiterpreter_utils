#include "tokenizer.h"
//#include "debugUtils.h"

#define STANDARD_SPLITTER "|"
#define START_TEXT "START >|"
#define END_TEXT "< END"

void printTokenVector(const std::vector<Token> tokenVector)
{
	std::cout << START_TEXT;

	for (auto iterator = tokenVector.begin(); iterator != tokenVector.end(); iterator++)
	{
		std::cout << (*iterator).getTokenText() << STANDARD_SPLITTER;
	}

	std::cout << END_TEXT << std::endl;
}

int main()
{
	Tokenizer* testTok = new Tokenizer();
	
	std::vector<Token> test123 = testTok->tokenize("TrueFalseTrueFalseasdasdFalseFalseTrue");

	printTokenVector(test123);

	//printTokenVector(testTok->tokenize("TrueFalse"));

	return 0;
}