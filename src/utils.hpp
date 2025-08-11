#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <fstream>
#include <system_error>
#include <errno.h>
namespace fs = std::filesystem;

namespace ppvenv {

    int init        ();
        // Creates .venv dir if not existing. Else, return 0.
    
    int run         (char* argv[]);
        // Runs the passed python file w. .venv/bin/python.
    
    int add_module  (char* argv[]);
        // Adds modules via pip to the requirements.txt.

    int sync        ();
        // Installs the requirments.txt file via pip.

	int cmd			(char* argv[]);
		// Runs commands via the ppvenv .venv

	// HELPERS //
	bool venv_exists();
	bool req_exists ();
};	

#endif  // UTILS_HPP CLOSE
