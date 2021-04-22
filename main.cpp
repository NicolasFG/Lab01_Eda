#include <iostream>
#include "Vector.h"
#include <fstream>
#include <string>

#include <chrono>
using namespace std::chrono;



using namespace std;
using namespace UTEC;



void LeerArchivo(const char *file, Vector &vectorcito){

    fstream hola;
    string data;
    int i = 0;
    pair<int,int> parcito;


    hola.open(file,ios::in|ios::out);
    if (hola.is_open()) {

            while(getline(hola,data)) {
                stringstream stream(data);
                string valor;
                while (getline(stream, valor, ' ')) {
                    string x, y;
                    if (i == 0){
                        x = valor;

                        i++;
                        parcito.first = stoi(x);
                        //cout << parcito.first << " " ;

                    }
                    else {
                        y = valor;

                        parcito.second = stoi(y);
                        //cout << parcito.second << endl;
                        i--;
                    }

                }

                vectorcito.push_back(parcito);

            }



        }

}


int main() {

    //Archivo data50000.txt

    vector<int> Tiempos;
    vector<int> Tiempos2;
    vector<int> Tiempos3;

    auto temp = Vector();

    LeerArchivo("data50000.txt",temp);

    auto start = high_resolution_clock::now();
    auto tempsito = temp.knn_vecinos(make_pair(302 ,150),1000);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    Tiempos.push_back(duration.count());

    auto temp2 = Vector();

    LeerArchivo("data50000.txt",temp2);

    auto start2 = high_resolution_clock::now();
    auto tempsito2 = temp.knn_vecinos(make_pair(704 ,200),5000);
    auto stop2 = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << "Time taken by function: "
         << duration2.count() << " microseconds" << endl;

    Tiempos.push_back(duration2.count());


    auto temp3 = Vector();

    LeerArchivo("data50000.txt",temp3);

    auto start3 = high_resolution_clock::now();
    auto tempsito3 = temp.knn_vecinos(make_pair(106 ,629),10000);
    auto stop3 = high_resolution_clock::now();

    auto duration3 = duration_cast<microseconds>(stop3 - start3);

    cout << "Time taken by function: "
         << duration3.count() << " microseconds" << endl;
    Tiempos.push_back(duration3.count());


    auto temp4 = Vector();

    LeerArchivo("data50000.txt",temp4);

    auto start4 = high_resolution_clock::now();
    auto tempsito4 = temp.knn_vecinos(make_pair(739 ,401),15000);
    auto stop4 = high_resolution_clock::now();

    auto duration4 = duration_cast<microseconds>(stop4 - start4);

    cout << "Time taken by function: "
         << duration4.count() << " microseconds" << endl;

    Tiempos.push_back(duration4.count());



    ofstream archivo;
    archivo.open("tiempos.txt", ios::out);
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }


    for(auto it: Tiempos){
        cout << it << endl;
        archivo << it << " ";
    }


    //Archivo datasetB.txt

    auto temp5 = Vector();

    LeerArchivo("datasetB.txt",temp5);

    auto start5 = high_resolution_clock::now();
    auto tempsito5 = temp.knn_vecinos(make_pair(204 ,629),1000);
    auto stop5 = high_resolution_clock::now();

    auto duration5 = duration_cast<microseconds>(stop5 - start5);

    cout << "Time taken by function: "
         << duration5.count() << " microseconds" << endl;
    Tiempos2.push_back(duration5.count());


    auto temp6 = Vector();

    LeerArchivo("datasetB.txt",temp6);

    auto start6 = high_resolution_clock::now();
    auto tempsito6 = temp.knn_vecinos(make_pair(589 ,358),5000);
    auto stop6 = high_resolution_clock::now();

    auto duration6 = duration_cast<microseconds>(stop6 - start6);

    cout << "Time taken by function: "
         << duration6.count() << " microseconds" << endl;

    Tiempos2.push_back(duration6.count());


    auto temp7 = Vector();

    LeerArchivo("datasetB.txt",temp7);

    auto start7 = high_resolution_clock::now();
    auto tempsito7 = temp.knn_vecinos(make_pair(639 ,888),10000);
    auto stop7 = high_resolution_clock::now();

    auto duration7 = duration_cast<microseconds>(stop7 - start7);

    cout << "Time taken by function: "
         << duration7.count() << " microseconds" << endl;
    Tiempos2.push_back(duration7.count());


    auto temp8 = Vector();

    LeerArchivo("datasetB.txt",temp8);

    auto start8 = high_resolution_clock::now();
    auto tempsito8 = temp.knn_vecinos(make_pair(529 ,440),15000);
    auto stop8 = high_resolution_clock::now();

    auto duration8 = duration_cast<microseconds>(stop8 - start8);

    cout << "Time taken by function: "
         << duration8.count() << " microseconds" << endl;

    Tiempos2.push_back(duration8.count());



    ofstream archivo2;
    archivo2.open("tiempos2.txt", ios::out);
    if(archivo2.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }


    for(auto it: Tiempos2){
        cout << it << endl;
        archivo2 << it << " ";
    }



    //Archivo dataetc

    auto temp9 = Vector();

    LeerArchivo("datasetc.txt",temp9);

    auto start9 = high_resolution_clock::now();
    auto tempsito9 = temp.knn_vecinos(make_pair(200 ,294),1000);
    auto stop9 = high_resolution_clock::now();

    auto duration9 = duration_cast<microseconds>(stop9 - start9);

    cout << "Time taken by function: "
         << duration9.count() << " microseconds" << endl;
    Tiempos3.push_back(duration9.count());



    auto temp10 = Vector();

    LeerArchivo("datasetc.txt",temp10);

    auto start10 = high_resolution_clock::now();
    auto tempsito10 = temp.knn_vecinos(make_pair(3 ,2),5000);
    auto stop10 = high_resolution_clock::now();

    auto duration10 = duration_cast<microseconds>(stop10 - start10);

    cout << "Time taken by function: "
         << duration10.count() << " microseconds" << endl;

    Tiempos3.push_back(duration10.count());
    //Caso3

    auto temp11 = Vector();

    LeerArchivo("datasetc.txt",temp11);

    auto start11 = high_resolution_clock::now();
    auto tempsito11 = temp.knn_vecinos(make_pair(110 ,382),10000);
    auto stop11 = high_resolution_clock::now();

    auto duration11 = duration_cast<microseconds>(stop11 - start11);

    cout << "Time taken by function: "
         << duration11.count() << " microseconds" << endl;
    Tiempos3.push_back(duration11.count());

    //Caso4

    auto temp12 = Vector();

    LeerArchivo("datasetc.txt",temp12);

    auto start12 = high_resolution_clock::now();
    auto tempsito12 = temp.knn_vecinos(make_pair(33 ,444),15000);
    auto stop12 = high_resolution_clock::now();

    auto duration12 = duration_cast<microseconds>(stop12 - start12);

    cout << "Time taken by function: "
         << duration12.count() << " microseconds" << endl;

    Tiempos3.push_back(duration12.count());



    ofstream archivo3;
    archivo3.open("tiempos3.txt", ios::out);
    if(archivo3.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }


    for(auto it: Tiempos3){
        cout << it << endl;
        archivo3 << it << " ";
    }



















    return 0;
}
