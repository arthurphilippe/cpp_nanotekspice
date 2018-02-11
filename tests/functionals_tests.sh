#!/bin/bash

RET=0

function diff_test {
	diff $1 $2 -q &> /dev/null
	if [ $? -ne 0 ]; then
		echo "NOK"
		RET=1
		diff $1 $2 --color=auto
		echo "***"
		echo
	else
		if [ $3 -ne $4 ]; then
			echo "KO"
			echo "Expected return status $3 but got status $4"
		else
			echo "OK"
		fi
	fi
}

function ret_test {
	if [ $1 -ne $2 ]; then
		echo "KO"
		echo "Expected return status $1 but got status $2"
	else
		echo "OK"
	fi
}

mkdir tests/logs/ -p

echo -n ":: Running simple xor test... "
./nanotekspice tests/nts_files/xor.nts a=0 b=0 &> tests/logs/test1.log << EOF
a=1
simulate
display
b=1
simulate
display
EOF

diff_test tests/logs/test1.log tests/logs/test1.txt $? 0

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

diff_test tests/logs/test2.log tests/logs/test2.txt $? 0

echo -n ":: Running invalid links test... "

./nanotekspice tests/nts_files/errorlink2.nts reset=1 &> /dev/null

ret_test $? 84

echo -n ":: Running invalid chipset test... "

./nanotekspice tests/nts_files/chipseterror2.nts &> /dev/null

ret_test $? 84

exit $RET
