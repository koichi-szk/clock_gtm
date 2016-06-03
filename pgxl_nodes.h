#include <sys/time.h>
#include "c.h"
#define PGXL_NODE_NAME_MAX 63
#define PGXL_CONNINFO_MAX 1023

struct pgxl_node
{
	int		nodeid;						/* 0 up_to pgxl.max_nodes. Now we assume coordinator
										   and datanode are unified. -1 siggests unused entry. */
	int		myseof;						/* Suggests if the node is myself. */
	char	nodename[PGXL_NODE_NAME_MAX+1];
	struct timeval	latest_valid_clock;	/* Latest valid clock value.  Reference beyond this value should
										   wait until this value is updated */
	struct timeval	earliest_ref_clock;	/* Earliest clock reference from this node.  Transactions whose
										   clock is earlier than this value is a candidate for cleanup */
	char	conninfo[PGXC_CONNINFO_MAX+1];
};

typedef struct pgxl_node pgxl_node;
