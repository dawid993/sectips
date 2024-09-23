#!/bin/bash

# It as opposed to c program doest work.
# Even when suid bit is set bash drops this privilege when executing script.
# It will work however if you use sudo
echo "$(id)"
echo "$(whoami)"

./greetings.sh