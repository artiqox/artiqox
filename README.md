# Artiqox Core [AIQ, ₳]
==========================

![Artiqox](https://avatars2.githubusercontent.com/u/37213767?s=250&v=4)

## What is Artiqox?
Artiqox is a cryptocurrency like Bitcoin, although it does not use SHA256 as its proof of work (POW). Taking development cues from Dogecoin, Tenebrix and Litecoin, Artiqox currently employs a simplified variant of scrypt.

http://artiqox.com/

## License
Artiqox is released under the terms of the MIT license. See [COPYING](COPYING)
for more information or see http://opensource.org/licenses/MIT.

## Development and contributions
Development is ongoing, and the development team, as well as other volunteers, can freely work in their own trees and submit pull requests when features or bug fixes are ready.

#### Version strategy
Version numbers are following ```major.minor.patch``` semantics.

#### Branches
There are 3 types of branches in this repository:

- **master:** Unstable, contains new code for planned releases.  We DO NOT recommend anyone run this code on a production machine or in a production environment.  If your wallet breaks, you get to keep all the pieces.  We have done this, to show code additions and removal as this is how most sites monitor development.
- **maintenance:** Stable, contains the latest version of previous releases, which are still under active maintenance. Format: ```<version>-maint```
- **archive:** Stable, contains obsolete and redundant code.  Kept in archive for historic reasons.  These versions will generally run but will not connect to the AIQ Network Format: ```<version>-archive```

## Frequently Asked Questions

### How to get Artiqox?
Artiqox uses a simplified variant of the scrypt key derivation function as its proof of work with a target time of one minute per block and difficulty readjustment after every block. The block rewards are fixed and halve every 200,000 blocks. Starting with the 1,000,000th block, a permanent reward of 42 Artiqox per block will be paid. 

The current block reward schedule:

1–199,999: 2,000 Artiqox 

200,000–399,999: 1,000 Artiqox

400,000–599,999: 500 Artiqox

600,000–799,999: 250 Artiqox

800,000–899,999: 125 Artiqox

900,000–999,999: 75 Artiqox

1,000,000+: 42 Artiqox

### How to Build artiqoxd/artiqox-cli/artiqox-qt

  The following are developer notes on how to build Artiqox on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

  - [OSX Build Notes](doc/build-osx.md)
  - [Unix Build Notes](doc/build-unix.md)
  - [Windows Build Notes](doc/build-msw.md)

### Ports
RPC 19421
P2P 19427

Translations
------------

Changes to translations, as well as new translations, can be submitted to
[Bitcoin Core's Transifex page](https://www.transifex.com/projects/p/bitcoin/).

Periodically the translations are pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

If the changes are Artiqox specific, they can be submitted as pull requests against this repository.
If it is a general translation, consider submitting it through upstream, as we will pull these changes later on.

Development tips and tricks
---------------------------

**compiling for debugging**

Run configure with the --enable-debug option, then make. Or run configure with
CXXFLAGS="-g -ggdb -O0" or whatever debug flags you need.

**debug.log**

If the code is behaving strangely, take a look in the debug.log file in the data directory;
error and debugging messages are written there.

The -debug=... command-line option controls debugging; running with just -debug will turn
on all categories (and give you a very large debug.log file).

The Qt code routes qDebug() output to debug.log under category "qt": run with -debug=qt
to see it.

**testnet and regtest modes**

Run with the -testnet option to run with "play AIQ" on the test network, if you
are testing multi-machine code that needs to operate across the internet.

If you are testing something that can run on one machine, run with the -regtest option.
In regression test mode, blocks can be created on-demand; see qa/rpc-tests/ for tests
that run in -regtest mode.

**DEBUG_LOCKORDER**

Artiqox Core is a multithreaded application, and deadlocks or other multithreading bugs
can be very difficult to track down. Compiling with -DDEBUG_LOCKORDER (configure
CXXFLAGS="-DDEBUG_LOCKORDER -g") inserts run-time checks to keep track of which locks
are held, and adds warnings to the debug.log file if inconsistencies are detected.
