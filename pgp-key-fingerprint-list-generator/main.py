#!/usr/bin/python3

import sys, subprocess

def main(argv):
    subprocess.run("gpg --import --import-options show-only %s \&> data/data.txt" % (str(argv[0])), shell=True)
    with open("data/data.txt", 'r') as data, open("data/%s" % str(argv[1]), "w+") as outputfile:
        copy_next = False
        for line in data.readlines():
            print(line)
            if copy_next:
                outputfile.write("%s\n" % (line.strip()))
                copy_next = False
            elif line[:3] == "pub":
                copy_next = True
                print("copy_next is True")
            else:
                copy_next = False

if __name__ == "__main__" and len(sys.argv) == 3:
    main(sys.argv[1:])
else:
    print("Incorrect arguments supplied.")
