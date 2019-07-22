# pgp-key-harvester
A utility for harvesting public PGP keys in .gpg format from various keyservers.

## How to use

Compile `pgp_harvester.c` on your system. Assuming that the output file is named `a.out`, the program is run in the following way:

```
./a.out <start_of_range> <end_of_range> <list_of_keyservers>
```

Where:

- `<start_of_range>` is the first short ID you wish to check (8-digit hexadecimal number, e.g. `010F56AE`)
- `<end_of_range>` is the last short ID you wish to check (8-digit hexadecimal number)
- `<list_of_keyservers>` is a list of keyservers, separated by spaces, which are to be queried for a key matching the short ID (e.g. `pgp.mit.edu keyring.debian.org keyserver.ubuntu.com` - single-item lists are also permitted)
