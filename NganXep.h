#ifndef _NganXep_H_
#define _NganXep_H_

#include <stdio.h>
#include "Stack.h"
#include <string.h>

int getType(char chr);
bool isSameType(char chr1, char chr2);
bool checkBracketPairs(char* str);
void btNganXep();

#endif