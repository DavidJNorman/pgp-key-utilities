# pgp-wordlist-converter
Utility for converting a hexadecimal key fingerprint into a string of words using the PGP WordList.

## How to use
Given a file containing a hexadecimal fingerprint on each line, this program outputs a file containing the corresponding PGP WordList representation on each line. The output file will be placed in the folder `io` - for example:

```
python3 main.py input.txt output.txt
```
