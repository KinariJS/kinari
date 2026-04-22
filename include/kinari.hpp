#pragma once

#include <jsapi.h>

namespace kinari {
    class Kinari {
        JSContext *ctx;
    public:
        explicit Kinari(JSContext *ctx);
        void populate_global(JS::Handle<JSObject*> global) const;
    };
}
