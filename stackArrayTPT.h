template <class Type>
class stackArrayTPT{
private:
    int size;
    int top;
    Type* list;
public:
    stackArrayTPT(int);
    ~stackArrayTPT();
    void push(Type);
    Type pop();
    bool isEmptyStack();
};
