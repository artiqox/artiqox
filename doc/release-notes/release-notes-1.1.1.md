# Artiqox Core 1.1.1

Artiqox Core 1.1.1 is primarily a bugfix release, bringing Artiqox Core in
line with Bitcoin 0.9.3. It updates OpenSSL to 1.0.1l, mainly fixing security
issues. Artiqox Core 1.1.1 also adds in support for printing paper wallets, and
disables connections to pre-1.1 clients. This is a RECOMMENDED upgrade due to the
large number of bug fixes, but is not a required one.

Paper wallet support has been developed by AndyMeows (IRC username), and 
can be accessed via the "File" menu. It's intended for two purposes; to generate
small value paper wallets to hand out, and more permanent deposit paper wallets
for keeping balances offline.

IMPORTANT: If you are producing offline paper wallets, you should do so on a
computer that's disconnected from the Internet. While the wallet generator
does not save the keys it generates, this ensures there is no risk of a virus
or similar capturing the key from memory or interfering with its generation.

## Artiqox Core Release Notes

* Translation improvements and corrections
* Disable Transifex based translation process (not used by Artiqox Core)
* Disable connections from pre-1.1 Artiqox Core clients
* Remove unreachable code introduced with AuxPoW support
* "blocknotify" option now supports %i as a format parameter, which is replaced by block height
* New option "maxoutconnections" to set the maximum number of outbound peer connections. Defaults to 8, minimum is 2, maximum is whatever "maxconnections" is set to (default 125).
* Update to OpenSSL 1.0.1l
* Added Peer Tab to Debug Window

## Bitcoin Core Release Notes

Full release notes for Bitcoin Core 0.9.3 are available from
https://bitcoin.org/en/release/v0.9.3 , but highlights are included
below:


* Better orphan transaction handling
* Add -maxorphantx=<n> and -maxorphanblocks=<n> options for control over the maximum orphan transactions and blocks
* key.cpp: fail with a friendlier message on missing ssl EC support
* Upgrade OpenSSL to 1.0.1i (see https://www.openssl.org/news/secadv_20140806.txt - just to be sure, no critical issues for Bitcoin Core)


## OpenSSL Warning

The main takeaway is that builds from http://github.com/artiqox/artiqox/releases
are not affected. But if you build your own version, please make sure you update to 1.1.1 **before** updating your OpenSSL!

Please refer to this section in the Bitcoin Core release notes for further info: https://github.com/bitcoin/bitcoin/blob/0.9/doc/release-notes.md#openssl-warning


## Credits

Listed in strictly alphabetical order, using name listed in Github. This
includes those whose contributions to Bitcoin Core have been merged
into Artiqox Core:

* Abderraouf Adjal
* Alan Cramer
* Andymeows
* Cory Fields
* Daniel Kraft
* Gavin Andresen
* Gregory Maxwell
* langerhans
* michilumin
* nameEO
* Patrick Lodder
* Ross Nicoll
* Wladimir J. van der Laan
* Whit J