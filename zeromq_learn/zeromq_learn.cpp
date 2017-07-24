// zeromq_learn.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "zmq.h"

int main()
{
	void *context = zmq_ctx_new();

	//与客户端交流的套接字
	void *responder = zmq_socket(context, ZMQ_REP);
	zmq_bind(responder, "tcp://*:5555");

	while (1)
	{
		zmq_msg_t request;

	}
    return 0;
}

