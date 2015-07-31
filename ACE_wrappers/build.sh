#!/bin/bash

export ACE_ROOT=$(pwd)

# for use shared library                                                        
export LD_LIBRARY_PATH=$ACE_ROOT/lib:$LD_LIBRARY_PATH

# for install usage
export INSTALL_PREFIX=$ACE_ROOT/install
mkdir -p $ACE_ROOT/install

if [ ! -f "$ACE_ROOT/ace/config.h" ] ; then
    touch $ACE_ROOT/ace/config.h
    echo "#include \"ace/config-linux.h\"" > $ACE_ROOT/ace/config.h
fi

if [ ! -f "$ACE_ROOT/include/makeinclude/platform_macros.GNU" ] ; then
    touch $ACE_ROOT/include/makeinclude/platform_macros.GNU
    echo "include \$(ACE_ROOT)/include/makeinclude/platform_linux.GNU"  > $ACE_ROOT/include/makeinclude/platform_macros.GNU
    echo "static_libs=1" > $ACE_ROOT/include/makeinclude/platform_macros.GNU
fi

make
make install
