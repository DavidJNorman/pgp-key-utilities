# word-analysis

This folder contains utilities for analysing lists of textual representations of key fingerprints. Output files are stored in the `output/` folder.

## `sort_by_first.py`

To sort a given file's lines into alphabetical order, run the following:

```
python3 sort_by_first.py <input_file> <output_file>
```

## `check_n.py`

To output the pairs of lines in a file where the `n`th word is the same, run the following:

```
python3 check_n.py <input_file> <output_file> n
```

The idea is for `check_n.py` to be used repeatedly, with iteration `i`'s `<output_file>` becoming the `<input_file>` for iteration `i+1` - e.g. first we find the pairs where the second word is the same, then of those pairs, we find those of which the third word is the same etc., hoping to eventually find a full or at least a near-collision.
