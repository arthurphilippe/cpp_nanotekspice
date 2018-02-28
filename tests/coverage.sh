#!/bin/bash

set -e

echo ":: Rebuilding with coverage flags..."
make fclean && make -j 4 CXX="g++ --coverage"
make -j 4 tests_run CXX="g++ --coverage"

echo -e "\n:: Running functionnal tests..."
./tests/functionals_tests.sh $1 || true
echo " --> Test and build complete!"


if [ "$1" == "html" ] || [ "$2" == "html" ]; then
	echo -e "\n:: Proccessing coverage artefacts..."
	gcovr -r . --html -o coverage.html --html-details --exclude-directories=include/ --delete -s

	echo -e "\n:: Displaying tests results..."
	firefox coverage.html
else
	echo -e "\n:: Proccessing coverage artefacts..."
	gcovr -r . --exclude-directories=include/ --delete -s > coverage.log
	echo -e "\n:: Displaying tests results..."
	cat coverage.log
fi

echo ":: Cleanning up..."
# make fclean
find -type f \( -name "*~" -o -name "#*#" -o -name "*.gcno" -o -name "*.gc*" -o -name "*.html" -o  -name "*.o" \) -delete || true
