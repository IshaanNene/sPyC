#ifndef STRING_LIBRARY_H
#define STRING_LIBRARY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>

int getStringLength(const char *string);
char* capitalizeString(const char *string);
char* toLowerCase(const char *string);
char* toUpperCase(const char *string);
char* swapStringCase(const char *string);
char* caseFoldString(const char *string);
bool isAlphanumeric(const char *string);
bool isAlphabetic(const char *string);
bool isAscii(const char *string);
bool isDigitString(const char *string);
bool isDecimal(const char *string);
bool isIdentifier(const char *string);
bool isLowercase(const char *string);
bool isNumeric(const char *string);
bool isPrintable(const char *string);
bool isWhitespace(const char *string);
bool isUppercaseString(const char *string);
bool isTitleCase(const char *string);
bool startsWith(const char *string, const char *prefix);
bool endsWith(const char *string, const char *suffix);
int countCharacter(const char *string, char character);
int findSubstring(const char *string, const char *substring);
int indexSubstring(const char *string, const char *substring);
int rfindSubstring(const char *string, const char *substring);
int rindexSubstring(const char *string, const char *substring);
char* stripString(const char *string);
char* lstripString(const char *string);
char* rstripString(const char *string);
char** splitString(const char *string, const char *delimiter, int *count);
char** rsplitString(const char *string, const char *delimiter, int *count);
char** splitLines(const char *string, int *count);
char* joinStrings(const char *delimiter, char **strings, int count);
char* replaceSubstring(const char *string, const char *oldSubstring, const char *newSubstring);
char* encodeString(const char *string);
char* zeroFillString(const char *string, int width);
char* expandTabs(const char *string, int tabSize);
char* centerString(const char *string, int width, char fillChar);
char* leftJustifyString(const char *string, int width, char fillChar);
char* rightJustifyString(const char *string, int width, char fillChar);
char* partitionString(const char *string, const char *separator);
char* rpartitionString(const char *string, const char *separator);
char* formatString(const char *string, ...);
char* formatStringMap(const char *string, const char **keys, const char **values, int count);
char* maketrans(const char *from, const char *to);
char* translate(const char *str, const char *table);
char* title(const char *str);
char* removeprefix(const char *str, const char *prefix);
char* removesuffix(const char *str, const char *suffix);

#endif