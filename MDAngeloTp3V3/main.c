#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "LinkedList.h"
#include "mdangelo/business/CompanyBsn.h"

int main() {
	LinkedList *linkedList = ll_newLinkedList();
	coBsn_startApp(linkedList);
	printf("--END---");
	return EXIT_SUCCESS;
}

