#!/bin/sh
sudo apt-get -y install binutils gcc make cmake autotools-dev autoconf automake libtool libudev-dev libusb-1.0-0-dev pkg-config g++
DIR=$( cd "$( dirname "$0" )" && pwd )
cd ${DIR}
make
cp tempered ../
sudo groupadd temper
sudo cp temper.rules /etc/udev/rules.d/
#sudo udevadm control --reload-rules
sudo udevadm trigger
