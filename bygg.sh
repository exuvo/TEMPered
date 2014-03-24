#!/bin/sh
sudo apt-get -y install binutils gcc make cmake autoconf libtool libudev
DIR=$( cd "$( dirname "$0" )" && pwd )
cd ${DIR}
make
cp tempered ../
