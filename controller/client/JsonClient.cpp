/**
*   Use C++11 standard and library.
*/
#include "json/json.h"
#include "memory"
#include "string"
#include "cassert"
#include "fstream"
#include "iostream"

/**
*   My cpp files.
*/
#include "OptParserImpl.h"

using namespace std;

/**
*   C-style function
*/
const string usage(void)
{
    return "Usage: JsonClient -h host -p port -f [PATH]file";
}

int
main(int argc, const char *argv[])
{
    try
    {
        /**
        *   At last, we have to construct OptParserImpl myself, instead of itself.
        *   Although this is not good idea, but if you use reference as Policy,
        *   you have to new this Policy by hand, here or some where.
        */
        // parse option
        static string empty("");
        map<string, string> optRes;
        auto_ptr<OptParser> optps (new OptParserImpl(argc, argv));
        optps->parse(argc, argv, optRes);
        assert((optRes.find("file") != optRes.end()) &&
                (optRes.find("file")->second.compare(empty) == 0));

        // open file
        ifstream ifs;
        ifs.open(optRes.find("file")->second.c_str(), ifstream::in);
        assert(ifs.is_open());

        // read into json
        Json::Reader reader;
        Json::Value root;
        if (!reader.parse(ifs, root, false)) {
            cout << "Parse Error." << endl;
            return -1;
        }

        cout << "Parse Result : " << root.asString() << endl;
    }
    catch (OptException &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Fatal Error." << endl;
    }
}

/*
int main(int argc, const char * argv[])
{
    static const string doc("./test.json");
    static const int argcCount = 2;
    auto_ptr<Json::Value> jv (new Json::Value);
    auto_ptr<Json::Reader> jr (new Json::Reader);
    auto_ptr<ACE::ACE_Option> ao (new ACE::ACE_Option);

    // check input
    if (argc != argcCount || !ao->parse(argv[1]) || !ao->parse(argv[2])) {
        cout << usage() << endl;
    }

    // no exception throw
    if (jr->parse(doc, *jv)) {
        auto_ptr<Json::Value> jv2 (new
            Json::Value("{\"Comment\":\"Add by JsonClient.\"}"));
        jv->append(*jv2);
        auto_ptr<Sender> s (new Sender());
        s->open(argv[1], argv[2]);
    } else {
        cout << "Parse Error!" << endl;
    }
}
*/
