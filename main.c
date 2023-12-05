#include <stdio.h>

void displayQuestion(char question[], char optionA[], char optionB[], char optionC[], char optionD[]) {
    printf("\n%s\n", question);
    printf("A. %s\n", optionA);
    printf("B. %s\n", optionB);
    printf("C. %s\n", optionC);
    printf("D. %s\n", optionD);
}

char getUserAnswer() {
    char answer;
    printf("Your answer (A/B/C/D): ");

    while (1) {
        answer = getchar();
        if (answer == '\n' || answer == EOF) {
            continue;  // Skip newline characters
        } else {
            break;  // Exit the loop when a valid character is entered
        }
    }

    return answer;
}

void provideHint(char hint[]) {
    printf("Hint: %s\n", hint);
}

void checkAnswer(char correctAnswer, char userAnswer, int *score, char hint[]) {
        // Convert both correctAnswer and userAnswer to uppercase
       
       if (toupper(userAnswer) == toupper(correctAnswer)) {
            printf("Correct!\n");
            (*score)++;
    } else {
        provideHint(hint);
        // Allow the user to try again after the hint
        char userAnswerAfterHint;
        printf("Your answer (A/B/C/D): ");
        while (1) {
            userAnswerAfterHint = getchar();
            if (userAnswerAfterHint == '\n' || userAnswerAfterHint == EOF) {
                continue;  // Skip newline characters
            } else {
                break;  // Exit the loop when a valid character is entered
            }
        }
        if (toupper(userAnswerAfterHint) == toupper(correctAnswer)) {
            printf("Correct after the hint!\n");
            (*score)++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", correctAnswer);
        }
    }
}

int main() {
    char userName[50] = ""; // Initialize with an empty string

    printf("\nRegister your name: ");
    scanf("%s", userName);

    printf("\n -------------------------  Welcome %s to Quiz Game -------------------------\n", userName);

    printf("\n Press Y  to start the game!\n");
    printf("\n Press X  to exit the game!\t");

    char choice;
    scanf(" %c", &choice);

    switch (choice) {
        case 'Y':
        case 'y':
            printf("\nStarting the quiz for %s:\n", userName);

            // Quiz questions, options, answers, and hints
            char questions[5][100] = {
                "What is the largest ocean on Earth?",
                "What is the powerhouse of the cell?",
                "Which country is known as the \"Land of the Rising Sun\"?",
                "Who wrote 'Romeo and Juliet'?",
                "What is the chemical symbol for gold?"
            };

            char options[5][4][50] = {
                {"Atlantic Ocean", "Indian Ocean", "Southern Ocean", "Pacific Ocean"}, 
                {"Nucleus", "Mitochondria", "Endoplasmic reticulum", "Golgi apparatus"},
                {"China","South Korea","Japan","Thailand"},
                {"William Shakespeare", "Jane Austen", "Charles Dickens", "Mark Twain"},
                {"Au", "Ag", "Fe", "Cu"}
            };

            char correctAnswers[5] = {'D', 'B', 'C', 'A', 'A'};

            char hints[5][150] = {
                "It stretches from the Arctic Ocean in the north to the Antarctic in the south.",
                "It produces energy in the form of ATP.",
                "This country's flag features a red circle.",
                "The playwright is widely regarded as one of the greatest writers in the English language.",
                "It comes from the Latin word aurum."
            };

            int score = 0;

            for (int i = 0; i < 5; i++) {
                displayQuestion(questions[i], options[i][0], options[i][1], options[i][2], options[i][3]);
                char userAnswer = getUserAnswer();
                checkAnswer(correctAnswers[i], userAnswer, &score, hints[i]);
            }

            printf("\n%s, your final score: %d out of 5\n", userName, score);
            break;

        case 'X':
        case 'x':
            printf("\nExiting the program. Goodbye, %s!\n", userName);
            break;

        default:
            printf("\nInvalid choice. Exiting the program. Goodbye, %s!\n", userName);
    }

    return 0;
}
