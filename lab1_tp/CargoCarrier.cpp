#include "CargoCarrier.hpp"

void CargoCarrier::setType(int type) {
    this->type = type;
}

int CargoCarrier::getType() {
    return type;
}

bool CargoCarrier::isError() {
    return this->error;
}

void CargoCarrier::setError(bool error) {
    this->error = error;
}

CargoCarrier::~CargoCarrier() {};
