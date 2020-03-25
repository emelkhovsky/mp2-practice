#ifndef _TNODE_H_
#define _TNODE_H_

template<class TKey, class TData>
class TNode {
public:
    TKey key;
    TData* pData;
    TNode<TKey, TData>* pNext;
    TNode();
    TNode(TKey k, TData* d, TNode<TKey, TData>* node = NULL);
    TNode(const TNode&);
    ~TNode();
};

template<class TKey, class TData>
TNode<TKey, TData>::TNode() {
    key = 0;
    pData = NULL;
    pNext = NULL;
}

template<class TKey, class TData>
TNode<TKey, TData>::TNode(TKey k, TData* d, TNode<TKey, TData>* node) {
    key = k;
    pData = d;
    pNext = node;
}

template<class TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& node) {
    key = node.key;
    pNext = NULL;
    pData = node.pData;
}

template<class TKey, class TData>
TNode<TKey, TData>::~TNode() {
    key = 0;
    pNext = NULL;
    pData = NULL;
}
#endif