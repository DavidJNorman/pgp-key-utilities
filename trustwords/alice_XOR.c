#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 4) {
        FILE *inputFile = fopen(argv[2], "r");
        FILE *outputFile = fopen(argv[3], "w+");
        char line[64], aliceKey[64];
        int same = 1;
        sprintf(aliceKey, "%s", argv[1]);
        while (fgets(line, sizeof(line), inputFile)) {
            for (int i = 0; i < 40; i++) {
                if (line[i] != aliceKey[i]) {
                    same = 0;
                }
            }
            if (!same) {
                for (int i = 0; i < 40; i++) {
                    char aliceChar[2] = {aliceKey[i], '\0'};
                    char bobChar[2] = {line[i], '\0'};
                    long int aliceXBob;
                    aliceXBob = strtol(aliceChar, NULL, 16) ^ strtol(bobChar, NULL, 16);
                    fprintf(outputFile, "%0lX", aliceXBob);
                }
                fprintf(outputFile, "\n");
            }
        }
        fclose(inputFile);
        fclose(outputFile);
        return 0;
    } else {
        printf("Incorrect arguments supplied.\n");
        return 1;
    }
}
