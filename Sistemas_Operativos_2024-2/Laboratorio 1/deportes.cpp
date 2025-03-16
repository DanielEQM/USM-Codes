#include <bits/stdc++.h>
#include <filesystem>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
namespace fs = std::filesystem;

void read_file(string file){
    
/***********
 * Parametros: (string) file
 * *********
 * Retorno: (void)
 * *********
 * Descripcion: Lee los archivos entregados y los procesa, separando los que tienen medalla
 * en la subcarpeta "ConMedalla" de los que no tienen en "SinMedalla". 
************/

    string line, directory = "", now = "archivos_deportes/" + file, l;
    ifstream myfile(now);
    while(getline(myfile, line)){
        if(line == "Sin Medalla"){
            l = "SinMedalla/";
            directory += l;
            mkdir(directory.c_str(), 0777);
            continue;
        } 
        if (line == "Oro" || line == "Plata" || line == "Bronce"){
            l = "ConMedalla/";
            directory += l;
            mkdir(directory.c_str(), 0777);
            continue;
        }
        directory += line;
        directory.erase(directory.end() - 1);
        mkdir(directory.c_str(), 0777);
        directory += "/";
    }
    directory += file;
    if(std::rename(now.c_str(), directory.c_str()) < 0) {
        std::cout << strerror(errno) << '\n';
    }
    myfile.close();
}

int main(){
    vector <string>  extensions = {".txt"};
    const fs::path directory = "./archivos_deportes";
    for (const fs::path &file: fs::recursive_directory_iterator(directory)){
        if (fs::is_regular_file(file)){
            if (extensions.empty() || find(extensions.begin(), extensions.end(), file.extension().string()) != (extensions.end())){
                read_file(file.filename().string());
            }
        }
    }
    return 0;
}