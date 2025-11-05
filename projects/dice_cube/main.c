#include <fcntl.h>
#include <stdio.h>

#include <stdlib.h>
#include <termios.h> // POSIX: Linux, macOS
#include <unistd.h>

// Кроссплатформенная функция чтения символа без эха и без Enter
int readch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt); // Сохраняем текущие настройки терминала
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // Отключаем canonical mode и эхо
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Применяем новые настройки
    ch = getchar();                          // Читаем один символ
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Восстанавливаем старые настройки
    return ch;
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(void) {
    printf("Press: \n    Enter - start game\n    Q/q or Esc - Exit\n");
    while (1) {
        int ch = readch();

        if (ch == '\n' || ch == '\r') { // Enter (Unix: \n, Windows: \r)
            clear_screen();
            printf("\nStart game!\n");
            break;
        } else if (ch == 'q' || ch == 'Q' || ch == 27) { // 27 = Esc
            printf("\nExit.\n");
            return 0;
        } else {
            printf("\nNo key (%d). again.\n", ch);
        }
    }

    printf("Добро пожаловать в игру!\n");
    // Здесь — логика вашей игры
    // srand(time(NULL));
    int random_num = 1 + rand() % (6 - 1 + 1); // [min, max]
    printf("Dice: %d\n", random_num);
    return 0;
}
