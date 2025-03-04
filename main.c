#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main() {
    char input[1024];
    char command[1024];
    int running = 1;

    char correct_username[] = "user";
    char correct_password[] = "password123";

    char username[1024];
    char password[1024];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    if (strcmp(username, correct_username) != 0 || strcmp(password, correct_password) != 0) {
        printf("Invalid username or password. Exiting...\n");
        return 1;
    }

    printf("Login successful! Welcome to the shell.\n");

    char hostname[] = "user-hostname";
    char cwd[1024];

    setenv("TZ", "America/Toronto", 1);
    tzset();

    printf("Welcome to %s's shell! Current time: ", hostname);

    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    printf("%02d-%02d-%04d %02d:%02d:%02d\n",
           local_time->tm_mon + 1, local_time->tm_mday, local_time->tm_year + 1900,
           local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
    printf("Type 'exit' to quit the shell.\n");

    while (running) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s@%s:%s$ ", username, hostname, cwd);
        }

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        sscanf(input, "%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the shell...\n");
            running = 0;
        }

        else if (strcmp(command, "echo") == 0) {
            printf("%s\n", input + 5);
        }

        else if (strcmp(command, "ls") == 0) {
            printf("file1.txt  file2.txt  file3.txt  file4.txt  file5.txt\n");
        }

        else if (strcmp(command, "pwd") == 0) {
            printf("/home/user/desktop\n");
        }

        else if (strcmp(command, "cd") == 0) {
            printf("Changed directory to /home/user/desktop\n");
        }

        else if (strcmp(command, "touch") == 0) {
            printf("File 'newfile.txt' created.\n");
        }

        else if (strcmp(command, "cat") == 0) {
            printf("This is the content of a text file.\n");
        }

        else if (strcmp(command, "rm") == 0) {
            printf("File 'oldfile.txt' removed.\n");
        }

        else if (strcmp(command, "cp") == 0) {
            printf("File 'source.txt' copied to 'destination.txt'.\n");
        }

        else if (strcmp(command, "mv") == 0) {
            printf("File 'file1.txt' moved to /home/user/desktop.\n");
        }

        else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("echo, cd, ls, pwd, touch, cat, rm, cp, mv, exit, help, clear\n");
            printf("date, whoami, hostname, ps, top, kill, env, mkdir, rmdir, chmod, chown\n");
            printf("ln, df, du, uptime, reboot, ip, free, find, history\n");
        }

        else if (strcmp(command, "clear") == 0) {
            printf("\033[H\033[J");
        }

        else if (strcmp(command, "date") == 0) {
            now = time(NULL);
            local_time = localtime(&now);
            printf("Current date and time: %02d-%02d-%04d %02d:%02d:%02d\n",
                   local_time->tm_mon + 1, local_time->tm_mday, local_time->tm_year + 1900,
                   local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
        }

        else if (strcmp(command, "whoami") == 0) {
            printf("Current user: %s\n", username);
        }

        else if (strcmp(command, "hostname") == 0) {
            printf("hostname: %s\n", hostname);
        }

        else if (strcmp(command, "ps") == 0) {
            printf("PID   COMMAND\n");
            printf("1234  process1\n");
            printf("2345  process2\n");
        }

        else if (strcmp(command, "top") == 0) {
            printf("Top processes:\n");
            printf("PID   USER   %%CPU   %%MEM\n");
            printf("1234  user   5.0    1.2\n");
            printf("2345  user   3.5    2.1\n");
        }

        else if (strcmp(command, "kill") == 0) {
            printf("Process '1234' killed.\n");
        }

        else if (strcmp(command, "env") == 0) {
            printf("PATH=/usr/bin:/bin\n");
            printf("HOME=/home/user\n");
        }

        else if (strcmp(command, "mkdir") == 0) {
            printf("Directory 'newdir' created.\n");
        }

        else if (strcmp(command, "rmdir") == 0) {
            printf("Directory 'olddir' removed.\n");
        }

        else if (strcmp(command, "chmod") == 0) {
            printf("Permissions for 'file.txt' changed.\n");
        }

        else if (strcmp(command, "chown") == 0) {
            printf("Ownership of 'file.txt' changed to '%s'.\n", username);
        }

        else if (strcmp(command, "ln") == 0) {
            printf("Hard link 'linkfile.txt' created for 'file.txt'.\n");
        }

        else if (strcmp(command, "df") == 0) {
            printf("Filesystem    1K-blocks  Used    Available  Use%%  Mounted on\n");
            printf("/dev/sda1     1024000    500000  524000     50%%   /home\n");
        }

        else if (strcmp(command, "du") == 0) {
            printf("4.0K    /home/user/desktop\n");
        }

        else if (strcmp(command, "uptime") == 0) {
            printf("Uptime: 5 days, 3 hours, 12 minutes\n");
        }

        else if (strcmp(command, "reboot") == 0) {
            printf("System is rebooting...\n");
            running = 0;
        }

        else if (strcmp(command, "ip") == 0) {
            printf("IP Address: 192.168.1.1\n");
        }

        else if (strcmp(command, "free") == 0) {
            printf("Mem:   8192 MB total, 4096 MB used, 4096 MB free\n");
        }

        else if (strcmp(command, "find") == 0) {
            printf("Searching for 'testfile' in current directory...\n");
            printf("Found: /home/user/desktop/testfile.txt\n");
        }

        else if (strcmp(command, "history") == 0) {
            printf("Command history:\n");
            printf("1. ls\n");
            printf("2. pwd\n");
            printf("3. echo Hello\n");
            printf("4. touch newfile.txt\n");
            printf("5. cd /home/user/desktop\n");
        }

        else {
            printf("Command not found: %s\n", command);
        }
    }

    return 0;
}
