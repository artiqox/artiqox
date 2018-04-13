# Artiqox Core 1.1.1
=====================

Artiqox Core 1.8.1 is primarily a bugfix release, bringing Artiqox Core in
line with Bitcoin 0.9.3. Artiqox Core 1.8.1 also adds in support for printing
paper wallets, and disables connections to pre-1.8 clients.

Paper wallet support has been developed by AndyMeows (IRC username), and 
can be accessed via the "File" menu. It's intended for two purposes; to generate
small value paper wallets to hand out, and more permanent deposit paper wallets
for keeping balances offline.

IMPORTANT: If you are producing offline paper wallets, you should do so on a
computer that's disconnected from the Internet. While the wallet generator
does not save the keys it generates, this ensures there is no risk of a virus
or similar capturing the key from memory or interfering with its generation.