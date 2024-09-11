#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    uid_t uid = getuid();   // Get the real user ID
    uid_t euid = geteuid(); // Get the effective user ID

    printf("Current UID: %d\n", uid);
    printf("Current EUID: %d\n", euid);
    setuid(euid);

    // Execute the greetings.sh script as user with euid - root
    printf("Executing greetings.sh...\n");
    execl("/bin/bash", "bash", "./greetings.sh", NULL);

    // If execl fails, print an error message
    perror("execl failed");
    return 1;
}