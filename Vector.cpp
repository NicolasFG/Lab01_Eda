#include "Vector.h"



UTEC::Vector::Vector(): data{nullptr}, nelementos{0} {
}

UTEC::Vector::Vector(int n): nelementos{n} {
    data = new pair<int, int>[nelementos];
}

UTEC::Vector::~Vector() {
        delete[] data;
}

int UTEC::Vector::size() {
    return nelementos;
}


void UTEC:: Vector::push_back(pair<int, int> coordenada) {
    pair<int, int>* temp = new pair<int, int>[nelementos + 1];
    for (int i=0; i < nelementos; i++)
    {
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
    data[nelementos]=coordenada;
    nelementos++;

}

double distancia(pair<int, int> x, pair<int, int> y)
{
    double dist = sqrt(pow(y.first-x.first,2) + pow(y.second - x.second,2));
    return dist;
}

double max_distance(vector<pair<pair<int, int>, double>> vecinos, int &posicion)
{
    double maximo = 0;
    for(int i = 0; i < vecinos.size(); i++)
    {
        if(vecinos[i].second > maximo)
        {
            maximo = vecinos[i].second;
            posicion = i;
        }
    }
    return maximo;
}

vector<pair<pair<int, int>, double>> UTEC::Vector::knn_vecinos(pair<int, int> coordenada, int k)
{

    vector<pair<pair<int, int>, double>> vecinos;

    for(int i = 0; i < this->nelementos; i++)
    {
        if(vecinos.size() < k)
        {
            if(distancia(coordenada, data[i]) > 0) {
                vecinos.push_back(make_pair(data[i], distancia(coordenada, data[i])));
            }

        }

        else
        {

            double distance = distancia(coordenada, data[i]);
            int index = 0;
            if(distance < max_distance(vecinos, index))
            {
                if(distancia(coordenada, data[i]) > 0) {
                    vecinos[index] = make_pair(data[i], distance);
                }
            }
        }
    }

    return vecinos;
}

