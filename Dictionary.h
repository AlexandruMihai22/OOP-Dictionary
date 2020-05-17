#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

template<class K>
class KeyComp
{
public:
    bool operator()(const K &key1, const K &key2)
    {
        return key1 == key2;
    }
};

template<>
class KeyComp<string>
{
public:
    bool operator()(const string &s1, const string &s2)
    {
        int n = min(s1.size(), s2.size());
        for(int i = 0; i < n/2; i++)
            if(s1[i] != s2[i])
                return false;
        return true;
    }
};

template<class K, class V, class F = KeyComp<K> >
class Dictionary
{
private:
    vector<pair<K, V> > v;
    F comp;

public:
    Dictionary();
    Dictionary(const Dictionary &D);
    void operator=(const Dictionary &D);
    void Add(const K &key, const V &valoare);
    void Delete(const K &key);
    bool Search(const K &key);
    void Clear();
    V operator[](const K &key);
    friend ostream& operator<<(ostream &out, const Dictionary<K, V, F> &D)
    {
         for(int i = 0; i < D.v.size(); ++i)
            out << D.v[i].first <<" "<<D.v[i].second<<endl;
        return out;
    }
    virtual ~Dictionary();

};

template<class K, class V, class F>
Dictionary<K, V, F>::Dictionary()
{

}

template<class K, class V, class F>
Dictionary<K, V, F>::Dictionary(const Dictionary& D)
{
    v = D.v;
    comp = D.comp;
}

template<class K, class V, class F>
void Dictionary<K, V, F>::operator=(const Dictionary& D)
{
    v = D.v;
    comp = D.comp;
}

template<class K, class V, class F>
void Dictionary<K, V, F>::Add(const K &key, const V &valoare)
{
    bool OK = false;
    for(int i = 0; i < v.size(); ++i)
        if(comp(v[i].first, key))
        {
            v[i].second = valoare;
            OK = true;
            break;
        }
    if(!OK)
        v.push_back({key, valoare});
}

template<class K, class V, class F>
void Dictionary<K, V, F>::Delete(const K &key)
{
    for(int i = 0; i < v.size(); ++i)
        if(comp(v[i].first, key))
        {
            v.erase(v.begin()+i);
            break;
        }
}

template<class K, class V, class F>
bool Dictionary<K, V, F>::Search(const K &key)
{
    for(int i = 0; i < v.size(); ++i)
        if(comp(v[i].first, key))
            return true;
    return false;
}

template<class K, class V, class F>
void Dictionary<K, V, F>::Clear()
{
    v.clear();
}

template<class K, class V, class F>
V Dictionary<K, V, F>::operator[](const K &key)
{
    for(int i = 0; i < v.size(); ++i)
        if(comp(v[i].first, key))
            return v[i].second;
    return V();
}

template<class K, class V, class F>
Dictionary<K, V, F>::~Dictionary()
{

}

#endif // DICTIONARY_H

