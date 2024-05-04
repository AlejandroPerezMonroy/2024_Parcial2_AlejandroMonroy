#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

// Utiliza el espacio de nombres std para filesystem
namespace fs = std::filesystem;

void crearArchivos(int cantidad) {
    std::string path;
    if (cantidad % 2 == 0) {
        path = fs::current_path() / "Escritorio" / "par";
    } else {
        path = fs::current_path() / "Escritorio" / "impar";
    }

    // Crear el directorio si no existe
    fs::create_directories(path);

    for (int i = 1; i <= cantidad; ++i) {
        std::string filename = "file" + std::to_string(i);
        std::ofstream file(path / filename);
    }
}

void agregarTexto(int cantidad) {
    std::string base_path;
    if (cantidad % 2 == 0) {
        base_path = fs::current_path() / "Escritorio" / "par";
    } else {
        base_path = fs::current_path() / "Escritorio" / "impar";
    }

    for (int i = 1; i <= cantidad; ++i) {
        std::string filename = "file" + std::to_string(i);
        std::ofstream file(base_path / filename, std::ios_base::app); // Abre el archivo en modo append
        for (int line = 0; line < i; ++line) {
            file << "Esta es la línea " << line + 1 << " del archivo " << filename << "\n";
        }
    }
}

int main() {
    int cantidad;
    std::cout << "¿Cuántos archivos deseas crear? ";
    std::cin >> cantidad;

    crearArchivos(cantidad);
    agregarTexto(cantidad);

    return 0;
}