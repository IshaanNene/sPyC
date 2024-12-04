#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>

// Returns the length of the given string
int getStringLength(const char *string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

// Capitalizes the first character of the given string
char* capitalizeString(const char *string) {
    int length = getStringLength(string);
    if (length == 0) {
        return strdup(string);
    }
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    if (string[0] >= 'a' && string[0] <= 'z') {
        result[0] = string[0] - 32;
    } else {
        result[0] = string[0];
    }
    for (int i = 1; i < length; i++) {
        result[i] = string[i];
    }
    result[length] = '\0';
    return result;
}

// Converts all characters of the given string to lowercase
char* toLowerCase(const char *string) {
    int length = getStringLength(string);
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            result[i] = string[i] + 32;
        } else {
            result[i] = string[i];
        }
    }
    result[length] = '\0';
    return result;
}

// Converts all characters of the given string to uppercase
char* toUpperCase(const char *string) {
    int length = getStringLength(string);
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            result[i] = string[i] - 32;
        } else {
            result[i] = string[i];
        }
    }
    result[length] = '\0';
    return result;
}

// Swaps the case of each character in the given string
char* swapStringCase(const char *string) {
    int length = getStringLength(string);
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            result[i] = string[i] + 32;
        } else if (string[i] >= 'a' && string[i] <= 'z') {
            result[i] = string[i] - 32;
        } else {
            result[i] = string[i];
        }
    }
    result[length] = '\0';
    return result;
}

// Converts all characters of the given string to lowercase (alias for toLowerCase)
char* caseFoldString(const char *string) {
    return toLowerCase(string);
}

// Checks if the given string contains only alphanumeric characters
bool isAlphanumeric(const char *string) {
    int length = getStringLength(string);
    for (int i = 0; i < length; i++) {
        if (!((string[i] >= '0' && string[i] <= '9') || (string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))) {
            return false;
        }
    }
    return true;
}

// Checks if the given string contains only alphabetic characters
bool isAlphabetic(const char *string) {
    int length = getStringLength(string);
    for (int i = 0; i < length; i++) {
        if (!((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))) {
            return false;
        }
    }
    return true;
}

// Checks if the given string contains only ASCII characters
bool isAscii(const char *string) {
    int length = getStringLength(string);
    for (int i = 0; i < length; i++) {
        if ((unsigned char)string[i] > 127) {
            return false;
        }
    }
    return true;
}

// Checks if the given string contains only digit characters
bool isDigitString(const char *string) {
    int length = getStringLength(string);
    for (int i = 0; i < length; i++) {
        if (!(string[i] >= '0' && string[i] <= '9')) {
            return false;
        }
    }
    return true;
}

// Checks if the given string contains only decimal characters (alias for isDigit)
bool isDecimal(const char *string) {
    return isDigitString(string);
}

// Checks if the given string is a valid identifier
bool isIdentifier(const char *string) {
    int length = getStringLength(string);
    if (length > 0) {
        if ((string[0] >= '0' && string[0] <= '9') || !isAlphanumeric(&string[0])) {
            return false;
        }
    }
    for (int i = 1; i < length; i++) {
        if (!isAlphanumeric(&string[i])) {
            return false;
        }
    }
    return true;
}

// Checks if the given string contains only lowercase characters
bool isLowercase(const char *string) {
    int length = getStringLength(string);
    for (int i = 0; i < length; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            return false;
        }
    }
    return true;
}

// Checks if the given string contains only numeric characters (alias for isDigit)
bool isNumeric(const char *string) {
    return isDigitString(string);
}

// Checks if the given string contains only printable characters
bool isPrintable(const char *string) {
    int length = getStringLength(string);
    for (int i = 0; i < length; i++) {
        if ((unsigned char)string[i] < 32 || (unsigned char)string[i] > 126) {
            return false;
        }
    }
    return true;
}

// Checks if the given string contains only whitespace characters
bool isWhitespace(const char *string) {
    int length = getStringLength(string);
    for (int i = 0; i < length; i++) {
        if (string[i] != ' ') {
            return false;
        }
    }
    return true;
}
// Checks if the given string contains only uppercase characters
bool isUppercaseString(const char *string) {
    int length = getStringLength(string);
    for (int i = 0; i < length; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            return false;
        }
    }
    return true;
}
// Checks if the first character of the given string is uppercase
bool isTitleCase(const char *string) {
    return isUppercaseString(&string[0]);
}

// Checks if the given string starts with the specified prefix
bool startsWith(const char *string, const char *prefix) {
    while (*prefix) {
        if (*string++ != *prefix++) {
            return false;
        }
    }
    return true;
}

// Checks if the given string ends with the specified suffix
bool endsWith(const char *string, const char *suffix) {
    int stringLength = getStringLength(string);
    int suffixLength = getStringLength(suffix);
    if (suffixLength > stringLength) {
        return false;
    }
    return strcmp(string + stringLength - suffixLength, suffix) == 0;
}

// Counts the occurrences of the specified character in the given string
int countCharacter(const char *string, char character) {
    int count = 0;
    while (*string) {
        if (*string == character) {
            count++;
        }
        string++;
    }
    return count;
}

// Finds the first occurrence of the specified substring in the given string
int findSubstring(const char *string, const char *substring) {
    char *position = strstr(string, substring);
    if (position) {
        return position - string;
    }
    return -1;
}

// Finds the first occurrence of the specified substring in the given string and exits if not found
int indexSubstring(const char *string, const char *substring) {
    int position = findSubstring(string, substring);
    if (position == -1) {
        fprintf(stderr, "substring not found\n");
        exit(EXIT_FAILURE);
    }
    return position;
}

// Finds the last occurrence of the specified substring in the given string
int rfindSubstring(const char *string, const char *substring) {
    char *position = NULL;
    char *temp = strstr(string, substring);
    while (temp) {
        position = temp;
        temp = strstr(temp + 1, substring);
    }
    if (position) {
        return position - string;
    }
    return -1;
}

// Finds the last occurrence of the specified substring in the given string and exits if not found
int rindexSubstring(const char *string, const char *substring) {
    int position = rfindSubstring(string, substring);
    if (position == -1) {
        fprintf(stderr, "substring not found\n");
        exit(EXIT_FAILURE);
    }
    return position;
}

// Removes leading and trailing whitespace from the given string
char* stripString(const char *string) {
    int start = 0;
    int end = getStringLength(string) - 1;
    while (isspace(string[start])) {
        start++;
    }
    while (isspace(string[end])) {
        end--;
    }
    int length = end - start + 1;
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    strncpy(result, string + start, length);
    result[length] = '\0';
    return result;
}

// Removes leading whitespace from the given string
char* lstripString(const char *string) {
    int start = 0;
    while (isspace(string[start])) {
        start++;
    }
    int length = getStringLength(string) - start;
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    strncpy(result, string + start, length);
    result[length] = '\0';
    return result;
}

// Removes trailing whitespace from the given string
char* rstripString(const char *string) {
    int end = getStringLength(string) - 1;
    while (isspace(string[end])) {
        end--;
    }
    int length = end + 1;
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    strncpy(result, string, length);
    result[length] = '\0';
    return result;
}

// Splits the given string by the specified delimiter and returns an array of strings
char** splitString(const char *string, const char *delimiter, int *count) {
    char *copy = strdup(string);
    char *token = strtok(copy, delimiter);
    char **result = NULL;
    *count = 0;
    while (token) {
        result = (char **)realloc(result, (*count + 1) * sizeof(char *));
        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, delimiter);
    }
    free(copy);
    return result;
}

// Splits the given string by the specified delimiter from the right and returns an array of strings
char** rsplitString(const char *string, const char *delimiter, int *count) {
    char *copy = strdup(string);
    char *token = strtok(copy, delimiter);
    char **result = NULL;
    *count = 0;
    while (token) {
        result = (char **)realloc(result, (*count + 1) * sizeof(char *));
        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, delimiter);
    }
    free(copy);
    return result;
}

// Splits the given string by newline characters and returns an array of strings
char** splitLines(const char *string, int *count) {
    return splitString(string, "\n", count);
}

// Joins an array of strings with the specified delimiter
char* joinStrings(const char *delimiter, char **strings, int count) {
    int length = 0;
    for (int i = 0; i < count; i++) {
        length += getStringLength(strings[i]);
    }
    length += (count - 1) * getStringLength(delimiter);
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    result[0] = '\0';
    for (int i = 0; i < count; i++) {
        strcat(result, strings[i]);
        if (i < count - 1) {
            strcat(result, delimiter);
        }
    }
    return result;
}

// Replaces all occurrences of the old substring with the new substring in the given string
char* replaceSubstring(const char *string, const char *oldSubstring, const char *newSubstring) {
    int count = 0;
    const char *temp = string;
    while ((temp = strstr(temp, oldSubstring))) {
        count++;
        temp += getStringLength(oldSubstring);
    }
    int newLength = getStringLength(string) + count * (getStringLength(newSubstring) - getStringLength(oldSubstring));
    char *result = (char *)malloc((newLength + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    char *position = result;
    while (*string) {
        if (strstr(string, oldSubstring) == string) {
            strcpy(position, newSubstring);
            position += getStringLength(newSubstring);
            string += getStringLength(oldSubstring);
        } else {
            *position++ = *string++;
        }
    }
    *position = '\0';
    return result;
}

// Encodes the given string (alias for strdup)
char* encodeString(const char *string) {
    return strdup(string);
}

// Pads the given string with zeros on the left to the specified width
char* zeroFillString(const char *string, int width) {
    int length = getStringLength(string);
    if (length >= width) {
        return strdup(string);
    }
    char *result = (char *)malloc((width + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    int fill = width - length;
    memset(result, '0', fill);
    strcpy(result + fill, string);
    return result;
}

// Expands tabs in the given string to the specified number of spaces
char* expandTabs(const char *string, int tabSize) {
    int length = getStringLength(string);
    int newLength = 0;
    for (int i = 0; i < length; i++) {
        if (string[i] == '\t') {
            newLength += tabSize;
        } else {
            newLength++;
        }
    }
    char *result = (char *)malloc((newLength + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    char *position = result;
    for (int i = 0; i < length; i++) {
        if (string[i] == '\t') {
            memset(position, ' ', tabSize);
            position += tabSize;
        } else {
            *position++ = string[i];
        }
    }
    *position = '\0';
    return result;
}

// Centers the given string within the specified width, padding with the specified character
char* centerString(const char *string, int width, char fillChar) {
    int length = getStringLength(string);
    if (length >= width) {
        return strdup(string);
    }
    int pad = (width - length) / 2;
    char *result = (char *)malloc((width + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    memset(result, fillChar, pad);
    strcpy(result + pad, string);
    memset(result + pad + length, fillChar, width - pad - length);
    result[width] = '\0';
    return result;
}

// Left-justifies the given string within the specified width, padding with the specified character
char* leftJustifyString(const char *string, int width, char fillChar) {
    int length = getStringLength(string);
    if (length >= width) {
        return strdup(string);
    }
    char *result = (char *)malloc((width + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    strcpy(result, string);
    memset(result + length, fillChar, width - length);
    result[width] = '\0';
    return result;
}

// Right-justifies the given string within the specified width, padding with the specified character
char* rightJustifyString(const char *string, int width, char fillChar) {
    int length = getStringLength(string);
    if (length >= width) {
        return strdup(string);
    }
    char *result = (char *)malloc((width + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    memset(result, fillChar, width - length);
    strcpy(result + (width - length), string);
    result[width] = '\0';
    return result;
}

// Partitions the given string into three parts: before the separator, the separator, and after the separator
char* partitionString(const char *string, const char *separator) {
    int separatorLength = getStringLength(separator);
    char *position = strstr(string, separator);
    if (!position) {
        return strdup(string);
    }
    int beforeLength = position - string;
    int afterLength = getStringLength(string) - beforeLength - separatorLength;
    char *result = (char *)malloc((beforeLength + separatorLength + afterLength + 3) * sizeof(char));
    if (!result) {
        return NULL;
    }
    strncpy(result, string, beforeLength);
    result[beforeLength] = '\0';
    strcat(result, separator);
    strcat(result, position + separatorLength);
    return result;
}

// Partitions the given string into three parts: before the last occurrence of the separator, the separator, and after the separator
char* rpartitionString(const char *string, const char *separator) {
    int separatorLength = getStringLength(separator);
    char *position = NULL;
    char *temp = strstr(string, separator);
    while (temp) {
        position = temp;
        temp = strstr(temp + 1, separator);
    }
    if (!position) {
        return strdup(string);
    }
    int beforeLength = position - string;
    int afterLength = getStringLength(string) - beforeLength - separatorLength;
    char *result = (char *)malloc((beforeLength + separatorLength + afterLength + 3) * sizeof(char));
    if (!result) {
        return NULL;
    }
    strncpy(result, string, beforeLength);
    result[beforeLength] = '\0';
    strcat(result, separator);
    strcat(result, position + separatorLength);
    return result;
}

// Formats the given string with the specified arguments
char* formatString(const char *string, ...) {
    va_list args;
    va_start(args, string);
    int length = vsnprintf(NULL, 0, string, args);
    va_end(args);
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    va_start(args, string);
    vsnprintf(result, length + 1, string, args);
    va_end(args);
    return result;
}

// Formats the given string with the specified key-value pairs
char* formatStringMap(const char *string, const char **keys, const char **values, int count) {
    char *result = strdup(string);
    for (int i = 0; i < count; i++) {
        char *temp = replaceSubstring(result, keys[i], values[i]);
        free(result);
        result = temp;
    }
    return result;
}

// Creates a translation table for the given from and to strings
char* maketrans(const char *from, const char *to) {
    int length = getStringLength(from);
    char *result = (char *)malloc(256 * sizeof(char));
    if (!result) {
        return NULL;
    }
    for (int i = 0; i < 256; i++) {
        result[i] = i;
    }
    for (int i = 0; i < length; i++) {
        result[(unsigned char)from[i]] = to[i];
    }
    return result;
}

char* translate(const char *str, const char *table) {
    int length = getStringLength(str);
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        result[i] = table[(unsigned char)str[i]];
    }
    result[length] = '\0';
    return result;
}

char* title(const char *str) {
    int length = getStringLength(str);
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    bool new_word = true;
    for (int i = 0; i < length; i++) {
        if (isspace(str[i])) {
            new_word = true;
            result[i] = str[i];
        } else if (new_word) {
            result[i] = toupper(str[i]);
            new_word = false;
        } else {
            result[i] = tolower(str[i]);
        }
    }
    result[length] = '\0';
    return result;
}

char* removeprefix(const char *str, const char *prefix) {
    int str_len = getStringLength(str);
    int prefix_len = getStringLength(prefix);
    if (prefix_len > str_len || strncmp(str, prefix, prefix_len) != 0) {
        return strdup(str);
    }
    char *result = (char *)malloc((str_len - prefix_len + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    strcpy(result, str + prefix_len);
    return result;
}

char* removesuffix(const char *str, const char *suffix) {
    int str_len = getStringLength(str);
    int suffix_len = getStringLength(suffix);
    if (suffix_len > str_len || strncmp(str + str_len - suffix_len, suffix, suffix_len) != 0) {
        return strdup(str);
    }
    char *result = (char *)malloc((str_len - suffix_len + 1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    strncpy(result, str, str_len - suffix_len);
    result[str_len - suffix_len] = '\0';
    return result;
}

int main() {
    printf("=== String Library Test Suite ===\n\n");

    printf("Testing get_length:\n");
    printf("Empty string: %d\n", getStringLength(""));
    printf("Normal string: %d\n", getStringLength("Hello"));
    printf("String with spaces: %d\n", getStringLength("Hello World"));
    printf("Special characters: %d\n", getStringLength("!@#$%^&*()"));
    printf("\n");

    const char *test_str = "Hello World 123!";
    printf("Testing case modifications:\n");
    char *cap_result = capitalizeString("hello world");
    printf("capitalize: %s\n", cap_result);
    printf("capitalize empty: %s\n", capitalizeString(""));
    printf("capitalize already caps: %s\n", capitalizeString("HELLO"));
    free(cap_result);

    char *lower_result = toLowerCase("HELLO WORLD");
    printf("to_lower: %s\n", lower_result);
    printf("to_lower already lower: %s\n", toLowerCase("hello"));
    printf("to_lower mixed: %s\n", toLowerCase("HeLLo WoRLD"));
    free(lower_result);

    char *upper_result = toUpperCase("hello world");
    printf("to_upper: %s\n", upper_result);
    printf("to_upper already upper: %s\n", toUpperCase("HELLO"));
    printf("to_upper mixed: %s\n", toUpperCase("HeLLo WoRLD"));
    free(upper_result);

    char *swap_result = swapStringCase("Hello World");
    printf("swap_case: %s\n", swap_result);
    printf("swap_case all upper: %s\n", swapStringCase("HELLO"));
    printf("swap_case all lower: %s\n", swapStringCase("hello"));
    free(swap_result);

    printf("\n");

    printf("Testing character type checks:\n");
    printf("is_alnum('Hello123'): %d\n", isAlphanumeric("Hello123"));
    printf("is_alnum('Hello!'): %d\n", isAlphanumeric("Hello!"));
    printf("is_alnum(''): %d\n", isAlphanumeric(""));

    printf("is_alpha('Hello'): %d\n", isAlphabetic("Hello"));
    printf("is_alpha('Hello123'): %d\n", isAlphabetic("Hello123"));
    printf("is_alpha(''): %d\n", isAlphabetic(""));

    printf("is_ascii('Hello'): %d\n", isAscii("Hello"));
    printf("is_ascii(special chars): %d\n", isAscii("ñ"));

    printf("is_digit('123'): %d\n", isDigitString("123"));
    printf("is_digit('12.3'): %d\n", isDigitString("12.3"));
    printf("is_digit(''): %d\n", isDigitString(""));

    printf("is_identifier('validName'): %d\n", isIdentifier("validName"));
    printf("is_identifier('123invalid'): %d\n", isIdentifier("123invalid"));
    printf("is_identifier(''): %d\n", isIdentifier(""));

    printf("\n");

    printf("Testing string search functions:\n");
    printf("startswith('Hello World', 'Hello'): %d\n", startsWith("Hello World", "Hello"));
    printf("startswith('Hello', 'World'): %d\n", startsWith("Hello", "World"));
    printf("startswith('', ''): %d\n", startsWith("", ""));

    printf("endswith('Hello World', 'World'): %d\n", endsWith("Hello World", "World"));
    printf("endswith('Hello', 'World'): %d\n", endsWith("Hello", "World"));
    printf("endswith('', ''): %d\n", endsWith("", ""));

    printf("count('Hello World', 'l'): %d\n", countCharacter("Hello World", 'l'));
    printf("count('', 'x'): %d\n", countCharacter("", 'x'));

    printf("find('Hello World', 'World'): %d\n", findSubstring("Hello World", "World"));
    printf("find('Hello World', 'xyz'): %d\n", findSubstring("Hello World", "xyz"));

    printf("rfind('Hello World World', 'World'): %d\n", rfindSubstring("Hello World World", "World"));
    printf("rfind('Hello World', 'xyz'): %d\n", rfindSubstring("Hello World", "xyz"));

    printf("\n");

    printf("Testing string modification functions:\n");
    char *strip_result = stripString("  Hello World  ");
    printf("strip: '%s'\n", strip_result);
    printf("strip empty: '%s'\n", stripString(""));
    printf("strip all spaces: '%s'\n", stripString("   "));
    free(strip_result);

    char *lstrip_result = lstripString("  Hello World  ");
    printf("lstrip: '%s'\n", lstrip_result);
    free(lstrip_result);

    char *rstrip_result = rstripString("  Hello World  ");
    printf("rstrip: '%s'\n", rstrip_result);
    free(rstrip_result);

    int count;
    char **split_result = splitString("Hello,World,Test", ",", &count);
    printf("split count: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("split[%d]: %s\n", i, split_result[i]);
        free(split_result[i]);
    }
    free(split_result);

    const char *strings[] = {"Hello", "World", "Test"};
    char *join_result = joinStrings(", ", (char**)strings, 3);
    printf("join: %s\n", join_result);
    free(join_result);

    printf("\n");

    printf("Testing string formatting and manipulation:\n");
    char *replace_result = replaceSubstring("Hello World World", "World", "Earth");
    printf("replace: %s\n", replace_result);
    printf("replace (no match): %s\n", replaceSubstring("Hello", "xyz", "abc"));
    free(replace_result);

    char *zfill_result = zeroFillString("123", 5);
    printf("zfill: %s\n", zfill_result);
    printf("zfill (width smaller): %s\n", zeroFillString("123", 2));
    free(zfill_result);

    char *expandtabs_result = expandTabs("Hello\tWorld", 4);
    printf("expandtabs: '%s'\n", expandtabs_result);
    free(expandtabs_result);

    char *center_result = centerString("Hello", 10, '*');
    printf("center: '%s'\n", center_result);
    free(center_result);

    char *ljust_result = leftJustifyString("Hello", 10, '*');
    printf("ljust: '%s'\n", ljust_result);
    free(ljust_result);

    char *rjust_result = rightJustifyString("Hello", 10, '*');
    printf("rjust: '%s'\n", rjust_result);
    free(rjust_result);

    printf("\n");

    char *partition_result = partitionString("Hello-World-Test", "-");
    printf("partition: %s\n", partition_result);
    free(partition_result);

    char *rpartition_result = rpartitionString("Hello-World-Test", "-");
    printf("rpartition: %s\n", rpartition_result);
    free(rpartition_result);

    const char *from = "aeiou";
    const char *to = "12345";
    char *trans_table = maketrans(from, to);
    char *translate_result = translate("Hello World", trans_table);
    printf("translate: %s\n", translate_result);
    free(translate_result);
    free(trans_table);

    char *title_result = title("hello world example");
    printf("title: %s\n", title_result);
    printf("title mixed case: %s\n", title("hELLo WoRLD"));
    printf("title empty: %s\n", title(""));
    free(title_result);

    // Testing new functions
    char *removeprefix_result = removeprefix("HelloWorld", "Hello");
    printf("removeprefix: %s\n", removeprefix_result);
    free(removeprefix_result);

    char *removesuffix_result = removesuffix("HelloWorld", "World");
    printf("removesuffix: %s\n", removesuffix_result);
    free(removesuffix_result);

    printf("\nAll tests completed successfully!\n");
    return 0;
}
