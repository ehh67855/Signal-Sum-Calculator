#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>

/*Handels the signals from kill and returns which kill was called before terminatin the program */
void handel_signal(int);
/* Prints the output for the beggining of the program */
void setUp();
/* Restrics the program to 90 secnods. Inputs: signal number */
void alarm_handler(int signum);
double sum = 0; //Global sum
/*
    Proccesses stdin, and facilitates inputs and sum accordingly.
    Inputs: comman line args
    Outputs: Success status
*/
int main(int argc, char * argv[]) {
    setUp(); char input[80]; char * endPtr;
    if (isatty(0)) { //from terminal
        while(1) {
            scanf("%[^\n]%*c", input);
            double x = strtod(input,&endPtr);
            if (*endPtr == 0) { sum+=x; } else {
                printf("Error: please input a numeric value.\n");
            }
        }
    } else {
        while(1) { //from file redirection
            fscanf(stdin, "%s%*[^\n]", input);
            double x = strtod(input,&endPtr);
            if (fgetc(stdin) == EOF){
                sleep(60);
                printf("The sum is %f.\n", sum);
                printf("Program ended after sleeping for 60 seconds.\n");
                exit(0);
            }
            if (*endPtr == 0) {
                sum+=x;
            } else {
                printf("Error: please input a numeric value.\n");
            }
        }
    }
}

void handel_signal(int signum) {
    printf("The sum is %f.\n", sum);
    printf("Program ended by handling the signal from kill -%i %i.\n", signum, getpid());
    exit(0);
}

void setUp() {
    int pid = getpid();
    printf("Program started with pid = %i.\n", pid);
    signal(8, handel_signal);
    signal(10, handel_signal);
    signal(12, handel_signal);
    signal(SIGALRM,alarm_handler); // Register signal handler
    alarm(90);
    printf("Enter a list of doubles to sum,\n");
    printf("and to end the program,\n");
    printf("run one of the following Unix commands:\n");
    printf("  kill -8 %i\n", pid);
    printf("  kill -10 %i\n", pid);
    printf("  kill -12 %i\n", pid);
}

void alarm_handler(int signum) {
    printf("90 seconds have passed. Program is now terminating\n");
    exit(0);
}
