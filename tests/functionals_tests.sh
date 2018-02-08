#!/bin/bash
# echo -e "dump\nreset=1\ndisplay" | ./nanotekspice tests/counter.nts reset=1

RET=0

function diff_test {
	diff $1 $2 -q &> /dev/null
	if [ $? -ne 0 ]; then
		echo "NOK"
		RET=1
		diff $1 $2 --color=auto
		echo "##########"
	else
		echo "OK"
	fi
}

mkdir tests/logs/ -p

echo -n ":: Running simple xor test... "
./nanotekspice tests/xor.nts a=0 b=0 &> tests/logs/test1.log << EOF
a=1
simulate
display
b=1
simulate
display
EOF

diff_test tests/logs/test1.log tests/logs/test1.txt
# RES=$(diff tests/logs/test1.log tests/logs/test1.txt)

echo -n ":: Running D latch test... "

./nanotekspice tests/nts_files/d_latch.nts data=0 set=0 reset=1 &> tests/logs/test2.log << EOF
reset=0
simulate
display
data=1
simulate
display
simulate
display
reset=1
simulate
display
reset=0
set=1
simulate
display
reset=1
simulate
display
EOF

diff_test tests/logs/test2.log tests/logs/test2.txt

exit $RET
