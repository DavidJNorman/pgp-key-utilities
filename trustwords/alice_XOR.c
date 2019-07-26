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
                for (int b = 0; b < 5; b++) {
                    char aliceByteStr[8], bobByteStr[8];
                    long int aliceXBob;
                    for (int count = 0; count < 8; count++) {
                        aliceByteStr[count] = aliceKey[(b * 8) + count];
                        bobByteStr[count] = line[(b * 8) + count];
                    }
                    printf("%08lX\n", strtol(aliceByteStr, NULL, 16));
                    printf("%08lX\n", strtol(bobByteStr, NULL, 16));
                    aliceXBob = strtol(aliceByteStr, NULL, 16) ^ strtol(bobByteStr, NULL, 16);
                    fprintf(outputFile, "%08lX", aliceXBob);
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