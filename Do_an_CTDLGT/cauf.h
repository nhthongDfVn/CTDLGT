//cauf.h
/*struct cau_f{
	string machuyenbay;
	int sovecontrong;
	int gio,phut;
};
struct tt{
	int n;
	cau_f *ds[200];
};
tt dsm;
string datetostring(datetime d){
	return tostring(d.ngay.dd)+"/"+tostring(d.ngay.mm)+"/"+tostring(d.ngay.yy);
}*/
string giotostring(datetime a){
	return tostring(a.gio)+":"+tostring(a.phut);
}
/*void invetrong(string mcb){
	//for()
}*/
int sochoo(string machuyenbay){
	LinkPTR p;
	p=Link_Search(link,machuyenbay);
	int i=Array_Search(ds,setdata(p->info.sohieumb));
	return ds.nodes[i]->socho;
}
void cauf(string sanbayden, string ngaydi)
{
	setScreen();
	int i=0;
	chuyenbay b;
	LinkPTR p;
	int day,month,year,h;
	char sbd[30];
	chuyenbay a[50];
	h=(ngaydi[0]-'0')*10+(ngaydi[1]-'0');
	day=h;
	h=(ngaydi[3]-'0')*10+(ngaydi[4]-'0');
	month=h;
	h=(ngaydi[6]-'0')*1000+(ngaydi[7]-'0')*100+(ngaydi[8]-'0')*10+(ngaydi[9]-'0');
	year=h;
	setScreen();
	for (int i=0;i<=29;i++) sbd[i]=sanbayden[i]; sbd[29]='\0';

	for (p=link;p!=NULL;p=p->next)
	{
		if (p->info.thoigian.ngay.dd==day&&p->info.thoigian.ngay.mm==month&&p->info.thoigian.ngay.yy==year&&strcmp(p->info.sanbayden,sbd)==0)
		{
			a[i]=p->info;
			i++;
		}	
	}	
	int n=i;
	int m1=124;
	string tieude[3]={"|Ma chuyen bay                 ","|So ve con trong","|Gio khoi hanh|"};
	char k;
	if(n==0) coutcolor(40,4,126,"Khong co chuyen bay nao !");
	int trang=1,sohangmax=25,j=1,d,sohang,thutu=n;
	int sotrang;   
	coutcolor(1,35,207,"                          ESC: Thoat                   |                                  Left, Right:    Chuyen trang                              |");
	if(thutu%sohangmax==0) sotrang=thutu/sohangmax;else sotrang=thutu/sohangmax+1;
	//sotrang
	coutcolor(1,1,144,"Trang "+tostring(trang)+"/"+tostring(sotrang));
	coutcolor(40,3,125,tieude[0]+tieude[1]+tieude[2]);
	//trang dau
	if(n<sohangmax) sohang=n;
	int mau1=123;
	for(i=0;i<sohang;i++){
		string tmp=a[i].machuyenbay;
		coutcolor(41,4+i,121,tmp);
		coutcolor(41+tieude[0].length(),4+i,mau1,tostring(sochoo(tmp)-a[i].n));
		coutcolor(41+tieude[0].length()+tieude[1].length(),4+i,mau1,giotostring(a[i].thoigian));
	}
	
		while(1){
		while(!kbhit()){
			k=getch();
			thutu=n;
			if(k==-32){
				k=getch();
				if(k==LEFT_KEY){
					if(trang>=2&&trang<=sotrang&&thutu>=(trang-1)*sohangmax){
					clearbang(sohangmax);
					trang--;
					coutcolor(1,1,144,"Trang "+tostring(trang)+"/"+tostring(sotrang));
					if(thutu-(trang-1)*sohangmax>=sohangmax) sohang=sohangmax; else sohang=thutu-(trang-1)*sohangmax;
					//p=First;
						for(d=1;d<=sohang;d++){
							string tmp=a[d-1].machuyenbay;
							coutcolor(41,3+d,mau1,tmp);
							coutcolor(41+tieude[0].length(),3+d,mau1,tostring(sochoo(tmp)-a[d-1].n));
							coutcolor(41+tieude[0].length()+tieude[1].length(),3+d,mau1,giotostring(a[d-1].thoigian));
						}
												
					}
				}
				if(k==RIGHT_KEY){
					if(trang<sotrang&&thutu>=(trang-1)*sohangmax){
						clearbang(sohangmax);
						trang++;
						coutcolor(1,1,144,"Trang "+tostring(trang)+"/"+tostring(sotrang));
						if(thutu-(trang-1)*sohangmax>=sohangmax) sohang=sohangmax; else sohang=thutu-(trang-1)*sohangmax;
						//p=First;
						for(d=1;d<=sohang;d++){
							string tmp=a[d+(trang-1)*sohangmax-1].machuyenbay;
							coutcolor(41,3+d,mau1,tmp);
							coutcolor(41+tieude[0].length(),3+d,mau1,tostring(sochoo(tmp)-a[d+(trang-1)*sohangmax-1].n));
							coutcolor(41+tieude[0].length()+tieude[1].length(),3+d,mau1,giotostring(a[d+(trang-1)*sohangmax-1].thoigian));
						}
					}
				}
			}
			if(k==ESC_KEY){
				menu();
				break;break;
			}
			
		}
	}
}

