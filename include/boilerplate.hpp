#pragma once

#include <jsapi.h>

namespace boilerplate {
    extern const JSClassOps DefaultGlobalClassOps;

    JSObject* CreateGlobal(JSContext* cx);

    void ReportAndClearException(JSContext* cx);

    bool RunExample(bool (*task)(JSContext*), bool initSelfHosting = true);

}