#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& rhs) {(void) rhs;}
Serializer& Serializer::operator=(const Serializer& rhs) {(void) rhs; return (*this);}
Serializer::~Serializer() {}

// 포인터를 정수형으로 변환
uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

// 정수형을 포인터형으로 변환
Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}