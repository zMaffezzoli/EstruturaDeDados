#ifndef TOCLOCK_H
#define TOCLOCK_H

#include <vector>
#include <functional>
#include <string>

void medirTempo(std::function<void (std::vector<int>&)> metodoOrdenamento, 
                std::vector<int> &valores,
                const std::string& metodo);

#endif