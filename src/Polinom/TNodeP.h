#ifndef _TNODE_TMONOM_H_
#define _TNODE_TMONOM_H_
#include "TNode.h"
#include "exceptions.h"

template<>
class TNode<int, float> {
public:
    int key;
    float data;
    TNode<int, float>* pNext;
    TNode():key(0), data(0), pNext(NULL){}
    TNode(int k, float d, TNode* node = NULL) : key(k), data(d), pNext(node) {}
    TNode(const TNode& node): key(node.key), data(node.data), pNext(node.pNext){}
    ~TNode() {
        key = 0;
        data = 0;
        pNext = NULL;
    }
    bool operator<(const TNode&) const;
    TNode<int, float>* operator*(const TNode&);
    TNode<int, float> operator-();
    bool operator==(const TNode&) const;
    bool operator!=(const TNode&) const;
};
bool TNode<int, float>::operator<(const TNode& tmp) const{
    return (this->key < tmp.key);
};

TNode<int, float> TNode<int, float>::operator-() {
    this->data = -this->data;
    return *this;
};

TNode<int, float>* TNode<int, float>::operator*(const TNode& tmp){
    TNode<int, float>* res = new TNode<int, float>();

    int degreeX = tmp.key / 100;
    int degreeY = (tmp.key % 100) / 10;
    int degreeZ = tmp.key % 10;

    int tmpdegreeX = key / 100;
    int tmpdegreeY = (key % 100) / 10;
    int tmpdegreeZ = key % 10;

    if ((degreeX + tmpdegreeX > 9) || ((degreeY + tmpdegreeY > 9) || (degreeZ + tmpdegreeZ > 9))){
        throw Exception("Степень превышает 9, попробуйте поменьше");
    };

    res->key = key + tmp.key;
    res->data = data * tmp.data;
    return res;
};
bool TNode<int, float>::operator==(const TNode& node) const{
    return ((this->key == node.key) && (this->data == node.data));
};

bool TNode<int, float>::operator!=(const TNode& node) const{
    return (!(*this == node));
};

#endif