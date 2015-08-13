#include "client.h"
#include "ace/Get_Opt.h"
#include "map"
#include "string"

class OptParserImpl : public OptParser
{
public:
    OptParserImpl();
    virtual ~OptParserImpl();
    bool parse(int argc, const char *argv[], map<string, string> &optRes);
public:
    ACE_Get_Opt &_optps;
};
