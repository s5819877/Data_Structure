#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

polynomial* createPolynomial(int capacity) {
	polynomial* po = (polynomial*)createArrayList(capacity);
	return po;
}

polynomial* addItemPolynomial(polynomial* po, elementType item) {
	int i;
	for (i = 0; i < sizeArrayList(po); i++) {
		if (po->data[i].expo <= item.expo) {
			break;
		}
	}

	if (i == sizeArrayList(po)) {
		insertArrayList(po, i, item);
	}
	else if (po->data[i].expo == item.expo) {
		po->data[i].coef += item.coef;
		if (po->data[i].coef == 0) {
			deleteArrayList(po, i);
		}
	}
	else {
		insertArrayList(po, i, item);
	}

	return po;
}

polynomial* addPolynomial(polynomial* p1, polynomial* p2) {
	polynomial* r = createPolynomial(
		sizeArrayList(p1) + sizeArrayList(p2));

	int i = 0, j = 0;

	while (i < sizeArrayList(p1) && j < sizeArrayList(p2)) {
		if (p1->data[i].expo > p2->data[j].expo) {
			addItemPolynomial(r, p1->data[i]);
			i++;
		}
		else if (p1->data[i].expo < p2->data[j].expo) {
			addItemPolynomial(r, p2->data[j]);
			j++;
		}
		else {
			int sumCoef = p1->data[i].coef + p2->data[j].coef;
			if (sumCoef != 0) {
				addItemPolynomial(r, (elementType) { sumCoef, p1->data[i].expo });
			}
			i++;
			j++;
		}
	}

	while (i < sizeArrayList(p1)) {
		addItemPolynomial(r, p1->data[i]);
		i++;
	}

	while (j < sizeArrayList(p2)) {
		addItemPolynomial(r, p2->data[j]);
		j++;
	}

	return r;
}

polynomial* multiplyPolynomial(polynomial* p1, polynomial* p2) {
	int n = sizeArrayList(p1);
	int m = sizeArrayList(p2);

	polynomial* r = createPolynomial(n * m + 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			elementType term;
			term.coef = p1->data[i].coef * p2->data[j].coef;
			term.expo = p1->data[i].expo + p2->data[j].expo;

			addItemPolynomial(r, term);
		}
	}

	return r;
}

void printPolynomial(polynomial* po) {
	printf("Polynomial: ");

	if (sizeArrayList(po) == 0) {
		printf("0");
	}

	for (int i = 0; i < sizeArrayList(po); i++) {
		int coef = po->data[i].coef;
		int expo = po->data[i].expo;

		if (i == 0) {
			printf("%dX^%d", coef, expo);
		}
		else {
			if (coef >= 0) {
				printf("+%dX^%d", coef, expo);
			}
			else {
				printf("-%dX^%d", -coef, expo);
			}
		}
	}

	printf("\n");
}