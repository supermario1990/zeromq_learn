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
		zmq_msg_init(&request);
		zmq_msg_recv(&request, responder, 0);
		printf("Received Hello\n");
		zmq_msg_close(&request);

		//do something
		Sleep(1);

		zmq_msg_t reply;
		zmq_msg_init_size(&reply, 5);
		memcpy(zmq_msg_data(&reply), "world", 5);
		zmq_msg_send(&reply, responder, 0);
		zmq_msg_close(&reply);

	}
	zmq_close(responder);
	zmq_ctx_destroy(&context);
	return 0;
}

