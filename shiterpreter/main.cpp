#include "tokenizer.h"
#include "debugStuff.h"

int main()
{
	Tokenizer* testTok = new Tokenizer();

	printTokenVector(testTok->tokenize("niggahuzz=123"));

	return 0;
}