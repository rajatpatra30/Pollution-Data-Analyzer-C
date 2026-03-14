#include<stdio.h>
int main() {
    int aqi[100];
    int n = 0,i;
    int choice;
    float avg,sum = 0;
    int max,min;
    int maxDay, minDay;
    FILE *fp;

    while(1) {
        printf("\n==== Pollution Data Analyzer ====\n");
        printf("1. Enter AQI Data\n");
        printf("2. Calculate Average AQI\n");
        printf("3. Show MAximum Aqi(with Day)\n");
        printf("4. Show Minimum AQI(with Day)\n");
        printf("5. Show Pollution Category\n");
        printf("6. Save AQI Report to File\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            printf("Enter number of days: ");
            scanf("%d", &n);

            if(n <= 0) {
                printf("Invalid number of days.\n");
                n = 0;
                break;
            }
            sum = 0;
            printf("Enter AQI values:\n");
            for(i = 0;i<n;i++) {
                printf("Day %d AQI: ",i+1);
                scanf("%d", &aqi[i]);
                sum += aqi[i];
            }
            break;
        case 2:
        if(n == 0) {
            printf("No data entered.\n");
            break;
        }
        avg = sum/n;
        printf("Average AQI = %.2f\n", avg);
        break;
        case 3:
        if(n == 0) {
            printf("No data entered.\n");
            break;
        }
        max = aqi[0];
        maxDay = 1;
        for(i=1; i < n;i++) {
            if(aqi[i] > max) {
                max = aqi[i];
                maxDay = i + 1;

            }
        }
        printf("Maximum AQI = %d on day %d\n",max,maxDay);
        break;
        case 4:
        if(n ==0) {
            printf("No data entered.\n");
            break;
        }
        min = aqi[0];
        minDay = 1;
        for(i=1;i < n;i++) {
            if(aqi[i] < min) {
                min =aqi[i];
                minDay =i + 1;
            }
        }
        printf("Minimum AQI = %d on Day %d\n",min,minDay);
        break;
        case 5:
        if(n == 0) {
            printf("No data entered.\n");
            break;
        }
        avg = sum/n;
        if(avg <= 50) {
            printf("Pollution Level: Good\n");
        }
        else if(avg <= 100) {
            printf("Pollution Level: Moderate\n");
        }
        else if(avg <= 200) {
            printf("Pollution Level: Unhealthy\n");
        }
        else if(avg <= 300) {
            printf("Pollution Level: Very Unhealthy\n");
        }
        else {
            printf("Pollution Level: Hazardous\n");
        }
        break;
        case 6:
        if(n == 0) {
            printf("No data to save.\n");
            break;
        }
        fp = fopen("aqi_report.txt", "w");
        if(fp == NULL) {
            printf("Error creating file.\n");
            break;
        }
        avg = sum/n;
        max = aqi[0];
        min = aqi[0];
        maxDay = 1;
        minDay = 1;
        for(i = 1; i < n;i++) {
            if(aqi[i] > max) {
                max = aqi[i];
                maxDay = i + 1;

        }
        if(aqi[i] < min) {
            min = aqi[i];
            minDay = i +1;
        }
        }
        fprintf(fp, "==== AQI REPORT ====\n");
        for(i =0;i <n;i++) {
            fprintf(fp, "Day %d AQI = %d\n",i+1,aqi[i]);
        }
        fprintf(fp,"\nAverage AQI = %.2f\n",avg);
        fprintf(fp, "Maximum AQI = %d(Day %d)\n",max,maxDay);
        fprintf(fp,"Minimum AQI = %d(Day %d)\n",min,minDay);
        if(avg <= 50) {
            fprintf(fp, "Pollution Level: Good\n");
        }
        else if(avg <= 100) {
            fprintf(fp, "Pollution Level: Moderate\n");
        }
        else if(avg <= 200) {
            fprintf(fp, "Pollution Level: Unhealthy\n");
        }
        else if(avg <= 300) {
            fprintf(fp, "Pollution Level: Very Unhealthy\n");
        }
        else {
            fprintf(fp, "Pollution Level: Hazardous\n");
        }
        fclose(fp);
        printf("AQI REport saved succesfully in aqi_report.txt\n");
        break;
        case 7:
        printf("Exiting Program...\n");
        return 0;

        default:
        printf("Invalid choice.\n");


        }


    }
}