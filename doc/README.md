Indocoin 1.7
=====================

* Copyright (c) 2009-2014 Bitcoin Developers
* Copyright (c) 2011-2013 Litecoin Developers
* Copyright (c) 2013-2014 Indocoin Developers


Setup
---------------------
[Indocoin Core](http://indocoin.xyz/en/download) is the original Indocoin client and it builds the backbone of the network. However, it downloads and stores the entire history of Indocoin transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once.

Running
---------------------
The following are some helpful notes on how to run Indocoin on your native platform. 

### Unix

You need the Qt4 run-time libraries to run Indocoin-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/indocoin-qt (GUI, 32-bit) or bin/32/indocoind (headless, 32-bit)
- bin/64/indocoin-qt (GUI, 64-bit) or bin/64/indocoind (headless, 64-bit)



### Windows

Unpack the files into a directory, and then run indocoin-qt.exe.

### OSX

Drag Indocoin-Qt to your applications folder, and then run Indocoin-Qt.

### Need Help?

* See the documentation at the [Indocoin Wiki](http://indocoin.xyz/)
for help and more information.
* Ask for help on [#indocoin](http://webchat.freenode.net?channels=indocoin) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=indocoin).
* Ask for help on the [/r/indoducation subreddit](http://reddit.com/r/indoducation).

Building
---------------------
The following are developer notes on how to build Indocoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-msw.md)

Development
---------------------
The Indocoin repo's [root README](https://github.com/indocoin/indocoin/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/bitcoin/doxygen/)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Resources
* Discuss on the [/r/indocoindev](http://www.reddit.com/r/indocoindev) subreddit.
* Discuss on [#indocoin-dev](http://webchat.freenode.net/?channels=indocoin-dev) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=indocoin-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
