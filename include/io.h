#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

char write_to_file(char* filename, double* data, uint64_t size, char binary);
char write_binary(char* filename, double* data, uint64_t size);
char write_text(char* filename, double* data, uint64_t size);
void progress(uint64_t curr, uint64_t size);
void clear_progress();
