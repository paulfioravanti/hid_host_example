#!/bin/bash
gcc $(pkg-config --cflags --libs hidapi) host.c -o host
