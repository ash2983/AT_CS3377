/*
Ashleigh Trout (ajt190001)

I followed Dr.Min's code from the video to make the callback function
and most of everything else. I mostly added a way to input a string and then
input that string (along with a command) into the exec() method. 

I also had issues accessing my history.db files, so I exported my history 
(as Ash_History.bak) from my desktop and have included that in my project. 
It should still open as a db file in the program below and/or open as a db file
in the SQLite Browser. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

typedef int (*sqlite3_callback)(
   void*,    /* Data provided in the 4th argument of sqlite3_exec() */
   int,      /* The number of columns in row */
   char**,   /* An array of strings representing fields in the row */
   char**    /* An array of strings representing column names */
); 

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   char url[100];
   const char* data = "\n";

   //Open database 
   rc = sqlite3_open("Ash_History.bak", &db);
   
   //check if error opening database 
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }

   
   //ask for url input
   printf("\n Input what keyword you would like to search your history for: \n");
   scanf("%s", url); 

   //create SQL statement to execute in SQLite
   char temp[500];
   strcpy(temp, "SELECT title, url, datetime(last_visit_time/1000000 - 11644473600, \'unixepoch\') AS last_visited, visit_count FROM urls WHERE url LIKE \'%");
   strcat(temp, url);
   strcat(temp, "%\'");
   printf("\n temp = %s \n", temp); 
   sql = temp; 

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
 //check if database executed correctly
 if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
 
   sqlite3_close(db);
   return 0;
}
