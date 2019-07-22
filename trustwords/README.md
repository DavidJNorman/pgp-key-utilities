# trustwords

This folder contains utilities for working with the TrustWords representation of a pair of key fingerprints.

All utilities described here place their output files in the `output/` folder.

## Generating pairs

Given a file containing a list of key fingerprints, to generate the file containing the hex numbers given by the XORs of each pair of fingerprints, we use the `pairer.py` utility, e.g.

```
python3 pairer.py input.txt output.txt
```

## Converting those pairs to the TrustWords representation

With `pairs.txt` as our input file containing the hex numbers generated by the pairs:

```
python3 HexToTrustword.py pairs.txt output.txt
```

Please note that `HexToTrustword.py` relies on the file `en.csv` being in the same folder as it - this file must not be moved or altered.

## Appending line numbers to files

When running analysis programs that return a subset of the original file (e.g. the lines where the first two words of the TrustWords representation match), we may wish to see the corresponding line numbers of the original file for each line in the new file. This can be achieved by appending line numbers to the original file:

```
python3 line_num_appender.py input.txt output.txt
```