Artiqox Core 1.14
==================

Setup
---------------------
[Artiqox Core](http://artiqox.com/) is the reference Artiqox client and it builds the backbone of the network. However, it downloads and stores the entire history of Artiqox transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download Artiqox Core, visit [artiqox.com](https://artiqox.com/releases/).

Running
---------------------
The following are some helpful notes on how to run Artiqox on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/artiqox-qt` (GUI) or
- `bin/artiqoxd` (headless)

### Windows

Unpack the files into a directory, and then run artiqox-qt.exe.

### OS X

Drag Artiqox-Core to your applications folder, and then run Artiqox-Core.

### Need Help?

* See the documentation at the [Artiqox Wiki](https://wiki.artiqox.com/Main_Page)
for help and more information.
* Ask for help on [#artiqox](http://webchat.freenode.net?channels=artiqox) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=artiqox).
* Ask for help on the official Telegram Channel (https://t.me/Artiqox).

Building
---------------------
The following are developer notes on how to build Artiqox on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The Artiqox repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/bitcoin/doxygen/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Travis CI](travis-ci.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the official Telegram Channel (https://t.me/Artiqox).
* Discuss on [#artiqox-dev](http://webchat.freenode.net/?channels=artiqox) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=artiqox-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the Bitcoin developers for use in [Bitcoin Core](https://www.bitcoin.org/). 
This product includes software developed by the Dogecoin developers for use in [Dogecoin Core](https://www.dogecoin.com/). 
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
