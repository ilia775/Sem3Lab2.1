#pragma once
#include <string>
#include <sstream>
using namespace std;
template<typename T>
class BinaryTree
{
public:

    BinaryTree()
    {
        LeftRoot = RightRoot = nullptr;
        Data = nullptr;
    }
    BinaryTree(BinaryTree<T>* other)
    {
        int len = other->GetSize();
        T* mass = new T[len];
        other->GetMass(mass);
        for (int i = 0; i < len; i++)
        {
            this->Insert(mass[i]);
        }
    }

    ~BinaryTree()
    {
        if (Data != nullptr) delete Data;
        if (LeftRoot != nullptr) delete LeftRoot;
        if (RightRoot != nullptr) delete RightRoot;
    }

    T& GetData()
    {
        return *Data;
    }

    BinaryTree<T>* GetLeftRoot()
    {
        return LeftRoot;
    }

    int GetMaxLVL()
    {
        static int LVL = 0;
        if (this == NULL) return LVL;
        return max(this->LeftRoot->GetMaxLVL(), this->RightRoot->GetMaxLVL());
    }

    int GetMinLVL()
    {
        static int LVL = 0;
        if (this == NULL) return LVL;
        return min(this->LeftRoot->GetMinLVL(), this->RightRoot->GetMinLVL());
    }

    BinaryTree<T>* DeleteElem(T elem)
    {
        int len = this->GetSize();
        T* mass = new T[len];
        this->GetMass(mass);
        BinaryTree<T>* newtree = new BinaryTree<T>();
        for (int i = 0; i < len; i++)
        {
            if (!(mass[i] == elem))
            {
                newtree->Insert(mass[i]);
            }
        }
        delete this;
        return newtree;
    }

    /*void DeleteElem(int value)
    {
        if (node == NULL)
            return;
        if (value < *this->Data)
            return this->LeftRoot->DeleteElem(value);
        else if (value > node->value)
            return this->RightRoot->DeleteElem(value);
        else {
            if (this->LeftRoot == NULL && this->RightRoot == NULL) {
                if (node->parent->leftChild == node)
                    node->parent->leftChild = NULL;
                else
                    node->parent->rightChild = NULL;
                delete node;
            }
            else {
                BinaryTreeNode* newnode = NULL;
                if (node->leftChild != NULL) {
                    newnode = Rightmost(node->leftChild);
                }
                else
                    newnode = Leftmost(node->rightChild);
                if (node->parent->leftChild == node)
                    node->parent->leftChild = newnode;
                else
                    node->parent->rightChild = newnode;
                newnode->parent = node->parent;
                newnode->rightChild = node->rightChild;
                newnode->leftChild = node->leftChild;
                delete node;
            }
        }
    }
    BinaryTree<T>* Leftmost() {
        if (this == NULL)
            return NULL;
        if (this->LeftRoot != NULL) {
            return Leftmost(this->LeftRoot);
        }
        return node;
    }
    BinaryTree<T>* Rightmost() {
        if (this == NULL)
            return NULL;
        if (this->RightRoot != NULL) {
            return Rightmost(this->RightRoot);
        }
        return node;
    }*/

    /*void BlanceTree()
    {
        int len = this->GetSize();
        T* mass = new T[len];
        this->GetMass(mass);
        sort_arr<T>(mass, len);
        BinaryTree<T>* newtree = GenBalancedTree(mass, len);
        delete this;
        this = newtree;
    }*/

    BinaryTree<T>* GetRightRoot()
    {
        return RightRoot;
    }



    BinaryTree<T>* GetLeftSubTree()
    {
        if (LeftRoot == nullptr) LeftRoot = new BinaryTree<T>();
        return LeftRoot;
    }

    BinaryTree<T>* GetRightSubTree()
    {
        if (RightRoot == nullptr) RightRoot = new BinaryTree<T>();
        return RightRoot;
    }

    BinaryTree(T* mass, int len)
    {
        for (int i = 0; i < len; i++)
        {
            this->Insert(mass[i]);
        }
    }

    BinaryTree(T* mass, long long len)
    {
        for (long long i = 0; i < len; i++)
        {
            this->Insert(mass[i]);
        }
    }

    BinaryTree(string String, string type = "RootLeftRight")
    {
        if (type == "LeftRightRoot")
        {

        }
        else if (type == "RightLeftRoot")
        {

        }
        else if (type == "LeftRootRight")
        {

        }
        else if (type == "RightRootLeft")
        {

        }
        //else if (type == "RootRightLeft")
        //{
        //    {
        //        while (1)
        //        {
        //            istringstream iss(String);
        //            string temp_s;
        //            string res;
        //            string* mass = new string[iss.str().length()]();
        //            getline(iss, temp_s, '\"');
        //            getline(iss, temp_s, '\"');
        //            for (int i = 0;; i++)
        //            {
        //                mass[i] = temp_s;
        //                getline(iss, temp_s, '\"');
        //                if (temp_s == string())
        //                {
        //                    mass->resize(i + 1);
        //                    break;
        //                }
        //            }
        //            int i1 = 0, i2 = 0;
        //            for (int i = 0;; i++)
        //            {
        //                if (mass[i] > mass[0])
        //            }
        //            string root = temp_s;
        //            getline(iss, temp_s, '\"');
        //            /*void* temp_t = new T();
        //            if (typeid(T).name() == typeid(double).name())
        //            {
        //                *(T*)temp_t = T(atof(temp_s.c_str()));
        //            }
        //            if (typeid(T).name() == typeid(string).name())
        //            {
        //                *(string*)temp_t = string(temp_s);
        //            }
        //            if (typeid(T).name() == typeid(Student).name())
        //            {
        //                *(Student*)temp_t = Student(temp_s);
        //            }
        //            if (typeid(T).name() == typeid(Teacher).name())
        //            {
        //                *(Teacher*)temp_t = Teacher(temp_s);
        //            }*/
        //        }
        //        istringstream iss(String);
        //        string temp_s;
        //        getline(iss, temp_s, '\"');
        //        getline(iss, temp_s, '\"');
        //        while (temp_s != string())
        //        {
        //            void* temp_t = new T();
        //            //cout << typeid(T).name()<<"  "<< atof(temp_s.c_str()) << endl;
        //            if (typeid(T).name() == typeid(double).name())
        //            {
        //                *(T*)temp_t = T(atof(temp_s.c_str()));
        //            }
        //            if (typeid(T).name() == typeid(string).name())
        //            {
        //                *(string*)temp_t = string(temp_s);
        //            }
        //            if (typeid(T).name() == typeid(Student).name())
        //            {
        //                *(Student*)temp_t = Student(temp_s);
        //            }
        //            if (typeid(T).name() == typeid(Teacher).name())
        //            {
        //                *(Teacher*)temp_t = Teacher(temp_s);
        //            }
        //            else T temp_t = T(atoi(temp_s.c_str()));
        //            this->Insert(*(T*)temp_t);
        //            getline(iss, temp_s, '\"');
        //        }
        //    }
        //}
        else if (type == "RootLeftRight")
        {
            istringstream iss(String);
            string temp_s;
            getline(iss, temp_s, '\"');
            getline(iss, temp_s, '\"');
            while (temp_s != string())
            {
                void* temp_t = new T();
                //cout << typeid(T).name()<<"  "<< atof(temp_s.c_str()) << endl;
                if (typeid(T).name() == typeid(double).name())
                {
                    *(T*)temp_t = atof(temp_s.c_str());
                }
                if (typeid(T).name() == typeid(string).name())
                {
                    *(string*)temp_t = string(temp_s);
                }
                else *(T*)temp_t = atoi(temp_s.c_str());
                this->Insert(*(T*)temp_t);
                getline(iss, temp_s, '\"');
            }
        }
        else cout << "ERROR Incorrect type  \"StringToTree\"  type: " + type << endl;
    }
    void Bypass(string type = "RootLeftRight")
    {
        if (type == "LeftRightRoot") this->BypassLeftRightRoot();
        else if (type == "RightLeftRoot") this->BypassRightLeftRoot();
        else if (type == "LeftRootRight") this->BypassLeftRootRight();
        else if (type == "RightRootLeft") this->BypassRightRootLeft();
        else if (type == "RootRightLeft") this->BypassRootRightLeft();
        else if (type == "RootLeftRight") this->BypassRootLeftRight();
        else cout << "ERROR Incorrect type  \"Bypass\"  type: " + type << endl;
    }

    int GetSize()
    {
        istringstream iss(this->ToString());
        string temp_s;
        getline(iss, temp_s, '\"');
        getline(iss, temp_s, '\"');
        int i = 0;
        while (temp_s != string())
        {
            i++;
            getline(iss, temp_s, '\"');
        }
        return i;
    }

    BinaryTree<T>* GetSubTreeFromPath(string path)
    {
        if (path.length() == 0 || path[0] == '\n')
        {
            int len = this->GetSize();
            T* mass = new T[len];
            this->GetMass(mass);
            BinaryTree<T>* newtree = new BinaryTree<T>(this);
            return newtree;
        }
        if (path[0] == 'r')
        {
            if (RightRoot == nullptr) return NULL;
            string path1 = string();
            int len = (int)path.length();
            path1.resize(len - 1);
            for (int i = 1; i < len; i++)
            {
                path1[i - 1] = path[i];
            }
            return RightRoot->GetSubTreeFromPath(path1);
        }
        if (path[0] == 'l')
        {
            if (LeftRoot == nullptr) return NULL;
            string path1 = string();
            int len = (int)path.length();
            path1.resize(len - 1);
            for (int i = 1; i < len; i++)
            {
                path1[i - 1] = path[i];
            }
            return LeftRoot->GetSubTreeFromPath(path1);
        }
        return NULL;
    }

    BinaryTree<T>* GetSubTree(T num)
    {
        if (num == *Data)
        {

            int len = this->GetSize();
            T* mass = new T[len];
            this->GetMass(mass);
            BinaryTree<T>* newtree = new BinaryTree<T>(this);
            return newtree;
        }
        if (num > *Data)
        {
            if (RightRoot == nullptr) return NULL;
            return RightRoot->GetSubTree(num);
        }
        if (num < *Data)
        {
            if (LeftRoot == nullptr) return NULL;
            return LeftRoot->GetSubTree(num);
        }
        return NULL;
    }


    void GetMass(T* mass, int* size = new int())
    {
        if (this != NULL)
        {
            if (Data != nullptr)
            {
                mass[*size] = *this->Data;
                (*size)++;
                RightRoot->GetMass(mass, size);
                LeftRoot->GetMass(mass, size);
            }
        }
    }
    void Insert(T item)
    {

        if (Data == nullptr)
        {
            Data = new T(item);
        }
        else
        {
            if (item > *Data)
            {
                if (RightRoot == nullptr) RightRoot = new BinaryTree<T>();
                RightRoot->Insert(item);
            }
            else if (item < *Data)
            {
                if (LeftRoot == nullptr) LeftRoot = new BinaryTree<T>();
                LeftRoot->Insert(item);
            }
            //else cout << "ERROR: item == root \"InsertRootLeftRight\""<<endl;
        }

    }

    void Insert(BinaryTree<T>* node)
    {
        if (node != NULL)
        {

            if (Data == nullptr)
            {
                Data = &node->GetData();
                LeftRoot = node->GetLeftSubTree();
                RightRoot = node->GetRightSubTree();
            }
            else
            {
                if (node->GetData() > *Data)
                {
                    if (RightRoot == nullptr) RightRoot = new BinaryTree<T>();
                    RightRoot->Insert(node);
                }
                else if (node->GetData() < *Data)
                {
                    if (LeftRoot == nullptr) LeftRoot = new BinaryTree<T>();
                    LeftRoot->Insert(node);
                }
            }
        }
    }

    bool operator==(BinaryTree<T>* other)
    {
        if (this == NULL && other == NULL)
            return true;
        else if (this == NULL || other == NULL)
            return false;
        else {
            if (*this->Data == *other->Data && this->LeftRoot->operator==(other->LeftRoot) && this->RightRoot->operator==(other->RightRoot))
                return true;
            else
                return false;
        }
    }

    /*bool CheckElement(T val)
    {
        string s1 = " " + this->ToString("RootLeftRight");
        return (s1.find(to_string(val)) > 0);
    }*/

    bool CheckElement(T val)
    {
        if (Data == nullptr) return 0;
        if (val == *Data) return true;
        if (val > *Data) return this->RightRoot->CheckElement(val);
        if (val < *Data) return this->LeftRoot->CheckElement(val);
    }

    bool CheckSubTree(BinaryTree<T>* other)
    {
        string s1 = string(), s2 = string();
        s1 = this->ToString("RootLeftRight");
        s2 = other->ToString("RootLeftRight");
        if (s1.find(s2) != string::npos)
        {
            return true;
        }
        return false;
    }

    string ToString(string type = "RootLeftRight", int mode = 0)
    {
        string temp = "";
        if (type == "LeftRightRoot")
        {
            this->ToStringLeftRightRoot(temp, mode);
            //return temp;
        }
        else if (type == "RightLeftRoot")
        {
            this->ToStringRightLeftRoot(temp, mode);
            //return temp;
        }
        else if (type == "LeftRootRight")
        {
            this->ToStringLeftRootRight(temp, mode);
            //return temp;
        }
        else if (type == "RightRootLeft")
        {
            this->ToStringRightRootLeft(temp, mode);
            //return temp;
        }
        else if (type == "RootRightLeft")
        {
            this->ToStringRootRightLeft(temp, mode);
            //return temp;
        }
        else if (type == "RootLeftRight")
        {
            this->ToStringRootLeftRight(temp, mode);
            //return temp;
        }
        else cout << "ERROR Incorrect type  \"ToString\"  type: " + type << endl;
        temp += "\"";
        return temp;
    }

    void Print(int lv = 0)
    {
        if (this != nullptr) if (Data != nullptr)
        {
            this->LeftRoot->Print(lv + 1);
            for (int i = 0; i < lv; i++)
            {
                cout << "   ";
            }
            cout << *Data << endl;
            this->RightRoot->Print(lv + 1);
        }
    }

    /*bool CheckSubTree(const BinaryTree<T>* other)
    {
        while (1)
        {
            if (other->Root > this->Root)
            {
                return this->RightRoot->CheckSubTree(other);
                break;
            }
            if (other->Root < this->Root)
            {
                return this->LeftRoot->CheckSubTree(other);
                break;
            }
            if (other->Root == this->Root)
            {
                if (this->LeftRoot != nullptr) return (this->RightRoot->CheckSubTree(other->RightRoot) && this->LeftRoot->CheckSubTree(other->LeftRoot));
                break;
            }
        }
    }
    bool operator== (const BinaryTree<T>* other)
    {
        if (this->Root == other->Root && this->LeftRoot == other->LeftRoot && this->RightRoot == other->RightRoot) return true;
        return false;
    }*/

private:

    /*void InsertRootLeftRight(T item)
    {
        if (root == nullptr)
        {
            root = new T(item);
        }
        else
        {
            if (item > *root) RightRoot->InsertRootLeftRight(item);
            else if (item < *root) LeftRoot->InsertRootLeftRight(item);
            else cout << "ERROR: item = root \"InsertRootLeftRight\"";
        }
    }
    void InsertRootRightLeft(T item)
    {
        if (root == nullptr)
        {
            root = new T(item);
        }
        else
        {
            if (item < *root) RightRoot->InsertRootLeftRight(item);
            else if (item > *root) LeftRoot->InsertRootLeftRight(item);
            else cout << "ERROR: item = root \"InsertRootLeftRight\"";
        }
    }
    void InsertRightRootLeft(T item)
    {
        if (RightRoot == nullptr)
        {
            RightRoot->root = new T(item);
        }
        else
        {
            if (item > *RightRoot->root) this->InsertRightRootLeft(item);
        }
    }*/

    void BypassRootLeftRight()
    {
        if (this != nullptr)
        {
            cout << *Data << endl;
            LeftRoot->BypassRootLeftRight();
            RightRoot->BypassRootLeftRight();
        }
    }

    void BypassRootRightLeft()
    {
        if (this != nullptr)
        {
            cout << *Data << endl;
            RightRoot->BypassRootRightLeft();
            LeftRoot->BypassRootRightLeft();
        }
    }

    void BypassRightRootLeft()
    {
        if (this != nullptr)
        {
            RightRoot->BypassRightRootLeft();
            cout << *Data << endl;
            LeftRoot->BypassRightRootLeft();
        }
    }

    void BypassLeftRootRight()
    {
        if (this != nullptr)
        {
            LeftRoot->BypassLeftRootRight();
            cout << *Data << endl;
            RightRoot->BypassLeftRootRight();
        }
    }

    void BypassRightLeftRoot()
    {
        if (this != nullptr)
        {
            RightRoot->BypassRightLeftRoot();
            LeftRoot->BypassRightLeftRoot();
            cout << *Data << endl;
        }
    }

    void BypassLeftRightRoot()
    {
        if (this != nullptr)
        {
            LeftRoot->BypassLeftRightRoot();
            RightRoot->BypassLeftRightRoot();
            cout << *Data << endl;
        }

    }

    void ToStringRootLeftRight(string& temp, int mode = 0)
    {
        if (this != nullptr && this != NULL)
        {
            if (Data != nullptr && Data != NULL)
            {
                temp += "\"";
                temp += to_string(*Data);
                //temp += " ";
                LeftRoot->ToStringRootLeftRight(temp, mode);
                RightRoot->ToStringRootLeftRight(temp, mode);
            }
        }
        else if (mode == 1)
        {
            temp += "\"";
            temp += "NULL";
            //temp += " ";
        }
    }

    void ToStringRootRightLeft(string& temp, int mode = 0)
    {
        if (this != nullptr)
        {
            temp += "\"";
            temp += to_string(*Data);
            //temp += " ";
            RightRoot->ToStringRootRightLeft(temp, mode);
            LeftRoot->ToStringRootRightLeft(temp, mode);
        }
        else if (mode == 1)
        {
            temp += "\"";
            temp += "NULL";
            //temp += " ";
        }
    }

    void ToStringRightRootLeft(string& temp, int mode = 0)
    {
        if (this != nullptr)
        {
            RightRoot->ToStringRightRootLeft(temp, mode);
            temp += "\"";
            temp += to_string(*Data);
            //temp += " ";
            LeftRoot->ToStringRightRootLeft(temp, mode);
        }
        else if (mode == 1)
        {
            temp += "\"";
            temp += "NULL";
            //temp += " ";
        }
    }

    void ToStringLeftRootRight(string& temp, int mode = 0)
    {
        if (this != nullptr)
        {
            LeftRoot->ToStringLeftRootRight(temp, mode);
            temp += "\"";
            temp += to_string(*Data);
            //temp += " ";
            RightRoot->ToStringLeftRootRight(temp, mode);
        }
        else if (mode == 1)
        {
            temp += "\"";
            temp += "NULL";
            //temp += " ";
        }
    }

    void ToStringRightLeftRoot(string& temp, int mode = 0)
    {
        if (this != nullptr)
        {
            RightRoot->ToStringRightLeftRoot(temp, mode);
            LeftRoot->ToStringRightLeftRoot(temp, mode);
            temp += "\"";
            temp += to_string(*Data);
            //temp += " ";
        }
        else if (mode == 1)
        {
            temp += "\"";
            temp += "NULL";
            //temp += " ";
        }
    }

    void ToStringLeftRightRoot(string& temp, int mode = 0)
    {
        if (this != nullptr)
        {
            LeftRoot->ToStringLeftRightRoot(temp, mode);
            RightRoot->ToStringLeftRightRoot(temp, mode);
            temp += "\"";
            temp += to_string(*Data);
            //temp += " ";
        }
        else if (mode == 1)
        {
            temp += "\"";
            temp += "NULL";
            //temp += " ";
        }
    }

    T* Data;
    BinaryTree* LeftRoot;
    BinaryTree* RightRoot;
};
