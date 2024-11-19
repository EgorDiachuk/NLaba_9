#include <iostream>
#include <locale>
#include <windows.h>
using namespace std;

class Queue {
private:
    int* arr;       // масив для зберігання елементів черги
    int capacity;   // максимальна кількість елементів
    int front;      // індекс початку черги
    int rear;       // індекс кінця черги
    int size;       // поточна кількість елементів

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == capacity) {
            cout << "Черга заповнена!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Черга порожня!" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    double calculateAverage() const {
        if (isEmpty()) {
            cout << "Черга порожня! Немає даних для обчислення." << endl;
            return 0.0;
        }
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[(front + i) % capacity];
        }
        return sum / size;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ukr");

    int capacity;
    cout << "Введіть розмір черги: ";
    cin >> capacity;

    Queue q(capacity);

    // Введення елементів черги з клавіатури
    for (int i = 0; i < capacity; i++) {
        int value;
        cout << "Введіть елемент черги #" << (i + 1) << ": ";
        cin >> value;
        q.enqueue(value);
    }

    cout << "Середнє арифметичне елементів черги: " << q.calculateAverage() << endl;

    // Видалення одного елемента
    q.dequeue();

    cout << "Середнє арифметичне після видалення елемента: " << q.calculateAverage() << endl;

    return 0;
}
