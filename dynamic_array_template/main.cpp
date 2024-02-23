#include "dynamic_array_template.h"

int main() {
    dynamic_array<int> a(20);
    dynamic_array<int> d;
    for(int i = 0; i < 10; i++) {
        d.append(i);
    }
    std::cout << d << std::endl; // Test der Ausgabe
    
    // Copy Konstruktor Test
    dynamic_array<int> copy = d;
    std::cout << copy << std::endl;
    
    // Zuweisungsoperator Test
    dynamic_array<int> zuw;
    zuw = copy;
    std::cout << zuw << std::endl;
    
    // Move Konstruktor und Zuweisungsoperator Test
    dynamic_array<int> mo = std::move(zuw);
    std::cout << mo << std::endl;
    std::cout << zuw << std::endl; // Sollte "leer" sein, da zuw verschoben wurde
    std::cout << zuw.size() << std::endl; // Sollte 0 sein, da zuw verschoben wurde
}
   

