#pragma once
#include <string>

//3 degree programs
enum  DegreeProgram {SECURITY, NETWORK, SOFTWARE};

//the following array of strings is useful for printing labels equivalent to the enumerated values
static const std::string degreeProgramString[] = { "SECURITY", "NETWORK", "SOFTWARE" };

/*You use the enumerated value as an index
example:
degreeProgramString[SECURITY] yields the string "SECURITY"
*/