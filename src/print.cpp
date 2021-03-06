#include "print.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void print(string text, string textColour, bool newLine)
{
    // print text with ANSI colour codes:

    if (textColour == "red") {
        printf("%c[1;31m", 27);
    } else if (textColour == "green") {
        printf("%c[1;32m", 27);
    } else if (textColour == "yellow") {
        printf("%c[1;33m", 27);
    } else if (textColour == "blue") {
        printf("%c[1;34m", 27);
    } else if (textColour == "magenta") {
        printf("%c[1;35m", 27);
    } else if (textColour == "cyan") {
        printf("%c[1;36m", 27);
    } else if (textColour == "brown") {
        printf("%c[1;94m", 27);
    } else {
        printf("%c[1;0m", 27);
    }

    if (newLine) {
        text += "\n";
    }
    printf(text.c_str(), 27);

    printf("%c[1;0m", 27);
}
