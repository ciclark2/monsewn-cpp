#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    try
    {
        po::options_description desc{"Options"};
        desc.add_options()
            ("help,h", "Help");

        po::variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.count("help")) 
        {
            std::cout << desc << std::endl;
            return 0;
        }
    }
    catch (const po::error& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}