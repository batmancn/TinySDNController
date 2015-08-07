/**
*   Use C++11 standard and library.
*/
#include "json.h"
#include "Sender.h"

using namespace std;

const string & usage(void)
{
    return "Usage: JsonClient -h host -p port";
}

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
