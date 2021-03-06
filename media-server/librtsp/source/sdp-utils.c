#include "sdp-utils.h"
#include <stdlib.h>
#include <string.h>

#if defined(OS_WINDOWS)
	#define strcasecmp	_stricmp
#endif

struct sdp_attr_value_t
{
	int value;
	const char* name;
};

static struct sdp_attr_value_t s_setups[] = {
	{ SDP_A_SETUP_ACTPASS,	"actpass"},
	{ SDP_A_SETUP_PASSIVE,	"passive"},
	{ SDP_A_SETUP_ACTIVE,	"active"},
	{ SDP_A_SETUP_HOLDCONN, "holdconn"},
};

static struct sdp_attr_value_t s_protos[] = {
	{ SDP_M_PROTO_RTP_AVP,				"RTP/AVP"},
	{ SDP_M_PROTO_RTP_AVPF,				"RTP/AVPF"},
	{ SDP_M_PROTO_RTP_SAVP,				"RTP/SAVP"},
	{ SDP_M_PROTO_RTP_SAVPF,			"RTP/SAVPF"},
	{ SDP_M_PROTO_RTP_AVP_TCP,			"TCP/RTP/AVP"},
	{ SDP_M_PROTO_RTP_AVPF_TCP,			"TCP/RTP/AVPF"},
	{ SDP_M_PROTO_RTP_SAVP_TCP,			"TCP/RTP/SAVP"},
	{ SDP_M_PROTO_RTP_SAVPF_TCP,		"TCP/RTP/SAVPF"},
	{ SDP_M_PROTO_RTP_SAVP_DTLS_TCP,	"TCP/DTLS/RTP/SAVP"},
	{ SDP_M_PROTO_RTP_SAVPF_DTLS_TCP,	"TCP/DTLS/RTP/SAVPF"},
	{ SDP_M_PROTO_RTP_AVP_TCP_TLS,		"TCP/TLS/RTP/AVP"},
	{ SDP_M_PROTO_RTP_AVPF_TCP_TLS,		"TCP/TLS/RTP/AVPF"},
	{ SDP_M_PROTO_RTP_SAVP_TLS,			"UDP/TLS/RTP/SAVP"},
	{ SDP_M_PROTO_RTP_SAVPF_TLS,		"UDP/TLS/RTP/SAVPF"},
	{ SDP_M_PROTO_RTP_SAVP_TLS_DCCP,	"DCCP/TLS/RTP/SAVP"},
	{ SDP_M_PROTO_RTP_SAVPF_TLS_DCCP,	"DCCP/TLS/RTP/SAVPF"},

	{ SDP_M_PROTO_RAW,					"raw"},
	{ SDP_M_PROTO_UDP,					"udp"},
	{ SDP_M_PROTO_SCTP_DTLS,			"UDP/DTLS/SCTP"},
	{ SDP_M_PROTO_SCTP_DTLS_TCP,		"TCP/DTLS/SCTP"},

	// other
	{ SDP_M_PROTO_RTP_AVP,				"RTP/AVP/UDP"},
	{ SDP_M_PROTO_RTP_AVP_TCP,			"RTP/TCP/AVP"},
	{ SDP_M_PROTO_RTP_AVP_TCP,			"RTP/AVP/TCP"},
};

static int sdp_util_find_name(const struct sdp_attr_value_t* attrs, int count, const char* name)
{
	int i;
	for (i = 0; i < count; i++)
	{
		if (name && 0 == strcasecmp(name, attrs[i].name))
			return i;
	}
	return -1;
}

static int sdp_util_find_value(const struct sdp_attr_value_t* attrs, int count, int value)
{
	int i;
	for (i = 0; i < count; i++)
	{
		if (value == attrs[i].value)
			return i;
	}
	return -1;
}

#define SDP_UTIL_FROM(attr, none) \
	int sdp_util_##attr##_from(const char* s) \
	{ \
		int r; \
		r = sdp_util_find_name(s_##attr##s, sizeof(s_##attr##s) / sizeof(s_##attr##s[0]), s); \
		return r ? s_##attr##s[r].value : none; \
	}

#define SDP_UTIL_TO(attr) \
	const char* sdp_util_##attr##_to(int v) \
	{ \
		int r; \
		r = sdp_util_find_value(s_##attr##s, sizeof(s_##attr##s) / sizeof(s_##attr##s[0]), v); \
		return r ? s_##attr##s[r].name : ""; \
	}

SDP_UTIL_FROM(setup, SDP_A_SETUP_NONE)
SDP_UTIL_TO(setup)

SDP_UTIL_FROM(proto, SDP_M_PROTO_UKNOWN)
SDP_UTIL_TO(proto)
