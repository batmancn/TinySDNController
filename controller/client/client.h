/**
*   All my interfaces
*/
#include "map"
#include "string"

class OptParser {
public:
    OptParser();
    virtual ~OptParser();

    bool Parse(int argc, const char *argv[],
                std::map<std::string, std::string> &optRes);
};
