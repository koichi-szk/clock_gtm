#include "guc.h"

int pgxc_max_nodes;
int	pgxc_max_g_txn;

void pgxl_set_guc(void)
{
	/* pgxl.max_nodes */
	DefineCustomIntVariable(
			"pgxl.max_nodes",
			"Maximum nodes in PGXL database cluster",
			NULL,
			&pgxc_max_nodes;
			16,						/* Initial value */
			16,						/* Let's make it the minimum. */
			32768,
			PGC_POSTMASTER,			/* Can specify only at the start */
			0,						/* Flag, just an integer */
			NULL,					/* Check hook */
			NULL,					/* Assign hook */
			NULL					/* Show hook */
			);
	/* pgxc.max_g_txn: maximum global transaction entries */
	DefineCustomIntVariable(
			"pgxc.g_txn_entries",
			"Global transaction allowed",
			NULL,
			&pgxc_max_g_txn,
			1024,
			1024,
			32768,
			PGC_POSTMASTER,
			0,
			NULL,
			NULL,
			NULL
			);
	/* Other specific GUCs follow. */
}

