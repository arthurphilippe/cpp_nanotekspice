#!/bin/bash
make fclean && make -j 4 CXX="g++ --coverage"
make -j 4 tests_run CXX="g++ --coverage"
./tests/functionals_tests.sh $1
gcovr -r . --exclude-directories=include/ --delete -s > coverage.log
which find
if [ $? -eq 0 ]; then
   find -type f \( -name "*~" -o -name "#*#" -o -name "*.gcno" -o -name "*.gc*" -o -name "*.html" -o  -name "*.o" \) -delete
fi
make fclean
