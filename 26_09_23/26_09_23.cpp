#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>

using namespace std;

class Queue
{
    // Очередь
    int* Wait;
    // Максимальный размер очереди
    int MaxQueueLength;
    // Текущий размер очереди
    int QueueLength;

public:
    // Конструктор
    Queue(int m);

    //Деструктор
    ~Queue();

    // Добавление элемента
    void Add(int c);

    // Извлечение элемента
    int GetLast();

    // Очистка очереди
    void Clear();

    // Проверка существования элементов в очереди
    bool IsEmpty();

    // Проверка на переполнение очереди
    bool IsFull();

    // Количество элементов в очереди
    int GetCount();

    //демонстрация очереди
    void Show();

    void Move();
};

void Queue::Show() {
    cout << "\n-------------------------------------\n";
    //демонстрация очереди
    for (int i = 0; i < QueueLength; i++) {
        cout << Wait[i] << " ";
    }
    cout << "\n-------------------------------------\n";
}

Queue::~Queue()
{
    //удаление очереди
    delete[]Wait;
}

Queue::Queue(int m)
{
    //получаем размер
    MaxQueueLength = m;
    //создаем очередь
    Wait = new int[MaxQueueLength];
    // Изначально очередь пуста
    QueueLength = 0;
}

void Queue::Clear()
{
    // Эффективная "очистка" очереди 
    QueueLength = 0;
}

bool Queue::IsEmpty()
{
    // Пуст?
    return QueueLength == 0;
}

bool Queue::IsFull()
{
    // Полон?
    return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
    // Количество присутствующих в стеке элементов
    return QueueLength;
}

void Queue::Add(int c)
{
    // Если в очереди есть свободное место, то увеличиваем количество
    // значений и вставляем новый элемент
    if (!IsFull())
        Wait[QueueLength++] = c;
}

int Queue::GetLast()
    {
        return Wait[0];
    }

void Queue::Move()
{
    // Если в очереди есть элементы, то возвращаем тот, 
    // который вошел первым и сдвигаем очередь	
    if (!IsEmpty()) {
        //запомнить первый
        int temp = Wait[0];

        //сдвинуть все элементы
        for (int i = 1; i < QueueLength; i++)
            Wait[i - 1] = Wait[i];

        //уменьшить количество
        //Wait[QueueLength - 1] = temp;

        //вернуть первый(нулевой)
        Wait[QueueLength - 1] = temp;
        //return 1;
    }

    else // Если в стеке элементов нет
    {
        return;
    }
}


void main()
{
    srand(time(0));

    Queue QU1(5);

    for (int i = 0; i < 3; i++) {
        QU1.Add(i);
    };
    Queue QU2(5);

    for (int i = 0; i < 3; i++) {
        QU2.Add(i);
    };
    Queue QU3(5);

    for (int i = 0; i < 3; i++) {
        QU3.Add(i);
    };

    for (int i = 0; i < rand() % 20 + 10; i++)
    {
        QU1.Move();
        cout << "[" << QU1.GetLast() << "]" << endl;
        cout << "[" << QU2.GetLast() << "]" << endl;
        cout << "[" << QU3.GetLast() << "]" << endl;;
        Sleep(50);
        system("CLS");
    }
    for (int i = 0; i < rand() % 20 + 10; i++)
    {
        QU2.Move();
        cout << "[" << QU1.GetLast() << "]" << endl;
        cout << "[" << QU2.GetLast() << "]" << endl;
        cout << "[" << QU3.GetLast() << "]" << endl;;
        Sleep(50);
        system("CLS");
    }
    for (int i = 0; i < rand() % 20 + 10; i++)
    {
        QU3.Move();
        cout << "[" << QU1.GetLast() << "]" << endl;
        cout << "[" << QU2.GetLast() << "]" << endl;
        cout << "[" << QU3.GetLast() << "]" << endl;;
        Sleep(50);
        system("CLS");
    }

    cout << "[" << QU1.GetLast() << "]" << endl;
    cout << "[" << QU2.GetLast() << "]" << endl;
    cout << "[" << QU3.GetLast() << "]" << endl;

    if (QU1.GetLast() == QU2.GetLast() && QU1.GetLast() == QU3.GetLast())
    {
        cout << "You win!";
    }
    else
    {
        cout << "You lose!";
    }
}
