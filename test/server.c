#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void handle_signal(int sig, siginfo_t *info, void *context) {
    static char *message = NULL;
    static size_t message_size = 0;
    static size_t byte_count = 0;
    static int bit_count = 0;
    static char current_char = 0;

    if (sig == SIGUSR1) {
        current_char |= (1 << bit_count);
    }

    bit_count++;

    if (bit_count == 8) {
        if (byte_count >= message_size) {
            message_size += 1024;
            message = realloc(message, message_size);
            if (!message) {
                perror("Failed to allocate memory");
                exit(EXIT_FAILURE);
            }
        }

        message[byte_count++] = current_char;

        if (current_char == '\0') {
            printf("Received message: %s\n", message);
            free(message);
            message = NULL;
            message_size = 0;
            byte_count = 0;
        }

        current_char = 0;
        bit_count = 0;
    }

    kill(info->si_pid, SIGUSR2);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("Server PID: %d\n", getpid());

    while (1) {
        pause();
    }

    return 0;
}

