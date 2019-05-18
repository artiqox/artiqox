
Debian
====================
This directory contains files used to package artiqoxd/artiqox-qt
for Debian-based Linux systems. If you compile artiqoxd/artiqox-qt yourself, there are some useful files here.

## artiqox: URI support ##


artiqox-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install artiqox-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your artiqox-qt binary to `/usr/bin`
and the `../../share/pixmaps/artiqox128.png` to `/usr/share/pixmaps`

artiqox-qt.protocol (KDE)

