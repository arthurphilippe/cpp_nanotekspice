#!/bin/sh
echo "dump\nreset=1\ndisplay" | ./nanotekspice tests/counter.nts reset=1
