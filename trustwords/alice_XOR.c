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
            printf("aliceKey = %s, line = %s\n", aliceKey, line);
            printf("With strtol applied:\n");
            printf("aliceKey = %040lX, line = %040lX\n", strtol(aliceKey, NULL, 16), strtol(line, NULL, 16));
            for (int i = 0; i < 40; i++) {
                if (line[i] != aliceKey[i]) {
                    same = 0;
                }
            }
            if (!same) {
                for (int i = 0; i < 40; i++) {
                    char aliceChar[1], bobChar[1];
                    long int aliceXBob;
                    aliceChar[0] = aliceKey[i];
                    bobChar[0] = line[i];
                    aliceXBob = strtol(aliceChar, NULL, 16) ^ strtol(bobChar, NULL, 16);
                    printf("%0lX ^ %0lX = %0lX\n", strtol(aliceChar, NULL, 16), strtol(bobChar, NULL, 16), aliceXBob);
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
