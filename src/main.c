#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]) {
    printf("Generating .editorconfig file...\n");

    char *path;
    char *name = ".editorconfig";

    if (argc < 2) {
        path = "./";
    }
    else {
        path = malloc(strlen(argv[1]) + 1);
        strcpy(path, argv[1]);
        strcat(path, "/");
    }

    printf("Setting file path to %s ...\n", path);
    char *filePath = (char *) malloc(strlen(path) + strlen(name) + 1);
    strcpy(filePath, path);
    strcat(filePath, name);

    printf("[DEBUG] FilePath: %s ...\n", filePath);

    // Check for .editorconfig file.
    if (access(filePath, F_OK) == -1) {
        // Create .editorconfig file.
        FILE* filePointer;
        char fileContent[] = "root = true \n"
            "\n"
            "[*]\n"
            "charset = utf-8\n"
            "end_of_line = lf\n"
            "indent_style = space\n"
            "indent_size = 4\n"
            "trim_trailing_whitespace = true\n"
            "insert_final_newline = true\n"
            "\n[*.md]\ntrim_trailing_whitespace = false\n";


        filePointer = fopen(filePath, "w");
        fprintf(filePointer, fileContent);
        fclose(filePointer);

        free(filePath);
        printf("Generated .editorconfig file successfully.\n");
        return 0;
    }
    else {
        // .editorconfig file exists already.
        fprintf(stderr, "File \".editorconfig\" already exits.\n");
        return 1;
    }
}
