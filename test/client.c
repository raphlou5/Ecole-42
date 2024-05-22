#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

volatile sig_atomic_t ack_received = 0;

void handle_ack(int sig) {
    ack_received = 1;
}

void send_string(int pid, const char *message) {
    for (size_t i = 0; i <= strlen(message); i++) { // include the null terminator
        char c = message[i];
        for (int bit = 0; bit < 8; bit++) {
            int bit_val = (c >> bit) & 1;
            if (bit_val) {
                kill(pid, SIGUSR1);
            } else {
                kill(pid, SIGUSR2);
            }
            ack_received = 0;
            while (!ack_received) {
                usleep(100); // wait for ack
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <PID> <message>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    const char *message = argv[2];

    struct sigaction sa;
    sa.sa_handler = handle_ack;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGUSR2, &sa, NULL);

    send_string(pid, message);

    return 0;
}

