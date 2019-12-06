#ifndef _TSTACK_H_
#define _TSTACK_H_

enum TypeStack {
	AStack,
	LStack
};

template<typename ValType> class TArrayStack;
template<typename ValType> class TListStack;

template <typename ValType>
class TStack {
public:
	static TStack* Create(TypeStack);
	virtual bool IsFull() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual void Push(ValType) = 0;
	virtual void Pop() = 0;
	virtual ValType Pop_Get() const = 0;
};

template<typename ValType>
TStack<ValType>* TStack<ValType>::Create(TypeStack type) {
	if (type == AStack) {
		return new TArrayStack<ValType>(50);
	}
	if (type == LStack) {
		return new TListStack<ValType>();
	}
	throw Exception("Некорректный тип стека\n");
}


#endif
