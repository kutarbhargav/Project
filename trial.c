#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6

void display_word(const char word[], const int guessed[]) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i])
            printf("%c ", word[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

int main() {
    int num;
    char word[50];  // <-- declare once so it is usable everywhere

    printf("Enter your choice: ");
    scanf("%d", &num);

    switch (num) {
        case 1: strcpy(word, "Toronto"); break;
        case 2: strcpy(word, "New York"); break;
        case 3: strcpy(word, "London"); break;
        case 4: strcpy(word, "Manchester"); break;
        case 5: strcpy(word, "Chicago"); break;
        case 6: strcpy(word, "Manhattan"); break;
        case 7: strcpy(word, "Zurich"); break;
        case 8: strcpy(word, "Tokyo"); break;
        case 9: strcpy(word, "Berlin"); break;
        case 10: strcpy(word, "Moscow"); break;
        default: strcpy(word, "error"); break;
    }

    // Convert word to lowercase for matching
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    int length = strlen(word);
    int guessed[50] = {0};
    int num_tries = 0;
    int correct_guesses = 0;
    char guess;

    printf("Welcome to Hangman!\n");

    while (num_tries < MAX_TRIES && correct_guesses < length) {
        int already_found = 0;
        int found = 0;

        printf("\nWord: ");
        display_word(word, guessed);
        printf("Tries left: %d\n", MAX_TRIES - num_tries);
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        for (int i = 0; i < length; i++) {
            if (word[i] == guess && guessed[i]) {
                already_found = 1;
                break;
            }
        }

        if (already_found) {
            printf("You already guessed that letter!\n");
            continue;
        }

        for (int i = 0; i < length; i++) {
            if (word[i] == guess) {
                guessed[i] = 1;
                found = 1;
                correct_guesses++;
            }
        }

        if (!found) {
            num_tries++;
            printf("Wrong guess!\n");
        } else {
            printf("Good guess!\n");
        }
    }

    if (correct_guesses == length) {
        printf("\nCongratulations! You guessed the word: %s\n", word);
    } else {
        printf("\nGame over! The word was: %s\n", word);
    }

    return 0;
}
