# src/lib/CMakeLists.txt
project( fpv-lib )

# The unit test is called fpv-lib-test
add_executable(fpv-lib-test
	test/main.cpp           # It needs a minimalistic main
	test/catch.hpp	        # Catch header library.

	test/any-test           # And one single test file.
)

# Add the unit tests to the list of tests for "make test"
add_test(NAME test COMMAND fpv-lib-test)