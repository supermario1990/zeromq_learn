// zeromq_learn.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "zmq.h"

int main()
{
	void *context = zmq_ctx_new();

	//��ͻ��˽������׽���
	void *responder = zmq_socket(context, ZMQ_REP);
	zmq_bind(responder, "tcp://*:5555");

	while (1)
	{
		zmq_msg_t request;

	}
    return 0;
}

