#include <torrent/Downloader.h>
#include <imgui/Window.h>

#include <boost/program_options.hpp>

#include <iostream>
#include <string>

namespace po = boost::program_options;

int main(int argc, char* argv[]) try
{
    std::string magnet_uri;

    po::options_description op_desc{"Allowed options"};
    op_desc.add_options()
        ("help,h", 
            "print usage")
        ;

    po::options_description pos_desc{"Positional arguments"};
    pos_desc.add_options()
        ("magnet-uri", 
            po::value(&magnet_uri), 
            "magnet URI")
        ;

    po::options_description all_args("All arguments");
    all_args.add(op_desc).add(pos_desc);

    po::positional_options_description pos_args;
    pos_args.add("magnet-uri", 1);

    po::variables_map vm;
    po::store(
        po::command_line_parser(argc, argv)
        .options(all_args)
        .positional(pos_args)
        .run(),
        vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << all_args << std::endl;
        return 0;
    }

    //Monsewn::Downloader downloader(magnet_uri);
    return Window();

    return 0;

} catch (const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
    return 1;
}