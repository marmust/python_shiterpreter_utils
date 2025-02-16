#pragma once

#include <iostream>
#include <vector>
#include "token.h"

#define STANDARD_SPLITTER "|"
#define START_TEXT "START >|"
#define END_TEXT "|< END"

void printTokenVector(const std::vector<Token> tokenVector);