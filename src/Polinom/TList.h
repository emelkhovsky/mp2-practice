#ifndef _TLIST_H_
#define _TLIST_H_
#include <iostream>
#include "TNode.h"
#include "exceptions.h"

template<class TKey, class TData>
class TList {
private:
    TNode<TKey, TData>* pFirst;
    TNode<TKey, TData>* pCurrent;
    TNode<TKey, TData>* pNext;
    TNode<TKey, TData>* pPrev;
public:
    TList();
    TList(const TList&);
    TList(const TNode<TKey, TData>*);
    ~TList();
    void Reset();
    void Next();
    bool End() const;
    TNode<TKey, TData>* GetpFirst() const;
    TNode<TKey, TData>* Search(TKey);
    void PushBegin(TKey, TData*);
    void PushEnd(TKey, TData*);
    void PushBefore(TKey, TKey, TData*);
    void PushAfter(TKey, TKey, TData*);
    void Remove(TKey);
    template<class TKey, class TData> friend ostream& operator<<(ostream&, TList<TKey, TData>&);
};

template<class TKey, class TData>//done
TList<TKey, TData>::TList() {
    pFirst = NULL;
    pNext = NULL;
    pPrev = NULL;
    pCurrent = NULL;
};

template<class TKey, class TData>//done
TList<TKey, TData>::TList(const TList& list) {
    pNext = NULL;
    pPrev = NULL;
    pCurrent = NULL;

    if (!list.pFirst) {
        pFirst = NULL;
    }
    else {
        pFirst = new TNode<TKey, TData>(*list.pFirst, NULL);//создали копию указател¤ на первый        
        pCurrent = pFirst;
        TNode<TKey, TData>* tmp = list.pFirst;//в тмп кладем указатель на первый от того, который мы копируем

        while (tmp->pNext) {//создаем цепочку из tmp
            tmp = tmp->pNext;
            pCurrent->pNext = new TNode<TKey, TData>(*tmp, NULL);//параллельно с этим создаем цепочку из tmp
            pPrev = pCurrent;//в предыдущий кладем прошлый текущий
            pCurrent = pCurrent->pNext;//текущий теперь смещаетс¤ дальше
            pNext = NULL;//следующего у нас уже нет
        }
        pPrev = NULL;//когда закончили с цепочкой предыдущего у нас нет(мы сейчас на первом как бы)
        pCurrent = pFirst;//текцщий-первый
        pNext = pFirst->pNext;
    }
};

template<class TKey, class TData>//done
TList<TKey, TData>::TList(const TNode<TKey, TData>* first) {
    pFirst = new TNode<TKey, TData>(*first);
    TNode<TKey, TData>* node = first;
    TNode<TKey, TData>* tmp = pFirst;
    while (tmp->pNext != nullptr) {
        node->pNext = new TNode<TKey, TData>(*(tmp->pNext));
        node = node->pNext;
        tmp = tmp->pNext;
    }
    pPrev = nullptr;
    pCurrent = pFirst;
    pNext = pFirst->pNext;
};

template<class TKey, class TData>//done
TList<TKey, TData>::~TList() {
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


template<class TKey, class TData>//done
void TList<TKey, TData>::Reset() {//переводит текущий  на первый
    pPrev = NULL;
    pCurrent = pFirst;
    if (pFirst) {
        pNext = pCurrent->pNext;
    }
    else {
        pNext = NULL;
    }
};

template<class TKey, class TData>//done
void TList<TKey, TData>::Next() {//сдвиг вправо
    pPrev = pCurrent;
    pCurrent = pNext;
    if (pCurrent) {
        pNext = pCurrent->pNext;
    }
    else {
        pNext = NULL;
    }
};

template<class TKey, class TData>//done
bool TList<TKey, TData>::End() const {
    return (pCurrent == NULL);
};

template<class TKey, class TData>//done
TNode<TKey, TData>* TList<TKey, TData>::GetpFirst() const {
    return pFirst;
};

template<class TKey, class TData>//done
TNode<TKey, TData>* TList<TKey, TData>::Search(TKey key_value) {
    TNode<TKey, TData>* tmppCurrent = pCurrent;
    TNode<TKey, TData>* tmppNext = pNext;
    TNode<TKey, TData>* tmppPrev = pPrev;
    this->Reset();

    while (!this->End() && (key_value != pCurrent->key)) {
        this->Next();
    }
    TNode<TKey, TData>* node = this->pCurrent;
    pCurrent = tmppCurrent;
    pNext = tmppNext;
    pPrev = tmppPrev;
    return node;
};

template<class TKey, class TData>//вставка в начало done
void TList<TKey, TData>::PushBegin(TKey key_value, TData* data_value) {
    if (pFirst == nullptr) {
        pFirst = new TNode<TKey, TData>(key_value, data_value);
        pCurrent = pFirst;
        return;
    };
    TNode<TKey, TData>* node = new TNode<TKey, TData>(key_value, data_value, pFirst);
    node->pNext = pFirst;
    if (pCurrent == pFirst)
        pPrev = node;
    pFirst = node;
};

template<class TKey, class TData>//done
void TList<TKey, TData>::PushEnd(TKey key_value, TData* data_value) {
    TNode<TKey, TData>* tmppCurrent = pCurrent;
    TNode<TKey, TData>* tmppNext = pNext;
    TNode<TKey, TData>* tmppPrev = pPrev;
    this->Reset();
    while (pNext)
        this->Next();
    TNode<TKey, TData>* node = new TNode<TKey, TData>(key_value, data_value);//в конец добавили

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

template<class TKey, class TData>//done
void TList<TKey, TData>::PushBefore(TKey nkey, TKey key_value, TData* data_value) {//вставка до
    TNode<TKey, TData>* tmppCurrent = pCurrent;
    TNode<TKey, TData>* tmppNext = pNext;
    TNode<TKey, TData>* tmppPrev = pPrev;
    this->Reset();

    if ((this->End()) || (pFirst->key == nkey)) {
        this->PushBegin(key_value, data_value);
        pCurrent = pFirst;
        return;
    }

    TNode<TKey, TData>* node_search = Search(nkey);
    if (!node_search) {
        throw Exception("¬аш ключ не найден:(");
        return;
    }

    while (pCurrent != node_search)
        this->Next();

    TNode<TKey, TData>* node = new TNode<TKey, TData>(key_value, data_value, pCurrent);
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

template<class TKey, class TData>//вставка после done
void TList<TKey, TData>::PushAfter(TKey nkey, TKey key_value, TData* data_value) {
    TNode<TKey, TData>* tmppCurrent = pCurrent;
    TNode<TKey, TData>* tmppNext = pNext;
    TNode<TKey, TData>* tmppPrev = pPrev;
    this->Reset();
    TNode<TKey, TData>* node_search = Search(nkey);

    if (!node_search) {
        throw Exception("¬аш ключ не найден:(");
        return;
    }

    while (pCurrent != node_search)
        this->Next();

    TNode<TKey, TData>* node = new TNode<TKey, TData>(key_value, data_value, pNext);
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

template<class TKey, class TData>//done
void TList<TKey, TData>::Remove(TKey key_value) {//удаление
    if (!pFirst)
        throw Exception("—писок пуст:(");

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

    TNode<TKey, TData>* tmppCurrent = pCurrent;
    TNode<TKey, TData>* tmppPrev = pPrev;
    TNode<TKey, TData>* tmppNext = pNext;
    this->Reset();
    TNode<TKey, TData>* node_search = Search(key_value);

    if (!node_search) {
        throw Exception("Ключ не найден:(");
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

template<class TKey, class TData>//done
ostream& operator<<(ostream& _out, TList<TKey, TData>& f_list) {
    if (!f_list.pFirst) {
        _out << "—писок пуст:(" << endl;
        return _out;;
    }

    TNode<TKey, TData>* tmppCurrent = f_list.pCurrent;
    TNode<TKey, TData>* tmppNext = f_list.pNext;
    TNode<TKey, TData>* tmppPrev = f_list.pPrev;
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