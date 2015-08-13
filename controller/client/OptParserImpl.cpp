#include "OptParser.h"
#include "iostream"

OptParser::OptParser() :
        _optps(new ACE_Get_Opt())
{
    cout << "construct OptParser." << endl;
}

virtual ~OptParser::Optparser()
{
    safe_delete(&_optps);
}


