#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 2048
#define NUM_AGE_GROUPS 21
#define LEFT_WIDTH 5 

char *labels[] = {
    "0- 4", "5- 9", "10-14", "15-19", "20-24", "25-29", "30-34", "35-39", 
    "40-44", "45-49", "50-54", "55-59", "60-64", "65-69", "70-74", "75-79", 
    "80-84", "85-89", "90-94", "95-99", "100+"
};

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE];
    int male_data[NUM_AGE_GROUPS] = {0};
    int female_data[NUM_AGE_GROUPS] = {0};
    int male_found = 0;
    int female_found = 0;
    int i, j;

    if (argc != 2) {
        fprintf(stderr, "usage: %s prefecture\n", argv[0]);
        exit(1);
    }

    if ((fp = fopen("09-a-07.csv", "r")) == NULL) {
        fprintf(stderr, "Cannot open file: 09-a-07.csv\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        char city[16] = {};
        if (sscanf(line, "%15[^,\n]", city) != 1) {
            continue;
        }

        if (strcmp(city, argv[1]) == 0) {
            char *p = line;
            
            p += strcspn(p, ",");
            if (*p == ',') p++;

            char gender = *p;
            
            p += strcspn(p, ",");
            if (*p == ',') p++;

            int *target_array;
            if (gender == 'M') {
                target_array = male_data;
                male_found = 1;
            } else if (gender == 'F') {
                target_array = female_data;
                female_found = 1;
            } else {
                continue;
            }

            for (i = 0; i < NUM_AGE_GROUPS; i++) {
                char *endptr;
                long val = strtol(p, &endptr, 10);
                target_array[i] = (int)val;
                
                p = endptr;
                while (*p != '\0' && *p != ',') {
                    p++;
                }
                if (*p == ',') p++;
            }
        }
    }

    fclose(fp);

    if (!male_found || !female_found) {
        printf("unknown pref (%s)\n", argv[1]);
        return 0;
    }
    
    for (i = NUM_AGE_GROUPS - 1; i >= 0; i--) {
        int m_stars = male_data[i] / 10000;
        int f_stars = female_data[i] / 10000;

        int spaces = LEFT_WIDTH - m_stars;
        if (spaces < 0) spaces = 0;

        for (j = 0; j < spaces; j++) putchar(' ');
        for (j = 0; j < m_stars; j++) putchar('*');

        printf(" %5s ", labels[i]);

        for (j = 0; j < f_stars; j++) putchar('*');
        
        putchar('\n');
    }

    return 0;
}