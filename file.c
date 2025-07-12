#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to create file.\n");
        return;
    }

    char line[256];
    printf("Enter text to write (type END to finish):\n");
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "END", 3) == 0) break;
        fputs(line, file);
    }

    fclose(file);
    printf("File written successfully.\n");
}

void appendToFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Unable to open file to append.\n");
        return;
    }

    char line[256];
    printf("Enter text to append (type END to finish):\n");
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "END", 3) == 0) break;
        fputs(line, file);
    }

    fclose(file);
    printf("Data appended successfully.\n");
}

void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    char line[256];
    printf("\nContents of the file:\n\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    printf("\nEnd of file.\n");
}

int main() {
    const char *filename = "codtech_intern_file.txt";
    int choice;

    printf("===================================\n");
    printf("         CODTECH FILE TOOL         \n");
    printf("===================================\n");

    do {
        printf("\nMenu:\n");
        printf("1. Write to file (overwrite)\n");
        printf("2. Append to file\n");
        printf("3. Read from file\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                printf("Exiting... Internship work completed.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
