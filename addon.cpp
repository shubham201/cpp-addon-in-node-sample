#include <node.h>

using namespace v8;

// Function to calculate the sum of two numbers
void Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
    return;
  }
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Both arguments should be numbers").ToLocalChecked()));
    return;
  }
  double num1 = Local<Number>::Cast(args[0])->Value();
  double num2 = Local<Number>::Cast(args[1])->Value();
  double value = num1 + num2;
  args.GetReturnValue().Set(Number::New(isolate, value));
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "add", Add);
}

NODE_MODULE(addon, Initialize)
