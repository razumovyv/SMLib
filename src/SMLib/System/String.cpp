#include <SMLib/System/String.h>

namespace sml {
    namespace system {
        String::String() : value_("") {}
        String::String(const char* value) : value_(value) {}
        String::~String() {}
    }
}