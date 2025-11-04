#include <stdio.h>

//RETURNERA STRÄNGAR!

typedef enum {
    EN,
    SE
} LANG; 

// how NOT to do it:
// INTE OK attr returnera en pelare toill en stackallokerad variabel!!!
// just denna är också farlig för buffer overflow
char *greet(const char *name, LANG lang) {

    char buffer[50];
    if(lang == SE){
        strcpy(buffer, "Hej, ");
    }else{
        strcpy(buffer, "Hello, "); 
    }
    strcat(buffer, name);
    strcat(buffer, "!");
    return buffer;
}

void greetGood(const char *name, LANG lang, char *buffer) {
    if(lang == SE){
        strcpy(buffer, "Hej, ");
    }else{
        strcpy(buffer, "Hello, "); 
    }
    strcat(buffer, name);
    strcat(buffer, "!");
    return buffer;
}


typedef enum {
    ERRORS_NONE,
    ERRORS_INVALID_LANG,
    ERRORS_BUFFER_TO_SMALL
} ERRORS;

// DETTA ÄR OK!!!
// string literals ligger i text segmentet
char *getErrorText(ERRORS err) {
    switch(err) {
        case ERRORS_NONE:
            return "No errors.";
        case ERRORS_INVALID_LANG:
            return "Invalid language.";
        case ERRORS_BUFFER_TO_SMALL:
            return "Buffer too small.";
        default:
            return "Unknown error.";
    }
}


int main() {
    char buffer[50];
    greetGood("Stefan", EN, buffer);

    char *text = greet("Stefan", EN);
    printf("%s\n", text);

    text = greet("Stefan", SE);
    printf("%s\n", text);

    return 0;
}