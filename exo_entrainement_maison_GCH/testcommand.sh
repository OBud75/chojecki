#!/bin/bash

command=htop

if command -v $command
then
    echo "ok $command est bien là"
else
    echo "non il nest pas là"
fi
