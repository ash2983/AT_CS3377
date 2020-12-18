 #include <iostream>
 #include <sqlite3.h>
 #include <sqltext.h>
 #include <string>
 
using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   cout << stderr << (const char*)data << endl;

   for(i = 0; i<argc; i++){
      cout << azColName[i] << argv[i] ? argv[i] : "NULL" << endl;
   }

   cout << endl;
   return 0;
}

int main(){
  string url;
  sqlite3 *db;
  int rc;
  char *sql;
  char *zErrMsg = 0;

  //open History file
  rc = sqlit3_open("History.db", &db);

  if(rc){
    cout << "Cannot open database \n" << sqlite3_errmsg(db) << endl;
  //else continue the program
  }else{
  //enter URL input
  cout << "Type in the URL you want to search your history for:" << endl;
  cin << url;

  sql = "SELECT datetime(last_visit_time/1000000-11644473600, "unixepoch") as last_visited, url, title, visit_count FROM urls WHEN url = " + url;
  rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);

  if(rc != SQLITE_OK){
    cout << stderr << "SQL error: " << endl << zErrMsg << endl;
    sqlite3_free(zErrMsg);
  }else{
    cout << stdout << "Operation done successfully!" << endl;
  }
  }

  //close database
  sqlite3_close(db);
  return 0;
}
