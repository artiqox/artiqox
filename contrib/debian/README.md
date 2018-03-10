
Debian
====================
This directory contains files used to package indocoind/indocoin-qt
for Debian-based Linux systems. If you compile indocoind/indocoin-qt yourself, there are some useful files here.

## indocoin: URI support ##


indocoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install indocoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your indocoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/indocoin128.png` to `/usr/share/pixmaps`

indocoin-qt.protocol (KDE)

