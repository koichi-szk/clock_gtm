#include <sys/time.h>
#include "c.h"

struct pgxl_g_txn
{
	int				root_node;
	TransactionId	root_xid;
	TransactionId	local_xid;
	struct timeval	finish_clock;
};

typedef struct pgxl_g_txn pgxl_g_txn;
