#include <iostream>
#include <vector>

using namespace std;

bool LoadFile1(string path, vector<string> &lista);
bool LoadFile2(string path, vector<string> &lista);

int main()
{
    //primeiro arquivo lido
    string path1 = "files/d1.txt";
    vector<string> lista;
    if(LoadFile1(path1, lista) == false)
    {
        cout << "Error, file not loaded" << endl;
        return 1;
    }

    //pair<string, vector<string>> f1(path1, lista);
    pair<string, vector<string>> f1;
    f1.first = path1;
    f1.second = lista;



    //seguno arquivo lido
    string path2 = "files/d2.txt";
    vector<string> lista2;
    if(LoadFile2(path2, lista2) == false)
    {
        cout << "Error, file 2 not loaded" << endl;
        return 1;
    }

    //pair<string, vector<string>> f1(path1, lista);
    pair<string, vector<string>> f2;
    f2.first = path2;
    f2.second = lista2;

    //armazenando tudo no mesmo objeto
    //vector<?> ListOfAllFiles;
    vector<pair<string, vector<string>>> ListOfAllFiles;
    ListOfAllFiles.push_back(f1);
    ListOfAllFiles.push_back(f2);


    //imprimir tudo, por ordem de arquivo
    for(size_t i=0; i<ListOfAllFiles.size(); i++)
    {
        cout << "Filename: " << ListOfAllFiles.at(i).first << endl;

        for(size_t j=0; j<ListOfAllFiles.at(i).second.size(); j++)
        {
            cout << " ->" << ListOfAllFiles.at(i).second.at(j) << endl;
        }
        cout << "----------------------------" << endl;
    }

    return 0;
}

bool LoadFile1(string path, vector<string> &lista)
{
    lista.push_back("amor");
    lista.push_back("vida");
    lista.push_back("esperanca");
    lista.push_back("romantico");
    return true;
}

bool LoadFile2(string path, vector<string> &lista)
{
    lista.push_back("abacate");
    lista.push_back("mamao");
    lista.push_back("cenoura");

    return true;
}

