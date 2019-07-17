#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
ifstream fin("datain.csv");
ofstream fout("dataout.csv");
struct STUD
{
	int stuid;
	char stuclass[30];
	char stuname[50];
	int math;
	int chin;
	int eng;
	int physcore;
	int chemscore;
	int bioscore;
	int geoscore;
	int hisscore;
	int poliscore;
	int phyarr;
	int chemarr;
	int bioarr;
	int geoarr;
	int hisarr;
	int poliarr;
	int phycl;
	int chemcl;
	int biocl;
	int geocl;
	int hiscl;
	int policl;
	int t3totals;
	int t3totala;
	int s6totals;
	int s6totala;
};
STUD wczs[5000];
char dat[100];
int wczsnum=0;
int temp95;
void k000output(int temp41000)
{
	
	if(temp41000<1000)
	{
		fout<<temp41000<<",";
		return;
	}
	else
	{
		if(temp41000<2000)
		{
			fout<<(temp41000-1000)<<".5,";
		}
		else
		{
			//cout<<"程序在处理小数点时出现不期望的问题,正在尝试解决"<<endl;
			fout<<fout<<(temp41000-999)<<",";
		}
	}
	return;
}
int s6ksort()
{
	int shuzu[10000];
	int tempj;
	int temp43;
	int tempt;
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].s6totals<1000)
			shuzu[temp43]=wczs[temp43].s6totals;
		if(wczs[temp43].s6totals>=1000)
			shuzu[temp43]=wczs[temp43].s6totals-999;
		
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		for(tempj=temp43;tempj<wczsnum;tempj++)
		{
			if(shuzu[tempj]>shuzu[temp43])
			{
				tempt=shuzu[tempj];
				shuzu[tempj]=shuzu[temp43];
				shuzu[temp43]=tempt;
			}
		}
	}

	int tongfen;
	for(temp43=0;temp43<wczsnum;)
	{
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].s6totals==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].s6totala=temp43+1;
			}

		}
		if(shuzu[temp43]!=shuzu[temp43+tongfen])
		{
			temp43+=tongfen;
			continue;
		}
		temp43+=tongfen;
		
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].s6totals-999==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].s6totala=temp43+1;
			}
		}
		temp43+=tongfen;
	}
	return 0;
}
int t3ksort()
{
	int shuzu[10000];
	int tempj;
	int temp43;
	int tempt;
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].t3totals<1000)
			shuzu[temp43]=wczs[temp43].t3totals;
		if(wczs[temp43].t3totals>=1000)
			shuzu[temp43]=wczs[temp43].t3totals-999;
		
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		for(tempj=temp43;tempj<wczsnum;tempj++)
		{
			if(shuzu[tempj]>shuzu[temp43])
			{
				tempt=shuzu[tempj];
				shuzu[tempj]=shuzu[temp43];
				shuzu[temp43]=tempt;
			}
		}
	}
	int tongfen;
	for(temp43=0;temp43<wczsnum;)
	{
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].t3totals==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].t3totala=temp43+1;
			}

		}
		if(shuzu[temp43]!=shuzu[temp43+tongfen])
		{
			temp43+=tongfen;
			continue;
		}
		temp43+=tongfen;
		
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].t3totals-999==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].t3totala=temp43+1;
			}
		}
		temp43+=tongfen;
	}
	return 0;
}
int phyksort()
{
	int shuzu[10000];
	int tempj;
	int temp43;
	int tempt;
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].physcore<1000)
			shuzu[temp43]=wczs[temp43].physcore;
		if(wczs[temp43].physcore>=1000)
			shuzu[temp43]=wczs[temp43].physcore-999;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		for(tempj=temp43;tempj<wczsnum;tempj++)
		{
			if(shuzu[tempj]>shuzu[temp43])
			{
				tempt=shuzu[tempj];
				shuzu[tempj]=shuzu[temp43];
				shuzu[temp43]=tempt;
			}
		}
	}
	int tongfen,population=wczsnum;
	for(temp43=0;temp43<wczsnum;)
	{
		if(shuzu[temp43]==0)
		{
			population=temp43;
			break;
		}
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].physcore==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].phyarr=temp43+1;
			}

		}
		if(shuzu[temp43]!=shuzu[temp43+tongfen])
		{
			temp43+=tongfen;
			continue;
		}
		temp43+=tongfen;
		
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].physcore-999==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].phyarr=temp43+1;
			}
		}
		temp43+=tongfen;
	}
	//等级赋分
	/*
	for(temp43=0;temp43<population;temp43++)
	{
		if(wczs[temp43].phyarr<=9/100) wczs[temp43].phycl=100;
		else if(wczs[temp43].phyarr<=14/100) wczs[temp43].phycl=97;
		else if(wczs[temp43].phyarr<=31/100) wczs[temp43].phycl=94;
		else if(wczs[temp43].phyarr<=47/100) wczs[temp43].phycl=91;
		else if(wczs[temp43].phyarr<=77/100) wczs[temp43].phycl=88;
		else if(wczs[temp43].phyarr<=121/100) wczs[temp43].phycl=85;
		else if(wczs[temp43].phyarr<=166/100) wczs[temp43].phycl=82;
		else if(wczs[temp43].phyarr<=236/100) wczs[temp43].phycl=79;
		else if(wczs[temp43].phyarr<=273/100) wczs[temp43].phycl=76;
		else if(wczs[temp43].phyarr<=312/100) wczs[temp43].phycl=73;
		else if(wczs[temp43].phyarr<=346/100) wczs[temp43].phycl=70;
		else if(wczs[temp43].phyarr<=385/100) wczs[temp43].phycl=67;
		else if(wczs[temp43].phyarr<=411/100) wczs[temp43].phycl=64;
		else if(wczs[temp43].phyarr<=436/100) wczs[temp43].phycl=61;
		else if(wczs[temp43].phyarr<=461/100) wczs[temp43].phycl=58;
		else if(wczs[temp43].phyarr<=481/100) wczs[temp43].phycl=55;
		else if(wczs[temp43].phyarr<=493/100) wczs[temp43].phycl=52;
		else if(wczs[temp43].phyarr<=504/100) wczs[temp43].phycl=49;
		else if(wczs[temp43].phyarr<=507/100) wczs[temp43].phycl=46;
		else if(wczs[temp43].phyarr<=512/100) wczs[temp43].phycl=43;
		else if(wczs[temp43].phyarr>512/100) wczs[temp43].phycl=40;
	}
	*/
	//按照示例输入数据对物理赋分
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].phyarr==0)
		{
			wczs[temp43].phycl=0;
			continue;
		}
		if(wczs[temp43].phyarr<=population*1/100) wczs[temp43].phycl=100;
		else if(wczs[temp43].phyarr<=population*3/100) wczs[temp43].phycl=97;
		else if(wczs[temp43].phyarr<=population*6/100) wczs[temp43].phycl=94;
		else if(wczs[temp43].phyarr<=population*10/100) wczs[temp43].phycl=91;
		else if(wczs[temp43].phyarr<=population*15/100) wczs[temp43].phycl=88;
		else if(wczs[temp43].phyarr<=population*22/100) wczs[temp43].phycl=85;
		else if(wczs[temp43].phyarr<=population*30/100) wczs[temp43].phycl=82;
		else if(wczs[temp43].phyarr<=population*39/100) wczs[temp43].phycl=79;
		else if(wczs[temp43].phyarr<=population*47/100) wczs[temp43].phycl=76;
		else if(wczs[temp43].phyarr<=population*55/100) wczs[temp43].phycl=73;
		else if(wczs[temp43].phyarr<=population*62/100) wczs[temp43].phycl=70;
		else if(wczs[temp43].phyarr<=population*68/100) wczs[temp43].phycl=67;
		else if(wczs[temp43].phyarr<=population*74/100) wczs[temp43].phycl=64;
		else if(wczs[temp43].phyarr<=population*80/100) wczs[temp43].phycl=61;
		else if(wczs[temp43].phyarr<=population*85/100) wczs[temp43].phycl=58;
		else if(wczs[temp43].phyarr<=population*89/100) wczs[temp43].phycl=55;
		else if(wczs[temp43].phyarr<=population*93/100) wczs[temp43].phycl=52;
		else if(wczs[temp43].phyarr<=population*96/100) wczs[temp43].phycl=49;
		else if(wczs[temp43].phyarr<=population*98/100) wczs[temp43].phycl=46;
		else if(wczs[temp43].phyarr<=population*99/100) wczs[temp43].phycl=43;
		else if(wczs[temp43].phyarr>population*99/100) wczs[temp43].phycl=40;
	}

	return 0;
}
int chemksort()
{
	int shuzu[10000];
	int tempj;
	int temp43;
	int tempt;
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].chemscore<1000)
			shuzu[temp43]=wczs[temp43].chemscore;
		if(wczs[temp43].chemscore>=1000)
			shuzu[temp43]=wczs[temp43].chemscore-999;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		for(tempj=temp43;tempj<wczsnum;tempj++)
		{
			if(shuzu[tempj]>shuzu[temp43])
			{
				tempt=shuzu[tempj];
				shuzu[tempj]=shuzu[temp43];
				shuzu[temp43]=tempt;
			}
		}
	}
	int tongfen,population=wczsnum;
	for(temp43=0;temp43<wczsnum;)
	{
		if(shuzu[temp43]==0)
		{
			population=temp43;
			break;
		}
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].chemscore==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].chemarr=temp43+1;
			}

		}
		if(shuzu[temp43]!=shuzu[temp43+tongfen])
		{
			temp43+=tongfen;
			continue;
		}
		temp43+=tongfen;
		
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].chemscore-999==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].chemarr=temp43+1;
			}
		}
		temp43+=tongfen;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].chemarr==0)
		{
			wczs[temp43].chemcl=0;
			continue;
		}
		if(wczs[temp43].chemarr<=population*1/100) wczs[temp43].chemcl=100;
		else if(wczs[temp43].chemarr<=population*3/100) wczs[temp43].chemcl=97;
		else if(wczs[temp43].chemarr<=population*6/100) wczs[temp43].chemcl=94;
		else if(wczs[temp43].chemarr<=population*10/100) wczs[temp43].chemcl=91;
		else if(wczs[temp43].chemarr<=population*15/100) wczs[temp43].chemcl=88;
		else if(wczs[temp43].chemarr<=population*22/100) wczs[temp43].chemcl=85;
		else if(wczs[temp43].chemarr<=population*30/100) wczs[temp43].chemcl=82;
		else if(wczs[temp43].chemarr<=population*39/100) wczs[temp43].chemcl=79;
		else if(wczs[temp43].chemarr<=population*47/100) wczs[temp43].chemcl=76;
		else if(wczs[temp43].chemarr<=population*55/100) wczs[temp43].chemcl=73;
		else if(wczs[temp43].chemarr<=population*62/100) wczs[temp43].chemcl=70;
		else if(wczs[temp43].chemarr<=population*68/100) wczs[temp43].chemcl=67;
		else if(wczs[temp43].chemarr<=population*74/100) wczs[temp43].chemcl=64;
		else if(wczs[temp43].chemarr<=population*80/100) wczs[temp43].chemcl=61;
		else if(wczs[temp43].chemarr<=population*85/100) wczs[temp43].chemcl=58;
		else if(wczs[temp43].chemarr<=population*89/100) wczs[temp43].chemcl=55;
		else if(wczs[temp43].chemarr<=population*93/100) wczs[temp43].chemcl=52;
		else if(wczs[temp43].chemarr<=population*96/100) wczs[temp43].chemcl=49;
		else if(wczs[temp43].chemarr<=population*98/100) wczs[temp43].chemcl=46;
		else if(wczs[temp43].chemarr<=population*99/100) wczs[temp43].chemcl=43;
		else if(wczs[temp43].chemarr>population*99/100) wczs[temp43].chemcl=40;
	}

	return 0;
}
int bioksort()
{
	int shuzu[10000];
	int tempj;
	int temp43;
	int tempt;
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].bioscore<1000)
			shuzu[temp43]=wczs[temp43].bioscore;
		if(wczs[temp43].bioscore>=1000)
			shuzu[temp43]=wczs[temp43].bioscore-999;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		for(tempj=temp43;tempj<wczsnum;tempj++)
		{
			if(shuzu[tempj]>shuzu[temp43])
			{
				tempt=shuzu[tempj];
				shuzu[tempj]=shuzu[temp43];
				shuzu[temp43]=tempt;
			}
		}
	}
	int tongfen,population=wczsnum;
	for(temp43=0;temp43<wczsnum;)
	{
		if(shuzu[temp43]==0)
		{
			population=temp43;
			break;
		}
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].bioscore==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].bioarr=temp43+1;
			}

		}
		if(shuzu[temp43]!=shuzu[temp43+tongfen])
		{
			temp43+=tongfen;
			continue;
		}
		temp43+=tongfen;
		
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].bioscore-999==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].bioarr=temp43+1;
			}
		}
		temp43+=tongfen;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].bioarr==0)
		{
			wczs[temp43].biocl=0;
			continue;
		}
		if(wczs[temp43].bioarr<=population*1/100) wczs[temp43].biocl=100;
		else if(wczs[temp43].bioarr<=population*3/100) wczs[temp43].biocl=97;
		else if(wczs[temp43].bioarr<=population*6/100) wczs[temp43].biocl=94;
		else if(wczs[temp43].bioarr<=population*10/100) wczs[temp43].biocl=91;
		else if(wczs[temp43].bioarr<=population*15/100) wczs[temp43].biocl=88;
		else if(wczs[temp43].bioarr<=population*22/100) wczs[temp43].biocl=85;
		else if(wczs[temp43].bioarr<=population*30/100) wczs[temp43].biocl=82;
		else if(wczs[temp43].bioarr<=population*39/100) wczs[temp43].biocl=79;
		else if(wczs[temp43].bioarr<=population*47/100) wczs[temp43].biocl=76;
		else if(wczs[temp43].bioarr<=population*55/100) wczs[temp43].biocl=73;
		else if(wczs[temp43].bioarr<=population*62/100) wczs[temp43].biocl=70;
		else if(wczs[temp43].bioarr<=population*68/100) wczs[temp43].biocl=67;
		else if(wczs[temp43].bioarr<=population*74/100) wczs[temp43].biocl=64;
		else if(wczs[temp43].bioarr<=population*80/100) wczs[temp43].biocl=61;
		else if(wczs[temp43].bioarr<=population*85/100) wczs[temp43].biocl=58;
		else if(wczs[temp43].bioarr<=population*89/100) wczs[temp43].biocl=55;
		else if(wczs[temp43].bioarr<=population*93/100) wczs[temp43].biocl=52;
		else if(wczs[temp43].bioarr<=population*96/100) wczs[temp43].biocl=49;
		else if(wczs[temp43].bioarr<=population*98/100) wczs[temp43].biocl=46;
		else if(wczs[temp43].bioarr<=population*99/100) wczs[temp43].biocl=43;
		else if(wczs[temp43].bioarr>population*99/100) wczs[temp43].biocl=40;
	}

	return 0;
}
int hisksort()
{
	int shuzu[10000];
	int tempj;
	int temp43;
	int tempt;
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].hisscore<1000)
			shuzu[temp43]=wczs[temp43].hisscore;
		if(wczs[temp43].hisscore>=1000)
			shuzu[temp43]=wczs[temp43].hisscore-999;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		for(tempj=temp43;tempj<wczsnum;tempj++)
		{
			if(shuzu[tempj]>shuzu[temp43])
			{
				tempt=shuzu[tempj];
				shuzu[tempj]=shuzu[temp43];
				shuzu[temp43]=tempt;
			}
		}
	}
	int tongfen,population=wczsnum;
	for(temp43=0;temp43<wczsnum;)
	{
		if(shuzu[temp43]==0)
		{
			population=temp43;
			break;
		}
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].hisscore==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].hisarr=temp43+1;
			}

		}
		if(shuzu[temp43]!=shuzu[temp43+tongfen])
		{
			temp43+=tongfen;
			continue;
		}
		temp43+=tongfen;
		
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].hisscore-999==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].hisarr=temp43+1;
			}
		}
		temp43+=tongfen;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].hisarr==0)
		{
			wczs[temp43].hiscl=0;
			continue;
		}
		if(wczs[temp43].hisarr<=population*1/100) wczs[temp43].hiscl=100;
		else if(wczs[temp43].hisarr<=population*3/100) wczs[temp43].hiscl=97;
		else if(wczs[temp43].hisarr<=population*6/100) wczs[temp43].hiscl=94;
		else if(wczs[temp43].hisarr<=population*10/100) wczs[temp43].hiscl=91;
		else if(wczs[temp43].hisarr<=population*15/100) wczs[temp43].hiscl=88;
		else if(wczs[temp43].hisarr<=population*22/100) wczs[temp43].hiscl=85;
		else if(wczs[temp43].hisarr<=population*30/100) wczs[temp43].hiscl=82;
		else if(wczs[temp43].hisarr<=population*39/100) wczs[temp43].hiscl=79;
		else if(wczs[temp43].hisarr<=population*47/100) wczs[temp43].hiscl=76;
		else if(wczs[temp43].hisarr<=population*55/100) wczs[temp43].hiscl=73;
		else if(wczs[temp43].hisarr<=population*62/100) wczs[temp43].hiscl=70;
		else if(wczs[temp43].hisarr<=population*68/100) wczs[temp43].hiscl=67;
		else if(wczs[temp43].hisarr<=population*74/100) wczs[temp43].hiscl=64;
		else if(wczs[temp43].hisarr<=population*80/100) wczs[temp43].hiscl=61;
		else if(wczs[temp43].hisarr<=population*85/100) wczs[temp43].hiscl=58;
		else if(wczs[temp43].hisarr<=population*89/100) wczs[temp43].hiscl=55;
		else if(wczs[temp43].hisarr<=population*93/100) wczs[temp43].hiscl=52;
		else if(wczs[temp43].hisarr<=population*96/100) wczs[temp43].hiscl=49;
		else if(wczs[temp43].hisarr<=population*98/100) wczs[temp43].hiscl=46;
		else if(wczs[temp43].hisarr<=population*99/100) wczs[temp43].hiscl=43;
		else if(wczs[temp43].hisarr>population*99/100) wczs[temp43].hiscl=40;
	}

	return 0;
}
int geoksort()
{
	int shuzu[10000];
	int tempj;
	int temp43;
	int tempt;
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].geoscore<1000)
			shuzu[temp43]=wczs[temp43].geoscore;
		if(wczs[temp43].geoscore>=1000)
			shuzu[temp43]=wczs[temp43].geoscore-999;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		for(tempj=temp43;tempj<wczsnum;tempj++)
		{
			if(shuzu[tempj]>shuzu[temp43])
			{
				tempt=shuzu[tempj];
				shuzu[tempj]=shuzu[temp43];
				shuzu[temp43]=tempt;
			}
		}
	}
	int tongfen,population=wczsnum;
	for(temp43=0;temp43<wczsnum;)
	{
		if(shuzu[temp43]==0)
		{
			population=temp43;
			break;
		}
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].geoscore==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].geoarr=temp43+1;
			}

		}
		if(shuzu[temp43]!=shuzu[temp43+tongfen])
		{
			temp43+=tongfen;
			continue;
		}
		temp43+=tongfen;
		
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].geoscore-999==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].geoarr=temp43+1;
			}
		}
		temp43+=tongfen;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].geoarr==0)
		{
			wczs[temp43].geocl=0;
			continue;
		}
		if(wczs[temp43].geoarr<=population*1/100) wczs[temp43].geocl=100;
		else if(wczs[temp43].geoarr<=population*3/100) wczs[temp43].geocl=97;
		else if(wczs[temp43].geoarr<=population*6/100) wczs[temp43].geocl=94;
		else if(wczs[temp43].geoarr<=population*10/100) wczs[temp43].geocl=91;
		else if(wczs[temp43].geoarr<=population*15/100) wczs[temp43].geocl=88;
		else if(wczs[temp43].geoarr<=population*22/100) wczs[temp43].geocl=85;
		else if(wczs[temp43].geoarr<=population*30/100) wczs[temp43].geocl=82;
		else if(wczs[temp43].geoarr<=population*39/100) wczs[temp43].geocl=79;
		else if(wczs[temp43].geoarr<=population*47/100) wczs[temp43].geocl=76;
		else if(wczs[temp43].geoarr<=population*55/100) wczs[temp43].geocl=73;
		else if(wczs[temp43].geoarr<=population*62/100) wczs[temp43].geocl=70;
		else if(wczs[temp43].geoarr<=population*68/100) wczs[temp43].geocl=67;
		else if(wczs[temp43].geoarr<=population*74/100) wczs[temp43].geocl=64;
		else if(wczs[temp43].geoarr<=population*80/100) wczs[temp43].geocl=61;
		else if(wczs[temp43].geoarr<=population*85/100) wczs[temp43].geocl=58;
		else if(wczs[temp43].geoarr<=population*89/100) wczs[temp43].geocl=55;
		else if(wczs[temp43].geoarr<=population*93/100) wczs[temp43].geocl=52;
		else if(wczs[temp43].geoarr<=population*96/100) wczs[temp43].geocl=49;
		else if(wczs[temp43].geoarr<=population*98/100) wczs[temp43].geocl=46;
		else if(wczs[temp43].geoarr<=population*99/100) wczs[temp43].geocl=43;
		else if(wczs[temp43].geoarr>population*99/100) wczs[temp43].geocl=40;
	}

	return 0;
}
int poliksort()
{
	int shuzu[10000];
	int tempj;
	int temp43;
	int tempt;
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].poliscore<1000)
			shuzu[temp43]=wczs[temp43].poliscore;
		if(wczs[temp43].poliscore>=1000)
			shuzu[temp43]=wczs[temp43].poliscore-999;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		for(tempj=temp43;tempj<wczsnum;tempj++)
		{
			if(shuzu[tempj]>shuzu[temp43])
			{
				tempt=shuzu[tempj];
				shuzu[tempj]=shuzu[temp43];
				shuzu[temp43]=tempt;
			}
		}
	}
	int tongfen,population=wczsnum;
	for(temp43=0;temp43<wczsnum;)
	{
		if(shuzu[temp43]==0)
		{
			population=temp43;
			break;
		}
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].poliscore==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].poliarr=temp43+1;
			}

		}
		if(shuzu[temp43]!=shuzu[temp43+tongfen])
		{
			temp43+=tongfen;
			continue;
		}
		temp43+=tongfen;
		
		tongfen=0;
		for(tempj=0;tempj<wczsnum;tempj++)
		{
			if(wczs[tempj].poliscore-999==shuzu[temp43])
			{
				tongfen++;
				wczs[tempj].poliarr=temp43+1;
			}
		}
		temp43+=tongfen;
	}
	for(temp43=0;temp43<wczsnum;temp43++)
	{
		if(wczs[temp43].poliarr==0)
		{
			wczs[temp43].policl=0;
			continue;
		}
		if(wczs[temp43].poliarr<=population*1/100) wczs[temp43].policl=100;
		else if(wczs[temp43].poliarr<=population*3/100) wczs[temp43].policl=97;
		else if(wczs[temp43].poliarr<=population*6/100) wczs[temp43].policl=94;
		else if(wczs[temp43].poliarr<=population*10/100) wczs[temp43].policl=91;
		else if(wczs[temp43].poliarr<=population*15/100) wczs[temp43].policl=88;
		else if(wczs[temp43].poliarr<=population*22/100) wczs[temp43].policl=85;
		else if(wczs[temp43].poliarr<=population*30/100) wczs[temp43].policl=82;
		else if(wczs[temp43].poliarr<=population*39/100) wczs[temp43].policl=79;
		else if(wczs[temp43].poliarr<=population*47/100) wczs[temp43].policl=76;
		else if(wczs[temp43].poliarr<=population*55/100) wczs[temp43].policl=73;
		else if(wczs[temp43].poliarr<=population*62/100) wczs[temp43].policl=70;
		else if(wczs[temp43].poliarr<=population*68/100) wczs[temp43].policl=67;
		else if(wczs[temp43].poliarr<=population*74/100) wczs[temp43].policl=64;
		else if(wczs[temp43].poliarr<=population*80/100) wczs[temp43].policl=61;
		else if(wczs[temp43].poliarr<=population*85/100) wczs[temp43].policl=58;
		else if(wczs[temp43].poliarr<=population*89/100) wczs[temp43].policl=55;
		else if(wczs[temp43].poliarr<=population*93/100) wczs[temp43].policl=52;
		else if(wczs[temp43].poliarr<=population*96/100) wczs[temp43].policl=49;
		else if(wczs[temp43].poliarr<=population*98/100) wczs[temp43].policl=46;
		else if(wczs[temp43].poliarr<=population*99/100) wczs[temp43].policl=43;
		else if(wczs[temp43].poliarr>population*99/100) wczs[temp43].policl=40;
	}

	return 0;
}
int main()
{
	//cout<<"程序正在启动,请确认指定目录（namespace std）下存在datain.csv"<<endl;
	int doti;
	int chara,lchara;
	//cout<<"正在尝试读入数据"<<endl;
	while(!fin.eof())
	{
		doti=0;
		chara=0;
		lchara=-1;

		fin>>dat;
		while(doti<13)
		{
			if(dat[chara]==',')
			{
				doti++;
				if(doti==1) doti=1;//hehe
				if(doti==2)//班级
				{
					int temp57=0;
					for(int temp58=lchara+1;temp58<chara;temp58++)
					{
						wczs[wczsnum].stuclass[temp57]=dat[temp58];
						temp57++;
					}
				}
				if(doti==3)//学号 - 假装都是9位数
				{
					int temp67=0;
					wczs[wczsnum].stuid=0;
					for(int temp68=lchara+1;temp68<chara;temp68++)
					{
						if(temp67==0) wczs[wczsnum].stuid+=(dat[temp68]-48)*100000000;
						if(temp67==1) wczs[wczsnum].stuid+=(dat[temp68]-48)*10000000;
						if(temp67==2) wczs[wczsnum].stuid+=(dat[temp68]-48)*1000000;
						if(temp67==3) wczs[wczsnum].stuid+=(dat[temp68]-48)*100000;
						if(temp67==4) wczs[wczsnum].stuid+=(dat[temp68]-48)*10000;
						if(temp67==5) wczs[wczsnum].stuid+=(dat[temp68]-48)*1000;
						if(temp67==6) wczs[wczsnum].stuid+=(dat[temp68]-48)*100;
						if(temp67==7) wczs[wczsnum].stuid+=(dat[temp68]-48)*10;
						if(temp67==8) wczs[wczsnum].stuid+=(dat[temp68]-48)*1;
						temp67++;
					}
				}
				if(doti==4)//姓名（UTF-8）
				{
					int temp85=0;
					for(int temp86=lchara+1;temp86<chara;temp86++)
					{
						wczs[wczsnum].stuname[temp85]=dat[temp86];
						temp85++;
					}
				}
				if(doti==5)//语文成绩
				{
					
					wczs[wczsnum].chin=0;
					for(temp95=chara-1;temp95>lchara;temp95--)
					{
						if(dat[chara-2]!='.')
						{
							if(temp95==chara-1) wczs[wczsnum].chin+=(dat[temp95]-48);
							if(temp95==chara-2) wczs[wczsnum].chin+=(dat[temp95]-48)*10;
							if(temp95==chara-3) wczs[wczsnum].chin+=(dat[temp95]-48)*100;
						}
						else
						{
							if(temp95==chara-1) wczs[wczsnum].chin+=1000;
							if(temp95==chara-3) wczs[wczsnum].chin+=(dat[temp95]-48);
							if(temp95==chara-4) wczs[wczsnum].chin+=(dat[temp95]-48)*10;
							if(temp95==chara-5) wczs[wczsnum].chin+=(dat[temp95]-48)*100;
						}
					}
				}
				if(doti==6)//数学成绩
				{
					
					wczs[wczsnum].math=0;
					for(temp95=chara-1;temp95>lchara;temp95--)
					{
						if(dat[chara-2]!='.')
						{
							if(temp95==chara-1) wczs[wczsnum].math+=(dat[temp95]-48);
							if(temp95==chara-2) wczs[wczsnum].math+=(dat[temp95]-48)*10;
							if(temp95==chara-3) wczs[wczsnum].math+=(dat[temp95]-48)*100;
						}
						else
						{
							if(temp95==chara-1) wczs[wczsnum].math+=1000;
							if(temp95==chara-3) wczs[wczsnum].math+=(dat[temp95]-48);
							if(temp95==chara-4) wczs[wczsnum].math+=(dat[temp95]-48)*10;
							if(temp95==chara-5) wczs[wczsnum].math+=(dat[temp95]-48)*100;
						}
					}
				}
				if(doti==7)//英语成绩
				{
					
					wczs[wczsnum].eng=0;
					for(temp95=chara-1;temp95>lchara;temp95--)
					{
						if(dat[chara-2]!='.')
						{
							if(temp95==chara-1) wczs[wczsnum].eng+=(dat[temp95]-48);
							if(temp95==chara-2) wczs[wczsnum].eng+=(dat[temp95]-48)*10;
							if(temp95==chara-3) wczs[wczsnum].eng+=(dat[temp95]-48)*100;
						}
						else
						{
							if(temp95==chara-1) wczs[wczsnum].eng+=1000;
							if(temp95==chara-3) wczs[wczsnum].eng+=(dat[temp95]-48);
							if(temp95==chara-4) wczs[wczsnum].eng+=(dat[temp95]-48)*10;
							if(temp95==chara-5) wczs[wczsnum].eng+=(dat[temp95]-48)*100;
						}
					}
				}
				
				if(doti==8)//物理成绩
				{
					wczs[wczsnum].physcore=0;
					for(temp95=chara-1;temp95>lchara;temp95--)
					{
						if(dat[chara-2]!='.')
						{
							if(temp95==chara-1) wczs[wczsnum].physcore+=(dat[temp95]-48);
							if(temp95==chara-2) wczs[wczsnum].physcore+=(dat[temp95]-48)*10;
							if(temp95==chara-3) wczs[wczsnum].physcore+=(dat[temp95]-48)*100;
						}
						else
						{
							if(temp95==chara-1) wczs[wczsnum].physcore+=1000;
							if(temp95==chara-3) wczs[wczsnum].physcore+=(dat[temp95]-48);
							if(temp95==chara-4) wczs[wczsnum].physcore+=(dat[temp95]-48)*10;
							if(temp95==chara-5) wczs[wczsnum].physcore+=(dat[temp95]-48)*100;
						}
					}
				}
				if(doti==9)//化学成绩
				{
					wczs[wczsnum].chemscore=0;
					for(temp95=chara-1;temp95>lchara;temp95--)
					{
						if(dat[chara-2]!='.')
						{
							if(temp95==chara-1) wczs[wczsnum].chemscore+=(dat[temp95]-48);
							if(temp95==chara-2) wczs[wczsnum].chemscore+=(dat[temp95]-48)*10;
							if(temp95==chara-3) wczs[wczsnum].chemscore+=(dat[temp95]-48)*100;
						}
						else
						{
							if(temp95==chara-1) wczs[wczsnum].chemscore+=1000;
							if(temp95==chara-3) wczs[wczsnum].chemscore+=(dat[temp95]-48);
							if(temp95==chara-4) wczs[wczsnum].chemscore+=(dat[temp95]-48)*10;
							if(temp95==chara-5) wczs[wczsnum].chemscore+=(dat[temp95]-48)*100;
						}
					}
				}
				if(doti==10)//生物成绩
				{
					wczs[wczsnum].bioscore=0;
					for(temp95=chara-1;temp95>lchara;temp95--)
					{
						if(dat[chara-2]!='.')
						{
							if(temp95==chara-1) wczs[wczsnum].bioscore+=(dat[temp95]-48);
							if(temp95==chara-2) wczs[wczsnum].bioscore+=(dat[temp95]-48)*10;
							if(temp95==chara-3) wczs[wczsnum].bioscore+=(dat[temp95]-48)*100;
						}
						else
						{
							if(temp95==chara-1) wczs[wczsnum].bioscore+=1000;
							if(temp95==chara-3) wczs[wczsnum].bioscore+=(dat[temp95]-48);
							if(temp95==chara-4) wczs[wczsnum].bioscore+=(dat[temp95]-48)*10;
							if(temp95==chara-5) wczs[wczsnum].bioscore+=(dat[temp95]-48)*100;
						}
					}
				}
				if(doti==11)//历史成绩
				{
					wczs[wczsnum].hisscore=0;
					for(temp95=chara-1;temp95>lchara;temp95--)
					{
						if(dat[chara-2]!='.')
						{
							if(temp95==chara-1) wczs[wczsnum].hisscore+=(dat[temp95]-48);
							if(temp95==chara-2) wczs[wczsnum].hisscore+=(dat[temp95]-48)*10;
							if(temp95==chara-3) wczs[wczsnum].hisscore+=(dat[temp95]-48)*100;
						}
						else
						{
							if(temp95==chara-1) wczs[wczsnum].hisscore+=1000;
							if(temp95==chara-3) wczs[wczsnum].hisscore+=(dat[temp95]-48);
							if(temp95==chara-4) wczs[wczsnum].hisscore+=(dat[temp95]-48)*10;
							if(temp95==chara-5) wczs[wczsnum].hisscore+=(dat[temp95]-48)*100;
						}
					}
				}
				if(doti==12)//地理成绩
				{
					wczs[wczsnum].geoscore=0;
					for(temp95=chara-1;temp95>lchara;temp95--)
					{
						if(dat[chara-2]!='.')
						{
							if(temp95==chara-1) wczs[wczsnum].geoscore+=(dat[temp95]-48);
							if(temp95==chara-2) wczs[wczsnum].geoscore+=(dat[temp95]-48)*10;
							if(temp95==chara-3) wczs[wczsnum].geoscore+=(dat[temp95]-48)*100;
						}
						else
						{
							if(temp95==chara-1) wczs[wczsnum].geoscore+=1000;
							if(temp95==chara-3) wczs[wczsnum].geoscore+=(dat[temp95]-48);
							if(temp95==chara-4) wczs[wczsnum].geoscore+=(dat[temp95]-48)*10;
							if(temp95==chara-5) wczs[wczsnum].geoscore+=(dat[temp95]-48)*100;
						}
					}
				}
				if(doti==13)//政治成绩
				{
					wczs[wczsnum].poliscore=0;
					for(temp95=chara-1;temp95>lchara;temp95--)
					{
						if(dat[chara-2]!='.')
						{
							if(temp95==chara-1) wczs[wczsnum].poliscore+=(dat[temp95]-48);
							if(temp95==chara-2) wczs[wczsnum].poliscore+=(dat[temp95]-48)*10;
							if(temp95==chara-3) wczs[wczsnum].poliscore+=(dat[temp95]-48)*100;
						}
						else
						{
							if(temp95==chara-1) wczs[wczsnum].poliscore+=1000;
							if(temp95==chara-3) wczs[wczsnum].poliscore+=(dat[temp95]-48);
							if(temp95==chara-4) wczs[wczsnum].poliscore+=(dat[temp95]-48)*10;
							if(temp95==chara-5) wczs[wczsnum].poliscore+=(dat[temp95]-48)*100;
						}
					}
				}
				lchara=chara;
			}
			
			chara++;

		}
		//三科成绩计算
		wczs[wczsnum].t3totals=wczs[wczsnum].math+wczs[wczsnum].chin+wczs[wczsnum].eng;
		if(wczs[wczsnum].t3totals>=3000)
		{
			wczs[wczsnum].t3totals-=2000;
			wczs[wczsnum].t3totals+=1;
		}
		if(wczs[wczsnum].t3totals>=2000)
		{
			wczs[wczsnum].t3totals-=2000;
			wczs[wczsnum].t3totals+=1;
		}
		
		wczsnum++;
	}
	//cout<<"数据读取完成，正在处理数据"<<endl;
	t3ksort();
	//cout<<"正在进行赋分"<<endl;
	phyksort();
	chemksort();
	bioksort();
	hisksort();
	geoksort();
	poliksort();
	
	for(int temp1009=0;temp1009<wczsnum;temp1009++)
	{
		wczs[temp1009].s6totals=wczs[temp1009].t3totals+wczs[temp1009].phycl+wczs[temp1009].chemcl
		+wczs[temp1009].biocl+wczs[temp1009].hiscl+wczs[temp1009].geocl+wczs[temp1009].policl;
	}
	s6ksort();
	//cout<<"正在输出数据"<<endl;
	fout<<"Class,ID,Name(UTF-8),Chinese,Maths,English,Physics,Chemistry,Biology,History,Geography,Politic,3_Subjects,3_Rank,6_Classified,Total_Ranking"<<endl;
	for(int temp532=0;temp532<wczsnum;temp532++)
	{
		fout<<wczs[temp532].stuclass<<","<<wczs[temp532].stuid<<","<<wczs[temp532].stuname<<",";
		k000output(wczs[temp532].chin);
		k000output(wczs[temp532].math);
		k000output(wczs[temp532].eng);
		fout<<wczs[temp532].phycl<<","<<wczs[temp532].chemcl<<","<<wczs[temp532].biocl<<","
		<<wczs[temp532].hiscl<<","<<wczs[temp532].geocl<<","<<wczs[temp532].policl<<",";
		k000output(wczs[temp532].t3totals);
		fout<<wczs[temp532].t3totala<<",";
		k000output(wczs[temp532].s6totals);
		fout<<wczs[temp532].s6totala;
		fout<<endl;
	}
	
	//cout<<"已完成数据输出"<<endl<<"version:0.2,	By Ant"<<endl;
	
	return 0;
}
