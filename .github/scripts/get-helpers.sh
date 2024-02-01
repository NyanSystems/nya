#!/usr/bin/env bash

# Check if there's "helpers" folder in the current directory, if no - create it
if [ ! -d helpers ]; then
    printf "Creating helpers folder...\n"
    mkdir helpers

    printf "Downloading libnya...\n"
    wget https://github.com/NyanSystems/libnya/archive/refs/heads/main.zip -O libnya.zip

    printf "Unzipping libnya...\n"
    unzip libnya.zip

    printf "Moving libnya...\n"
    rm libnya.zip
    mv libnya-main/src/* helpers
    mv libnya-main/include/* helpers
    rm -rf libnya-main
fi