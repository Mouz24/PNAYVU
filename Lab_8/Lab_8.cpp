#include <iostream>

using namespace std;

class ExceptionHandler : public logic_error
{
public:
    explicit ExceptionHandler(string message) : logic_error(message) {}
};

class NotFound : public ExceptionHandler
{
public:
    explicit NotFound() : ExceptionHandler("This node is not found") {}
};
class Dublicate : public ExceptionHandler
{
public:
    explicit Dublicate() : ExceptionHandler("This node already exists") {}
};

template<class mytype>class List {
    class Node {
    public:
        mytype data;
        Node* next;

        Node(mytype data) 
        { 
           this->data = data; 
        }
    };

    class Iterator
    {
    public:
        Iterator(Node* node) : m_node(node) {}

        bool operator==(const Iterator& other) const
        {
            /*if (this == &other)
            {
                return true;
            }*/

            return m_node == other.m_node;
        }

        bool operator!=(const Iterator& other) const
        {
            return !operator==(other);
        }

        mytype operator*() const
        {
            if (m_node)
            {
                return m_node->data;
            }

            return mytype();
        }

        void operator++()
        {
            if (m_node)
            {
                m_node = m_node->next;
            }
        }

        friend class List;

    private:
        Node* m_node;
    };

    Node* pbeg;
public:
    List() { pbeg = NULL; }

    ~List()
    {
        if (pbeg != NULL) {
            Node* pv = pbeg;

            do 
            {
                pv = pv->next;
                
                delete pbeg;
                
                pbeg = pv;
            } 
            while (pv != pbeg);
        }
    }
    
    Iterator begin()
    {
        return Iterator(pbeg);
    }

    Iterator end()
    {
        return Iterator(pbeg);
    }

    Node* Init(mytype d)
    {
        Node* pv = new Node(d);
        
        pbeg = pv;
        pbeg->next = pbeg;

        return pbeg;
    }

    Node* Add(mytype d)
    {
        Node* checkfordublicate = pbeg;
        Node* Dublicatenode = FindForAdding(d);

        do
        {
            if (checkfordublicate == Dublicatenode)
            {
                throw Dublicate();
            }

            checkfordublicate = checkfordublicate->next;
        } 
        while (checkfordublicate != pbeg);
        
        Node* pv = new Node(d);
        
        Node* p = pbeg->next;

        pbeg->next = pv;
        pv->next = p;

        return pv;
    }

    bool Remove(mytype key)
    {
        if (Node* pkey = Find(key)) {
            if (pkey == pbeg)
            {
                pbeg = pbeg->next;
            }
            else
            {
                Node* rab = pbeg;

                do
                {
                    if ((rab->next) == pkey)
                    {
                        break;
                    }

                    rab = rab->next;
                } while (rab != pbeg);

                rab->next = pkey->next;
            }

            delete pkey;

            return true;
        }

        return false;
    }

    Node* FindForAdding(mytype key)
    {
        Node* pv = pbeg;
        bool found = false;

        do
        {
            if ((pv->data) == key)
            {
                found = true;
                break;
            }

            pv = pv->next;
        } 
        while (pv != pbeg);

        if (found)
        {
            return pv;
        }
    }

    Node* Find(mytype key)
    {
        Node* pv = pbeg;
        bool found = false;

        do
        {
            if ((pv->data) == key)
            {
                found = true;
                break;
            }

            pv = pv->next;
        } 
        while (pv != pbeg);

        if (!found)
        {
            throw NotFound();
        }
        else
        {
            return pv;
        }
    }

    Node* Insert(mytype key, mytype d)
    {
        if (Node* pkey = Find(key))
        {
            Node* pv = new Node(d);

            pv->next = pkey->next;

            pkey->next = pv;

            return pv;
        }
    }

    void Print()
    {
        cout << "List: ";

        Iterator it = begin();
        do
        {
            cout << *it << ' ';

            ++it;
        } 
        while (it != end());

        cout << endl;
    }
};

int main()
{
    try
    {
            List<int> list1;
            list1.Init(2);
            list1.Add(3);
            list1.Add(4);
            list1.Print();
            cout << "Found: " << list1.Find(3)->data << endl;
            list1.Remove(3);
            //cout << "Found: " << list1.Find(3)->data << endl;
            list1.Print();

            cout << endl;
            
            List<float> list2;
            list2.Init(2.5);
            list2.Add(3.1);
            list2.Add(4.5);
            list2.Print();
            cout << "Found: " << list2.Find(3.1)->data << endl;
            list2.Remove(3.1);
            cout << "Found: " << list2.Find(4.5)->data << endl;
            list2.Print();

            cout << endl;

            List<char> list3;
            list3.Init('b');
            list3.Add('r');
            list3.Add('a');
            list3.Add('t');
            list3.Print();
            cout << "Found: " << list3.Find('a')->data << endl;
            list3.Remove('a');
            //cout << "Found: " << list3.Find('a')->data << endl;
            list3.Print();

            cout << endl;
    }
    catch (ExceptionHandler ex)
    {
        cout << ex.what();
    }
}