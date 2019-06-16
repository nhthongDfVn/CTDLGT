//cauh.h
struct cauh{
	int soluot;
	char sohieu[30];
};
struct dstt{
	int n;
	cauh *ds[300];
};
dstt cau_h;
/*void thongke(){
	int i,j;
	cau_h.n=0;
	LinkPTR xet=link;
	char sht[30];
	for(i=0;i<ds.n;i++){
		strcpy(sht,ds.nodes[i]->sohieu);
		strcpy(cau_h.ds[i]->sohieu,sht);
		cau_h.ds[i]->soluot=0;
		for(j=0;xet->next!=NULL;j++){
			if(!strcmp(xet->info.machuyenbay,sht)){
				cau_h.ds[i]->soluot++;
				cau_h.n++;
			};
			//&&xet=xet->next
			
		}
	}
}*/
void sortmb(){
	cauh tmp;
	int i,j;unsigned char check=1;
	while(check){
		check=0;
		for(i=0;i<cau_h.n-1;i++)
		{
			if(cau_h.ds[i]->soluot<cau_h.ds[i]->soluot)
			{
				tmp=*cau_h.ds[i];
				*cau_h.ds[i]=*cau_h.ds[i+1];
				*cau_h.ds[i+1]=tmp;
				check=1;
			}
		}
	}
}
void hienthicauf(){
	char k;
	setScreen();
	lptr First=NULL;
	lptr p=First;
	string tieude[2]={"|So hieu may bay                      ","|So luot thuc hien chuyen bay|"};
	coutcolor(40,3,125,tieude[0]);coutcolor(30+tieude[0].length(),3,125,tieude[1]);
    coutcolor(1,35,207,"       ESC: Thoat             |               P: Luu lai file thong ke                |                 Left, Right:    Chuyen trang                 ");
	if(ds.n==0) {
		coutcolor(30,4,127,"Khong co may bay nao de thong ke!");
		while(1){
			char n;
			n=getch();
			if(!n) {
				menu();
				break;
				return;
			}
		}
	}
	int b;
	int trang=1,sohangmax=20,j=1,sotrang,d,sohang;int m1=124,sh=sohangmax;
	if(ds.n<sohangmax) sh=ds.n;
	for(b=0;b<sh;b++){
		coutcolor(41,4+b,124,ds.nodes[b]->sohieu);
		coutcolor(41+tieude[0].length(),4+b,124,tostring(ds.nodes[b]->sochuyendathuchien));

	}
	int thutu=ds.n;
	
	sotrang=ds.n/sohangmax+1;
	coutcolor(1,1,144,"Trang "+tostring(trang)+"/"+tostring(sotrang));
	while(1){
		while(!kbhit()){
			k=getch();
			if(k==-32){
				k=getch();
				if(k==LEFT_KEY){
					if(trang>=2&&trang<=sotrang&&thutu>=(trang-1)*sohangmax){
					clearbang(sohangmax);
					trang--;
					coutcolor(1,1,144,"Trang "+tostring(trang)+"/"+tostring(sotrang));
					if(thutu-(trang-1)*sohangmax>=sohangmax) sohang=sohangmax; else sohang=thutu-(trang-1)*sohangmax;
					p=First;
						for(d=1;d<=sohang;d++){
							coutcolor(41,3+d,m1,ds.nodes[d-1]->sohieu);
							coutcolor(41+tieude[0].length(),3+d,m1,tostring(ds.nodes[d-1]->sochuyendathuchien));
							//p=p->next;
						}
												
					}
				}
				if(k==RIGHT_KEY){
					if(trang<sotrang&&thutu>=(trang-1)*sohangmax){
						clearbang(sohangmax);
						trang++;
						coutcolor(1,1,144,"Trang "+tostring(trang)+"/"+tostring(sotrang));
						if(thutu-(trang-1)*sohangmax>=sohangmax) sohang=sohangmax; else sohang=thutu-(trang-1)*sohangmax;
						p=First;
						for(d=1;d<=sohang;d++){
							coutcolor(41,3+d,m1,ds.nodes[d+(trang-1)*sohangmax-1]->sohieu);
							coutcolor(41+tieude[0].length(),3+d,m1,tostring(ds.nodes[d+(trang-1)*sohangmax-1]->sochuyendathuchien));
							//p=p->next;
						}
					}
				}
			}
			if(k==ESC_KEY){
				menu();
				break;break;
			}
			if(k=='P'||k=='p'){
				FILE *fp;
				int i;
				char a[60],b[60];strcpy(a,tieude[0].c_str());strcpy(b,tieude[1].c_str());
				char tenfile[30]="thongkemaybay.txt";
				fp=fopen(tenfile,"w");
				fprintf(fp,a);
				fprintf(fp,b);
				fprintf(fp,"\n");
				char st[1000];
				for(i=0;i<ds.n;i++){
					strcpy(st,tostring(ds.nodes[i]->sochuyendathuchien).c_str());
					fprintf(fp,ds.nodes[i]->sohieu);
					fprintf(fp,"                                        ");
					fprintf(fp,st);
					fprintf(fp,"\n");
				}
				fclose(fp);
				coutcolor(41,34,164,"Da luu file thong ke !");
			}
		}
	}
}
