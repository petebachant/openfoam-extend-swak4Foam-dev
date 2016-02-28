#!/usr/bin/env sh
# This script installs OpenFOAM on the system
# The first arg should be the OpenFOAM version

if [ "$1" = "dev" ]
then
    cd $HOME/OpenFOAM
    git clone https://github.com/OpenFOAM/OpenFOAM-dev.git
    git clone https://github.com/OpenFOAM/ThirdParty-dev.git
    source $HOME/OpenFOAM/OpenFOAM-dev/etc/bashrc
    # Obtain binaries built by wyldckat
    wget https://github.com/wyldckat/OpenFOAM-dev/releases/download/20160227-181109/OpenFOAM-dev.linux64GccDPInt32Opt_2016-02-27.tbz
    tar -xf OpenFOAM-dev.linux64GccDPInt32Opt_2016-02-27.tbz
    wget https://github.com/wyldckat/ThirdParty-dev/releases/download/20160227-181109/ThirdParty-dev.linux64GccDPInt32Opt_2016-02-27.tbz
    tar -xf ThirdParty-dev.linux64GccDPInt32Opt_2016-02-27.tbz
    cd $WM_PROJECT_DIR
    wmakeLnIncludeAll
elif [ "$1" = "3.0" ]
then
    sudo add-apt-repository http://www.openfoam.org/download/ubuntu
    sudo apt-get update -qq
    sudo apt-get install -qq openfoam30 --allow-unauthenticated
fi
