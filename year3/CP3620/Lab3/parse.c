#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *query = getenv("QUERY_STRING");
    char delim[] ="=&";
    char *ptr = strtok(query, delim);
    char *values[5];
    char *variables[5];
    printf("Content-type: text/html\n\n");
    int i = 0;
    int z = 0;
    int isValue = 0;
    while(ptr != NULL){
        if(isValue == 0){
            variables[i] = ptr;
            isValue = 1;
            i++;
        }
        else if(isValue == 1){
            values[z] = ptr;
            isValue = 0;
            z++;
        }
        // printf("'%s'\n", ptr);
        ptr = strtok(NULL, delim);
    }
    printf("<html>"
          "<table>"
          "<tr><th>\"%s\"</th><th>\"%s\"</th>/</tr>"
          "<tr><td>\"%s\"</th><td>\"%s\"</td>/</tr>"
          "<tr><td>\"%s\"</th><td>\"%s\"</td>/</tr>"
         "<tr><td>\"%s\"</th><td>\"%s\"</td>/</tr>"
          "</table>"
          "</html>\r\n", "Variables","Values", 
          variables[0],
          values[0],
          variables[1],
          values[1],
          variables[2],
          values[2]
          );
    
    return 0;
}