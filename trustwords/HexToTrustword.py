#!/usr/bin/python3

# Except where noted as authored by David Norman, original author was Aidan Fray.

import sys, re # added DN

MAP_HEX_TO_WORDS = {}

def load_mappings(filePath):
    """
    Loads the hex -> word mapping into a local dictionary
    """

    with open(filePath) as f: # edited DN

        for line in f: # edited DN
            line_parts = line.split(",")

            # Maps string to 
            word        =  line_parts[2]

            # [2:]        - Removes "0x"
            # zfill(4)    - Pads to a minimum of 4 hex values
            word_hex    =  hex(int(line_parts[1]))[2:].zfill(4)

            # Hex --> Word
            MAP_HEX_TO_WORDS.update({word_hex : word})

def fingerprint_to_words(fingerprint):
    """
    Maps the hex value of the key to a word defined in
    the dictionary
    """

    fingerprint = fingerprint.replace(" ", "")

    trustwords = []

    chunks = re.findall(".{4}", fingerprint)

    for chunk in chunks:
        trustwords.append(MAP_HEX_TO_WORDS[chunk.lower()])

    trustwords_str = " ".join(trustwords)

    print("#" * (len(trustwords_str) + 1))
    print(trustwords_str)
    print("#" * (len(trustwords_str) + 1))

    return trustwords

# !!! work by DN:

def main(argv):
    load_mappings("en.csv")
    with open(str(argv[0]), 'r') as input_file, open("output/%s" % str(argv[1]), "w+") as output_file:
        for line in input_file:
            print("Processing " + line)
            trustwords_list = fingerprint_to_words(line)
            output_line = ""
            for word in trustwords_list:
                output_line += (word + ' ')
            output_file.write(output_line[:-1] + "\n")

if __name__ == "__main__" and len(sys.argv) == 3:
    main(sys.argv[1:])
else:
    print("Incorrect arguments supplied.")
