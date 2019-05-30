#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    FILE *fp; int hits;

    char digits[20];
    
    fp = fopen("/usr/lib/cgi-bin/counter.file", "r");
    fscanf(fp, "%d", &hits); hits++;
    fclose(fp);
    
    fp = fopen("/usr/lib/cgi-bin/counter.file", "w");
    fprintf(fp, "%d", hits);
    sprintf(digits, "%d", hits);
    fclose(fp);
    for(int i = 0; i < strlen(digits); i++){
    // printf("Content-type: text/html\r\n\r\n");
    printf("<html>"
          "<img src=\"%s%c%s\">\r\n"
          "</html>\r\n", "/odo", digits[i], ".gif");
	}
    return 0;
}