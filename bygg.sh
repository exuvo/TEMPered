#!/bin/sh
#sudo apt-get -y install binutils gcc make cmake
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd ${DIR}
make
cp tempered ../
