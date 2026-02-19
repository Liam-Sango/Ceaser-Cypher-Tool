#include <stdio.h>
#include <stdlib.h>

//Global variables
char text_chunk [2048] = {};

int shift_value = 3;


//Function declerations
char* Process_string(char *text_chunk, int shift);
char* read_text_chunk(char input_file_path[512], char *text_chunk);
int write_text_chunk(char output_file_path[512], char *text_chunk);


//Main
int main () {
    return 0;
}

//Processes a string using Caesar Cypher algorithm
char* Process_string(char *text_chunk, int shift) {
    int text_chunk_size = sizeof(text_chunk) / sizeof(text_chunk[0]);

    // input validation
    if (text_chunk == NULL) {
        return NULL;
    }

    if (text_chunk_size <= 0 || text_chunk_size > 2048) {
        return NULL;
    } else if (shift <= -27 || shift >= 27) {
        shift = 1;
    }

    // filtering
    for (int i = 0; i < text_chunk_size; i++) {
        if ((text_chunk[i] >= 97 && text_chunk[i] <= 122) || (text_chunk[i] >= 65 && text_chunk[i] <= 90)) {
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


char* read_text_chunk(char input_file_path[512], char *text_chunk) {

    //defines and opens our file pointer
    FILE *file_read_pointer;
    file_read_pointer = fopen(input_file_path, "r");


    //Checks for a a null pointer
    if (file_read_pointer = NULL) {
        fclose(file_read_pointer);
        return NULL;
    } 

    //reads the content of the input file and writes it to the text_chunk
    fgets(text_chunk, 2048, file_read_pointer);
    fclose(file_read_pointer);

    return text_chunk;
}


int write_text_chunk(char output_file_path[512], char *text_chunk) {

    //defines and opens our file pointer
    FILE *file_write_pointer;
    file_write_pointer = fopen(output_file_path, "w");

    //Checks for a a null pointer
    if (file_write_pointer = NULL) {
        fclose(file_write_pointer);
        return 1;
    } 
    
    //writes the content of text_chunk to the output file.
    fprintf(file_write_pointer, text_chunk);
    fclose(file_write_pointer);

    return 0;
}



