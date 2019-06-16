//cauh.h
LinkPTR ds_co_ve(string mcb){
	LinkPTR l=Link_Search(link,mcb);
	return l;
}
void Sort_dsve(LinkPTR &p){
	int i,j;unsigned char check=1;
	ds_ve tmp;
	while(check){
		check=0;
		for(i=0;i<p->info.n-1;i++)
		{
			if(p->ds[i]->vitrighe>p->ds[i+1]->vitrighe)
			{
				tmp=*p->ds[i];
				*p->ds[i]=*p->ds[i+1];
				*p->ds[i+1]=tmp;
				check=1;
			}
		}
	}
	
}
struct cau_e{
	int stt;
	int sove;
	long long cmnd;
	char hoten[30];
	int phai;
};
struct linknode{
	cau_e info;
	linknode *next;
};
typedef linknode *lptr;

void Ins_Fir_ve(lptr &First, cau_e x) {    
	lptr p;    
	p = new linknode;    
	p->info = x;    
	p->next = First;    
	First = p; 
} 
int Ins_aft_ve(lptr p, cau_e x)
{
	if(p!=NULL){
	
 	lptr q;
 	q =new linknode;
 	q->info = x;
 	q->next = p->next;
 	p->next = q;
 	return 1;
	}
	return 0;
}
lptr search_next_null(lptr first){
	lptr p;
	p=first;
	while(p->next!=NULL){p=p->next;
		//if(p->next==NULL) return p;
	};
	return p;
}
void gp(lptr &First){
	lptr p;
	if(First==NULL) return;
	while (p != NULL){
		p=First;
		First=First->next;
		delete p;
	}
}
void clearbang(int n){
	int i;
	for(i=0;i<n;i++){
		coutcolor(1,4+i,120,"                                                                                                           ");
	}
}
string namnu(int phai){
    if(phai==1) return "NAM";
    if(phai==0) return "NU";
    if(phai==2) return "KHAC";
}

void xuat_ds_nguoi(string mcb){
			setScreen();
			lptr First=NULL;
			cau_e hang;
			LinkPTR tro;
			tro=ds_co_ve(mcb);
			Sort_dsve(tro);
			char qw;
			string x="DANH SACH HANH KHACH THUOC MA CHUYEN BAY "+mcb;
			//Link_Insert_Passenger(link,mcb,d);
			
				//	coutcolor(110+error.length(),2,124,"                                             ");
					int i,thutu=0,tam=tro->info.n;
					for(i=0;i<tam;i++){
						long long tmp=tro->ds[i]->cmnd;
						thutu++;
						hang.cmnd=tmp;
						hang.sove=tro->ds[i]->vitrighe;
						hang.stt =thutu;
						NODEPTR trptr=Tree_Location(tree,tmp);
						strcpy(hang.hoten,trptr->info.hoten);
						hang.phai=trptr->info.gioitinh;
						
						
			
						if(thutu==1) Ins_Fir_ve(First,hang);
						else {
							Ins_aft_ve(search_next_null(First),hang);
						}
					}
					int trang=1,sohangmax=20,j=1,d,sohang;
					
					//int t;
					/*for(t=First;t!=NULL;t=t->next){
						p=t;
						p=p->
					}*/
					int sotrang;
					if(thutu%sohangmax==0) sohang=thutu/sohangmax; else sohang=thutu/sohangmax+1;
					coutcolor(1,1,144,"Trang "+tostring(trang)+"/"+tostring(sotrang));
					
					coutcolor(75-x.length()/2,1,164,x);
					//string hangduoi="|   Esc: Tro ve menu chinh    |  Left, Right: Chuyen trang | P: Luu lai file thong ke";       
                    coutcolor(1,35,207,"       ESC: Thoat             |               P: Luu lai file thong ke                |                 Left, Right:    Chuyen trang                 ");
             
					
					//voi moi trang co 30 nguoi thi for(trang*30+1,i<=(trang+1)*30;i++)
					//stt-so ve-so cmnd-ho ten- phai
					string hangdau[6]={"|STT ","|  SO VE  ","|      CMND        ","|           HO TEN          ","|  PHAI   |"};
					lptr p=First;
					int m1=121;
					coutcolor(40,3,125,hangdau[0]);coutcolor(40+hangdau[0].length(),3,125,hangdau[1]);coutcolor(40+hangdau[0].length()+hangdau[1].length(),3,125,hangdau[2]);coutcolor(40+hangdau[0].length()+hangdau[1].length()+hangdau[2].length(),3,125,hangdau[3]);coutcolor(40+hangdau[0].length()+hangdau[1].length()+hangdau[2].length()+hangdau[3].length(),3,125,hangdau[4]);
					if(thutu==0) {
						while(1){
							coutcolor(41,4,126,"May bay nay chua co hanh khach!");
							qw=getch();
							if(!qw) break;
							menu();
							return;
							
						}
					}
					else{
						//trang dau tien
						for(j=1;j<=sohangmax;j++)
						//for(p=First;p!=NULL;p=p->next)
						{
							if(p==NULL) 
								{
								break;
							    }
							else {
								coutcolor(41,j+3,m1,tostring(p->info.stt));
								coutcolor(44+hangdau[0].length(),j+3,m1,tostring(p->info.sove));
								string ht=p->info.hoten;
								coutcolor(41+hangdau[0].length()+hangdau[1].length(),j+3,m1,tostring(p->info.cmnd));
								coutcolor(41+hangdau[0].length()+hangdau[1].length()+hangdau[2].length(),j+3,m1,ht);
								coutcolor(43+hangdau[0].length()+hangdau[1].length()+hangdau[2].length()+hangdau[3].length(),j+3,m1,namnu(p->info.phai));
								p=p->next;
								
							}
							
						}
						
						while(1){
							while(!kbhit()){
								char k=getch();
								if(k==-32){
									k=getch();
									if(k==LEFT_KEY){
										if(trang>=2&&trang<=sotrang&&thutu>=(trang-1)*sohangmax){
											clearbang(sohangmax);
											trang--;
											coutcolor(1,1,144,"Trang "+tostring(trang)+"/"+tostring(sotrang));
											if(thutu-(trang-1)*sohangmax>=sohangmax) sohang=sohangmax; else sohang=thutu-(trang-1)*sohangmax;
											p=First;
											while(p->info.stt!=sohangmax*(trang-1)+1)  p=p->next;
											for(d=1;d<=sohang;d++){
												coutcolor(41,d+3,m1,tostring(p->info.stt));
												coutcolor(44+hangdau[0].length(),d+3,m1,tostring(p->info.sove));
												string ht=p->info.hoten;
												coutcolor(41+hangdau[0].length()+hangdau[1].length(),d+3,m1,tostring(p->info.cmnd));
												coutcolor(41+hangdau[0].length()+hangdau[1].length()+hangdau[2].length(),d+3,m1,ht);
												coutcolor(43+hangdau[0].length()+hangdau[1].length()+hangdau[2].length()+hangdau[3].length(),d+3,m1,namnu(p->info.phai));
												p=p->next;
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
											while(p->info.stt!=sohangmax*(trang-1)+1)  p=p->next;
											for(d=1;d<=sohang;d++){
												coutcolor(41,d+3,m1,tostring(p->info.stt));
												coutcolor(44+hangdau[0].length(),d+3,m1,tostring(p->info.sove));
												string ht=p->info.hoten;
												coutcolor(41+hangdau[0].length()+hangdau[1].length(),d+3,m1,tostring(p->info.cmnd));
												coutcolor(41+hangdau[0].length()+hangdau[1].length()+hangdau[2].length(),d+3,m1,ht);
												coutcolor(43+hangdau[0].length()+hangdau[1].length()+hangdau[2].length()+hangdau[3].length(),d+3,m1,namnu(p->info.phai));
												p=p->next;
											}
										}
									}
								}
								if(k==ESC_KEY){
									//gp(First);
									//gp(p);
									menu();
									break;break;
								}
								if(k=='P'||k=='p'){
									FILE *fp;
									char tenfile[34]="";strcat(tenfile,tro->info.machuyenbay);strcat(tenfile,".txt");
									fp=fopen(tenfile,"w");
									p=First;
									for(i=0;i<tam;i++){
										char st[4];strcpy(st,tostring(p->info.stt).c_str());
										fprintf(fp,st);
										fprintf(fp," ");
										strcpy(st,tostring(p->info.sove).c_str());
										fprintf(fp,st);
										fprintf(fp," ");
										fprintf(fp,p->info.hoten);
										fprintf(fp," ");
										char gt[5];strcpy(gt,namnu(p->info.phai).c_str());
										fprintf(fp,gt);
										fprintf(fp," ");
										string c=tostring(p->info.cmnd);char cm[13];strcpy(cm,c.c_str());
										fprintf(fp,cm);
										fprintf(fp,"\n");
										p=p->next;
									}
									fclose(fp);
									coutcolor(41,34,164,"Da ghi file !");
								}
				
							}
						}
					}
				
}



