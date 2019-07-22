#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void harvester(unsigned long start_val, unsigned long end_val);
void receive_and_export(char keyserver[], int prefix, unsigned long short_id);

/* first argument is program name, second is start value, third is end value */
int main(int argc, char *argv[]) {
    if (argc >= 4) {
	    for (int i = 3; i < argc; i++) {
            // filename is "<i-2>-<short_id>.gpg"
            for (unsigned long j = strtol(argv[1], NULL, 16); j <= strtol(argv[2], NULL, 16); j++) {
                receive_and_export(argv[i], i-2, j);
            }
        }
        return 0;
    }
    else {
        printf("Incorrect arguments.\n");
        return 1;
    }
}

void receive_and_export(char keyserver[], int prefix, unsigned long short_id) {
    char command1[256], command2[256], filename[256];
    printf("Searching for 0x%08lX on keyserver %s...\n", short_id, keyserver);
    sprintf(command1, "gpg --keyserver %s --recv-keys 0x%08lX", keyserver, short_id);
    int recv = system(command1);
    sprintf(filename, "exported/%d-%08lX.gpg", prefix, short_id);
    sprintf(command2, "gpg --export --output %s 0x%08lX", filename, short_id);
    int exp = system(command2);
    if (access(filename, F_OK) != -1) {
        printf("Exported public key from fingerprint 0x%08lX to %s\n", short_id, filename);
    } else {
        printf("No key found for short id 0x%08lX on server %s\n", short_id, keyserver);
    }
}
