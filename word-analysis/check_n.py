#!/usr/bin/python3

import sys

def main(argv):
    with open(str(argv[0]), 'r') as infile, open("output/%s" % str(argv[1]), "w+") as outfile:
        lines = infile.readlines()
        collisions = 0
        for i in range(len(lines) - 1):
            if lines[i].split()[int(argv[2]) - 1] == lines[i + 1].split()[int(argv[2]) - 1]:
                collisions += 1
                #outfile.write("%i\n" % (i - 1))
                outfile.write("%s %i\n" % (lines[i][:-2], collisions))
                outfile.write("%s %i\n" % (lines[i + 1][:-2], collisions))

if __name__ == "__main__" and len(sys.argv) == 4:
    main(sys.argv[1:])
else:
    print("Incorrect arguments supplied.")
