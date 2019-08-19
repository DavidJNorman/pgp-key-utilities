#!/usr/bin/python3

import sys, subprocess

def main(argv):
    with open(str(argv[4]), "w+") as output_file:
        for i in range(int(argv[1]), int(argv[2]) + 1):
            filename = ("%s%0" + str(len(str(argv[1]))) +"d%s") % (str(argv[0]), i, str(argv[3]))
            print("Attempting to process %s" % (filename))
            try:
                with open(filename, 'r') as input_file:
                    for line in input_file:
                        output_file.write(line)
                    print("%s added to output" % (filename))
            except:
                print("%s not found" % (filename))
                continue

if __name__ == "__main__" and len(sys.argv) == 6:
    main(sys.argv[1:])
else:
    print("Incorrect arguments supplied.")
