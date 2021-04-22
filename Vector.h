#include <bits/stdc++.h>

using namespace std;

namespace UTEC {
    class Vector {

    private:
        pair<int, int> *data;
        int nelementos;

    public:
        Vector();

        Vector(int);

        virtual ~Vector();

        int size();

        void push_back(pair<int, int>);

        int operator[](int);

        vector<pair<pair<int, int>, double>> knn_vecinos(pair<int, int>, int);

        void ImprimirVector(){

            for (auto i = 0; i < this->size(); i++)
            {
                cout << this->data[i].first << " " << this->data[i].second << endl;
            }

        }
    };
}

