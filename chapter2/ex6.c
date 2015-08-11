unsigned invert(unsigned str1,int p,int n,unsigned str2)
{
	return (str2&~(~0<<n)|str1&((~(~0<<n))<<n)
}
