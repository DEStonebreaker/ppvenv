#include "utils.hpp"
#include <cstdlib>
#include <filesystem>
#include <system_error>

namespace ppvenv {

int init () {
    // std::cerr << "Initializing venv" << std::endl;
    int state = std::system("python3 -m venv .venv");
    if (state != 0) { 
        throw std::system_error(ECANCELED, std::generic_category(),
                                "\'python3 -m venv .venv\' failed");
    };
  
    // Generate requirements.txt
    if (req_exists() != true) {
        std::ofstream req_file {"requirements.txt"};
        if (req_file.is_open())
            req_file.close();
    }

    return state;
};

int run (char* argv[]) {
    std::cerr << "Running with PPVENV\n" << std::endl;
    std::string command {".venv/bin/python "};
    std::string script_name {argv[2]};
    command += script_name;

    int state = std::system(command.c_str());
    if (state != 0) {
        throw std::system_error(ECANCELED, std::generic_category(),
                                "'" + command + "' failed");
    };    
    
    return 0;
};

int add_module (char* argv[]) {
    std::cerr << "Attempting to import module" << std::endl;

    try {
        if (req_exists() != false) {
            std::ofstream req_file {"requirements.txt"};
            
            if (req_file.is_open()) {
                std::string mod_in = argv[2];
                req_file << mod_in << "\n";
                req_file.close();
            }
        } else {
            std::cerr << "requirements.txt not found" << std::endl;
        }
 
    } catch (...) {
        // resolve later : 08.07.2025         
    }

    return 0;
};

int sync () {
    std::cerr << "Syncing with requirements.txt" << std::endl;
    
    if (req_exists() != true) {
        throw std::system_error(ENOENT, std::generic_category(),
                                "'requirements.txt' was not found");
    } else {
        return std::system(".venv/bin/pip install -r requirements.txt");
    }

};

bool req_exists() {
    for (auto const& entry : fs::directory_iterator(fs::current_path())) {
        // std::cerr << entry.path().filename() << std::endl;
        if (entry.path().filename().string() == "requirements.txt") {
            return true;
        }
    }    

    return false;
};

};
