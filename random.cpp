void Sudoku::Random()
{
    int i,j,k,a,a1,a2,s1[12],s2[12],ap[144];
    srand(time(NULL));
    a=rand()%5; //choose the order random
    ifstream in("Q.txt",ios::in);
    ofstream out("file.out",ios::out);
    if(a==0)
        for(int i=0;i<144;++i)
                in>>ap[i];
    if(a==1)
        for(int i=143;i>=0;--i)
                in>>ap[i];
    if(a==2)
        for(int i=0;i<12;++i)//from the left to the right
                for(j=i;j<144;j+=12)
                    in>>ap[j];
    if(a==3)
        for(int i=11;i>=0;--i)//from up to down,left to right
                for(j=i;j<144;j=j+12)
                    in>>ap[j];
    if(a==4)
        for(int i=11;i<144;i=i+12)
                for(j=i;j>=(i-11);j--)
                    in>>ap[j];
    for (k=0;k<4;++k)
    {
        for(int i=0;i<12;++i)
            s1[i]=-1;
		for(int i=0;i<12;++i)
            s2[i]=-1;
        a1=rand()%9+1;
        do
        {
            a2=rand()%9+1;
        }while(a1==a2);
        int j=0;
        for(int i=0;i<144;++i)
        {
                if(ap[i]==a1)
                {
                    s1[j]=i;
                    j++;
                }
        }
        for(int i=0;i<144;++i)
        {
                if(ap[i]==a2)
                {
                    s2[j]=i;
                    j++;
                }
        }
        for(int i=0;i<12;i++)
                if(s1[i]!=(-1)) ap[s1[i]]=a2;
        for(int i=0;i<12;++i)
                if(s2[i]!=(-1)) ap[s2[i]]=a1;
    }
	for(int i=0;i<144;i++)
    {
            out<<ap[i]<<" ";
        if(i%12==11)
            out<<endl;
    }
}

