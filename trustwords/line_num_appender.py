#!/usr/bin/python3

import sys

def main(argv):
    with open(str(argv[0]), 'r') as input_file, open(("output/%s" % str(argv[1])), "w+") as output_file:
        i = 1
        for line in input_file:
            new_line = line[:-2] + " %d\n" % i
            output_file.write(new_line)
            i += 1

if __name__ == "__main__" and len(sys.argv) == 3:
    main(sys.argv[1:])
else:
    print("Incorrect arguments supplied.")
