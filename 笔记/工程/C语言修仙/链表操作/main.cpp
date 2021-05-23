#include "list.h"

int main()
{
	List ls;
	ls.AddListHead(1);
	ls.AddListHead(1);
	ls.AddListHead(1);
	ls.AddListHead(1);
	ls.AddListHead(1);
	ls.AddListHead(1);

	ls.ScanList();

	ls.DeleteNodeRand(1);
	ls.ScanList();

	system("pause");
	return 0;
}