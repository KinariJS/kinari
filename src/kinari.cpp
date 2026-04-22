#include <kinari.hpp>

namespace kinari {
    void init_global(JSContext *ctx, JS::Handle<JSObject*> global);

    Kinari::Kinari(JSContext *ctx)
    {
        this->ctx = ctx;
    }

    void Kinari::populate_global(const JS::Handle<JSObject*> global) const
    {
        init_global(this->ctx, global);
    }
}