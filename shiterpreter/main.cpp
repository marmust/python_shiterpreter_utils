#include "tokenizer.h"
#include "debugStuff.h"

int main()
{
	Tokenizer* testTok = new Tokenizer();

	printTokenVector(testTok->tokenize(">=<===!=<><>=="));

	return 0;
}