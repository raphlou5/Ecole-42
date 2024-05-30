#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

volatile sig_atomic_t ack_received = 0;
volatile sig_atomic_t message_received = 0;

void handle_ack(int sig) {
    ack_received = 1;
}

void handle_message_received(int sig) {
    message_received = 1;
}

void send_bit(int pid, int bit_val) {
    if (bit_val) {
        kill(pid, SIGUSR1);
    } else {
        kill(pid, SIGUSR2);
    }
}

void send_string(int pid, const char *message) {
    for (size_t i = 0; i <= strlen(message); i++) { // include the null terminator
        char c = message[i];
        for (int bit = 0; bit < 8; bit++) {
            int bit_val = (c >> bit) & 1;
            ack_received = 0;

            // Retry mechanism
            int retries = 0;
            while (!ack_received) {
                send_bit(pid, bit_val);
                usleep(600); // Increased delay for ack

                retries++;
                if (retries > 5) { // if no ACK received after 5 retries
                    fprintf(stderr, "Error: No ACK received after multiple retries\n");
                    return;
                }
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

    struct sigaction sa_ack, sa_msg;
    sa_ack.sa_handler = handle_ack;
    sigemptyset(&sa_ack.sa_mask);
    sa_ack.sa_flags = 0;
    sigaction(SIGUSR2, &sa_ack, NULL);

    sa_msg.sa_handler = handle_message_received;
    sigemptyset(&sa_msg.sa_mask);
    sa_msg.sa_flags = 0;
    sigaction(SIGUSR1, &sa_msg, NULL);

    send_string(pid, message);

    while (!message_received) {
        pause(); // Wait for the message received signal
    }

    printf("Message successfully received by the server\n");

    return 0;
}

