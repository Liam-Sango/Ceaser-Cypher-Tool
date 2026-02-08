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

//Reads texts chunks from an input file
char* read_text_chunk (char *txt_chunk_ptr) {
    return 0;
}

//processes the text chunk using Caesar Cypher algorithm
char* Process_text_chunk (char *text_chunk, int text_chunk_size, int shift) {

    //input validation
    if (text_chunk == NULL) {
        return NULL;
    }

    if (text_chunk_size <= 0 || text_chunk_size > 256) {
        return NULL;
    }

    else if (shift <= -27 || shift >= 27) {
        shift = 1;
    }

    //filtering
    for (int i = 0; i < text_chunk_size; i++) { 

        if ( (text_chunk[i] >= 97 && text_chunk[i] <= 122) || (text_chunk[i] >= 65 && text_chunk[i] <= 90) ) {
            continue;

        } else {
            text_chunk[i] = ' ';

        }
    }
    
    // processing
    for (int i = 0; i < text_chunk_size; i++) {

        // lowercase
        if (text_chunk[i] >= 'a' && text_chunk[i] <= 'z') {
            text_chunk[i] = text_chunk[i] + shift;

            if (text_chunk[i] > 'z') {
                text_chunk[i] -= 26;

            } else if (text_chunk[i] < 'a') {
                text_chunk[i] += 26;
            }
        }
    
        // uppercase
        else if (text_chunk[i] >= 'A' && text_chunk[i] <= 'Z') {
            text_chunk[i] = text_chunk[i] + shift;

            if (text_chunk[i] > 'Z') {
                text_chunk[i] -= 26;

            } else if (text_chunk[i] < 'A') {
                text_chunk[i] += 26;
            }
        }
    }

    return text_chunk;
}
    
//Writes processed text chunks to an output file
char* write_text_chunk (char* txt_chunk_ptr[256]) {
    return 0;
}

//MAIN LOOP
int main() {  
    return 0;
}