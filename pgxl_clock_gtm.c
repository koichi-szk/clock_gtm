#include "c.h"

#include "pgxl_nodes.h"
#include "pgxl_gtxn.h"
#include "pgxl_guc.h"

pgxl_node_t	*pgxl_nodelist;
int pgxl_actual_nodes;

pgxl_gtxn_t *pgxl_gtxn_list;

void pgxl_allocagte_nodes(void)
{
	pgxl_nodelist = (pgxl_node *)malloc(sizeof(pgxl_node) * pgxl_max_nodes);
	if (pgxl_nodelist == NULL)
	{
		elog(PANIC, "No more memory available.   Allocating pgxc node list.");
		return;
	}
}

void pgxl_allocate_gtxn_entries(void)
{
	pgxl_gtxn_list = (pgxl_gtxn *)malloc(sizeof(pgxl_gtxn) * pgxl_max_g_txn);
	if (pgxl_nodelist == NULL)
	{
		elog(PANIC, "No more memory available.   Allocating pgxc global transaction list.");
		return;
	}
}


