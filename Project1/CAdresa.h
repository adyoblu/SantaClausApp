#pragma once
#include <string>
#include "IModel.h"

class CAdresa
{
    int id;
    std::string localitate;
    std::string strada;
    int nr;
public:
    CAdresa(int id, std::string localitate, std::string strada, int nr) : id(id),
        localitate(localitate), strada(strada), nr(nr) {}

    CAdresa(CAdresa&& other) noexcept{
        other.id = id;
        id = 0;
        localitate = std::move(other.localitate);
        strada = std::move(other.strada);
        nr = other.nr;
        other.nr = 0;
    }
    int getId() const { return id; }
    std::string getLocalitate() const { return localitate; }
    std::string getStrada() const { return strada; }
    int getNr() const { return nr; }

};