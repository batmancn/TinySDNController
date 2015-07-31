#!/bin/bash

export ACE_ROOT=$(pwd)

# for use shared library
export LD_LIBRARY_PATH=$ACE_ROOT/lib:$LD_LIBRARY_PATH

# for install usage
export INSTALL_PREFIX=$ACE_ROOT/install
mkdir -p $ACE_ROOT/install
