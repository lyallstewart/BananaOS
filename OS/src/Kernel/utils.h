long double floor(long double x)
{
    long double xcopy=x<0?x-1:x;
    unsigned int zeros=0;
    long double n=1;
    for(n=1;xcopy>n*10;n*=10,++zeros);
    for(xcopy-=n;zeros!=-1;xcopy-=n)
        if(xcopy<0)
        {
            xcopy+=n;
            n/=10;
            --zeros;
        }
    xcopy+=n;
    return x<0?(xcopy==0?x:x-(1-xcopy)):(x-xcopy);
}