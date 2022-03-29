#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// dont code after midnight -.-

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
    char buf[41];
    int counter = 0;
    text_ = struprD(buf);
    for (int i = 0; i < sLength_[0]; i++) {
        if (checkLetter(text_[i])) {
            buf[counter] = text_[i];
            counter++;
        }
    }
    text_ = buf;
    sLength_[0] = counter;
    return text_;
}

char* scanInput(int* length_)
{
    printf(": ");
    char buf[41], *text, *result;
    fgets(buf, 40, stdin);
    length_[0] = (int)strlen(buf)-1;
    text = (char*)calloc((length_[0])+1, sizeof(char));
    text = buf;
    text = cleanupString(text, length_);
    printf("\n%s", text);
    text = (char*)realloc(text, (length_[0])+1);
    strcpy(text, result);
    free(text);
    return result;
}

int checkPalindrom(char* text_)
{

}

int main()
{
    int length = 0, *lengthPtr = &length;
    char* input = scanInput(lengthPtr);
    printf("\n%s\n%d", input, lengthPtr);
}
