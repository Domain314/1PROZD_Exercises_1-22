#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// had to use <ctype.h>, because strupr() and strlwr() are only available on
// windows. This version is compatible with linux and mac too.
char *struprD(char* str_)
{
    char *next = str_;
    while (*next != '\0') {
        *next = toupper((char)*next);
        next++;
    }
    return str_;
}

int checkLetter(char c_)
{
    return (64 < c_ && c_ < 91);
}

char* cleanupString(char* text_, int* sLength_)
{
    char buf[41], *result;
    int counter = 0;
    text_ = struprD(text_);
    for (int i = 0; i < sLength_[0]; i++) {
        if (checkLetter(text_[i])) {
            buf[counter] = text_[i];
            counter++;
        }
    }
    result = (char*)malloc(sizeof(char)*(counter+1));
    strcpy(result, buf);
    sLength_[0] = counter;
    return result;
}

char* scanInput(int* length_)
{
    printf(": ");
    char buf[41], *text;
    fgets(buf, 41, stdin);
    length_[0] = (int)strlen(buf)+1;
    text = cleanupString(buf, length_);
    //printf("\n%s", text);
    return text;
}

int checkPalindrome(char* text_, int* slength_)
{
    int error = 0, length = slength_[0]/2;
    slength_[0]--;
    for (int i = 0; i < length; i++) {
        if (text_[i] != text_[slength_[0]-i])
        {
            error++;
        }
    }
    return error;
}

void printResult(int error_)
{
    if (error_) {
        printf("false");
    } else {
        printf("true");
    }
}

int main()
{
    int length = 0, *lengthPtr = &length;
    char* input = scanInput(lengthPtr);
    //printf("\n%s\n%d", input, lengthPtr[0]);
    printResult(checkPalindrome(input, lengthPtr));
    free(input);
    return 0;
}
