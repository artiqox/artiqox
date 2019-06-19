### Building artiqox-qt 1.14 on modern macs. ###

Note that this requires changes made by michilumin on the 1.14-dev branch as well as some changes to BDB.

Tested on OSX 10.11 El Capitan and 10.13 High Sierra.

**Paper wallet printing support seems to work fine through this method as well.**

### Clone artiqox locally, or check it out, etc. ###

For this purpose, just indicating the 1.14-branding branch in my repo.

	$git clone -b 1.14-branding --single-branch https://github.com/michilumin/artiqox.git

### Set up OSX basic build dependencies. ##

Install xcode-select commandline utils.

    $xcode-select --install

**note:** If you have Xcode installed, simply zip it up and move it for this process, as your current Xcode install will likely conflict. Unzip it back later.

Make sure frameworks dir is properly owned...

    $sudo mkdir /usr/local/Frameworks
    $sudo chown $(whoami):admin /usr/local/Frameworks

Install Brew.

    $/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

Install dependencies via Brew.

    $brew install autoconf automake libtool miniupnpc openssl pkg-config protobuf qt5 zeromq qrencode librsvg boost

Install Boost lib via Brew from source, and link it to be sure:

**note** Boost version may have changed by the time you're reading this, from 167.

    $brew install boost --build-from-source --HEAD
    $brew link boost167

### Get, Patch And Compile BDB 5.1 ###

Download bdb 5.1.29 source from Oracle.

    $curl -o db-5.1.29.tar.gz http://download.oracle.com/berkeley-db/db-5.1.29.tar.gz
    $tar xvfz db-5.1.29.tar.gz
    $cd db-5.1.29

Patch bdb 5.1.29 from our patchfiles

    $cd src
    $cd dbinc
    $patch -b atomic.h ~/artiqox/depends/patches/bdb-5.1.29-clang-osx/atomic.h.patch
    $cd ..
    $cd mp
    $patch -b mp_fget.c ~/artiqox/depends/patches/bdb-5.1.29-clang-osx/mp_fget.c.patch
    $patch -b mp_mvcc.c ~/artiqox/depends/patches/bdb-5.1.29-clang-osx/mp_mvcc.c.patch
    $patch -b mp_region.c ~/artiqox/depends/patches/bdb-5.1.29-clang-osx/mp_region.c.patch
    $cd ..
    $cd mutex
    $patch -b mut_method.c ~/artiqox/depends/patches/bdb-5.1.29-clang-osx/mut_method.c.patch
    $patch -b mut_tas.c ~/artiqox/depends/patches/bdb-5.1.29-clang-osx/mut_tas.c.patch

Build BDB 5.1.29

    $cd ../.. 
    $cd build_unix
    $../dist/configure CXX=clang++ --enable-cxx
    $make
    $sudo mkdir /usr/local/BerkeleyDB.5.1
    $sudo chown $(whoami):admin /usr/local/BerkeleyDB.5.1
    $sudo make install

### Set some environment variables and links for bdb and openssl ###

    $export LDFLAGS=-L/usr/local/BerkeleyDB.5.1/lib
    $export CPPFLAGS=-I/usr/local/BerkeleyDB.5.1/include
    $export INCPATHS=-I/usr/local/opt/openssl/include
    $export LIBPATHS=-L/usr/local/opt/openssl/lib
    $cd /usr/local/include 
    $ln -s ../opt/openssl/include/openssl 

### Go back to your Dogecoin repo ###

    $cd ~/artiqox
    $./autogen.sh
    $./configure --with-gui=qt5 --with-qrcode=yes
    $make

Go have a beverage.

    $make install

Go have another beverage.

Run it.

	$/usr/local/bin/artiqox-qt





