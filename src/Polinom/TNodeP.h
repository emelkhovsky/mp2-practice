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
	bool operator==(const TNode&) const;
	bool operator!=(const TNode&) const;
};
bool TNode<int, float>::operator==(const TNode& node) const{
	return ((this->key == node.key) && (this->data == node.data));
};

bool TNode<int, float>::operator!=(const TNode& node) const{
	return (!(*this == node));
};

#endif