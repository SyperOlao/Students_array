#include "List.h"

void List::add(InfoAboutUniversity info)
{

    Node* temp = new Node;               //Выделение памяти под новый элемент структуры
    temp->info = info;                   //Записываем значение в структуру
    temp->next = nullptr;                //Указываем, что изначально по следующему адресу пусто
   

    if (head != nullptr)                 //Если список не пуст
    {
        temp->prev = tail;               //Указываем адрес на предыдущий элемент в соотв. поле
        tail->next = temp;               //Указываем адрес следующего за хвостом элемента
        tail = temp;                     //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->prev = nullptr;            //Предыдущий элемент указывает в пустоту
        head = tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
    }

    size++;
}

void List::delete_elem(int index)
{
    if (index == 0) {
        head = head->next;
        size--;
        return;
    }
    Node* temp = head;
    while (index !=1)
    {
        if (temp == nullptr) {
            return;
        }
        temp = temp->next;
        index--;
    }
    if(temp->next->next == nullptr){
        temp->next = nullptr;
    }
    else {
        temp->next = temp->next->next;
    }
    size--;
}

InfoAboutUniversity List::get(int index)
{
    Node* temp = head;
    while (index != 0) {
        if (temp == nullptr) {
            InfoAboutUniversity NULLinfo;
            return NULLinfo;
        }
        temp = temp->next;
        index--;
    }
    if (temp == nullptr) {
        InfoAboutUniversity NULLinfo;
        return NULLinfo;
    }
    else {
        return temp->info;
    }

}
