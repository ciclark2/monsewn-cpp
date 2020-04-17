#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    try {
        po::options_description desc{"Options"};
        desc.add_options()
            ("help,h", "print usage")
            ;

        po::variables_map vm;
        po::store(parse_command_line(argc, argv, desc), vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }

    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}