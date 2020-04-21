#pragma once

#include <libtorrent/torrent_status.hpp>

namespace Monsewn {

class Downloader
{
public:
    explicit Downloader(const std::string& magnet_uri);

private:
    // return the name of a torrent status enum
    static const std::string StateString(const lt::torrent_status::state_t s);
};

} // Monsewn