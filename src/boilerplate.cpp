#include <jsapi.h>

#include <js/Initialization.h>
#include <js/Exception.h>

#include <boilerplate.hpp>

// Helper to read current exception and dump to stderr.
//
// NOTE: This must be called with a JSAutoRealm (or equivalent) on the stack.
void boilerplate::ReportAndClearException(JSContext* cx) {
  JS::ExceptionStack stack(cx);
  if (!JS::StealPendingExceptionStack(cx, &stack)) {
    fprintf(stderr, "Uncatchable exception thrown, out of memory or something");
    exit(1);
  }

  JS::ErrorReportBuilder report(cx);
  if (!report.init(cx, stack, JS::ErrorReportBuilder::WithSideEffects)) {
    fprintf(stderr, "Couldn't build error report");
    exit(1);
  }

  JS::PrintError(stderr, report, false);
}