int rank[MAXN], parent[MAXN];
void init(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		parent[i] = i;
		rank[i] = 1;
	}
}
int find(int p) // veradardznum e p-i cari armaty (nerkayacucichy)
{
	if (p == parent[p])
		return p;
	return parent[p] = find(parent[p]); // es en glxavor optimization-n a
}
bool merge(int p, int q) // ete miacac en return false. Ete kpac chem kpcnum e u return true;
{
	p = find(p); // p-i "cary"
	q = find(q); // q-i "cary"
	if (p == q)
		return 0;
	if (rank[p] > rank[q]) // rank[x]-y x gagatov cari "chapn" a. Henc chapy che, bnutagrogh ban e.
	{
		parent[q] = p;
		rank[p]++; // rank-y mecacnum enq. Irakanum es rank-y cari chapi log-i kargi tive e.
	}
	else
	{
		parent[p] = q;
		rank[q]++;
	}
	return 1;
}
