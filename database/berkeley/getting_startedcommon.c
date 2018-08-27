#include "getting_startedcommon.h"
void initialize_stockdbs(STOCK_DB* dbp){
    dbp->home_dir = DEFAULT_HOMEDIR;
    dbp->inventory_db_name = NULL;
    dbp->vendor_db_name = NULL;
    dbp->inventory_dbp = NULL;
    dbp->vendor_dbp = NULL;
}

