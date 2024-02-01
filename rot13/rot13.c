#include <stdio.h>
#include <string.h>
# include <stdlib.h>
int main(int argc, char **argv){
    for (int j=1;j<argc;j++){
        int len = strlen(argv[j]);
    for (int i =0; i<len;i++){
        char a = argv[j][i];
        if (((a>64)&&(a<91))||((a>96)&&(a<123))){
            if (((a>64)&&(a<78))||((a>96)&&(a<110))) {
                a=a+13;}
            else if (((a>77)&&(a<91))||((a>109)&&(a<123))){
                a=a-13;}
        }
        if (i==len-1){
            putchar(a);
            putchar('\n');
        }
        else{
        putchar(a);}
    }}

//takes argument, goes through each character and if it is a letter is replaces it. if it is in the first half of the alphabet it replaces it with the letter 13 letters after it, 
//and if it is in the second half, it replaces it with the letter 13 letters before it. it prints a new line at the end
//use ctype.h , especially isalpha()
//output can be printed a single character at a time using putchar(), so it is not necessary to print the entire output at once.

return 0;
}