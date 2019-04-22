#!/bin/bash
echo -e "\nBuilding client.\n"
cd client
cmake . .
make
cd ..
echo -e "\nStarting client.\n"
./client/bin/client
