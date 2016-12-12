
#include <node.h>

#include "audio/audio.h"

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;


void Method1(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();
	args.GetReturnValue().Set(Number::New(isolate, getOutputDevicesCount()));
}

void Method2(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();
	args.GetReturnValue().Set(Number::New(isolate, getInputDevicesCount()));
}

void init(Local<Object> exports) {
	NODE_SET_METHOD(exports, "getOutputDevicesCount", Method1);
	NODE_SET_METHOD(exports, "getInputDevicesCount", Method2);
}

NODE_MODULE(windowsaudio, init)

}