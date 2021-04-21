#ifndef _http_websocket_internal_h_
#define _http_websocket_internal_h_

#include "http-websocket.h"
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct websocket_header_t
{
	unsigned int fin : 1; // final fragment
	unsigned int rsv : 3; // reserved
	unsigned int opcode : 4;
	unsigned int mask : 1;
	uint8_t masking_key[4]; // 32-bits masking-key

	uint64_t len; // payload length
};

int websocket_header_read(struct websocket_header_t* header, const uint8_t* data, size_t bytes);
int websocket_header_write(const struct websocket_header_t* header, uint8_t* data, size_t bytes);


struct websocket_parser_t
{
	struct websocket_header_t header;
	int header_masking_key_off;
	int header_opcode; // save for continuation frame
	int state;

	uint8_t h[14];
	uint8_t* ptr;
	unsigned int len;
	unsigned int capacity;
	unsigned int max_capacity;
};

typedef int (*websocket_parser_handler)(void* param, int opcode, const void* data, size_t bytes, int flags);

/// @param[in] data raw data, don't with const, maybe use as unmasking
int websocket_parser_input(struct websocket_parser_t* parser, uint8_t* data, size_t bytes, websocket_parser_handler handler, void* param);

int websocket_parser_destroy(struct websocket_parser_t* parser);


struct http_client_t;
struct http_session_t;
struct http_websocket_t
{
	// union
	struct http_client_t* client;
	struct http_session_t* session;

	struct websocket_parser_t parser;

	struct websocket_handler_t handler;
	void* param;
};

int http_session_websocket_send_vec(struct http_websocket_t* ws, int opcode, const struct http_vec_t* vec, int num);

#ifdef __cplusplus
}
#endif
#endif /* !_http_websocket_internal_h_ */
