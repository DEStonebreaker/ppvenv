#include "utils.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "{USAGE} ./ppvenv [CMD] [PYTHON_FILE *OPTIONAL*]" << std::endl;
    };

    try {
        std::string cmd {argv[1]};
        
        if (cmd == "init") {
            if (!std::filesystem::exists(".venv"))
                ppvenv::init();
        } else if (cmd == "run") {
            ppvenv::run(argv);
        } else if (cmd == "add") {
            ppvenv::add_module(argv);
        } else if (cmd == "sync") {
            ppvenv::sync(); 
        } else if (cmd == "cmd") {
			ppvenv::cmd(argv);
		}
        
        else {
            std::cerr << "err" << std::endl;
            return 0;
        }
    }
    catch (const std::system_error& ex) {
        std::cerr << ex.what() << std::endl;
    }
    
    return 0;
}
