#include <stdio.h>

//RETURNERA STRÄNGAR!

typedef enum {
    EN,
    SE
} LANG; 

// how NOT to do it:
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

int main() {
    char *text = greet("Stefan", EN);
    printf("%s\n", text);

    text = greet("Stefan", SE);
    printf("%s\n", text);

    return 0;
}