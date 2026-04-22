#include <jsapi.h>

namespace kinari {
    bool print(JSContext* ctx, unsigned argc, JS::Value* vp);

    JSObject *create_global(JSContext *ctx)
    {
        const JS::RealmOptions options;

        static JSClass KinariGlobalClass = {
            "KinariGlobal", JSCLASS_GLOBAL_FLAGS,
            &JS::DefaultGlobalClassOps
        };

        return JS_NewGlobalObject(ctx, &KinariGlobalClass,
            nullptr, JS::FireOnNewGlobalHook, options);
    }

    void init_global(JSContext *ctx, const JS::Handle<JSObject*> global)
    {
        if (!JS_DefineFunction(ctx, global, "print", print, 0, 0))
            abort();
    }
}