#include <stdio.h>
#include <unistd.h>

int main() {
    // Affiche le PID du processus actuel
    printf("PID du processus actuel : %d\n", getpid());
    
    // Affiche le PID du processus parent
    printf("PID du processus parent : %d\n", getppid());
    
    return 0;
}