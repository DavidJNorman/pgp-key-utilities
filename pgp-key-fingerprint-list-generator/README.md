# pgp-key-fingerprint-list-generator
Generates a list of key fingerprints given a file containing public keys.

## How to use
This project consists of three scripts. The first, `main.py` takes a file containing a key or keys and outputs a file containing the corresponding key fingerprints. For example, to output the fingerprints of the keys contained in `keys.pgp` to `data/output.txt`, one would run the following:

```
python3 main.py keys.pgp output.txt
```

If one has a sequence of files with similar (enumerating) names to be processed (in this example, `key001.pgp`, `key002.pgp`, ..., `key017.pgp`), the following is run:

```
python3 sequencer.py key 001 017 .pgp
```

Output files `key001.txt` to `key017.txt` will be written into the `data/` folder.

Finally, one may wish to join multiple output files into one file. Using the previous example:

```
python3 joiner.py data/key 001 017 .txt output.txt
```

which will output to file `output.txt` in `data/`.

(or you could just use `cat` like a normal person...)
