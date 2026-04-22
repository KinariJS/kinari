#include <jsapi.h>
#include <jsfriendapi.h>

#include "kinari.hpp"
#include "js/Initialization.h"

static JSContext *init();
static void deinit(JSContext *ctx);

namespace kinari {
    JSObject *create_global(JSContext *ctx);
}

int main(int argc, const char* argv[])
{
    JSContext *ctx = init();
    {
        const JS::Rooted<JSObject*> global(ctx, kinari::create_global(ctx));
        if (!global) return 1;

        JSAutoRealm realm(ctx, global);

        const kinari::Kinari kinari(ctx);
        kinari.populate_global(global);
    }
    deinit(ctx);
    return 0;
}

static JSContext *init()
{
    JS_Init();

    JSContext *ctx = JS_NewContext(JS::DefaultHeapMaxBytes);
    if (ctx == nullptr) return nullptr;

    if (!js::UseInternalJobQueues(ctx)) return nullptr;
    if (!JS::InitSelfHostedCode(ctx)) return nullptr;

    return ctx;
}

static void deinit(JSContext *ctx)
{
    JS_DestroyContext(ctx);
    JS_ShutDown();
}