#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc == 4) {
        FILE* inputFile = fopen(argv[2], 'r');
        FILE* outputFile = fopen(argv[3], "w+");
        char line[64];
        char aliceKey[64] = argv[1];
        int same = 1;
        while (fgets(line, sizeof(line), inputFile)) {
            for (int i = 0; i < 40; i++) {
                if (line[i] != aliceKey[i]) {
                    same = 0;
                }
            }
            if (!same) {
                int i = 0;
                for (int b = 0; b < 5; b++) {
                    char aliceByteStr[8];
                    char bobByteStr[8];
                    int aliceByte;
                    int bobByte;
                    int aliceXBob;
                    for (int count = 0; count < 8; count++) {
                        aliceByteStr[count] = aliceKey[i];
                        bobByteStr[count] = line[i]
                        i++;
                    }
                    aliceXBob = strtol(aliceByteStr, NULL, 16) ^ strtol(bobByteStr, NULL, 16);
                    fprintf(outputFile, "%00000000X", aliceXBob);
                }
                fprintf(output_file, '\n');
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
