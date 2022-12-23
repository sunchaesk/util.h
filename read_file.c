
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    if (argc < 2) {
        fprintf(stderr, "ERROR: no file input\n");
        exit(1);
    }
    FILE * file = fopen(argv[1], "r");

    if (file == NULL){
        fprintf(stderr, "ERROR: file open returned NULL\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *file_contents = malloc(file_size +1);

    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    fread(file_contents, 1, file_size, file);

    file_contents[file_size] = '\0';

    fclose(file);

    /////////////////////////////////////
    //           DO STUFF           ////
    printf("%s\n", file_contents);
    /////////////////////////////////////
    free(file_contents);
    return 0;
}
