#include <Python.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

static char bug_doc[] = "Reproduce a PyArg_ParseTuple bug";

static char bug2_doc[] = "Reproduce the bug with 2 arguments";
static PyObject *bug2(PyObject *self, PyObject *args) {
	int a = 0;
	bool p = false;
	int aa = 0;
	int pi = 0;

    int ok = 0;

//	printf("\tOriginal: a = %i\tp = %d\t\taa = %i\tpi = %i\n", a, p, aa, pi);

//  Parse the input parametres
    ok = PyArg_ParseTuple(args, "ip", &a, &p);

    if (ok == 0) {
        return NULL;
    }

	ok = PyArg_ParseTuple(args, "ii", &aa, &pi);

	if (ok == 0) {
		return NULL;
	}

//  ?
	printf("\tC:\ta = %i\tp = %d\n\t\taa = %i\tpi = %i\n\n", a, p, aa, pi);

    if ((a == aa)&&(p == pi)) {
        Py_RETURN_TRUE;
    }
    else Py_RETURN_FALSE;
}

static char bug3_doc[] = "Reproduce the bug with 3 arguments";
static PyObject *bug3(PyObject *self, PyObject *args) {
	int a = 0;
    int b = 0;
	bool p = false;
	int aa = 0;
	int bb = 0;
    int pi = 0;

    int ok = 0;

//	printf("\tOriginal: a = %i\tb = %i\tp = %d\t\taa = %i\tbb = %i\tpi = %i\n", a, b, p, aa, bb, pi);

//  Parse the input parametres
    ok = PyArg_ParseTuple(args, "iip", &a, &b, &p);

    if (ok == 0) {
        return NULL;
    }

	ok = PyArg_ParseTuple(args, "iii", &aa, &bb, &pi);

	if (ok == 0) {
		return NULL;
	}

//  ?
	printf("\tC:\ta = %i\tb = %i\tp = %d\n\t\taa = %i\tbb = %i\tpi = %i\n\n", a, b, p, aa, bb, pi);

    if ((a == aa)&&(b == bb)&&(p == pi)) {
        Py_RETURN_TRUE;
    }
    else Py_RETURN_FALSE;
}

static char bug4_doc[] = "Reproduce the bug with 4 arguments";
static PyObject *bug4(PyObject *self, PyObject *args) {
	int a = 0;
    int b = 0;
    int c = 0;
	bool p = false;
	int aa = 0;
	int bb = 0;
    int cc = 0;
    int pi = 0;

    int ok = 0;

//	printf("\tOriginal: a = %i\tb = %i\tc = %i\tp = %d\t\taa = %i\tbb = %i\tcc = %i\tpi = %i\n", a, b, c, p, aa, bb, cc, pi);

//  Parse the input parametres
    ok = PyArg_ParseTuple(args, "iiip", &a, &b, &c, &p);

    if (ok == 0) {
        return NULL;
    }

	ok = PyArg_ParseTuple(args, "iiii", &aa, &bb, &cc, &pi);

	if (ok == 0) {
		return NULL;
	}

//  ?
	printf("\tC:\ta = %i\tb = %i\tc = %i\tp = %d\n\t\taa = %i\tbb = %i\tcc = %i\tpi = %i\n\n", a, b, c, p, aa, bb, cc, pi);

    if ((a == aa)&&(b == bb)&&(c == cc)&&(p == pi)) {
        Py_RETURN_TRUE;
    }
    else Py_RETURN_FALSE;
}

/*
    1. name of func when called from Python
    2. corresponding C function
    3. ordinary (not keyword) arguments
    4. doc string for gridloop1 function
*/
static PyMethodDef bug_methods[] = {
    {"bug2", bug2, METH_VARARGS, bug2_doc},
    {"bug3", bug3, METH_VARARGS, bug3_doc},
    {"bug4", bug4, METH_VARARGS, bug4_doc},
    {NULL, NULL, 0, NULL}
};

/*
    1. name of module
    2. module documentation, may be NULL
    3. size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
*/
static struct PyModuleDef bug_module = {
    PyModuleDef_HEAD_INIT,
    "papt.bug",
    bug_doc,
    -1,
    bug_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_bug(void) {
    PyObject *bm;

    bm = PyModule_Create(&bug_module);

    return(bm);
}
