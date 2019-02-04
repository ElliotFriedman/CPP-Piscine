#ifndef NETWORKINFO_HPP
#define NETWORKINFO_HPP

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>
#include <net/route.h>
#include <net/if.h>

class   NetworkInfo: public IMonitorModule {
    public:
        NetworkInfo(void);
        ~NetworkInfo(void);
        std::string data(void);
        void        getNetworkInfo(void);
        long        getInBytes(void);
        long        getOutBytes(void);
        long        getInPackets(void);
        long        getOutPackets(void);
    private:
        long    _in_bytes;
        long    _out_bytes;
        long    _in_packets;
        long    _out_packets;
};

#endif