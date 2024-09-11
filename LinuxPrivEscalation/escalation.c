#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
* If executable of that program has suid bit set
* we can use that to exploit privilages escalation
* Any binary that has SUID bit set and calling another program from the PATH environment variable is a clear indication of privilege escalation. 
* All you can do is simply prepend your path variable with the path where your malicious executable exists and it will give you a root shell.
*/
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