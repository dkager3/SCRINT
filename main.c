//
//  main.c
//
//  Screw Interpreter
//
//  Created by Dennis Kager on 7/6/19.
//  Last Modified on 7/8/19.
//  Copyright © 2019 Dennis Kager. All rights reserved.
//

#include <stdio.h>
#include <fcntl.h>  // For open()
#include <unistd.h> // For lseek(), close()
#include <string.h> // For memset(), strlen(), strcmp()
#include <stdlib.h> // For malloc() and free()
#include <ctype.h>  // isdigit()

#define CELLS 60000 // How many memory cells there will be
#define RESET "\033[0m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"

_Bool termChar(char *);         // Check to make sure the program has a terminating character
_Bool matchingBraces(char *);   // Check to make sure the program has matching braces
void run(char *);               // Interpret tokenized screw code

int main(int argc, const char * argv[]) {
    int file_name_len = 0;                  // Holds the length of the file name
    const char *file_extension = NULL;      // Holds the extension of the given file
    char *file_buffer = NULL;               // Holds unfiltered contents of file
    int file_length = 0;                    // Holds the unfiltered file length
    char *token = NULL;                     // Holds the filtered contents of the file
    int token_length = 0;                   // Holds the filtered file length
    char *c = NULL;                         // Cursor for filtering the file contents
    _Bool comment = 0;                      // True if reading a comment
    int rd = 0;                             // File descriptor for reading the file
    
    if(argc == 2 && strcmp(argv[1], "-v") != 0){    // Check to make sure there are two arguments and that using is not asking for version info
        file_name_len = (int)strlen(argv[1]);       // Get length of the file name
        file_extension = &argv[1][file_name_len-4]; // Pointer to the file extension
        
        if(file_name_len < 5){                      // Minimum name for a screw file
            fprintf(stderr, "%sError:%s Invalid filename\n", RED, RESET);
            exit(EXIT_FAILURE);
        }
        else if (strcmp(file_extension, ".scw") != 0){ // Check to make sure the file given is a screw file
            fprintf(stderr, "%sError:%s This type of file is not supported. Please use a screw (.scw) file!\n", RED, RESET);
            exit(EXIT_FAILURE);
        }
        
        // GET THE CONTENTS OF THE FILE INTO A STRING
        //===================================================================================================
        rd = open(argv[1], O_RDONLY);                   // Open .scw file
        
        if(rd != -1){                                   // Check to make sure file exists
            file_length = (int)lseek(rd, 0, SEEK_END);  // Get the length of the file
            
            if(file_length == -1){                      // Check for lseek() error
                fprintf(stderr, "%sError:%s Lseek() returned error from reading %s!\n", RED, RESET, argv[1]);
                exit(EXIT_FAILURE);                     // Exit if lseek() failed
            }
            else{                                       // Read file contents
                lseek(rd, 0, SEEK_SET);                 // Reset the file offset
                file_buffer = (char *)malloc((file_length * sizeof(char)) + 1); // Set file_buffer to the length of the file
                if(file_buffer == NULL){
                    fprintf(stderr, "%sError:%s Malloc() failed to allocate memory! Exiting...\n", RED, RESET);
                    exit(EXIT_FAILURE);                 // Exit if malloc() failed
                }
                memset(file_buffer, '\0', file_length + 1); // Initialize all of file_buffer with '\0'
                read(rd, file_buffer, file_length);         // Read all the contents of the file into file_buffer
                close(rd);                                  // Close the file
            }
        }else{                                          // If here, then the file doesn't exist -- Exit
            fprintf(stderr, "%sError:%s %s doesn't exist!\n", RED, RESET, argv[1]);
            exit(EXIT_FAILURE);                        // Exit if the file does not exist
        }
        
        if(termChar(file_buffer) == 0){                 // Check to see if the terminating character exists in the program
            fprintf(stderr, "%sError:%s Program does not have terminating character!\n", RED, RESET);
            free(file_buffer);                          // Free dynamically allocated memory
            exit(EXIT_FAILURE);                         // Exit if the terminating character is not in the program
        }
        if(matchingBraces(file_buffer) == 0){           // Check to see if there are matching braces
            fprintf(stderr, "%sError:%s Program has mismatched braces!\n", RED, RESET);
            free(file_buffer);                          // Free dynamically allocated memory
            exit(EXIT_FAILURE);                         // Exit if braces are mismatched
        }
        
        // TOKENIZE AND REDUCE THE FILE CONTENTS INTO SINGLE TOKEN
        //===================================================================================================
        c = file_buffer;                                // Set cursor to beginning of the file_buffer (holds the original contents of file)
        while(*c != '~'){                               // While the cursor is not the terminating character
            switch(*c){                                 // Switch case to count all operators to put into token
                case '+':
                    if(!comment)
                        ++token_length;
                    break;
                case '-':
                    if(!comment)
                        ++token_length;
                    break;
                case '{':
                    if(!comment)
                        ++token_length;
                    break;
                case '}':
                    if(!comment)
                        ++token_length;
                    break;
                case '?':
                    if(!comment)
                        ++token_length;
                    break;
                case '>':
                    if(!comment)
                        ++token_length;
                    break;
                case '<':
                    if(!comment)
                        ++token_length;
                    break;
                case '.':
                    if(!comment)
                        ++token_length;
                    break;
                case '*':
                    if(!comment)
                        ++token_length;
                    break;
                case '^':
                    if(!comment)
                        ++token_length;
                    break;
                case '0':
                    if(!comment)
                        ++token_length;
                    break;
                case '1':
                    if(!comment)
                        ++token_length;
                    break;
                case '2':
                    if(!comment)
                        ++token_length;
                    break;
                case '3':
                    if(!comment)
                        ++token_length;
                    break;
                case '4':
                    if(!comment)
                        ++token_length;
                    break;
                case '5':
                    if(!comment)
                        ++token_length;
                    break;
                case '6':
                    if(!comment)
                        ++token_length;
                    break;
                case '7':
                    if(!comment)
                        ++token_length;
                    break;
                case '8':
                    if(!comment)
                        ++token_length;
                    break;
                case '9':
                    if(!comment)
                        ++token_length;
                    break;
                case ';':                               // If semi-colon is found, set comment to true
                    if(!comment)
                        comment = 1;
                    break;
                case '\n':                              // If newline is found, set comment to false
                    if(comment)
                        comment = 0;
                    break;
                default:
                    break;
            }
            ++c;                                        // Move cursor to the next character
        }
        
        if(comment)
            comment = 0;
        
        
        token = (char*)malloc((token_length * sizeof(char)) + 1); // Set the token length to the length of all the operators found
        if(token == NULL){                              // Check to make sure malloc() did not return NULL
            fprintf(stderr, "%sError:%s Malloc() failed to allocate memory! Exiting...\n", RED, RESET);
            free(file_buffer);                         // Free dynamically allocated memory
            exit(EXIT_FAILURE);                        // Exit if malloc() failed
        }
        memset(token, '\0', token_length + 1);         // Initialize the tokenized file to NULL terminator
        
        int i = 0;                                     // Index of instruction in token
        c = file_buffer;                               // Set cursor to beginning of the file_buffer (holds the original contents of file)
        while(*c != '~'){                              // While the cursor is not the terminating character
            switch(*c){                                // Switch case adds operations to the token
                case '+':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '-':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '{':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '}':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '?':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '>':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '<':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '.':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '*':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '^':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '0':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '1':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '2':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '3':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '4':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '5':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '6':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '7':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '8':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case '9':
                    if(!comment){
                        token[i] = *c;
                        ++i;
                    }
                    break;
                case ';':                              // If semi-colon is found, set comment to true
                    if(!comment)
                        comment = 1;
                    break;
                case '\n':                             // If newline is found, set comment to false
                    if(comment)
                        comment = 0;
                    break;
                default:
                    break;
            }
            ++c;                                       // Move cursor to the next character
        }
        token[i] = '~';                                // Finish token by adding terminator at the end
        
        // RUN FILE
        //===================================================================================================
        run(token);                                    // Run the tokenized, ready-to-go screw code
        //printf("%s\n", token);                       // For debugging - Viewing final token to be run
        
        free(file_buffer);                             // Free dynamically allocated memory
        free(token);                                   // Free dynamically allocated memory
    }
    else if(argc == 2 && strcmp(argv[1], "-v") == 0){
        printf("\n");
        printf("                  Screw Interpreter\n");
        printf("========================================================\n");
        printf("|| Version 1.5 - July 8, 2019\n");
        printf("|| Screw language based on Brainf**k by Urban Müller\n");
        printf("|| Full documentation on GitHub @dkager3\n");
        printf("|| Designed by Dennis Kager\n");
        printf("========================================================\n\n");
    }
    else{
        printf("%sTo run a screw file:%s ./scrint <file>.scw\n", YELLOW, RESET);  // Usage string to show user how to run screw files
        printf("%sFor version information:%s ./scrint -v\n", YELLOW, RESET);      // Usage string to show user version information
    }
    
    return 0;
}

_Bool termChar(char *text){                            // Used to see if the screw file has the terminating character '~' in it
    char *cursor = text;
    
    while(*cursor != '\0'){                            // Go through all file contents looking for '~'
        if(*cursor == '~')
            return 1;                                  // Return 1 if '~' is found
        
        ++cursor;
    }
    
    return 0;                                          // Return 0 if '~' is NOT found
}

_Bool matchingBraces(char *text){                      // Used to check for matching braces within screw file
    char *cursor = text;
    int brace_num = 0;
    
    while(*cursor != '~'){                             // Search through whole file for braces
        if(*cursor == '{')
            ++brace_num;                               // Increment for every '{' found
        else if(*cursor == '}')
            --brace_num;                               // Decrement for every '}' found
        
        ++cursor;
    }
    
    if(brace_num == 0) {                               // Return 1 if all braces are matched
        return 1;
    }else
        return 0;                                      // Return 0 if braces are mismatched
}

void run(char *code){                                  // Interpret tokenized screw file
    char memory[CELLS];                                // 60,000 memory cells initialized to 0
    memset(memory, 0, CELLS);
    char *data_ptr = memory;                           // Cursor for modifying the memory cells
    char *code_ptr = code;                             // Cursor to read the screw code
    int braces = 0;                                    // Keep track of braces
    int left_offset = 0;                               // Keep track of how far away the cell cursor is from the left-most cell
    
    while(*code_ptr != '~'){                           // Run code while the terminating character '~' has not been found
        if(*code_ptr == '>'){                          // Shift cursor to right cell
            if(left_offset == CELLS){
                fprintf(stderr, "%sError:%s Invalid instruction, cannot shift right anymore! Exiting...\n", RED, RESET);
                return;
            }
            ++data_ptr;
            ++left_offset;                             // Update offset from left
        }
        else if(*code_ptr == '<'){                     // Shift cursor to left cell
            if(left_offset == 0){
                fprintf(stderr, "%sError:%s Invalid instruction, cannot shift left anymore! Exiting...\n", RED, RESET);
                return;
            }
            --data_ptr;
            --left_offset;                             // Update offset from left
        }
        else if(*code_ptr == '+')                      // Increment value in cell
            ++*data_ptr;
        else if(*code_ptr == '-')                      // Decrement value in cell
            --*data_ptr;
        else if(*code_ptr == '.')                      // Output cell contents
            putchar(*data_ptr);
        else if (*code_ptr == '*'){                    // Dump multiple cell's contents
            int lower_bound = 0;                       // First cell user wants dumped
            int upper_bound = 0;                       // Last cell user wants dumped
            
            ++code_ptr;                                // Increment instruction pointer
            if(!isdigit(*code_ptr)){                   // Check to make sure the instruction is a digit
                fprintf(stderr, "%sError:%s Cell Dumping - Expected integer for lower bound!\n", RED, RESET);
                return;
            }
            lower_bound = *code_ptr - '0';             // Set lower bound
            
            ++code_ptr;                                // Increment instruction pointer
            if(*code_ptr != '^'){                      // Make sure instruction is '^'
                if(isdigit(*code_ptr)){                // If not '^' and is digit
                    fprintf(stderr, "%sError:%s Cell Dumping may only be applied to cells 0-9\n", RED, RESET);
                }
                else                                   // If not '^' and is anything else
                    fprintf(stderr, "%sError:%s Cell Dumping - Expected '^'\n", RED, RESET);
                return;
            }
            ++code_ptr;                                // Increment instruction pointer
            
            if(!isdigit(*code_ptr)){                   // Check to make sure next instruction is digit
                fprintf(stderr, "%sError:%s Cell Dumping - Expected integer for upper bound!\n", RED, RESET);
                return;
            }
            upper_bound = *code_ptr - '0';             // Set upper bound
            
            ++code_ptr;                                // Temporarily increment instruction pointer
            if(isdigit(*code_ptr)){                    // Check to see is the next instruction is a digit
                fprintf(stderr, "%sError:%s Cell Dumping may only be applied to cells 0-9\n", RED, RESET);
                return;
            }
            --code_ptr;                                // Decrement instruction pointer if not a digit
            
            if(lower_bound > upper_bound) {            // Check to make sure the lower bound is less than the upper bound
                fprintf(stderr, "%sError:%s Cell Dumping - Lower bound is greater than upper bound!\n", RED, RESET);
                return;
            }
            
            if(left_offset < lower_bound){             // If the data pointer is below the lower bound, then move it to the lower bound
                while(left_offset != lower_bound){
                    ++data_ptr;
                    ++left_offset;
                }
            }
            else if(left_offset > lower_bound){        // If the data pointer is above the lower bound, then move it to the lower bound
                while(left_offset != lower_bound){
                    --data_ptr;
                    --left_offset;
                }
            }
            if(left_offset == lower_bound){           // If the data pointer is at the lower bound, then output data until upper bound, inclusive
                while(left_offset != upper_bound + 1){
                    putchar(*data_ptr);
                    if(left_offset != upper_bound){
                        ++data_ptr;
                        ++left_offset;
                    }
                    else
                        break;
                }
            }
            
            while(left_offset != lower_bound -1){    // Reset all dumped cells to default value (0)
                *data_ptr = 0;
                if(left_offset != lower_bound){
                    --data_ptr;
                    --left_offset;
                }
                else
                    break;
            }
        }
        else if(*code_ptr == '?')                      // Input char
            *data_ptr=getchar();
        else if(*code_ptr == '{'){                     // Loop instructions between braces until the start cell reaches 0
            if(!(*data_ptr))                             //===============================================================
            {                                                                       //
                braces++;                                                           //
                while(braces)                                                       //
                {                                                                   //
                    ++code_ptr;                                                     //
                    if(*code_ptr == '}')                                            //
                        braces--;                                                   //
                    else if(*code_ptr == '{')                                       //
                        braces++;                                                   //
                }                                                                   //
            }                                                                       //
        }                                                                           //
        else if(*code_ptr == '}'){                                                  //
            if(*data_ptr){                                                          //
                braces++;                                                           //
                while(braces)                                                       //
                {                                                                   //
                    code_ptr--;                                                     //
                    if(*code_ptr == '{')                                            //
                        braces--;                                                   //
                    else if(*code_ptr == '}')                                       //
                        braces++;                                                   //
                }                                                                   //
            }                                                                       //
        }                                              //================================================================
        else{
            fprintf(stderr, "%sError:%s Unknown symbol '%c' found!\n", RED, RESET, *code_ptr); // Error if an unknown symbol has been found
            return;
        }
        ++code_ptr;                                   // Increment to next screw instruction
    }
}
