#ifndef _TLISTP_H_
#define _TLISTP_H_
#include <iostream>
#include "TList.h"
#include "TNodeP.h"
#include "TNode.h"
#include "exceptions.h"

template<>
class TList<int, float> {
private:
    TNode<int, float>* pFirst;
    TNode<int, float>* pCurrent;
    TNode<int, float>* pNext;
    TNode<int, float>* pPrev;
public:
    TList();
    TList(const TList&);
    TList(const TNode<int, float>*);
    ~TList();
    void Reset();
    void Next();
    bool End() const;
    TNode<int, float>* GetpFirst() const;
    TNode<int, float>* GetpCurrent() const;
    TNode<int, float>* Search(int);
    void PushBegin(int, float);
    void PushEnd(int, float);
    void PushBefore(int, int, float);
    void PushAfter(int, int, float);
    void Remove(int);
    void Sort();
    bool operator==(const TList&) const;
    bool operator!=(const TList&) const;
    friend ostream& operator<<(ostream&, TList<int, float>&);
};


TList<int, float>::TList() {
    pFirst = NULL;
    pNext = NULL;
    pPrev = NULL;
    pCurrent = NULL;
};

TList<int, float>::TList(const TList& list) {
    pNext = NULL;
    pPrev = NULL;
    pCurrent = NULL;

    if (!list.pFirst) {
        pFirst = NULL;
    }
    else {
        pFirst = new TNode<int, float>(*list.pFirst);//создали копию указател§ на первый        
        pCurrent = pFirst;
        TNode<int, float>* tmp = list.pFirst;//в тмп кладем указатель на первый от того, который мы копируем

        while (tmp->pNext) {//создаем цепочку из tmp
            tmp = tmp->pNext;
            pCurrent->pNext = new TNode<int, float>(*tmp);//параллельно с этим создаем цепочку из tmp
            pPrev = pCurrent;//в предыдущий кладем прошлый текущий
            pCurrent = pCurrent->pNext;//текущий теперь смещаетс§ дальше
            pNext = NULL;//следующего у нас уже нет
        }
        pPrev = NULL;//когда закончили с цепочкой предыдущего у нас нет(мы сейчас на первом как бы)
        pCurrent = pFirst;//текцщий-первый
        pNext = pFirst->pNext;
    }
};

TList<int, float>::TList(const TNode<int, float>* first) {
    pNext = pPrev = pCurrent = NULL;
    if (!first)
        pFirst = NULL;
    else{
        TNode<int, float>* node = new TNode<int, float>(*first);
        pFirst = node;
        TNode<int, float>* tmp = first->pNext;
        TNode<int, float>* prev = pFirst;
        while (tmp)
        {
            TNode<int, float>* n = new TNode<int, float>(*tmp);
            prev->pNext = n;
            prev = n;
            tmp = tmp->pNext;
        }
        pCurrent = pFirst;
        pNext = pCurrent->pNext;
    }
};

TList<int, float>::~TList() {
    this->Reset();
    while (!this->End()) {
        this->Next();
        delete pPrev;
    }
    delete pCurrent;
    pFirst = NULL;
    pNext = NULL;
    pPrev = NULL;
    pCurrent = NULL;
};


void TList<int, float>::Reset() {//переводит текущий  на первый
    pPrev = NULL;
    pCurrent = pFirst;
    if (pFirst) {
        pNext = pCurrent->pNext;
    }
    else {
        pNext = NULL;
    }
};


void TList<int, float>::Next() {//сдвиг вправо
    pPrev = pCurrent;
    pCurrent = pNext;
    if (pCurrent) {
        pNext = pCurrent->pNext;
    }
    else {
        pNext = NULL;
    }
};

bool TList<int, float>::End() const {
    return (pCurrent == NULL);
};

TNode<int, float>* TList<int, float>::GetpFirst() const {
    return pFirst;
};

TNode<int, float>* TList<int, float>::GetpCurrent() const{
    return pCurrent;
};


TNode<int, float>* TList<int, float>::Search(int key_value) {
    TNode<int, float>* tmppCurrent = pCurrent;
    TNode<int, float>* tmppNext = pNext;
    TNode<int, float>* tmppPrev = pPrev;
    this->Reset();

    while (!this->End() && (key_value != pCurrent->key)) {
        this->Next();
    }
    TNode<int, float>* node = this->pCurrent;
    pCurrent = tmppCurrent;
    pNext = tmppNext;
    pPrev = tmppPrev;
    return node;
};

void TList<int, float>::PushBegin(int key_value, float data_value) {
    if (pFirst == nullptr) {
        pFirst = new TNode<int, float>(key_value, data_value);
        pCurrent = pFirst;
        return;
    };
    TNode<int, float>* node = new TNode<int, float>(key_value, data_value, pFirst);
    node->pNext = pFirst;
    if (pCurrent == pFirst)
        pPrev = node;
    pFirst = node;
};

void TList<int, float>::PushEnd(int key_value, float data_value) {
    TNode<int, float>* tmppCurrent = pCurrent;
    TNode<int, float>* tmppNext = pNext;
    TNode<int, float>* tmppPrev = pPrev;
    this->Reset();
    while (pNext)
        this->Next();
    TNode<int, float>* node = new TNode<int, float>(key_value, data_value);//в конец добавили

    if (!pFirst) {
        pFirst = node;
    }
    else {
        pCurrent->pNext = node;
    }

    if (tmppCurrent == pCurrent) {//если у нас всего один элемент
        pNext = node;
    }
    else {
        pNext = tmppNext;
    }
    pCurrent = tmppCurrent;
    pPrev = tmppPrev;
};

void TList<int, float>::PushBefore(int nkey, int key_value, float data_value) {//вставка до
    TNode<int, float>* tmppCurrent = pCurrent;
    TNode<int, float>* tmppNext = pNext;
    TNode<int, float>* tmppPrev = pPrev;
    this->Reset();

    if ((this->End()) || (pFirst->key == nkey)) {
        this->PushBegin(key_value, data_value);
        pCurrent = pFirst;
        return;
    }

    TNode<int, float>* node_search = Search(nkey);
    if (!node_search) {
        throw Exception("¬аш ключ не найден:(");
        return;
    }

    while (pCurrent != node_search)
        this->Next();

    TNode<int, float>* node = new TNode<int, float>(key_value, data_value, pCurrent);
    pPrev->pNext = node;

    if (tmppCurrent == pPrev) {
        pNext = node;
    }
    else {
        pNext = tmppNext;
    }

    if (tmppCurrent == pCurrent) {
        pPrev = node;
    }
    else {
        pPrev = tmppPrev;
    }

    pCurrent = tmppCurrent;
};

void TList<int, float>::PushAfter(int nkey, int key_value, float data_value) {
    TNode<int, float>* tmppCurrent = pCurrent;
    TNode<int, float>* tmppNext = pNext;
    TNode<int, float>* tmppPrev = pPrev;
    this->Reset();
    TNode<int, float>* node_search = Search(nkey);

    if (!node_search) {
        throw Exception("ђаш ключ не найден:(");
        return;
    }

    while (pCurrent != node_search)
        this->Next();

    TNode<int, float>* node = new TNode<int, float>(key_value, data_value, pNext);
    pCurrent->pNext = node;

    if (tmppCurrent == pCurrent) {
        pNext = node;
    }
    else {
        pNext = tmppNext;
    }
    if (tmppCurrent == pNext) {
        pPrev = node;
    }
    else {
        pPrev = tmppPrev;
    }

    pCurrent = tmppCurrent;
};

void TList<int, float>::Remove(int key_value) {//удаление
    if (!pFirst)
        throw Exception("Чписок пуст:(");

    if (pFirst->key == key_value) {
        if (pCurrent == pFirst) {//если первый
            pCurrent = pNext;
            if (pNext) {
                pNext = pNext->pNext;
            }
            else {
                pNext = NULL;
            }
            delete pFirst;
            pFirst = pCurrent;
            return;
        }

        if (pCurrent == pFirst->pNext) {//если второй
            pPrev = NULL;
            delete pFirst;
            pFirst = pCurrent;
            return;
        }

        delete pFirst;
        return;
    }

    TNode<int, float>* tmppCurrent = pCurrent;
    TNode<int, float>* tmppPrev = pPrev;
    TNode<int, float>* tmppNext = pNext;
    this->Reset();
    TNode<int, float>* node_search = Search(key_value);

    if (!node_search) {
        throw Exception(" люч не найден:(");
        return;
    }

    while (pCurrent != node_search)
        this->Next();

    pPrev->pNext = pNext;

    if (tmppCurrent == pCurrent) {
        pCurrent = tmppNext;
        pNext = pCurrent->pNext;
        delete node_search;
        return;
    }

    if (tmppCurrent == pPrev) {
        pCurrent = pPrev;
        pPrev = tmppPrev;
        pNext = pCurrent->pNext;
        delete node_search;
        return;
    }

    if (tmppCurrent == pNext) {
        pCurrent = pNext;
        pNext = pCurrent->pNext;
        delete node_search;
        return;
    }

    pNext = tmppCurrent->pNext;
    pCurrent = tmppCurrent;
    delete node_search;
    return;
};

void TList<int, float>::Sort(){
    TNode<int, float>* last = new TNode<int, float>;
    TNode<int, float>* tmpfirst = new TNode<int, float>;
    bool first = true;

    while (this->pFirst){
        this->Reset();
        TNode<int, float>* min = new TNode<int, float>;
        min = pFirst;

        while (!this->End()){
            if (pCurrent->key < min->key)
                min = pCurrent;
            this->Next();
        }

        this->Reset();
        while ((this->pCurrent != min) && (!this->End()))
            this->Next();

        if (pCurrent == pFirst)//если первый
            pFirst = pCurrent = pNext;
        else if (pNext == NULL)//если последний
            pPrev->pNext = NULL;//вместо текущего стал нул
        else
            pPrev->pNext = pNext;//склеиваем то, что по бокам от pCurrent
        this->Reset();

        if (first){//заполнили начало
            tmpfirst = min;
            first = false;
        }
        else { 
            last->pNext = min;//приделываем к концу списка
        }
        last = min;//и последний у нас и оказываетс¤ минимум
    }

    last->pNext = NULL;
    pFirst = tmpfirst;
    pPrev = NULL;
    pCurrent = pFirst;
    pNext = pCurrent->pNext;
};


bool TList<int, float>::operator==(const TList& _l) const{
    TNode<int, float>* tmp1 = this->pFirst;
    TNode<int, float>* tmp2 = _l.pFirst;
    while (tmp1 && tmp2 && (*tmp1 == *tmp2)){
        tmp1 = tmp1->pNext;
        tmp2 = tmp2->pNext;
    }
    return (!(tmp1 || tmp2));
};

bool TList<int, float>::operator!=(const TList& _l) const{
    return (!(*this == _l));
};

ostream& operator<<(ostream& _out, TList<int, float>& f_list) {
    if (!f_list.pFirst) {
        _out << "—писок пуст:(" << endl;
        return _out;;
    }

    TNode<int, float>* tmppCurrent = f_list.pCurrent;
    TNode<int, float>* tmppNext = f_list.pNext;
    TNode<int, float>* tmppPrev = f_list.pPrev;
    f_list.Reset();

    while (!f_list.End()) {
        _out << f_list.pCurrent->key << ", ";
        f_list.Next();
    }
    f_list.pCurrent = tmppCurrent;
    f_list.pNext = tmppNext;
    f_list.pPrev = tmppPrev;
    return _out;
};

#endif