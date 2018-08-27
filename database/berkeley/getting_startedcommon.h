#include<db.h>
typedef struct{
    DB* inventory_dbp;
    DB* vendor_dbp;
    char* home_dir;
    char* inventory_db_name;
    char* vendor_db_name;
} STOCK_DB;
int database_setup(STOCK_DB*, const char*, FILE*);
int database_close(STOCK_DB*);
void initialize_stockdbs(STOCK_DB*);
int open_database(DB**, const char*, const char*, FILE*);
void set_db_filenames(STOCK_DB*);