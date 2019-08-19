#!/usr/bin/python3

import sys, subprocess

def main(argv):
    for i in range(int(argv[1]), int(argv[2]) + 1):
        filename = ("%s%0" + str(len(str(argv[1]))) +"d") % (str(argv[0]), i)
        postfix = str(argv[3])
        subprocess.run("python3 main.py data/%s%s %s.txt" % (filename, postfix, filename), shell=True)

if __name__ == "__main__" and len(sys.argv) == 5:
    main(sys.argv[1:])
else:
    print("Incorrect arguments supplied.")
