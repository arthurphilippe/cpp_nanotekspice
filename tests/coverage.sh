#!/bin/bash
make fclean && make -j 4
make -j 4 tests_run
./tests/functionals_tests.sh $1
gcovr -r . --html -o coverage.html --html-details --exclude-directories=include/ --delete -s
firefox coverage.html
find -type f \( -name "*~" -o -name "#*#" -o -name "*.gcno" -o -name "*.gc*" -o -name "*.html" -o  -name "*.o" \) -delete
make fclean
