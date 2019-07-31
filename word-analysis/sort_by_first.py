#!/usr/bin/python3

import sys

def main(argv):
    with open(str(argv[0]), 'r') as infile, open("output/%s" % str(argv[1]), "w+") as outfile:
        trustwords = []
        for line in infile:
            trustwords.append(line.split())
        trustwords.sort()
        for sublist in trustwords: 
            #print(" ".join(sublist))
            outfile.write(" ".join(sublist) + "\n")

if __name__ == "__main__" and len(sys.argv) == 3:
    main(sys.argv[1:])
else:
    print("Incorrect arguments supplied")
