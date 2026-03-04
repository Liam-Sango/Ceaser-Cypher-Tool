#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global variables
char text_chunk [2048] = {};


//Function declerations
char* Process_string(char *text_chunk, int shift);
char* read_text_chunk(char input_file_path[512], char *text_chunk);
int write_text_chunk(char output_file_path[512], char *text_chunk);


//Main
int main () {
    //Variables
    char in_file_name[512];
    char out_file_name[512];
    int shift_value;

    //Gathers the input filename, reads the file
    printf("\nPlease enter the full path to your input file in the prompt below.\n");
    printf("\nMake sure the input file contains no more than 2048 characters.\n");
    while (strlen(in_file_name) <= 0) {scanf("%s", in_file_name);}
    read_text_chunk(in_file_name, text_chunk);

    //proccesses the text inside the input file
    printf("\nPlease enter your shift value.\n");
    while (shift_value < -27 || shift_value > 27) {scanf("%i", &shift_value);}
    Process_string(text_chunk, shift_value);

    //gathers the output filename, writes to the file.
    printf("\nPlease enter the full path to your output file in the prompt below.\n");
    while (strlen(out_file_name) <= 0) {scanf("%s", out_file_name);}
    write_text_chunk(out_file_name, text_chunk);

    printf("\n\nDone.\n");
    return 0;
}

//Processes a string using Caesar Cypher algorithm
char* Process_string(char *text_chunk, int shift) {

    int text_chunk_size = strlen(text_chunk);

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
    if (file_read_pointer == NULL) {
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
    if (file_write_pointer == NULL) {
        return 1;
    } 
    
    //writes the content of text_chunk to the output file.
    fprintf(file_write_pointer, "%s", text_chunk);
    fclose(file_write_pointer);

    return 0;
}



