

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
//#include "BinaryTree.h"
using namespace std;

double doublerand(double min, double max)
{
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}


float floatrand(float min, float max)
{
    float f = (float)rand() / RAND_MAX;
    return min + f * (max - min);
}

string GenRandomString(const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ "
        "abcdefghijklmnopqrstuvwxyz ";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

int rand(int min, int max)
{
    return min + rand() % (max - min + 1);
}

long long rand(long long min, long long max)
{
    return min + (long long)rand() % (max - min + 1);
}



class mycomplex
{
public:

    mycomplex()
    {
        this->Re = 0;
        this->Im = 0;
    }

    mycomplex(double Re, double Im)
    {
        this->Re = Re;
        this->Im = Im;
    }

    bool operator>(mycomplex other)
    {
        if (sqrt(this->GetRe() * this->GetRe() + this->GetIm() * this->GetIm()) > sqrt(other.GetRe() * other.GetRe() + other.GetIm() * other.GetIm())) return 1;
        return 0;
    }

    bool operator!=(mycomplex other)
    {
        if (this->GetRe() != other.GetRe() || this->GetIm() != other.GetIm()) return false;
        return true;
    }

    bool operator<(mycomplex other)
    {
        if (sqrt(this->GetRe() * this->GetRe() + this->GetIm() * this->GetIm()) < sqrt(other.GetRe() * other.GetRe() + other.GetIm() * other.GetIm())) return 1;
        return 0;
    }

    mycomplex& operator+(const mycomplex other)
    {
        mycomplex* temp = new mycomplex();
        temp->GetRe() = this->Re + other.Re;
        temp->GetIm() = this->Im + other.Im;
        return *temp;
    }

    friend ostream& operator<<(ostream& out, const mycomplex c);

    friend istream& operator>>(istream& in, mycomplex& c);

    mycomplex operator=(const mycomplex c1)
    {
        this->Im = c1.Im;
        this->Re = c1.Re;
        return mycomplex(c1.Re, c1.Im);
    }

    double& GetRe()
    {
        return Re;
    }

    double& GetIm()
    {
        return Im;
    }

    bool operator==(const mycomplex other)
    {
        if (this->Re == other.Re && this->Im == other.Im) return true;
        else return false;
    }

    void operator+=(const mycomplex* other)
    {
        this->Re += other->Re;
        this->Im += other->Im;
    }

    void operator+=(const double other)
    {
        this->Re += other;
        this->Im += other;
    }

    void operator+=(const mycomplex other)
    {
        this->Re += other.Re;
        this->Im += other.Im;
    }

    void operator*=(const mycomplex other)
    {
        double ReStart = this->Re, ImStart = this->Im;
        this->Re = ReStart * other.Re - ImStart * other.Im;
        this->Im = ReStart * other.Im + ImStart * other.Re;
    }

    mycomplex& operator=(const int i)
    {
        this->Im = this->Re = i;
        return *this;
    }

    mycomplex& operator*(const mycomplex other)
    {
        mycomplex* temp = new mycomplex();
        temp->Re = Re * other.Re - Im * other.Im;
        temp->Im = Re * other.Im + Im * other.Re;
        return *temp;
    }

    mycomplex& operator-(const mycomplex other)
    {
        mycomplex* temp = new mycomplex();
        temp->Re = Re - other.Re;
        temp->Im = Im - other.Im;
        return *temp;
    }

    void rand(double min = 0, double max = 1000)
    {
        Re = doublerand(min, max);
        Im = doublerand(min, max);
        //complex(doublerand(min, max), doublerand(min, max));
    }

    void Print()
    {
        cout << this->to_string() << endl;
    }

    string to_string()
    {
        return "Re: " + std::to_string(Re) + "     Im: " + std::to_string(Im);
    }
private:
    double Re;
    double Im;
};

istream& operator>>(istream& in, mycomplex& c)
{
    cout << "Re:";
    in >> c.GetRe();
    cout << "Im:";
    in >> c.GetIm();
    return in;
}

ostream& operator<<(ostream& out, const mycomplex c)
{
    if (c.Im > 0) out << to_string(c.Re) + "+" + to_string(c.Im) + "i";
    else out << to_string(c.Re) + to_string(c.Im) + "i";
    return out;
}

mycomplex pow(mycomplex num, int pow)
{
    mycomplex temp = num;
    for (int i = 1; i < pow; i++)
    {
        num *= temp;
    }
    return num;
}

void swap(mycomplex* c1, mycomplex* c2)
{
    mycomplex* temp = new mycomplex();
    temp = c1;
    c1 = c2;
    c2 = temp;
}

template<typename T>
void* TemplateRand(int randmax = 1000, int strmin = 5, int strmax = 20, int argmax = 10, /*long long longmax = 5000000000*/ long long longmax = 9999999)
{
    if (typeid(T).name() == typeid(int).name())
    {
        return new int(rand(-randmax, randmax));
    }

    if (typeid(T).name() == typeid(long).name())
    {
        return new long(rand(-longmax, longmax));
    }

    if (typeid(T).name() == typeid(long long).name())
    {
        return new long long(rand(-longmax, longmax));
    }

    else if (typeid(T).name() == typeid(float).name())
    {
        return new float(doublerand(-randmax, randmax));
    }

    else if (typeid(T).name() == typeid(double).name())
    {
        return new double(doublerand(-randmax, randmax));
    }
    else if (typeid(T).name() == typeid(string).name())
    {
        return new string(GenRandomString(rand(strmin, strmax)));
    }
    else if (typeid(T).name() == typeid(mycomplex).name())
    {
        return new mycomplex(doublerand(-randmax, randmax), doublerand(-randmax, randmax));
    }
    else
    {
        return nullptr;
    }
}


template <typename T> class DynamicArray
{
public:
    DynamicArray(int size)
    {
        this->arr = new T[size];
        this->len = size;
    }
    DynamicArray()
    {
        len = 0;
        arr = new T[len];
    }
    DynamicArray(T* items, int count)
    {
        /*if (arr != nullptr)
        {
            delete[] arr;
            len = count;
        }*/
        arr = new T[count];
        len = count;
        for (int i = 0; i < len; i++)
        {
            arr[i] = items[i];
        }
    }

    DynamicArray(const DynamicArray<T>& other)
    {
        this->len = other.len;
        this->arr = new T[this->len];
        for (int i = 0; i < this->len; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    T* GetArr()
    {
        return arr;
    }

    T& Get(int index)
    {
        if (index < len) return arr[index];
        else throw "IndexOutOfRange_DA_Get";
        //else cout << "IndexOutOfRange_DA_Get\n";
        return arr[0];
    }
    T GetLast()
    {
        try {
            return this->Get(len - 1);
        }
        catch (string ex)
        {
            throw ex;
        }
    }
    T GetFirst()
    {
        try {
            return this->Get(0);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    int GetSize()
    {
        return len;
    }

    void set(int index, T item)
    {
        if (index < len) arr[index] = item;
        else throw "IndexOutOfRange";
    }

    void Resize(int NewSize)
    {
        T* arrnew = new T[NewSize]();
        if (NewSize >= len)
        {
            for (int i = 0; i < len; i++)
            {
                arrnew[i] = arr[i];
            }

        }
        else
        {
            for (int i = 0; i < NewSize; i++)
            {
                arrnew[i] = arr[i];
            }
        }
        len = NewSize;
        delete[] arr;
        this->arr = arrnew;
    }

    DynamicArray<T> operator=(const DynamicArray<T>& other)
    {
        T* arrnew = new T[other.len];
        for (int i = 0; i < other.len; i++)
        {
            arrnew[i] = other.arr[i];
        }
        delete[] arr;
        len = other.len;
        this->arr = arrnew;
        return DynamicArray<T>(*this);
    }



    ~DynamicArray()
    {
        delete[] this->arr;
    }

    void Print(int index)
    {
        cout << arr[index] << endl;
    }

    T& operator[](int index)
    {
        if (index < len) return arr[index];
        else throw "IndexOutOfRange_DA_[]";
        return arr[0];
    }

private:
    T* arr;
    int len;
};

template <typename T> class LinkedList
{
public:
    LinkedList() {
        size = 0;
        head = nullptr;
    }

    ~LinkedList()
    {
        while (size)
        {
            this->Pop_Front();
        }
    }

    LinkedList(T* items, int count)
    {
        size = 0;
        //head = new Node<T>();
        for (int i = 0; i < count; i++)
        {
            this->Push_Back(items[i]);
        }
    }

    LinkedList(int count)
    {
        size = 0;
        head = nullptr;
        /*head = new Node<T>();
        Node<T>* temp = head;
        for (int i = 0; i < count - 1; i++)
        {
            temp = temp->ptrNext;
            temp = new Node<T>();
        }*/
        for (int i = 0; i < count; i++)
        {
            this->Push_Back(T());
        }
    }

    LinkedList(const LinkedList<T>& other)
    {
        Node<T>* temp = other.head;
        for (int i = 0; i < other.size; i++)
        {
            this->Push_Back(temp->data);
            temp = temp->ptrNext;
        }
    }

    T GetFirst()
    {
        if (size >= 1)
        {
            try {
                return this->Get(0);
            }
            catch (string ex)
            {
                throw ex;
            }
        }
        else
        {
            throw "IndexOutOfRange_LL_GetFirst";
            //return T();
        }
    }

    void Resize(int NewSize)
    {
        if (NewSize == size) {}
        else if (NewSize > size) for (int i = 0; i < NewSize - size;) this->Append(T());
        else if (NewSize < size) for (int i = 0; i < size - NewSize;) this->Pop_Back();
    }

    T GetLast()
    {
        if (size == 0)
        {
            throw "IndexOutOfRange_LL_GetLast";
            return T();
        }
        else
        {
            try
            {
                return this->Get(size - 1);
            }
            catch (string ex)
            {
                throw ex;
            }
            /*Node<T>* temp = head;
            while (temp->ptrNext != nullptr)
            {
                temp = temp->ptrNext;
            }
            return temp->data;*/
        }
    }

    T& Get(int index)
    {
        if (index < size)
        {
            return this->operator[](index);
        }
        else
        {
            throw "IndexOutOfRange_LL_Get";
            //return *(new T());
        }

    }

    //LinkedList<T>* GetRelatedSubList(int startIndex, int endIndex)
    //{
    //    if (startIndex < size && endIndex < size && startIndex >= 0 && endIndex >= 0)
    //    {
    //        if (endIndex < startIndex)
    //        {
    //            LinkedList<T>* res = new LinkedList<T>();
    //            return res;
    //        }
    //        LinkedList<T>* res = new LinkedList<T>(endIndex - startIndex + 1);
    //        Node<T>* temp = head, temp1 = res->head;
    //        //T* arrnew = new T[endIndex - startIndex + 1];
    //        for (int i = 0; i < startIndex; i++)
    //        {
    //            temp = temp->ptrNext;
    //        }
    //        for (int i = startIndex; i <= endIndex; i++)
    //        {
    //            temp1->data = &temp->data;
    //            temp1 = temp1->ptrNext;
    //            temp = temp->ptrNext;
    //        }
    //        //LinkedList<T>* res = new LinkedList<T>(arrnew, endIndex - startIndex + 1);
    //        //delete[] arrnew;
    //        return res;
    //    }
    //    else
    //    {
    //        throw "IndexOutOfRange_LL_GetSubList";
    //        LinkedList<T>* res = new LinkedList<T>();
    //        return res;
    //    }
    //}

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        if (startIndex < size && endIndex < size && startIndex >= 0 && endIndex >= 0)
        {
            if (endIndex < startIndex)
            {
                LinkedList<T>* res = new LinkedList<T>();
                return res;
            }
            Node<T>* temp = head;
            T* arrnew = new T[endIndex - startIndex + 1];
            for (int i = 0; i < startIndex; i++)
            {
                temp = temp->ptrNext;
            }
            for (int i = startIndex; i <= endIndex; i++)
            {
                arrnew[i - startIndex] = temp->data;
                temp = temp->ptrNext;
            }
            LinkedList<T>* res = new LinkedList<T>(arrnew, endIndex - startIndex + 1);
            delete[] arrnew;
            return res;
        }
        else
        {
            throw "IndexOutOfRange_LL_GetSubList";
            LinkedList<T>* res = new LinkedList<T>();
            return res;
        }
    }

    void Clear()
    {
        while (size)
        {
            this->Pop_Front();
        }
    }

    void printall()
    {
        cout << "printall  this=" << this << endl;
        for (int i = 0; i < size; i++)
        {
            cout << this->operator[](i) << endl;
        }
    }

    void Pop_Front()
    {
        //cout << this << "   " << size << this->head->data << endl;
        Node<T>* temp = head->ptrNext;
        delete head;
        head = temp;
        size -= 1;
    }

    void Push_Back(T data)
    {
        size += 1;
        if (head == nullptr)
        {
            head = new Node<T>(data);
        }
        else
        {
            Node<T>* current = this->head;
            while (current->ptrNext != nullptr)
            {
                current = current->ptrNext;
            }
            current->ptrNext = new Node<T>(data);
        }
    }

    int GetSize()
    {
        return size;
    }

    T& operator[](int index)
    {
        Node<T>* current = this->head;
        for (int i = 0; i < index; i++)
        {
            current = current->ptrNext;
        }
        return current->data;
    }

    LinkedList<T>& operator=(const LinkedList<T>& other)
    {
        Clear();
        Node<T>* temp = other.head;
        for (int i = 0; i < other.size; i++)
        {
            Push_Back(temp->data);
            temp = temp->ptrNext;
        }
        return *this;
    }

    void Push_Front(T data)
    {
        head = new Node<T>(data, head);
        size += 1;
    }

    T* GetArr()
    {
        T* Arr = new T[size]();
        Node<T>* temp = this->head;
        for (int i = 0; i < size; i++)
        {
            Arr[i] = temp->data;
            temp = temp->ptrNext;
        }
        return Arr;
    }

    void Pop_Back()
    {
        Node<T>* current = this->head;
        for (int i = 0; i < size - 1; i++)
        {
            current = current->ptrNext;
        }
        delete[] current->ptrNext;
        current->ptrNext = nullptr;
        size -= 1;
    }

    void Append(T item)
    {
        Push_Back(item);
    }

    void Prepend(T item)
    {
        Push_Front(item);
    }


    void InsertAt(T item, int index)
    {
        if (index > size) throw "IndexOutOfRange_LL_InsertAt";
        else
        {

            if (index == 0)
            {
                Push_Front(item);
            }
            else {
                index -= 1;
                size += 1;
                Node<T>* temp = this->head;
                for (int i = 0; i < index; i++)
                {
                    temp = temp->ptrNext;
                }
                Node<T>* ins = new Node<T>(item, temp->ptrNext);
                temp->ptrNext = ins;
            }
        }
    }
    LinkedList<T>* Concat(LinkedList<T>* other)
    {
        size += other->size;
        Node<T>* temp = head;
        while (temp->ptrNext != nullptr)
        {
            temp = temp->ptrNext;
        }
        temp->ptrNext = other->head;
        LinkedList<T>* res = new LinkedList<T>(*this);
        return res;
    }



private:
    template <typename T1> class Node
    {
    public:
        Node<T1>* ptrNext;
        T1 data;

        Node(T1 data = T1(), Node<T1>* ptrNext = nullptr)
        {
            this->data = data;
            this->ptrNext = ptrNext;
        }
        Node<T1>& operator=(const Node<T1> other)
        {
            this->data = other.data;
        }
        /*Node<T1>& operator[](const int index)
        {
            Node<T1>* temp = this;
            for (int i = 0; i < index; i++)
            {
                temp = temp->ptrNext;
            }
            return &temp->data;
        }*/
    };
    int size;
    Node<T>* head;
};

template <typename T> class ISortedSequence
{
public:

    virtual ~ISortedSequence() {};
    virtual T GetFirst() = 0;
    virtual void Resize(int len) = 0;
    virtual T GetLast() = 0;
    virtual T* GetArr() = 0;

    virtual T& Get(int index) = 0;
    virtual void Set(int index, T Value) = 0;
    virtual ISortedSequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;

    virtual int GetLenght() = 0;

    virtual void Append(T item) = 0;


    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, int index) = 0;

    virtual ISortedSequence <T>* Concat(ISortedSequence <T>* list) = 0;
    virtual T& operator[](int index) = 0;
    virtual void Sort() = 0;
private:
};

template <typename T> class ArraySortedSequence : public ISortedSequence<T>
{
public:
    ~ArraySortedSequence() override
    {
        delete items;
    }

    void Set(int index, T Value) override
    {
        items->operator[](index) = Value;
    }

    void Sort() override // ShellSort
    {
        int i = 0, j = 0, len = this->GetLenght();
        T tmp;
        for (int step = len / 2; step > 0; step /= 2)
        {
            for (i = step; i < len; i++)
            {
                tmp = items->Get(i);
                for (j = i; j >= step; j -= step)
                {
                    if (tmp > items->Get(j - step))
                    {
                        items->Get(j) = items->Get(j - step);
                    }
                    else
                    {
                        break;
                    }
                }
                items->Get(j) = tmp;
            }
        }
    }

    ArraySortedSequence(T* items, int count)
    {
        this->items = new DynamicArray<T>(items, count);
    }
    ArraySortedSequence(const ISortedSequence<T>& other)
    {
        this->items = new DynamicArray(other->items);
    }
    ArraySortedSequence()
    {
        this->items = new DynamicArray<T>();
    }

    ArraySortedSequence(int count)
    {
        this->items = new DynamicArray<T>(count);
    }

    T& operator[](int index) override
    {
        return items->operator[](index);
    }

    int GetSize()
    {
        return this->GetLenght();
    }

    T* GetArr() override
    {
        return items->GetArr();
    }

    ISortedSequence <T>* Concat(ISortedSequence <T>* other) override
    {
        for (int i = 0; i < other->GetLenght(); i++)
        {
            try {
                this->Append(other->Get(i));
            }
            catch (string ex)
            {
                throw ex;
            }
        }
        ArraySortedSequence<T>* res = new ArraySortedSequence<T>(*this);
        return res;
    }



    ISortedSequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        DynamicArray<T>* temp = new DynamicArray<T>(abs(endIndex - startIndex) + 1);
        for (int i = startIndex; i <= endIndex; i++)
        {
            temp->operator[](i - startIndex) = items->operator[](i);
        }
        int len = temp->GetSize();
        T* arr = new T[len];
        for (int i = 0; i < len; i++)
        {
            try {
                arr[i] = temp->Get(i);
            }
            catch (string ex)
            {
                throw ex;
            }
        }
        delete temp;
        ArraySortedSequence<T>* res = new ArraySortedSequence<T>(arr, len);
        return res;
    }

    T GetFirst() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetFirst();
        }

        else throw "IndexOutOfRange_DS_GETFIRST";
        return items->GetFirst();
    }

    T GetLast() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetLast();
        }

        else throw "IndexOutOfRange_DS_GetLast";
        return items->GetLast();
    }

    T& Get(int index) override
    {
        try
        {
            return items->Get(index);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    int GetLenght() override
    {
        return items->GetSize();
    }

    void Append(T item) override
    {
        //if (items->GetSize() != 0) {
        int len = items->GetSize() + 1;
        DynamicArray<T>* items_new = new DynamicArray<T>(len);
        for (int i = 0; i < len - 1; i++)
        {
            items_new->operator[](i) = items->operator[](i);
        }
        items_new->operator[](len - 1) = item;
        if (items->GetSize() != 0) delete items;
        items = items_new;
        //}
        //else throw "IndexOutOfRange_DS_APPEND";
    }

    void InsertAt(T item, int index) override
    {
        if (this->GetSize() < index) throw"IndexOutOfRange_AS_InsertAt";
        if (index == 0) this->Prepend(item);
        else if (index == items->GetSize()) this->Append(item);
        else
        {
            int len = items->GetSize() + 1;
            DynamicArray<T>* items_new = new DynamicArray<T>(len);
            int i1 = 0;
            for (int i = 0; i < len; i++)
            {
                if (i != index) {
                    items_new->operator[](i) = items->operator[](i1);
                    i1++;
                }
                else
                {
                    items_new->operator[](i) = item;
                }
            }
            delete items;
            items = items_new;
        }
    }

    void Prepend(T item) override
    {
        int len = items->GetSize() + 1;
        DynamicArray<T>* items_new = new DynamicArray<T>(len);
        items_new->operator[](0) = item;
        for (int i = 1; i < len; i++)
        {
            items_new->operator[](i) = items->operator[](i - 1);
        }
        delete items;
        this->items = items_new;
    }

    void Resize(int len) override
    {
        items->Resize(len);
    }

private:
    DynamicArray<T>* items;
};


template <typename T> class ListSortedSequence : public ISortedSequence<T>
{
public:

    void Sort() override
    {
        int i = 0, j = 0, step = 0, len = this->GetSize();
        T tmp;
        for (step = len / 2; step > 0; step /= 2)
        {
            for (i = step; i < len; i++)
            {
                tmp = this->Get(i);
                for (j = i; j >= step; j -= step)
                {
                    if (compare(tmp, this->Get(j - step)))
                    {
                        this->Get(j) = this->Get(j - step);
                    }
                    else
                    {
                        break;
                    }
                }
                this->Get(j) = tmp;
            }
        }
    }

    ~ListSortedSequence() override
    {
        if (items->GetSize() != 0) delete items;
    }

    ListSortedSequence(const ListSortedSequence<T>& other)
    {
        this->items = new LinkedList(other->items);
    }

    ListSortedSequence(T* items, int count)
    {
        this->items = new LinkedList<T>(items, count);
    }

    ListSortedSequence(int count)
    {
        this->items = new LinkedList<T>(count);
    }

    ListSortedSequence()
    {
        this->items = new LinkedList<T>();
    }

    T* GetArr()
    {
        return items->GetArr();
    }


    int GetSize()
    {
        return this->GetLenght();
    }

    T& operator[](int index) override
    {
        return items->operator[](index);
    }
    ISortedSequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        ListSortedSequence<T>* res = new ListSortedSequence<T>();
        try
        {
            res->items = this->items->GetSubList(startIndex, endIndex);
        }
        catch (string ex)
        {
            throw ex;
        }
        return res;
    }

    ISortedSequence <T>* Concat(ISortedSequence <T>* other) override
    {
        ListSortedSequence<T>* temp = new ListSortedSequence<T>(this->GetArr(), this->GetLenght());
        temp->items->Concat(new LinkedList<T>(other->GetArr(), other->GetLenght()));
        return temp;
    }

    T GetFirst() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetFirst();
        }
        else
        {
            throw "IndexOutOfRange_LS_GetFirst";
            return T();
        }
    }

    T GetLast() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetLast();
        }
        else
        {
            throw "IndexOutOfRange_DS_GetLast";
            return T();
        }
    }

    T& Get(int index) override
    {
        try
        {
            return items->Get(index);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    int GetLenght() override
    {
        return items->GetSize();
    }

    void Append(T item) override
    {
        items->Append(item);
    }

    void InsertAt(T item, int index) override
    {
        try
        {
            items->InsertAt(item, index);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    void Prepend(T item) override
    {
        items->Prepend(item);
    }

    void Resize(int len) override
    {
        items->Resize(len);
    }

private:
    LinkedList<T>* items;
};

template <typename T>
class KeyKeyValue
{
private:
    size_t column, row;
    T value;
public:
    KeyKeyValue()
    {
        column = row = 0;
        value = T();
    }
    KeyKeyValue(size_t column, size_t row, T value)
    {
        this->value = value;
        this->column = column;
        this->row = row;
    }
    KeyKeyValue operator=(const KeyKeyValue kkv1)
    {
        this->SetColumn(kkv1.column);
        this->SetRow(kkv1.row);
        this->SetValue(kkv1.value);
        return kkv1;
    }

    bool operator>(KeyKeyValue kkv1)
    {
        if (this->value > kkv1.GetValue()) return true;
        return false;
    }
    bool operator>=(KeyKeyValue kkv1)
    {
        if (this->value >= kkv1.GetValue()) return true;
        return false;
    }
    bool operator<(KeyKeyValue kkv1)
    {
        if (this->value < kkv1.GetValue()) return true;
        return false;
    }
    bool operator<=(KeyKeyValue kkv1)
    {
        if (this->value <= kkv1.GetValue()) return true;
        return false;
    }
    size_t GetRow() { return row; }
    size_t GetColumn() { return column; }
    T GetValue() { return value; }
    void SetRow(size_t nrow) { row = nrow; }
    void SetColumn(size_t ncolumn) { column = ncolumn; }
    void SetValue(T nvalue) { value = nvalue; }
};

template <typename T>
class SparseMatrix
{
private:
    ISortedSequence<KeyKeyValue<T>>* mass;
    size_t len;
    size_t columns;
    size_t rows;
public:
    SparseMatrix()
    {
        len = 0;
        columns = rows = 0;
        mass = new ArraySortedSequence<KeyKeyValue<T>>();
    }
    void add(T value, size_t row, size_t column)
    {
        if (value != T())
        {
            if (this->Get(row, column) == T())
            {
                cout << "old: " << this->Get(row, column) << " new " << value << " column: " << column << " row: " << row << endl;
                mass->Append(KeyKeyValue<T>(column, row, value));
                len++;
                if (row > rows) rows = row;
                if (column > columns) columns = column;
                //mass->Sort();
            }
            else
            {
                for (int i = 0; i < len; i++)
                {
                    if ((mass->Get(i)).GetValue() == value)
                    {
                        mass->Get(i) = KeyKeyValue<T>(column, row, value);
                    }
                }
            }
        }
    }

    void operator+=(SparseMatrix<T> other)
    {
        if (other.columns > this->columns) this->columns = other.columns;
        if (other.rows > this->rows) this->rows = other.rows;
        for (int i = 1; i < rows + 1; i++)
        {
            for (int j = 1; j < columns + 1; j++)
            {
                T temp = this->Get(i, j) + other.Get(i, j);
                if (temp != T())
                {
                    this->add(temp, i, j);
                }
            }
        }
    }

    SparseMatrix<T>* operator *(SparseMatrix<T> other)
    {
        SparseMatrix<T>* SMtemp = new SparseMatrix<T>();
        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < columns; j++)
            {
                T temp = T();
                for (int k = 0; k < columns; k++)
                {
                    temp += this->Get(i, k) * other.Get(k, j);
                }

                SMtemp->add(temp, i, j);
            }
        }
        return SMtemp;
    }

    int GetLen() { return len; }

    void SetLen(int nlen) { len = nlen; }

    T Get(size_t row, size_t column)
    {
        if (mass == nullptr)
        {
            return T();
        }
        else
        {
            for (int i = 0; i < mass->GetLenght(); i++)
            {
                if ((mass->Get(i)).GetRow() == row && (mass->Get(i)).GetColumn() == column)
                {
                    return (mass->Get(i)).GetValue();
                }
            }
            return T();
        }
    }

    SparseMatrix(ISortedSequence<T>* sec, size_t* positionsc, size_t* positionsr)
    {
        int slen = sec->GetLenght();
        for (int i = 0; i < slen; i++)
        {
            this->add(sec->Get(i), positionsr[i], positionsc[i]);
        }
    }
    ~SparseMatrix()
    {
        delete mass;
    }
    void Print(size_t width = 8)
    {
        if (len == 0)
        {
            cout << "Матрица пуста.\n";
        }
        else
        {
            T tempv = T();
            for (int i = 0; i <= rows; i++)
            {
                for (int j = 0; j <= columns; j++)
                {
                    tempv = this->Get(i, j);
                    cout << setw(width) << tempv << " ";
                }
                cout << endl;
            }
        }
    }

    int GetColumns() { return columns; }

    int GetRows() { return rows; }

    void PrintParams()
    {
        if (len != 0) cout << "Количество ненулевых элементов: " << len << endl << "Количество столбцов матрицы: " << columns + 1 << endl << "Количество строк: " << rows + 1 << endl;
        else cout << "Матрица пуста.\n";
    }
};

//template <typename T>
//void map(SparseMatrix<T> mat)
//{
//    int len = mat->GetLen(), rowmax = mat->GetRows(), columnmax = mat->GetColumns();
//    pair* = new pair[len];
//    for (int i = 0; i < columnmax; i++)
//    {
//        for (j = 0; j < rowmax; j++)
//        {
//
//        }
//    }
//}

//class Person
//{
//private:
//    static int id;
//    int pid;
//    string FirstName;
//    string adress;
//    string telephone;
//    int birth_year;
//    int birth_month;
//    int birth_day;
//    double height;
//    double weight;
//public:
//    Person()
//    {
//        id++;
//        pid = id;
//        int birth_year = rand(1900, 2022);
//        int birth_month = rand(1, 12);
//        int birth_day = rand(1, 28);
//    }
//};
//int Person::id = 0;

template <typename T>
SparseMatrix<T>* GetRandSM(int rowmax, int columnmax, int len)
{
    SparseMatrix<T>* ret = new SparseMatrix<T>();
    int row = 0, column = 0;
    for (int i = 0; i < len; i++)
    {
        row = rand(1, rowmax + 1) - 1;
        column = rand(1, columnmax + 1) - 1;
        //if (SMptr->Get(row, column) != T())
        //{
        //    SMptr->SetLen(SMptr->GetLen() - 1);
        //}
        ret->add(*(T*)TemplateRand<T>(), row, column);
    }
    return ret;
}

template <typename T>
SparseMatrix<T>* GetManualSM(int len)
{
    T tempv = T();
    SparseMatrix<T>* ret = new SparseMatrix<T>();
    int row = 0, column = 0;
    for (int i = 0; i < len; i++)
    {
        tempv = T();
        row = column = 0;
        cout << "Введите " << i + 1 << "й элемент: " << endl;
        cout << "Значение(типа " << typeid(T).name() << "): ";
        cin >> tempv;
        cout << "Столбец: ";
        cin >> column;
        cout << "Строка: ";
        cin >> row;
        if (column <= 0 || row <= 0)
        {
            i--;
            cout << "Неверный ввод.\n";
            continue;
        }
        else
        {
            ret->add(tempv, row - 1, column - 1);
        }
    }
    return ret;
}

template <typename T>
void interfacesparce()
{
    int choice1 = -1, choice2 = -1, choice3 = -2, len = 0, rowmax1 = 60, columnmax1 = 15, printtemp = 1;
    SparseMatrix<T>* SMptr = new SparseMatrix<T>();
    while (1)
    {
        choice1 = choice2 = choice3 = -1, len = 0;
        cout << "Выберите дествие(0 для возвращения назад):\n1. Добавить элементы в разржённую матрицу.\n2. Вывести разряжённую матрицу.\n3. Получить характеристики матрицы.\n4. Действия над разярженной матрицей.\n5. Очистить матрицу.\n6. Изменить параметры случайного генерирования.\n";
        cin >> choice1;
        if (choice1 == 1)
        {
            while (1)
            {
                len = 0;
                cout << "Выберите способ ввода:\n1. Случайный.\n2. Ручной.\n";
                cin >> choice2;
                cout << "Введите количество элементов: ";
                cin >> len;
                if (len <= 0)
                {
                    cout << "Неверный ввод.\n";
                    cin.clear();
                    while (cin.get() != '\n');
                    continue;
                }
                if (choice2 == 1)
                {
                    if (rowmax1 <= 0 || columnmax1 <= 0)
                    {
                        cout << "Неверный ввод.\n";
                        cin.clear();
                        while (cin.get() != '\n');
                        continue;
                    }
                    int row = 0, column = 0;
                    for (int i = 0; i < len; i++)
                    {
                        row = rand(0, rowmax1 - 1);
                        column = rand(0, columnmax1 - 1);
                        //if (SMptr->Get(row, column) != T())
                        //{
                        //    SMptr->SetLen(SMptr->GetLen() - 1);
                        //}
                        SMptr->add(*(T*)TemplateRand<T>(), row, column);
                    }
                    break;
                }
                else if (choice2 == 2)
                {
                    T tempv = T();
                    int row = 0, column = 0;
                    for (int i = 0; i < len; i++)
                    {
                        tempv = T();
                        row = column = 0;
                        cout << "Введите " << i + 1 << "й элемент: " << endl;
                        cout << "Значение(типа " << typeid(T).name() << "): ";
                        cin >> tempv;
                        cout << "Столбец: ";
                        cin >> column;
                        cout << "Строка: ";
                        cin >> row;
                        if (column <= 0 || row <= 0)
                        {
                            i--;
                            cout << "Неверный ввод.\n";
                            continue;
                        }
                        else
                        {
                            SMptr->add(tempv, row - 1, column - 1);
                        }
                    }
                    break;
                }
            }
        }
        else if (choice1 == 2)
        {
            SMptr->Print();
        }
        else if (choice1 == 3)
        {
            SMptr->PrintParams();
        }
        else if (choice1 == 4)
        {
            while (1)
            {
                choice2 = -1;
                cout << "Выберите действие:\n1. Сложение разряженных матриц.\n2. Умножение разряженных матриц.\n";
                cin >> choice2;
                if (choice2 == 1)
                {
                    while (1)
                    {
                        int len = -1;//maxrow = -1, maxcolumn = -1;
                        cout << "Выберите способ ввода матрицы для сложения:\n1. Случайный.\n2. Ручной.\n";
                        cin >> choice3;
                        cout << "Введите количество элементов новой матрицы: ";
                        cin >> len;
                        if (len < 0 || (choice3 != 1 && choice3 != 2))
                        {
                            cout << "Неверный ввод.\n";
                            cin.clear();
                            while (cin.get() != '\n');
                            continue;
                        }
                        else
                        {
                            if (choice3 == 1)
                            {
                                SparseMatrix<T>* SMtemp = new SparseMatrix<T>();
                                SMtemp = GetRandSM<T>(rowmax1, columnmax1, len);
                                if (printtemp == 1)
                                {
                                    cout << "Матрица для сложения:\n";
                                    SMtemp->Print();
                                }
                                SMptr->operator+=(*SMtemp);
                                //delete SMtemp;
                            }
                            else if (choice3 == 2)
                            {
                                SparseMatrix<T>* SMtemp = new SparseMatrix<T>();
                                SMtemp = GetManualSM<T>(len);
                                if (printtemp == 1)
                                {
                                    cout << "Матрица для сложения:\n";
                                    SMtemp->Print();
                                }
                                SMptr->operator+=(*SMtemp);
                                //delete SMtemp;
                            }
                            break;
                        }
                    }
                    break;
                }
                else if (choice2 == 2)
                {
                    while (1)
                    {
                        choice2 = -1;
                        int len = -1;//maxrow = -1, maxcolumn = -1;
                        cout << "Выберите способ ввода матрицы для умножения:\n1. Случайный.\n2. Ручной.\n";
                        cin >> choice3;
                        cout << "Введите количество элементов новой матрицы: ";
                        cin >> len;
                        if (len < 0 || (choice3 != 1 && choice3 != 2))
                        {
                            cout << "Неверный ввод.\n";
                            cin.clear();
                            while (cin.get() != '\n');
                            continue;
                        }
                        else
                        {
                            if (choice3 == 1)
                            {
                                SparseMatrix<T>* SMtemp = new SparseMatrix<T>();
                                SMtemp = GetRandSM<T>(rowmax1, columnmax1, len);
                                if (printtemp == 1)
                                {
                                    cout << "Матрица для умножения:\n";
                                    SMtemp->Print();
                                }
                                SparseMatrix<T>* SMtemp1 = *SMptr * *SMtemp;
                                delete SMptr;
                                SMptr = SMtemp1;
                                //delete SMtemp;
                            }
                            else if (choice3 == 2)
                            {
                                SparseMatrix<T>* SMtemp = new SparseMatrix<T>();
                                SMtemp = GetManualSM<T>(len);
                                if (printtemp == 1)
                                {
                                    cout << "Матрица для умножения:\n";
                                    SMtemp->Print();
                                }
                                SparseMatrix<T>* SMtemp1 = *SMptr * *SMtemp;
                                delete SMptr;
                                SMptr = SMtemp1;
                                //delete SMtemp;
                            }
                            break;
                        }
                    }
                    break;
                }
                else
                {
                    cout << "Неверный ввод.\n";
                    cin.clear();
                    while (cin.get() != '\n');
                    continue;
                }
            }
        }
        else if (choice1 == 5)
        {
            delete SMptr;
            SMptr = new SparseMatrix<T>();
        }
        else if (choice1 == 6)
        {
            int rowmax = -1, columnmax = -1;
            char ct = 'n';
            cout << "Введите максимальный столбец: ";
            cin >> columnmax;
            cout << "Введите максимальную строку: ";
            cin >> rowmax;
            cout << "Выводить временные матрицы:(y/n)";
            cin >> ct;
            if (rowmax > 0 && columnmax > 0 && (ct == 'n' || ct == 'y'))
            {
                if (ct == 'y') printtemp = 1;
                else printtemp = 0;
                columnmax1 = columnmax;
                rowmax1 = rowmax;
            }
            else
            {
                cout << "Неверный ввод.\n";
                cin.clear();
                while (cin.get() != '\n');
            }
        }
        else if (choice1 != 0)
        {
            cout << "Неверный ввод.\n";
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }
        else
        {
            break;
        }
    }
}

void printerror()
{
    cout << "Неверный ввод.\n";
    cin.clear();
    while (cin.get() != '\n');
}
template <typename T>
class Node
{
private:
    T Data;
    Node<T>* parent;
    ISortedSequence<Node<T>>* children;
public:
    Node(T Data = T(), Node<T>* parents = nullptr, ISortedSequence<Node<T>>* children = nullptr)
    {
        this->Data = Data;
        this->parents = parents;
        this->children = new ArraySortedSequence<Node<T>>(children);
    }
    T& GetData() { return Data; }
    void SetData(T nData) { Data = nData; }
    Node<T>* GetParent() { return parent; }
    ISortedSequence<Node<T>>* GetChildren() { return children; }
};
template <typename T>
class DecisionTree
{
private:

public:

};

template <typename Tkey, typename Tvalue>
class Pair
{
private:
    Tkey key;
    Tvalue value;
public:
    Pair()
    {
        key = Tkey();
        value = Tvalue();
    }
    Pair(Tkey nkey, Tvalue nvalue)
    {
        key = nkey;
        value = nvalue;
    }
    void SetValue(Tvalue nvalue) { value = nvalue; }
    void SetKey(Tkey nkey) { key = nkey; }
    Tvalue& GetValue() { return value; }
    Tkey& GetKey() { return key; }
    bool operator>(Pair other) { return key > other.key; }
    bool operator<(Pair other) { return key < other.key; }
    bool operator==(Pair other) { return key == other.key; }
    bool operator>=(Pair other) { return key >= other.key; }
    bool operator<=(Pair other) { return key <= other.key; }
    friend ostream& operator<<(ostream& out, const Pair p);
};
template <typename Tkey, typename Tvalue>
ostream& operator<<(ostream& out, const Pair<Tkey, Tvalue> p)
{
    out << p.GetKey() + " Value: " << p.GetValue();
    return out;
    /*if (c.Im > 0) out << to_string(c.Re) + "+" + to_string(c.Im) + "i";
    else out << to_string(c.Re) + to_string(c.Im) + "i";
    return out;*/
}

//template <typename T>
ISortedSequence<Pair<string, long>>* GreedyArranger(ISortedSequence<Pair<string, long>>* sec, size_t lenofpage)
{
    int lenofarray = sec->GetLenght();
    int numofunarranged = lenofarray;
    for (int i = 0; i < lenofarray; i++)
    {
        if (sec->Get(i).GetValue() > lenofpage) sec->Get(i).SetValue(-1);
        else sec->Get(i).SetValue(1);
        if (sec->Get(i).GetValue() <= 0) numofunarranged--;
    }
    ISortedSequence<Pair<string, long>>* res = new ArraySortedSequence<Pair<string, long>>(numofunarranged);
    int numofpage = 0, numofword = 0;
    while (numofunarranged > 0)
    {
        //sec->Sort();
        //cout << "Оставшиеся слова: " << numofunarranged << endl;
        int leftspace = lenofpage;
        numofpage++;
        if (numofpage == 1) leftspace /= 2;
        if (numofpage % 10 == 0) leftspace = 3 * leftspace / 4;
        for (int i = 0; i < lenofarray; i++)
        {
            if (sec->Get(i).GetValue() > 0) if (sec->Get(i).GetKey().size() <= leftspace)
            {
                leftspace -= sec->Get(i).GetKey().size();
                res->Set(numofword, Pair<string, long>(sec->Get(i).GetKey(), numofpage));
                numofword += 1;
                sec->Get(i).SetValue(-1);
                numofunarranged -= 1;
                break;
            }
        }
        if (leftspace != 0) for (int i = 0; i < lenofarray; i++)
        {
            if (sec->Get(i).GetValue() > 0) if (sec->Get(i).GetKey().size() + 1 <= leftspace)
            {

                leftspace -= sec->Get(i).GetKey().size() + 1;
                if (leftspace == 0) break;
                sec->Get(i).SetValue(-1);
                res->Set(numofword, Pair<string, long>(sec->Get(i).GetKey(), numofpage));
                numofword += 1;
                numofunarranged -= 1;
                i = 0;
            }
        }

    }
    //delete sec;
    return res;
}

//template <typename T>
int interfaceAPointer()
{
    int choice1 = -1, choice2 = -1, choice3 = -1, lenofpage = -1, maxrandlen = 50000, minrandlen = 5000;
    //ISortedSequence<char>* text = new ArraySortedSequence<char>();
    string text;
    while (1)
    {
        cout << "Выберите способ ввода текста(0 для возврата):\n1. Случайный.\n2. Из файла.\n3. Ручной.\n";
        cin >> choice1;
        if (choice1 == 1)
        {
            int len = 0;
            /*cout << "Введите длинну случайного массива символов: ";
            cin >> len;
            if (len < 0)
            {
                printerror();
                continue;
            }*/
            len = rand(minrandlen, maxrandlen);
            //string temp;
            //temp.reserve(len);
            text = GenRandomString(len);
            //text->Resize(len);
            /*for (int i = 0; i < len; i++)
            {
                text->Get(i) = temp[i];
            }
            temp.clear();*/
            break;
        }
        else if (choice1 == 2)
        {
            string temp, path, temp1;
            cout << "Введите название файла(формата txt): ";
            cin >> path;
            ifstream in(path);
            if (!in.is_open())
            {
                printerror();
                continue;
            }
            getline(in, text);
            /*while (getline(in, text))
            {
                temp += temp1;
                temp1.clear();
            }*/
            int len = temp.length();
            /*text->Resize(len);
            for (int i = 0; i < len; i++)
            {
                text->Get(i) = temp[i];
            }*/
            break;
        }
        else if (choice1 == 3)
        {
            cout << "Введите строку: \n";
            //string temp;
            getline(cin, text);
            int len = text.length();
            /*text->Resize(len);
            for (int i = 0; i < len; i++)
            {
                text->Get(i) = temp[i];
            }
            temp.clear();*/
            break;
        }
        else if (choice1 != 0)
        {
            printerror();
        }
        else
        {
            return 0;
        }
    }
    cout << "Введённый текст: \n" << text << endl;;
    cout << "Длинна: " << text.length() << endl;
    /*string path;
    cout << "Введите название файла для записи: ";
    cin >> path;
    ofstream out(path, ios_base::out);
    out << text->GetArr();*/
    int type = -1;
    while (1)
    {
        cout << "Выберите формат размера страницы:\n1. Буквы.\n2. Слова.\n";
        type = -1;
        cin >> type;
        if (type != 1 && type != 2)
        {
            printerror();
            continue;
        }
        break;
    }
    while (1)
    {
        if (type == 1)
        {
            cout << "Введите размер страницы в буквах: ";
            cin >> lenofpage;
            if (lenofpage <= 0)
            {
                printerror();
                continue;
            }
            break;
        }
        else if (type == 2)
        {
            cout << "Введите размер страницы в словах: ";
            cin >> lenofpage;
            if (lenofpage <= 0)
            {
                printerror();
                continue;
            }
            break;
        }
    }
    stringstream str(text);
    string word;
    int len_temp = 0;
    while (getline(str, word, ' '))
    {
        if (word.length() != 0)
        {
            len_temp += 1;
        }
        word.clear();
    }
    str.clear();
    stringstream str1(text);
    ISortedSequence<Pair<string, long>>* arrayoftexts = new ArraySortedSequence<Pair<string, long>>(len_temp);
    int i = 0;
    while (getline(str1, word, ' '))
    {
        if (word.length() != 0)
        {
            arrayoftexts->Get(i) = Pair<string, long>(word, word.length()/* * -1*/);
            i++;
        }

        word.clear();
    }
    arrayoftexts->Sort();

    //for (int i = 0; i < arrayoftexts->GetLenght(); i++)
    //{
    //    //(arrayoftexts->Get(i)).GetValue() *= -1;
    //    cout << (arrayoftexts->Get(i)).GetKey() << endl;
    //}
    ISortedSequence<Pair<string, long>>* arrangedarray = new ArraySortedSequence<Pair<string, long>>(arrayoftexts->GetLenght());
    if (type == 1)
    {
        delete arrangedarray;
        arrangedarray = GreedyArranger(arrayoftexts, lenofpage);
    }
    else if (type == 2)
    {
        int numofword = 0, numofpage = 1, templenofpage = 0;
        while (1)
        {
            if (numofpage == 1) templenofpage = lenofpage / 2;
            else if (numofpage % 10 == 0) templenofpage = 3 * lenofpage / 4;
            else templenofpage = lenofpage;
            for (int j = 0; j < templenofpage; j++)
            {
                if (numofword < arrayoftexts->GetLenght())
                {
                    arrangedarray->Get(numofword) = arrayoftexts->Get(numofword);
                    (arrangedarray->Get(numofword)).SetValue(numofpage);
                    numofword++;
                }
                else
                {
                    break;
                }
            }
            if (numofword >= arrayoftexts->GetLenght())
            {
                break;
            }
            numofpage++;
        }
    }
    for (int i = 0; i < arrangedarray->GetLenght(); i++)
    {
        if (arrangedarray->Get(i).GetValue() == -1)
        {
            cout << "Слово: " << arrangedarray->Get(i).GetKey() << " Не попало ни в 1 страницу" << endl;
        }
        else
        {
            cout << "Слово: " << arrangedarray->Get(i).GetKey() << " Страница: " << arrangedarray->Get(i).GetValue() << endl;
        }
    }
    //delete text;
    delete arrayoftexts;
    delete arrangedarray;
}

template <typename Tkey, typename Tvalue>
class IDictionary
{
    //private:
    //    ISortedSequence<Pair<Tkey, Tvalue>> self;
public:
    virtual Tvalue GetValue(Tkey key) = 0;
    virtual Tvalue operator[](Tkey key) = 0;
    virtual void add(Tkey key, Tvalue value) = 0;
    //virtual void del(Tkey key) = 0;
};

template <typename Tkey, typename Tvalue>
class dict : IDictionary<Tkey, Tvalue>
{
private:
    ISortedSequence<Pair<Tkey, Tvalue>> self;
public:
    dict()
    {
        self = ArraySortedSequence<Pair<Tkey, Tvalue>>();
    }
    Tvalue GetValue(Tkey key) override
    {
        for (int i = 0; i < self.GetLenght(); i++)
        {
            if (self.Get(i).GetKey() == key) return self.Get(i).GetValue();
        }
        return Tvalue(); //не найдено по ключу
    }
    Tvalue operator[](Tkey key) override
    {
        return this->GetValue(key);
    }
    void add(Tkey key, Tvalue value) override
    {
        for (int i = 0; i < self.GetLenght(); i++)
        {
            if (self.Get(i).GetKey() == key) self.Get(i).SetValue(value);
        }
        self.Append(Pair<Tkey, Tvalue>(key, value));
    }

    /*void del(Tkey key, Tvalue, value) override
    {
        for (int i = 0; i < self.GetLenght(); i++)
        {
            if (self.Get(i).GetKey() == key) self.
        }
    }*/
};



template <typename Tkey, typename Tvalue>
class Cache
{
private:

    template <typename KEY, typename VALUE>
    class CacheNode
    {
    public:
        KEY key;
        VALUE value;
        CacheNode* prev, * next;
        CacheNode(KEY k, VALUE v)
        {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    size_t capacity, size;
    CacheNode<Tkey, Tvalue>* start, * end;
public:
    Cache(size_t cap)
    {
        capacity = cap;
        size = 0;
        start = nullptr;
        end = nullptr;
    }
    void remove(Tkey key)
    {
        if (start != nullptr)
        {
            CacheNode<Tkey, Tvalue>* temp = start;
            while (temp != nullptr)
            {
                if (temp->key == key)
                {
                    size--;
                    if (temp->prev != nullptr)
                    {
                        temp->prev->next = temp->next;
                    }
                    else
                    {
                        start = temp->next;
                    }
                    if (temp->next != nullptr)
                    {
                        temp->next->prev = temp->prev;
                    }
                    else
                    {
                        end = temp->prev;
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
    void Prepend(Tkey key, Tvalue value)
    {
        size++;
        CacheNode<Tkey, Tvalue>* nstart = new CacheNode<Tkey, Tvalue>(key, value);
        nstart->next = start;
        nstart->prev = nullptr;
        if (start != nullptr)
        {
            start->prev = nstart;
        }
        start = nstart;
        if (end == nullptr)
        {
            end = start;
        }
    }
    Tvalue Get(Tkey key)
    {
        if (start != nullptr)
        {
            CacheNode<Tkey, Tvalue>* temp = start;
            while (temp->key != key)
            {
                if (temp->next != nullptr) temp = temp->next;
                else return NULL;
            }
            this->remove(temp->key);
            this->Prepend(temp->key, temp->value);
            return temp->value;
        }
    }

    void Set(Tkey key, Tvalue value)
    {
        if (start != nullptr)
        {
            size++;
            bool found = false;
            CacheNode<Tkey, Tvalue>* temp = start;
            while (temp->key != key)
            {
                if (temp->next != nullptr) temp = temp->next;
                else break;
            }
            found = (temp->key == key);
            if (found)
            {
                //CacheNode<Tkey, Tvalue>*temp1 = temp->
                //temp->value = value;
                this->remove(key);
                this->Prepend(key, value);
            }
            else
            {
                size--;
                if (size >= capacity)
                {
                    this->remove(end->key);
                }
                this->Prepend(key, value);
            }
        }
        else
        {
            this->Prepend(key, value);
        }
    }

};

template <typename T>
void testcache(int size)
{
    while (1)
    {
        auto cache = Cache<T, int>(size);
        cout << "выберите тип теста: \n1. Ручной.\n 2. Случайный.\n";
        int testtype = -1;
    }
}

void interfaceCache()
{
    while (1)
    {
        cout << "Выюберите тип данных для тестирования кеширования(0 для возврата):\n1. Целые числа.\n2 Дробные числа.\n3. Комплексные числа.\n4. Человек.\n";
        int type = -1;
        cin >> type;
        cout << "Введите размер кеша: ";
        int cachesize = -1;
        cin >> cachesize;
        if (cachesize <= 0)
        {
            printerror();
            continue;
        }
        if (type == 1)
        {
            testcache<int>(cachesize);
        }
        else if (type == 2)
        {
            testcache<double>(cachesize);
        }
        else if (type == 3)
        {
            testcache<mycomplex>(cachesize);
        }
        else if (type == 4)
        {
            //testcache<Person>(cachesize);
        }
        else if (type != 0)
        {
            printerror();
            continue;
        }
        else break;
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    while (1)
    {
        cout << "Выберите задачу(введите 0 для выхода из программы):\n1. Работа с разреженными матрицами.\n2. Построение алфавитного указателя.\n3. Кэширование данных.\n";
        int choice0 = -1;
        cin >> choice0;
        if (choice0 == 1)
        {
            while (1)
            {
                cout << "Выберите тип данных для работы(введите 0 для выбора другой задачи):\n1. Целые\n2. Дробные.\n3. Комплексные.\n"; //\n6. string.
                int choice1 = -1;
                cin >> choice1;
                if (choice1 == 1)
                {
                    interfacesparce<int>();
                }
                else if (choice1 == 2)
                {
                    interfacesparce<double>();
                }
                else if (choice1 == 3)
                {
                    interfacesparce<mycomplex>();
                }
                else if (choice1 == 0) break;
                else
                {
                    cout << "Неверный ввод\n";
                    cin.clear();
                    while (cin.get() != '\n');
                }
            }
        }
        else if (choice0 == 2)
        {
            while (1)
            {
                interfaceAPointer();
                break;
                //cout << "Выберите тип данных для работы(введите 0 для выбора другой задачи):\n1. Целые\n2. Дробные.\n3. Комплексные.\n"; //\n6. string.
                //int choice1 = -1;
                //cin >> choice1;
                //if (choice1 == 1)
                //{
                //    interfaceAPointer<int>();
                //}
                //else if (choice1 == 2)
                //{
                //    interfaceAPointer<double>();
                //}
                //else if (choice1 == 3)
                //{
                //    interfaceAPointer<mycomplex>();
                //}
                //else if (choice1 == 0) break;
                //else
                //{
                //    cout << "Неверный ввод\n";
                //    cin.clear();
                //    while (cin.get() != '\n');
                //}
            }
        }
        if (choice0 == 3)
        {
            interfaceCache();
            break;
        }
        else if (choice0 == 0) break;
        else
        {
            cout << "Неверный ввод\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    }
    return 0;
}

