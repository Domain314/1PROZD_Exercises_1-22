#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* scanText()
{
    char* text = (char*)calloc(1, sizeof(char*));
    char buf[1001];
    printf("input text: \n");
    scanf("%1000s", buf);
    text=(char*)calloc(strlen(buf)+1, sizeof(char));
    strcpy(text, buf);
    return text;
}

char** scanWords(int* _counter) {
    char** words= ( char**)calloc(1, sizeof(char*)), **tmp;
    int i=0;
    while(1) {
        char buf[81];
        scanf("%80s", buf);
        if(buf[0]=='-') break;
        if(NULL==(tmp = ( char**)realloc(words, sizeof(char*)*(i+2)))) {
            printf("out of memory");
            break;
        }
        words=tmp;
        words[i] = ( char*)calloc(strlen(buf)+1, sizeof(char));
        strcpy(words[i], buf);
        i++;
    }
    words[i]=( char*)calloc(1,sizeof(char));
    *_counter = i;
    return words;
}

void freeAll(char** _words, int _counter)
{
    for (int i = 0; i < _counter; i++) {
        free(_words[i]);
    }
}

int countWord(char* _text, char* _word)
{
    char* ptr;
    if ((ptr = strchr(_text, _word[0])) == NULL)
    {
        printf("\nno matches found");
        return 0;
    }

    int counter = 0;
    int textLength = strlen(_text);
    int wordLength = strlen(_word);
    //puts(_text);

    char* temp = (char*)calloc(0, sizeof(char)*1000);
    strcpy(temp, _text);
    puts(temp);
    temp = ptr;
    int bool = 1;
    while(bool)
    {

        printf("\ntemp1: %s", temp);
        if (strncmp(temp, _word, wordLength) == 0)
        {
            printf("\nMatch!");
            temp = temp+wordLength;
            counter++;
        } else {
            temp = temp+1;
            printf("\ntemp2: %s", temp);
            temp = strchr(temp, _word[0]);
            printf("\ntemp3: %s", temp);
            if (temp == NULL)
            {
                printf("\nend");
                printf("\ncounted: %d", counter);
                return counter;
            }
        }
    }

    for (int i = 0; i < textLength; i++) {
        //printf("%c\n", _text[i]);
    }

}

int main()
{
    int counter, *counterPtr = &counter;
    //char text[1000];
    char* textPtr = scanText();      //&text[1000];
    //fgets(textPtr, sizeof(char)*1000, stdin);

    char** words = scanWords(counterPtr);
    int* amounts = (int*)calloc(counter, sizeof(int)*counter);
    for (int i = 0; i < counter; i++) {

        amounts[i] = countWord(textPtr, words[i]);
    }



    freeAll(words, counter);

    //puts(words[1]);
    //printf("%s\n", words[0] );
    //printf("%s\n", words[1] );

    return 0;
}
