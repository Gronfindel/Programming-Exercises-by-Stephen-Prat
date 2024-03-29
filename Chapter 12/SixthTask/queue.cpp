#include "queue.h"
#include <cstdlib> 

//Методы класса Queue
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;    // или nullptr
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != NULL)   //пока очередь не пуста
    {
        temp = front;       //сохранение адреса начального элемента
        front = front->next;//переустановка указателя на следующий элемент
        delete temp;        //удаление предыдущего начального элемента
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

//Добавление элемента в очередь
bool Queue::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node;  //создание узла
//при неудачном выполнении операции new генерирует исключение std::bad_alloc
    add->item = item;       //занесение указателя на узлы 
    add->next = NULL;       //или nullptr;
    items++;
    if (front == NULL)      //если очередь пуста,
        front = add;        //элемент помещается в начало
    else
        rear->next = add;   //иначе он помещается в конец
    rear = add;             //указатель конца указывает на новый узел
    return true;
}

//Помещение элемента front в переменную item и его удаление из очереди
bool Queue::dequeue(Item & item)
{
    if (front == NULL)
        return false;
    item = front->item;     //в item заночится первый элемент из очереди
    items--;
    Node * temp = front;    //сохранение местоположения первого элемента
    front = front->next;    //сдвиг указателя начала на следующий елемент
    delete temp;            //удаление предыдущего элемента
    if (items == 0)
        rear = NULL;
    return true;
}

// Метод класса customer

//При появлении клиента фиксируется момент его прбытия, а время
//обслуживания выбирается случайным образом из диапазона 1-3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when; 
}