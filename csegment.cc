#include <node.h>
#include <v8.h>
#include <stdlib.h>
#include <string.h>
#include "ICTCLAS50.h"

using namespace v8;
using namespace node;
	
typedef struct segment_task {
	Persistent<Function> cb;
	char *rst;
	char content[1];
} segment_task;

Handle<Value> doSegmentAsync(const Arguments& args);
static void doSegment(eio_req *req);
static int doSegmentAfter(eio_req *req);

Handle<Value> doSegmentAsync(const Arguments& args) {
	HandleScope scope;

	const char *usage = "usage: doWork(content, cb)";
	if (args.Length() != 2) {
		return ThrowException(Exception::Error(String::New(usage)));
	}

	String::Utf8Value content(args[0]);
	Local<Function> cb = Local<Function>::Cast(args[1]);

	segment_task *task = (segment_task *)malloc(sizeof(segment_task) + content.length() + 1);
	memset(task, 0, sizeof(segment_task) + content.length() + 1);
	task->cb = Persistent<Function>::New(cb);
	strncpy(task->content, *content, content.length());
	
	eio_custom(doSegment, EIO_PRI_DEFAULT, doSegmentAfter, task);
	ev_ref(EV_DEFAULT_UC);
	return Undefined();
}

static void doSegment(eio_req *req) {
	if(!ICTCLAS_Init()) {
		return;
	}
	ICTCLAS_SetPOSmap(2);

	segment_task *task = (segment_task *)req->data;
	unsigned int nLen = strlen(task->content);

	char* sRst = (char *)malloc(nLen * 6);
	memset(sRst, 0, nLen * 6);
	int nRstLen = 0;

	nRstLen = ICTCLAS_ParagraphProcess(task->content, nLen, sRst, CODE_TYPE_UNKNOWN, 1);
	task->rst = sRst;

	ICTCLAS_Exit();
}

static int doSegmentAfter(eio_req *req) {
	HandleScope scope;

	ev_unref(EV_DEFAULT_UC);
	segment_task *task = (segment_task *)req->data;

	Local<Value> argv[1];
	argv[0] = String::New(task->rst);
	TryCatch try_catch;
	task->cb->Call(Context::GetCurrent()->Global(), 1, argv);
    if (try_catch.HasCaught()) {
    	FatalException(try_catch);
  	}
  	task->cb.Dispose();
  	free(task->rst);
  	free(task);
	return 0;
}

extern "C" {

void init(Handle<Object> target) {
	target->Set(String::NewSymbol("doWork"), 
		  	  FunctionTemplate::New(doSegmentAsync)->GetFunction());
}

NODE_MODULE(csegment, init)

}

