#include "object.h"

#include <cstdio>

struct Int: public PyTypeObject, public PyNumberMethods {
	Int(): PyTypeObject() { tp_name = "Int"; }
	int i;
	Int *nb_add(Int *other) {
		Int *result = new Int;
		result->i = this->i + other->i;
		return result;
	}
};

int main() {
	Int *a = new Int;
	Int *b = new Int;
	a->i = 1;
	b->i = 2;
	printf("%s %d\n", a->str(), a->nb_add(b)->i);
}
