#include <cstdio>

struct PyTypeObject;

struct PyObject {
	ssize_t ob_refcnt;
	PyTypeObject *ob_type;

	ssize_t Py_REFCNT() { return ob_refcnt; }
	PyTypeObject *Py_TYPE() { return ob_type; }

	virtual ~PyObject() {}
	virtual int tp_print(FILE *, int) {}
	virtual PyObject *tp_getattr(PyObject *) {}
	virtual PyObject *tp_setattr(char *, PyObject *) {}
	void *tp_reserved;
	virtual PyObject *tp_repr() {}
};

struct PyVarObject {
	PyObject ob_base;
	ssize_t ob_size;

	ssize_t Py_SIZE() { return ob_size; }
};

struct _Py_Identifier {
	_Py_Identifier *next;
	const char* string;
	PyObject *object;
};

struct PyNumberMethods {
	virtual PyObject * nb_add(PyObject *) {};
	/*virtual PyObject * nb_subtract(PyObject *) = 0;
	virtual PyObject * nb_multiply(PyObject *) = 0;
	virtual PyObject * nb_remainder(PyObject *) = 0;
	virtual PyObject * nb_divmod(PyObject *) = 0;
	virtual PyObject * nb_power(PyObject *, PyObject *) = 0;
	virtual PyObject * nb_negative() = 0;
	virtual PyObject * nb_positive() = 0;
	virtual PyObject * nb_absolute() = 0;
	virtual int nb_bool() = 0;
	virtual PyObject * nb_invert() = 0;
	virtual PyObject * nb_lshift(PyObject *) = 0;
	virtual PyObject * nb_rshift(PyObject *) = 0;
	virtual PyObject * nb_and(PyObject *) = 0;
	virtual PyObject * nb_xor(PyObject *) = 0;
	virtual PyObject * nb_or(PyObject *) = 0;
	virtual PyObject * nb_int() = 0;
	void *nb_reserved;
	virtual PyObject * nb_float() = 0;*/
};

struct PyTypeObject: public PyObject {
	const char *tp_name;
	int tp_basicsize, tp_itemsize;
	const char *str() { return tp_name; }
};
