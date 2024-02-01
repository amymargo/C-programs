/*#include <stdio.h>
#include <string.h>
# include <stdlib.h>
    //sorta takes zero or more arguments, sorts them lexicographically, and then prints each argument on its own line.
    //MUST use strcmp() (compares lexico..)
    //if its negative, A is first
    //if >0 need to switch //i j for loop

    //scanf("%s", str);
    //fgets() reads from file
int main(int argc, char **argv){
    char *test;
    *test = 'a';
    scanf("%s", test);
    printf("%s", test);
    int amt = argc;
    while (scanf("%s", in[amt]) == 1) {
        amt++;
    }
    printf("%d",amt);
    printf("%s",in[0]);
        while (fgets(in[amt], 100, stdin) != NULL) {
        // Remove the trailing newline character from the input
        in[amt][strcspn(in[amt], "\n")] = '\0';
        amt++;
    }

    if (amt==1){printf("one");return 0;}
    else if (amt==2){printf("%s", in[1]);return 0;}
    else{
    for (int i =1; i<amt; i++){
        for (int j =i+1; j<amt; j++){
            if ((strcmp(in[i],in[j]))>0){
                char temp[100];
                strcpy(temp, in[i]);
                strcpy(in[i], in[j]);
                strcpy(in[j], temp);
            }
        }
    }
    }
    for (int k =0; k<amt; k++){
        printf("%s", in[k]);
    }*/
   /* return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 0;
    }
    char *temp;
    for (int i = 1; i < argc; ++i) {
      for (int j = i + 1; j < argc; ++j) {

         if (strcmp(argv[i], argv[j]) > 0) {
            temp = argv[i];
            argv[i]=argv[j];
            argv[j]=temp;
         }
      }
   }
 
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}