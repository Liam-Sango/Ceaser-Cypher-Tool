//PRECOMPILER INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//GLOBAL VARS
char current_txt_chunk [256] = {"This is a sample text."};
int shift_value = 3;
int text_chunk_size = sizeof(current_txt_chunk) / sizeof(current_txt_chunk[0]);

//FUNCTIONS

//FReads texts chunks from an input file
char* read_text_chunk (char *txt_chunk_ptr) {
    return 0;
}

//processes the text chunk using Caesar Cypher algorithm
char* Process_text_chunk (char *text_chunk, int text_chunk_size, int shift) {

    //input validation
    if (text_chunk == NULL) {
        return NULL;
    }

    //filtering

    //processing
    for (int i = 0; i < text_chunk_size; i++) {
    }
    
    return text_chunk;
}

//Writes processed text chunks to an output file
char* write_text_chunk (char* txt_chunk_ptr[256]) {
    return 0;
}

//MAIN LOOP

int main() {  
    //VARIABLES
    return 0;
}