#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

// 1. Структура для представления пользователя
struct User {
    char username[50];  // Имя пользователя
    char password[50];  // Пароль
    double balance;     // Баланс
};

// 2. Структура для представления игры казино
struct Game {
    char gameName[50];      // Название игры
    double minBet;          // Минимальная ставка
    double maxBet;          // Максимальная ставка
    double payoutMultiplier; // Множитель выигрыша
};

// 3. Структура для представления транзакции
struct Transaction {
    char username[50];      // Имя пользователя
    char transactionType[20]; // Тип транзакции (например, "депозит" или "ставка")
    double amount;          // Сумма транзакции
    char date[20];          // Дата транзакции
};

// 4. Структура для представления игрового раунда
struct GameRound {
    struct User* player;    // Игрок
    struct Game* game;      // Игра
    double betAmount;       // Сумма ставки
    int result;             // 0 - проигрыш, 1 - выигрыш
};

// 5. Структура для представления лобби игры
struct GameLobby {
    struct Game* availableGames[10]; // Массив доступных игр
    int gameCount;                   // Количество доступных игр
};

// 6. Структура для представления джекпота
struct Jackpot {
    double currentAmount;    // Текущая сумма джекпота
    int isWon;               // Флаг выигрыша: 1 - джекпот сорван, 0 - нет
};

// 7. Структура для представления бонусов
struct Bonus {
    char bonusType[30];      // Тип бонуса (например, "фриспины", "кэшбэк")
    double bonusAmount;      // Сумма бонуса
    int isActive;            // Флаг активности бонуса: 1 - активен, 0 - не активен
};

// 8. Структура для представления истории ставок
struct BetHistory {
    struct User* player;     // Игрок
    struct Game* game;       // Игра
    double betAmount;        // Сумма ставки
    int result;              // 0 - проигрыш, 1 - выигрыш
    char date[20];           // Дата ставки
};

// Функции для работы со структурами

// Функция для отображения информации о пользователе
void displayUserInfo(struct User* user) {
    printf("Имя пользователя: %s\n", user->username);
    printf("Баланс: %.2f рублей\n", user->balance); printf("\n");
}

// Функция для отображения информации об игре
void displayGameInfo(struct Game* game) {
    printf("Игра: %s\n", game->gameName);
    printf("Минимальная ставка: %.2f рублей\n", game->minBet);
    printf("Максимальная ставка: %.2f рублей\n", game->maxBet);
    printf("Множитель выигрыша: %.2fx\n", game->payoutMultiplier); printf("\n");
}

// Функция для отображения транзакции
void displayTransactionInfo(struct Transaction* transaction) {
    printf("Пользователь: %s\n", transaction->username);
    printf("Тип транзакции: %s\n", transaction->transactionType);
    printf("Сумма: %.2f рублей\n", transaction->amount);
    printf("Дата: %s\n", transaction->date); printf("\n");
}

// Функция для отображения результата игрового раунда
void displayGameRoundResult(struct GameRound* round) {
    printf("Игрок: %s\n", round->player->username);
    printf("Игра: %s\n", round->game->gameName);
    printf("Ставка: %.2f рублей\n", round->betAmount);

    // Используем if вместо тернарного оператора
    if (round->result) {
        printf("Результат: Выигрыш\n");
    }
    else {
        printf("Результат: Проигрыш\n");
    }printf("\n");
}

// Функция для отображения информации о джекпоте
void displayJackpot(struct Jackpot* jackpot) {
    printf("Текущая сумма джекпота: %.2f рублей\n", jackpot->currentAmount);

    // Используем if вместо тернарного оператора
    if (jackpot->isWon) {
        printf("Состояние джекпота: Сорван\n");
    }
    else {
        printf("Состояние джекпота: Не сорван\n");
    }printf("\n");
}

// Функция для отображения информации о бонусе
void displayBonusInfo(struct Bonus* bonus) {
    printf("Тип бонуса: %s\n", bonus->bonusType);
    printf("Сумма бонуса: %.2f рублей\n", bonus->bonusAmount);

    // Используем if вместо тернарного оператора
    if (bonus->isActive) {
        printf("Статус бонуса: Активен\n");
    }
    else {
        printf("Статус бонуса: Не активен\n");
    }printf("\n");
}

// Основная функция программы
int main() {
    setlocale(2, "rus");
    // Пример данных для тестирования
    struct User user = { "Игрок1", "password123", 100.0 };
    struct Game game = { "Однорукий бандит", 5.0, 100.0, 2.5 };
    struct Transaction transaction = { "Игрок1", "Депозит", 50.0, "2024-10-18" };
    struct GameRound round = { &user, &game, 10.0, 1 };
    struct Jackpot jackpot = { 5000.0, 0 };
    struct Bonus bonus = { "Фриспины", 20.0, 1 };

    // Отображение данных
    displayUserInfo(&user);
    displayGameInfo(&game);
    displayTransactionInfo(&transaction);
    displayGameRoundResult(&round);
    displayJackpot(&jackpot);
    displayBonusInfo(&bonus);

    return 0;
}
