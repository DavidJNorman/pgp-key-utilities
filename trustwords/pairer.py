#!/usr/bin/python3

import sys

def main(argv):
    with open(str(argv[0]), 'r') as input_file, open(("output/%s" % str(argv[1])), "w+") as output_file:
        lines = input_file.readlines()
        for i in range(len(lines) - 1):
            for j in range(i + 1, len(lines)):
                #print(str(hex(int(lines[i], 16))))
                #print(str(hex(int(lines[j], 16))))
                combined = int(lines[i], 16) ^ int(lines[j], 16)
                #print(str(hex(combined)))
                output_file.write(("%X" % combined).zfill(40) + "\n")

#[2:]

if __name__ == "__main__" and len(sys.argv) == 3:
    main(sys.argv[1:])
else:
    print("Incorrect arguments supplied.")
