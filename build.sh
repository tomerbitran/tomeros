#!/bin/bash
export PREFIX="$HOME/opt/cross_compiler"
export TARGET=i386-elf
export PATH="$PREFIX/bin:$PATH"

export GCC_VERSION=9.3.0
export BINUTILS_VERSION=2.34

cd $HOME/src

# binutils
mkdir build-binutils
cd build-binutils
../binutils-$BINUTILS_VERSION/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install


# gcc, g++

cd $HOME/src

cd gcc-$GCC_VERSION
./contrib/download_prerequisites
cd $HOME/src # Returning the main src folder

# The $PREFIX/bin dir _must_ be in the PATH. We did that above.
which -- $TARGET-as || echo $TARGET-as is not in the PATH
 
mkdir build-gcc
cd build-gcc
../gcc-$GCC_VERSION/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers

make all-target-libgcc
make install-target-libgcc
make all-gcc
make install-gcc
