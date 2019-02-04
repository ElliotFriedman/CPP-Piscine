#include "../inc/NetworkInfo.hpp"

NetworkInfo::NetworkInfo(void): IMonitorModule()
                            , _in_bytes(0)
                            , _out_bytes(0)
                            , _in_packets(0)
                            , _out_packets(0) {}

NetworkInfo::~NetworkInfo(void) {}

NetworkInfo::NetworkInfo( NetworkInfo &obj) :  _previousIdleTicks(0), _previousTotalTicks(0) {}

NetworkInfo& NetworkInfo::operator=(NetworkInfo &obj)
{
	return *this;
}

/*
** https://stackoverflow.com/questions/1126790/how-to-get-network-adapter-stats-in-linux-mac-osx
** The state is described using a ``Management Information Base'' (MIB)
** style name, listed in name, which is a namelen length array of integers.
** {network subsystem, info type, protocol, addr family, operation}
*/

static int     mib[6] = {CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0};

void    NetworkInfo::getNetworkInfo(void) {
    size_t              len;
    char                *next;
    long                in_packets = 0, out_packets = 0, in_bytes = 0, out_bytes = 0;
    struct if_msghdr    *ifm;
    struct if_msghdr2   *ifm2;

    sysctl(mib, 6, NULL, &len, NULL, 0);
    char                buf[len];
    sysctl(mib, 6, buf, &len, NULL, 0);
    next = buf;
    while (next < buf + len) {
        ifm = (struct if_msghdr*)next;
        next += ifm->ifm_msglen;
        if (ifm->ifm_type == RTM_IFINFO2) {
            ifm2 = (struct if_msghdr2*)ifm;
            if (ifm2->ifm_data.ifi_type != 18) {
                in_packets += ifm2->ifm_data.ifi_ipackets;
                out_packets += ifm2->ifm_data.ifi_opackets;
                in_bytes += ifm2->ifm_data.ifi_ibytes;
                out_bytes += ifm2->ifm_data.ifi_obytes;
            }
        }
    }
    _in_bytes = in_bytes;
    _out_bytes = out_bytes;
    _in_packets = in_packets;
    _out_packets = out_packets;
}

std::string NetworkInfo::data(void) {

    getNetworkInfo();
    return std::string(std::to_string(_in_bytes)
                + " bytes in, "
                + std::to_string(_out_bytes)
                + " bytes out, "
                + std::to_string(_in_packets)
                + " packets in, "
                + std::to_string(_out_packets)
                + " packets out.");
}

long    NetworkInfo::getInBytes(void) {
    return _in_bytes;
}

long    NetworkInfo::getOutBytes(void) {
    return _out_bytes;
}

long    NetworkInfo::getInPackets(void) {
    return _in_packets;
}

long    NetworkInfo::getOutPackets(void) {
    return _out_packets;
}
