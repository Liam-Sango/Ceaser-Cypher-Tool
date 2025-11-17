//PRECOMPILER INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//GLOBAL VARS
char L_Eng_alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char str_to_prc[20] = {};
//MAIN LOOP
int main () {
 return 0;
}

//FUNCTIONS
char* Process_string_chunk (char chunk[10]) {
    //Dynamically allocates 
    char* Processed_Chunk = (char*)calloc(10, sizeof(char));
    if (Processed_Chunk == NULL) {printf("\nMemory Allocation error in Process_string() function\n"); exit(1);}
}