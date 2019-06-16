//bien toan cuc
//LinkPTR link;



void Link_nhapFile()
{
	fstream  filein("D:\\DATABASE_CHUYEN_BAY.DATA", ios::in  | ios::binary);
	fstream  filein1("D:\\DATABASE_DS_HANH_KHACH.DATA", ios::in| ios::binary);
	if (!filein||!filein1)
	{
		cout << "Khong the mo file de doc. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	chuyenbay info; 
	ds_ve info1;
	int i=0,size=0;
	while (filein.read(reinterpret_cast<char*>(&info), sizeof(chuyenbay)))
	{
		i=0;
		Link_Insert_First(link,info);
		size=link->info.n;
		link->info.trangthai=info.trangthai;
		Link_Array_Init(link);
		while (i<size)
		{
			filein1.read(reinterpret_cast<char*>(&info1), sizeof(ds_ve));
			//cout<<info1.cmnd<<" "<<info1.vitrighe<<endl;
			Link_Insert_Passenger(link,"",info1);
			i++;
		}
		
	}
	filein.close();	
	filein1.close();
}
void Link_xuatFile(LinkPTR  &link)
{
	fstream fileout("D:\\DATABASE_CHUYEN_BAY.DATA", ios::out | ios::binary);
	fstream fileout1("D:\\DATABASE_DS_HANH_KHACH.DATA", ios::out| ios::binary);
	if (!fileout||!fileout1)
	{
		cout << "Khong the mo file de ghi. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	LinkPTR p;
	int i=0;
	ds_ve ve;
	for (p=link; p!=NULL;p=p->next)
	{
		fileout.write(reinterpret_cast<char*>(&p->info), sizeof(chuyenbay));
		i=0;
		while (i<p->info.n)
		{
			ve=*(p->ds[i]);
			fileout1.write(reinterpret_cast<char*>(&ve), sizeof(ds_ve));	
			i++;
		} 	
	}	
	fileout.close();
	fileout1.close();
}
void Link_Init(LinkPTR &First)
{
	First=NULL;
}
int Link_Empty(LinkPTR &First)
{
	return First==NULL;
}
void Link_Insert_First(LinkPTR &First,chuyenbay info)
{
	LinkPTR p;
	info.trangthai=1;
	p=new Linknode;
	Link_Array_Init(p);
	p->info=info;
	p->next=First;
	First=p;
}
void Link_Insert_After(LinkPTR &First,chuyenbay info)
{
	LinkPTR q;
	if (First==NULL) return;
	else
	{
		q=new Linknode;
		q->info=info;
		q->next=First->next;
		First->next=q;
	}
}
void Link_Array_Init(LinkPTR &link)
{
	link->info.n=0;
}
int Link_Array_Full(LinkPTR &link)
{
	return link->info.n==250;
}
int Link_Insert_Passenger(LinkPTR &link,string machuyenbay,ds_ve info)
{
	LinkPTR p;
	int j;
	if (machuyenbay=="")
	{
		if (Link_Array_Full(link)==1) return 0;
		link->ds[link->info.n]=new ds_ve;
    	*(link->ds[link->info.n])=info;
		link->info.n++;
		return 1;
	}
	else
	{
		char z[30]; for (int i=0;i<30;i++) z[i]=machuyenbay[i];
		for (p=link;p!=NULL;p=p->next)
		{
			if (strcmp(p->info.machuyenbay,z)==0)
			{
				if (Link_Array_Full(p)==1) return 0;
				p->ds[p->info.n]=new ds_ve;
    			*(p->ds[p->info.n])=info;
				p->info.n++;
				return 1;
			}
		}
	}
	
}
int Link_Array_Delete(LinkPTR &link,string machuyenbay,int i)
{
	LinkPTR p;
	char z[30]; for (int k=0;k<30;k++) z[k]=machuyenbay[k];
	for(p=link;p!=NULL;p=p->next)
	{
		if (strcmp(p->info.machuyenbay,z)==0)
		{
			int j;
			if (i<0||i>=p->info.n||p->info.n==0) return 0;
			for (j=i+1;j<p->info.n;j++)
	  		*(p->ds[j-1])=*(p->ds[j]);
			delete p->ds[p->info.n];
			p->info.n--;
			return 1;
		}
	}
}
int Link_Array_Empty(LinkPTR &link)
{
	return link->info.n==0;
}
int Link_Array_Search(LinkPTR &link,string machuyenbay, long long cmnd)
{
	LinkPTR p;
	char z[30]; for (int i=0;i<30;i++) z[i]=machuyenbay[i];
	for(p=link;p!=NULL;p=p->next)
	{
		if (strcmp(p->info.machuyenbay,z)==0)
		{
			for (int i=0;i<p->info.n;i++)
			{
				if (p->ds[i]->cmnd==cmnd)
		    	return i;
			}  
		}
	}
	return -1;
}
int dadatve(long long cmnd)
{
	LinkPTR p;
	int m;
	for (p=link;p!=NULL;p=p->next)
	{
		m=p->info.n;
		for (int z=0;z<m;z++)
		{
			if (p->ds[z]->cmnd==cmnd) return 1;
		}
	}
	return 0;
}
void Link_Array_Update(LinkPTR &link,string machuyenbay,long long cmndcu,long long cmndmoi,int vtghe)
{
	LinkPTR p;
	int ok=0;
	char z[30]; for (int i=0;i<30;i++) z[i]=machuyenbay[i];
	for(p=link;p!=NULL;p=p->next)
	{
		if (strcmp(p->info.machuyenbay,z)==0)
		{
			for (int i=0;i<p->info.n;i++)
			{
				if (p->ds[i]->cmnd==cmndcu)
		    	{
		    		p->ds[i]->cmnd=cmndmoi;
		    		p->ds[i]->vitrighe=vtghe;
		    		ok=1;
		    		break;
				}
			}  
		}
		if (ok==1) break;
	}
	return ;
}
void Link_Traverse(LinkPTR link)
{
	LinkPTR p;
	int i=0;
	for (p=link; p!=NULL;p=p->next)
	{
		cout<<"THONG TIN MAY BAY "<<i<<endl;
		cout<<"Ma chuyen bay: "<<p->info.machuyenbay<<endl;
		cout<<"So ve da dat: "<<p->info.n<<endl;
		cout<<"San bay den: "<<p->info.sanbayden<<endl;
		cout<<"So hieu may bay: "<<p->info.sohieumb<<endl;
		i++;
	}
}
void Link_Delete_Info(LinkPTR &First, chuyenbay info)
{
	LinkPTR p=First;
	
	if (First==NULL) return;
	if (strcmp(First->info.machuyenbay,info.machuyenbay)==0)
	{
		p=First;
		First=p->next;
		delete p;
		return;
	}
	for (p!=First;p->next!=NULL&&strcmp(p->next->info.machuyenbay,info.machuyenbay)!=0;p=p->next);
	LinkPTR q=First;
	if (p->next!=NULL)
	{
		q=p->next;
		p->next=q->next;
		delete q;
		return;
	}
	return;
}
LinkPTR Link_Search(LinkPTR &first,string machuyenbay)
{
	char info[30];
	for (int i=0;i<30;i++) info[i]=machuyenbay[i];
	LinkPTR p;
	for (p=first; p!=NULL;p=p->next)
	  if (strcmp(p->info.machuyenbay,info)==0) return p;
	return NULL;
}

chuyenbay Link_setdata(khung a[6])
{
	int m;
	char z[30];
	chuyenbay info;
	m=(a[1].dulieu[0]-'0')*10+(a[1].dulieu[1]-'0');
	info.thoigian.ngay.dd=m;
	m=(a[1].dulieu[3]-'0')*10+(a[1].dulieu[4]-'0');
	info.thoigian.ngay.mm=m;
	m=(a[1].dulieu[6]-'0')*1000+(a[1].dulieu[7]-'0')*100+(a[1].dulieu[8]-'0')*10+(a[1].dulieu[9]-'0');
	info.thoigian.ngay.yy=m;
	m=(a[2].dulieu[0]-'0')*10+(a[2].dulieu[1]-'0');
	info.thoigian.gio=m;
	m=(a[2].dulieu[3]-'0')*10+(a[2].dulieu[4]-'0');
	info.thoigian.phut=m;
//	for (int j=3;j<=5;j++)
//	{
		for (int i=0;i<30;i++)
		{	
		//	z[i]=a[j].dulieu[i];
			info.sanbayden[i]=a[3].dulieu[i];
			info.machuyenbay[i]=a[4].dulieu[i];
			info.sohieumb[i]=a[5].dulieu[i];	
		}
		info.sanbayden[29]='\0';
		//if (j==3) strcpy(info.sanbayden,z);
		//if (j==4) strcpy(info.machuyenbay,z);
		//if (j==5) strcpy(info.sohieumb,z);
//	}
	info.trangthai=1;
	info.n=0;
	return info;
}
void Link_update(LinkPTR &link,khung a[6], string machuyenhientai)
{
	LinkPTR p;
	int trangthai,sl=0;
	char info[30];
	for (int i=0;i<30;i++) info[i]=machuyenhientai[i];
	for (p=link;p!=NULL;p=p->next)
	{
		if (strcmp(p->info.machuyenbay,info)==0)
		{
			sl=p->info.n;
			trangthai=p->info.trangthai;
			p->info=Link_setdata(a);
			p->info.trangthai=trangthai;
			p->info.n=sl;
		}
	}
	return;
}

void inthongtinchuyenbay(chuyenbay a[100], int vt)
{
	string s="                                            ";
	for (int i=10;i<=14;i++) coutcolor(81,i,241,s);
	s="Ma chuyen bay:   "+setdata(a[vt].machuyenbay);
	coutcolor(81,10,241,s);
	s="San bay den:    "+setdata(a[vt].sanbayden);
	coutcolor(81,11,241,s); coutcolor(125,11,120,"                    ");
	s="So hieu may bay: "+setdata(a[vt].sohieumb);
	coutcolor(81,12,241,s);
	s="Ngay bay:        ";
	if (a[vt].thoigian.ngay.dd<10) s=s+'0'+	tostring(a[vt].thoigian.ngay.dd); else s=s+	tostring(a[vt].thoigian.ngay.dd); s=s+"/";
    if (a[vt].thoigian.ngay.mm<10) s=s+'0'+	tostring(a[vt].thoigian.ngay.mm); else s=s+	tostring(a[vt].thoigian.ngay.mm); s=s+"/";
    s=s+tostring(a[vt].thoigian.ngay.yy);
	coutcolor(81,13,241,s);
	s="Gio bay:         ";
	if (a[vt].thoigian.gio<10) s=s+'0'+	tostring(a[vt].thoigian.gio); else s=s+	tostring(a[vt].thoigian.gio); s=s+":";
	if (a[vt].thoigian.phut<10) s=s+'0'+tostring(a[vt].thoigian.phut); else s=s+tostring(a[vt].thoigian.phut);
	
	coutcolor(81,14,241,s);
	s="Tinh trang: ";
	if (a[vt].trangthai==1) 
	{
		s=s+"Da dat "+tostring(a[vt].n)+" ve may bay  ";
		coutcolor(81,15,47,s);
	}
	else if (a[vt].trangthai==2)
	{
		s=s+"Da cat canh          ";
		coutcolor(81,15,47,s);
	}
	else
	{
		s=s+"Chuyen bay da bi huy ";
		coutcolor(81,15,78,s);
	}

}
void ket_qua_tim_chuyen_bay(string sanbayden,string ngaydi,int id)  //1: dat ve may bay //2 : tat ca chuyen bay hien co   //3 xoa    4: huy ve 5: xem ds hanh khach   6: xem ghe trong
{
	int sochuyen=0,k,vt=1,num=20,sopage=1;
	int page=1;
	string s="                                             ";
	string s1;
	chuyenbay a[100];
	int day,month,year,h;
	LinkPTR p,q;
	int i=1;
	char tt[30];
	char sbd[30];
	
	h=(ngaydi[0]-'0')*10+(ngaydi[1]-'0');
	day=h;
	h=(ngaydi[3]-'0')*10+(ngaydi[4]-'0');
	month=h;
	h=(ngaydi[6]-'0')*1000+(ngaydi[7]-'0')*100+(ngaydi[8]-'0')*10+(ngaydi[9]-'0');
	year=h;
	setScreen();
	for (int i=0;i<=29;i++) sbd[i]=sanbayden[i]; sbd[29]='\0';
	cout<<sanbayden<<endl;
	if (id==1)
	{
		for (p=link;p!=NULL;p=p->next)
		{
			if (p->info.thoigian.ngay.dd==day&&p->info.thoigian.ngay.mm==month&&p->info.thoigian.ngay.yy==year&&strcmp(p->info.sanbayden,sbd)==0)
			{
				a[i]=p->info;
				i++;	
				sochuyen++;
			}	
		}		
	}
	else
	{
		for (p=link;p!=NULL;p=p->next)
		{
			a[i]=p->info;
			i++;	
		}
	}
	setScreen();
	coutcolor(67,4,62," TIM KIEM CHUYEN BAY ");
	if (ngaydi!="")
	{
		string m="Tim thay ";
		m=m+tostring(sochuyen);
		m=m+" chuyen bay trong ngay "+ngaydi;
		coutcolor(60,6,62,m);
	}
	sochuyen=i-1;
	if (id==3) coutcolor(1,35,207,"            ESC: Quay lai            |                  Up,Down,Left,Right  : Di chuyen, chuyen trang               |             Enter: Xoa         ");	
	else if (id==4) coutcolor(1,35,207,"            ESC: Quay lai            |                  Up,Down,Left,Right  : Di chuyen, chuyen trang               |             Enter: Huy         ");
	else	coutcolor(1,35,207,"            ESC: Quay lai            |                  Up,Down,Left,Right  : Di chuyen, chuyen trang               |             Enter: Chon        ");
	if (sochuyen%num!=0) sopage=sochuyen/num+1; else sopage=sochuyen/num;
	s1="Trang ";
	sopage=1;
	s1=s1+tostring(page)+"/"+tostring(sopage);
	coutcolor(66,30,111,s1);
	
	
	
	coutcolor(30,9,139,"              Ket qua tim kiem               ");
	coutcolor(80,9,139,"            Thong tin chuyen bay             ");
	
	for (int i=0;i<20;i++)
	{
		coutcolor(30,10+i,241,s);
		coutcolor(80,10+i,241,s);
	}
	for (int i=1;i<=num&&i<=sochuyen;i++)
	{
		coutcolor(35,9+i,241,a[i].machuyenbay); 
	}
	
	coutcolor(30,10,111,s);
	coutcolor(35,10,111,a[1].machuyenbay);
	if (sochuyen>0) inthongtinchuyenbay(a,1);
	if (sochuyen>0)
	{
	while (1)
	{
		k=getch();
		if (k==ESC_KEY)
		{
			if (id==2||id==3||id==4) menu();      // 1: them 2: chinh sua  3: xoa 4: huy
			else tim_chuyen_bay(1);
		}
		if (k==ENTER_KEY)
		{
			if (id==1)
			{
				if (a[vt].trangthai==2||a[vt].trangthai==3)
				{
					for (int i=1;i<=6;i++)
					{					
						coutcolor(62,12+i,41,"                                      ");
					}	
					coutcolor(62,14,46,"  Ban khong the dat ve chuyen nay    ");
					coutcolor(78,17,95,"  OK  ");
					k=getch();
					ket_qua_tim_chuyen_bay(sanbayden,ngaydi,1);
				}
				else
				tim_kiem_hanh_khach(1,setdata(a[vt].machuyenbay)); 
			}
			if (id==2)
			{
				if (a[vt].trangthai==1)
					them_chuyen_bay(setdata(a[vt].sohieumb),setdata(a[vt].machuyenbay),2);    // chinh sua thong tin chuyen bay	
				else
				{
					for (int i=1;i<=6;i++)
					{					
						coutcolor(62,12+i,41,"                                      ");
					}	
					coutcolor(62,14,46,"      Khong the chinh sua!         ");
					coutcolor(78,17,95,"  OK  ");
					k=getch();
					ket_qua_tim_chuyen_bay("","",2);
				}
			}
			if (id==3)
			{
				for (int i=1;i<=6;i++)
				{					
					coutcolor(62,12+i,41,"                                       ");
				}	
				coutcolor(62,14,46,"     Ban co muon xoa khong?(Y/N)    ");
				coutcolor(62,17,95,"      Co(Y)       ");
				coutcolor(81,17,95,"     Khong(N)     ");
				coutcolor(1,1,130,"");
				while (1)
				{
					k=getch();
					{
						if (k==ESC_KEY)
						{
							ket_qua_tim_chuyen_bay("","",3);
						}
						if (k==89||k==121)
						{
							
							Link_Delete_Info(link,a[vt]);
							int gg=Array_Search(ds,setdata(	a[vt].sohieumb));
							ds.nodes[gg]->flag=0;
							// xoa thanh cong
							for (int i=1;i<=6;i++)
							{					
							coutcolor(62,12+i,41,"                                      ");
							}	
							coutcolor(62,14,46,"               Da xoa                ");
							coutcolor(78,17,95,"  OK  ");
							k=getch();
							ket_qua_tim_chuyen_bay("","",3);
						}
						if (k==78||k==110)
						{
							ket_qua_tim_chuyen_bay("","",3);
						}
					}
				}
			}
			if (id==4)
			{
				for (int i=1;i<=6;i++)
				{					
					coutcolor(62,12+i,41,"                                     ");
				}	
				coutcolor(62,14,46," Ban co muon huy chuyen khong?(Y/N)  ");
				coutcolor(62,17,95,"      Co(Y)       ");
				coutcolor(81,17,95,"     Khong(N)     ");
				coutcolor(1,1,130,"");
				
				while (1)
				{
					k=getch();
					if (k==ESC_KEY)
					{
						ket_qua_tim_chuyen_bay("","",4);
					}
					if (k==89||k==121)
					{	
						int gg=Array_Search(ds,setdata(	a[vt].sohieumb));
						ds.nodes[gg]->flag=0;
						for (int i=0;i<=29;i++) tt[i]=a[vt].machuyenbay[i];
						for (q=link;q!=NULL;q=q->next)
						{
							if (strcmp(q->info.machuyenbay,tt)==0)
							{
								if (q->info.trangthai==2) 
								{
									for (int i=1;i<=6;i++)
									{					
										coutcolor(62,12+i,41,"                                      ");
									}	
									coutcolor(62,14,46,"       Chuyen bay da hoan thanh      ");
									coutcolor(62,15,46,"            Khong the huy            ");
									coutcolor(78,17,95,"  OK  ");
									k=getch();
									ket_qua_tim_chuyen_bay("","",4);
									break;
								}
								q->info.trangthai=3;
								break;
							}
						}
						// huy chuyen bay thanh cong
						for (int i=1;i<=6;i++)
						{					
							coutcolor(62,12+i,41,"                                      ");
						}	
						coutcolor(62,14,46,"               Da huy                ");
						coutcolor(78,17,95,"  OK  ");
						k=getch();
						ket_qua_tim_chuyen_bay("","",4);
					}
					if (k==78||k==110)
					{
						ket_qua_tim_chuyen_bay("","",4);
					}
				}				
			}
			if (id==5) xuat_ds_nguoi(setdata(a[vt].machuyenbay));
			if (id==6) cho_ngoi(setdata(a[vt].machuyenbay),"",1,2);
		}
		if (k==224)
		{
			k=getch();
			switch(k)
			{
				case UP_KEY:
				{
					coutcolor(30,9+vt,241,s);
					coutcolor(35,9+vt,241,a[num*(page-1)+vt].machuyenbay);
					vt--; if (vt<=1) vt=1;
					coutcolor(30,9+vt,111,s);
					coutcolor(35,9+vt,111,a[num*(page-1)+vt].machuyenbay);
					inthongtinchuyenbay(a,vt);
					break;	
				}
				case DOWN_KEY:
				{
					coutcolor(30,9+vt,241,s);
					coutcolor(35,9+vt,241,a[num*(page-1)+vt].machuyenbay);
					vt++;if (vt>=num) vt=num;
					if (vt>sochuyen) vt=sochuyen;
					coutcolor(30,9+vt,111,s);
					coutcolor(35,9+vt,111,a[num*(page-1)+vt].machuyenbay);
					inthongtinchuyenbay(a,vt);
					break;
				}
			}
		}
	}
	}
	else
	{
		s="Khong co thong tin hien thi                 ";
		coutcolor(81,10,241,s);
		s=s+" ";
		coutcolor(30,10,241,s);
		while (1)
		{
			k=getch();
			if (k==ESC_KEY) 
				if (id==2) menu();
				else tim_chuyen_bay(1);
		}
		
	}
}
void tim_chuyen_bay(int sign)
{
	int vtsb=1;        // vtr tri lua chon san bay
	string san_bay[11]={
	"",
	" Noi Bai(HAN)                 ",
	" Cat Bi-Hai Phong(HPH)        ",
	" Vinh(VII)                    ",
	" Phu Bai-Hue(HUI)             ",
	" Da Nang(DAD)                 ",
	" Tan Son Nhat(SGN)            ",
	" Con Dao(PQC)                 ",
	" Can Tho(VCA)                 ",
	" Phu Quoc(PQC)                ",
	};
	int k;
	khung a[4];  //san bay di, san bay den, ngay khoi hanh
	int vt=1;     // vi tri chon lua
	int da_dien[3];
	
	//Setup man hinh
	setScreen();
	string temp;
	coutcolor(67,9,62," TIM KIEM CHUYEN BAY ");
	a[1].x=54; a[1].y=11; a[1].color=110; a[1].vt=1; a[1].tenkhung="San bay di:    "; a[1].dulieu=san_bay[6];
	a[2].x=54; a[2].y=13; a[2].color=241; a[2].vt=1; a[2].tenkhung="San bay den:   "; a[2].dulieu=" Enter de lua chon";
	a[3].x=54; a[3].y=15; a[3].color=241; a[3].vt=1; a[3].tenkhung="Ngay khoi hanh:"; 
	ve_khung(a[1]); 
	ve_khung(a[2]); 
	ve_khung(a[3]); 
	coutcolor(1,35,207,"     ESC: Thoat         |          F: Tim kiem chuyen bay          |          Up,Down,Left,Right  : Di chuyen         |        Enter:    Chon        ");
	
	
	while (1)
	{
		k=getch();
		
		// kiem tra dau vao
		if ((vt==2)&&(a[2].dulieu != " Enter de lua chon")) 
		{
			if (a[1].dulieu==a[2].dulieu) 
			{
				da_dien[vt]=0;
				coutcolor(a[vt].x+52,a[vt].y,122,"                                ");
				coutcolor(a[vt].x+52,a[vt].y,124," San bay den khong hop le       ");
			}
			else
			{
				da_dien[vt]=1;
				coutcolor(a[vt].x+52,a[vt].y,122,"                                ");
				coutcolor(a[vt].x+52,a[vt].y,122," OK                             ");
			}
		} 
		  	
		if (vt==3&&a[3].dulieu.length()>0)
		{
			if (check_ngay_thang(a[3].dulieu)==0)
			{
				da_dien[vt]=0;
				coutcolor(a[vt].x+52,a[vt].y,122,"                                ");
				coutcolor(a[vt].x+52,a[vt].y,124," Ngay khong hop le!             ");
			}
			else
			{	
				da_dien[vt]=1;
				coutcolor(a[vt].x+52,a[vt].y,122,"                                 ");							
				coutcolor(a[vt].x+52,a[vt].y,122," OK                              ");
			}
		}
		
		// cac phim tat dac biet
		if (k==70||k==102)  // phim F hoac f : tim kiem chuyen bay
		{
			if (da_dien[2]==1&&da_dien[3]==1)
			{
				if (sign==1) ket_qua_tim_chuyen_bay(a[2].dulieu,a[3].dulieu,1);
				if (sign==2) cauf(a[2].dulieu,a[3].dulieu);
			}
			else
			{
				
				for (int i=0;i<=5;i++)
				{					
				coutcolor(56,13+i,236,"                                     ");
				}	
				coutcolor(56,15,236,"  Vui long nhap tat ca cac truong  ");	
				k=getch();
				for (int i=0;i<=5;i++)
				{					
				coutcolor(56,13+i,119,"                                     ");
				}	
				ve_khung(a[2]);
				ve_khung(a[3]);
			}
		}
		if (k==ESC_KEY)
		{
			menu();
		}
		if (k==ENTER_KEY)
		{
			if (vt==1) continue;
			if (vt==3)
			{
				if (a[3].dulieu.length()>0)
				{
					if (check_ngay_thang(a[3].dulieu)==0)
					{
						da_dien[vt]=0;
						coutcolor(a[vt].x+52,a[vt].y,122,"                                ");
						coutcolor(a[vt].x+52,a[vt].y,124," Ngay khong hop le!             ");
					}
					else
					{						
						da_dien[vt]=1;
						coutcolor(a[vt].x+52,a[vt].y,122,"                                 ");							
						coutcolor(a[vt].x+52,a[vt].y,122," OK                              "); 
					}		
			    }
			    continue;
			}
			
			for (int i=1;i<=9;i++)
			{
				coutcolor(74,a[vt].y+i,78,san_bay[i]);	
			} 
			coutcolor(74,a[vt].y+vtsb,174,san_bay[vtsb]);	
			while (1)                  // lua chon san bay
			{
				k=getch();
				if (k==ENTER_KEY||k==ESC_KEY)
				{
					a[vt].dulieu=san_bay[vtsb];
					for (int i=1;i<=9;i++)
					{
						coutcolor(74,a[vt].y+i,119,"                                      ");	
					} 
					ve_khung(a[2]);
					ve_khung(a[3]);
					break;
				}
				if (k==224)
				{
					k=getch();
					switch(k)
					{
						case UP_KEY:
						{
							coutcolor(74,a[vt].y+vtsb,78,san_bay[vtsb]);
							vtsb--; if (vtsb<1) vtsb=9;
							coutcolor(74,a[vt].y+vtsb,174,san_bay[vtsb]);
							break;
						}
						case DOWN_KEY:
						{
							coutcolor(74,a[vt].y+vtsb,78,san_bay[vtsb]);
							vtsb++; if (vtsb>9) vtsb=1;
							coutcolor(74,a[vt].y+vtsb,174,san_bay[vtsb]);
							break;		
						}
					}
				}
			}
		}
		if (k==224)
		{
			k=getch();
			switch (k)
			{
				case DOWN_KEY:
				{
					a[vt].color=241; ve_khung(a[vt]); 
					vt++; if (vt>3) vt=1;
					a[vt].color=110;ve_khung(a[vt]); 
					break;
				}
				case UP_KEY:
				{
					a[vt].color=241; ve_khung(a[vt]); 
					vt--; if (vt<1) vt=3;
					a[vt].color=110;ve_khung(a[vt]);
					break;
				} 
				case LEFT_KEY:
				{
					if (vt==1||vt==2) break;
					string temp;
					temp=temp+a[vt].dulieu[a[vt].vt-1];
					coutcolor(a[vt].x+19+a[vt].vt,a[vt].y,110,temp);
					a[vt].vt--; if (a[vt].vt<=1) a[vt].vt=1;
					temp="";temp=temp+a[vt].dulieu[a[vt].vt-1];
					coutcolor(a[vt].x+19+a[vt].vt,a[vt].y,62,temp);
					break;
				}
				case RIGHT_KEY:
				{
					if (vt==1||vt==2) break;
					string temp1;
					temp1=temp1+a[vt].dulieu[a[vt].vt-1];
					coutcolor(a[vt].x+19+a[vt].vt,a[vt].y,110,temp1);
					a[vt].vt++; if (a[vt].vt>a[vt].dulieu.length()) a[vt].vt=a[vt].dulieu.length()+1;
					temp1="";temp1=temp1+a[vt].dulieu[a[vt].vt-1];
					coutcolor(a[vt].x+19+a[vt].vt,a[vt].y,62,temp1);
					break;
				}	
			}
		}
		else
		{
			if ((vt==3)&&(k>=48&&k<=57)||(k==BACKSPACE_KEY))
			{
				if (k==BACKSPACE_KEY) 
				{
					if (a[3].vt==4||a[3].vt==7) xoa_ky_tu(a[3]);
					xoa_ky_tu(a[3]);
					if (a[3].dulieu.length()==6||a[3].dulieu.length()==3) xoa_ky_tu(a[3]);
				}
				else
				{
					if (a[3].dulieu.length()==10) continue;
					them_ky_tu(a[vt],k);
					if (a[vt].dulieu.length()==2||a[vt].dulieu.length()==5) them_ky_tu(a[vt],47);
				}
				ve_khung(a[vt]);
				coutcolor(a[vt].x+20,a[vt].y,110,a[vt].dulieu);
				temp="";
				temp=a[vt].dulieu[a[vt].vt-1];
				if (temp.length()==0) temp=" ";
				coutcolor(a[vt].x+19+a[vt].vt,a[vt].y,62,temp);
			}
		}
	}
	
}

void Chuyenbaychecksave(khung aa[6],int da_dien[6],int  sign,string machuyenhientai)
{
	int k;
	int dem=0;
	for (int i=1;i<=5;i++) if (da_dien[i]==1) dem++;
	if (dem==5)
	{
		//ng dung du dieu kien de luu du lieu, da dien day du tat ca cac truong
		if (sign==1)
		{
			Link_Insert_First(link,Link_setdata(aa));
			int mm=Array_Search(ds,aa[5].dulieu);
			ds.nodes[mm]->flag=1;
				
			if (Link_Search(link,aa[4].dulieu)!=NULL)
			{
				coutcolor(60,25,110," Da them chuyen bay ");				// neu chuyen bay chua co trong danh sach
				cout<<link->info.machuyenbay;
				k=getch();
				menu();
			}
			else
			{
				coutcolor(60,25,110," Them that bai! ");				// neu chuyen bay chua co trong danh sach
			}				
		}
		else
		{
			Link_update(link,aa,machuyenhientai);
			coutcolor(60,25,110,"  Luu thanh cong ");				// ng dung chinh sua may bay trong ds chuyen chuyen bay
			k=getch();
			menu();
		}
	}
	else
	{
		coutcolor(60,25,124,"Ban phai dien tat ca cac truong!");	// neu ng dung chua dien xong ma doi luu 
	}
}
void them_chuyen_bay(string mamaybay,string machuyenbay,int  sign )  //1 them 2// sua 3 xoa
{
	//menu save
	int flag=0;	 //nhan biet xem ng dung co nhap hay chinh sua gi khong?
	string save[4]={" "," Luu "," Khong luu "," Huy bo "};
	int vtsave=1;	//save/ don't save or cancel
	khung aa[15];
	int k,vtri=1;
	int da_dien[6];		// check for filled
	int vtsb=1;        // vtr tri lua chon san bay
	string machuyenhientai;
	string san_bay[11]={
	"",
	" Noi Bai(HAN)                 ",
	" Cat Bi-Hai Phong(HPH)        ",
	" Vinh(VII)                    ",
	" Phu Bai-Hue(HUI)             ",
	" Da Nang(DAD)                 ",
	" Con Dao(PQC)                 ",
	" Can Tho(VCA)                 ",
	" Phu Quoc(PQC)                ",
	};
	
	string temp;
	setScreen();
	coutcolor(67,4,236," THONG TIN CHUYEN BAY ");
	aa[1].id=1; aa[1].x=49; aa[1].y=8;   aa[1].tenkhung="Ngay khoi hanh  ";   aa[1].color=110; aa[1].vt=1;
	aa[2].id=2; aa[2].x=49; aa[2].y=10;  aa[2].tenkhung="Gio bay         ";   aa[2].color=241; aa[2].vt=1;
	aa[3].id=3; aa[3].x=49; aa[3].y=12;  aa[3].tenkhung="San bay den     ";   aa[3].color=241; aa[3].vt=1; aa[3].dulieu=" Enter de lua chon ";
	aa[4].id=4; aa[4].x=49; aa[4].y=14;  aa[4].tenkhung="Ma chuyen bay   ";   aa[4].color=241; aa[4].vt=1; 
	aa[5].id=5; aa[5].x=49; aa[5].y=16;  aa[5].tenkhung="May bay         ";   aa[5].color=241; aa[5].vt=1; aa[5].dulieu=mamaybay;   flag=1;

	if (sign==2)
	{      
		LinkPTR p;
		p=Link_Search(link,machuyenbay);
		string temp;
						
		
		
		//get ngay
		if (p->info.thoigian.ngay.dd<10) temp=temp+"0"+tostring(p->info.thoigian.ngay.dd)+"/";
		else temp=temp+tostring(p->info.thoigian.ngay.dd)+"/";
		
		if (p->info.thoigian.ngay.mm<10) temp=temp+"0"+tostring(p->info.thoigian.ngay.mm)+"/"+tostring(p->info.thoigian.ngay.yy);
		else temp=temp+tostring(p->info.thoigian.ngay.mm)+"/"+tostring(p->info.thoigian.ngay.yy);
		aa[1].dulieu=temp; temp="";
		//get gio, phut
		if (p->info.thoigian.gio<10) temp=temp+"0"+tostring(p->info.thoigian.gio)+":";
		else temp=temp+tostring(p->info.thoigian.gio)+":";
		if (p->info.thoigian.phut <10) temp=temp+"0"+tostring(p->info.thoigian.phut);
		else temp=temp+tostring(p->info.thoigian.phut);
		aa[2].dulieu=temp; temp="";
		
		//get san bay den
		temp="";
		for (int i=0;i<30;i++) temp=temp+p->info.sanbayden[i];
		aa[3].dulieu=temp;
	//	 cout<<p->info.sanbayden[i];
		//get ma chuyen bay
		aa[4].dulieu=setdata(p->info.machuyenbay);
		machuyenhientai=aa[4].dulieu;
		//get may bay
		aa[5].dulieu=setdata(p->info.sohieumb);
		flag=1;
		for (int i=1;i<=5;i++) da_dien[i]=1;
	}
	
	ve_khung(aa[1]);
	ve_khung(aa[2]);
	ve_khung(aa[3]);
	ve_khung(aa[4]);
	ve_khung(aa[5]);
	coutcolor(72,19,236," Luu lai ");
	coutcolor(1,35,207,"               ESC: Thoat                 |                     Up,Down,Left,Right  : Di chuyen              |             Enter:    Chon           ");
	// bat dau nhan phim
	while (1)
	{
		k=getch();
		// kiem tra tinh dung dan cua du lieu dau vao
		if (vtri!=6) 
		if (aa[vtri].dulieu.length()>0) 
		{	
			if (vtri==1)
			{
				if (check_ngay_thang(aa[1].dulieu)==0)
				{
					da_dien[vtri]=0;
					coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
					coutcolor(aa[vtri].x+52,aa[vtri].y,124," Ngay thang khong hop le!");
				}
				else
				{
					if (thoigianhientai(aa[1].dulieu,aa[2].dulieu)==2)
					{
						da_dien[vtri]=1;
						coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                 ");
						coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
					}
					else
					{
						da_dien[vtri]=0;
						coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
						coutcolor(aa[vtri].x+52,aa[vtri].y,124," Ngay thang khong hop le!");
					}
				}
			}
			else if (vtri==3)
			{
				if (aa[3].dulieu==" Enter de lua chon ")
				{
					da_dien[vtri]=0;
					coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
					coutcolor(aa[vtri].x+52,aa[vtri].y,124," San bay den khong hop le!");
				}
				else
				{
					da_dien[vtri]=1;
					coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                 ");
					coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
				}
			}
			else
			if (vtri==2)
			{
				if (check_thoi_gian(aa[vtri].dulieu)==0)
				{
					da_dien[vtri]=0;
					coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
					coutcolor(aa[vtri].x+52,aa[vtri].y,124," Thoi gian khong hop le!");
				}
				else
				{
					if (thoigianhientai(aa[1].dulieu,aa[2].dulieu)==2)
					{
						da_dien[vtri]=1;
						coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                 ");
						coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
					}
					else
					{
						da_dien[vtri]=0;
						coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
						coutcolor(aa[vtri].x+52,aa[vtri].y,124," Thoi gian khong hop le!");
					}
				}
			}
			else if (vtri==4)
			{
				if (machuyenhientai==aa[4].dulieu)
				{
					da_dien[vtri]=1;
					coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                 ");
					coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
				}
				else
				{
					if (Link_Search(link,aa[4].dulieu)==NULL)
					{
						da_dien[vtri]=1;
					    coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                 ");
						coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
					}
					else
					{
						da_dien[vtri]=0;
						coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
						coutcolor(aa[vtri].x+52,aa[vtri].y,124," Ma chuyen bay da ton tai!");
					}
				}
			}
			else
			{
				da_dien[vtri]=1;
			    coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                 ");
				coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
			}
		}
		else 
		{
			da_dien[vtri]=0;
			coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                          ");	
		}
		
		// cac phim tat dac biet
		if (k==ENTER_KEY)
		{
			if (vtri!=6) 
			{
				if (vtri==3)
				{
					for (int i=1;i<=9;i++)
					{
						coutcolor(70,aa[vtri].y+i,78,san_bay[i]);	
					} 
					coutcolor(70,aa[vtri].y+vtsb,174,san_bay[vtsb]);
					while (1)                  // lua chon san bay	
					{
						k=getch();
						if (k==ENTER_KEY||k==ESC_KEY)
						{
							aa[vtri].dulieu=san_bay[vtsb];
							for (int i=1;i<=9;i++)
							{
							coutcolor(70,aa[vtri].y+i,119,"                                          ");	
							}		 
						ve_khung(aa[3]);
						ve_khung(aa[4]);
						ve_khung(aa[5]);
						coutcolor(72,19,236," Luu lai ");	
						break;
						}
						if (k==224)
						{
							k=getch();
							switch(k)
							{
								case UP_KEY:
								{
									coutcolor(70,aa[vtri].y+vtsb,78,san_bay[vtsb]);
									vtsb--; if (vtsb<1) vtsb=8;
									coutcolor(70,aa[vtri].y+vtsb,174,san_bay[vtsb]);
									break;
								}
								case DOWN_KEY:
								{
									coutcolor(70,aa[vtri].y+vtsb,78,san_bay[vtsb]);
									vtsb++; if (vtsb>8) vtsb=1;
									coutcolor(70,aa[vtri].y+vtsb,174,san_bay[vtsb]);
									break;		
								}
							}
						}
					}	
						
				}
				aa[vtri].color=241; ve_khung(aa[vtri]);
			}
			vtri++; 
			if (vtri>=6&&k==ENTER_KEY) 
			{
				if (vtri==6)
				{
					vtri=6;
					coutcolor(72,19,110," Luu lai ");	
				}
				else
				{
					vtri=6;
					flag=0;
					coutcolor(72,19,110," Luu lai ");
					if (sign==1) Chuyenbaychecksave(aa,da_dien,1,machuyenhientai); else Chuyenbaychecksave(aa,da_dien,2,machuyenhientai);
				}
			}
			else
			{
				aa[vtri].color=110; ve_khung(aa[vtri]);	
		    }	
		}
		if (k==ESC_KEY)
		{
		if (flag==1)
			{
				for (int i=1;i<=6;i++)
				{					
				  coutcolor(62,12+i,41,"                                         ");
				}	
				if (sign==1)
				{
					coutcolor(62,14,46," Ban co muon them chuyen bay khong?(Y/N) ");
					coutcolor(62,17,95,"    Co(Y)   ");
					coutcolor(75,17,95,"   Khong(N)  ");
					coutcolor(89,17,95,"   Huy(ESC)   ");
					coutcolor(1,1,130,"");
					while (1)
					{
						k=getch();
						if (k==ESC_KEY)
						{
							for (int i=1;i<=6;i++)
							{					
								coutcolor(62,12+i,120,"                                          ");
							}	
							ve_khung(aa[3]);
							ve_khung(aa[4]);
							ve_khung(aa[5]);
							break;
						}
						if (k==89||k==121)
						{
							Chuyenbaychecksave(aa,da_dien,1,machuyenhientai);
						}
						if (k==78||k==110)
						{
							if (sign==1 ) menu(); else chon_may_bay(1);
						}
					}
				}
				else if (sign==2)
				{
					coutcolor(62,14,46,"  Ban co muon luu chuyen bay khong?(Y/N) ");
					coutcolor(62,17,95,"    Co(Y)   ");
					coutcolor(75,17,95,"   Khong(N)  ");
					coutcolor(89,17,95,"   Huy(ESC)   ");
					coutcolor(1,1,130,"");
					while (1)
					{
						k=getch();
						if (k==ESC_KEY)
						{
							for (int i=1;i<=6;i++)
							{					
								coutcolor(62,12+i,120,"                                          ");
							}	
							ve_khung(aa[3]);
							ve_khung(aa[4]);
							ve_khung(aa[5]);
							break;
						}
						if (k==89||k==121)
						{
							Chuyenbaychecksave(aa,da_dien,2,machuyenhientai);
						}
						if (k==78||k==110)
						{
							ket_qua_tim_chuyen_bay("","",2);
						}
						
					}	
				}	
			}
			else 
			{
				menu();
			}
		}
		if (k==224)
		{
			k=getch();
			switch(k)
			{
				case DOWN_KEY:
				{
					if (vtri!=6) 
					{
					    aa[vtri].color=241; ve_khung(aa[vtri]);	
					} 
					vtri++; 
					if (vtri<6) 
					{
						aa[vtri].color=110; ve_khung(aa[vtri]); if(aa[vtri].dulieu.length()>0) aa[vtri].vt=aa[vtri].dulieu.length()+1;		
					}
					else 
					{
						vtri=6;
						coutcolor(72,19,110," Luu lai ");	
					}
					break;
				}
				case UP_KEY:
				{
					if (vtri==6) 
					{
						coutcolor(72,19,236," Luu lai "); 
						vtri=5; 
					} 
					else 
					{
					 	aa[vtri].color=241; 
						ve_khung(aa[vtri]);
						vtri--; 
					} 
				    if (vtri==0) vtri=1;
					aa[vtri].color=110; ve_khung(aa[vtri]); if(aa[vtri].dulieu.length()>0)  aa[vtri].vt=aa[vtri].dulieu.length()+1;
					break;
				}
				case LEFT_KEY:
				{
					if (vtri==3||vtri==5||vtri==6) continue;
					string temp;
					temp=temp+aa[vtri].dulieu[aa[vtri].vt-1];
					coutcolor(aa[vtri].x+20+aa[vtri].vt,aa[vtri].y,110,temp);
					aa[vtri].vt--; if (aa[vtri].vt<=1) aa[vtri].vt=1;
					temp="";temp=temp+aa[vtri].dulieu[aa[vtri].vt-1];
					coutcolor(aa[vtri].x+20+aa[vtri].vt,aa[vtri].y,62,temp);
					break;
				}
				case RIGHT_KEY:
				{
					if (vtri==3||vtri==5||vtri==6) continue;
					string temp1;
					temp1=temp1+aa[vtri].dulieu[aa[vtri].vt-1];
					coutcolor(aa[vtri].x+20+aa[vtri].vt,aa[vtri].y,110,temp1);
					aa[vtri].vt++; if (aa[vtri].vt>aa[vtri].dulieu.length()) aa[vtri].vt=aa[vtri].dulieu.length()+1;
					temp1="";temp1=temp1+aa[vtri].dulieu[aa[vtri].vt-1];
					coutcolor(aa[vtri].x+20+aa[vtri].vt,aa[vtri].y,62,temp1);
					break;
				}	
			}		
		}
		else
		if (((k>=65&&k<=90)||(k>=97&&k<=122)||k==SPACE_KEY||k==45||k==BACKSPACE_KEY||(k>=48&&k<=57))&&(vtri>=1&&vtri<=5))
		{
				if (k==SPACE_KEY&&aa[vtri].dulieu[aa[vtri].dulieu.length()-1]==SPACE_KEY) continue;
				if (vtri==3||vtri==5) continue;
				if ((vtri==1||vtri==2)&&((k>=65&&k<=90)||(k>=97&&k<=122)||k==SPACE_KEY)||aa[1].dulieu.length()>10||aa[2].dulieu.length()>5||aa[4].dulieu.length()>15)
				{
					continue;
				}
				flag=1;
				if (k==BACKSPACE_KEY) 
				{
					if (vtri==1) if (aa[vtri].vt==4||aa[vtri].vt==7) xoa_ky_tu(aa[vtri]);
					if (vtri==2||vtri==4) if (aa[vtri].vt==4) xoa_ky_tu(aa[vtri]);
					xoa_ky_tu(aa[vtri]);
					if (vtri==1) if (aa[1].dulieu.length()==6||aa[1].dulieu.length()==3) xoa_ky_tu(aa[vtri]);
					if (vtri==2) if (aa[2].dulieu.length()==3) xoa_ky_tu(aa[vtri]);
				}
				else
				{
					if (vtri==1&&(aa[vtri].dulieu.length()==10)) continue;
					if ((vtri==2)&&aa[vtri].dulieu.length()==5) continue;
					them_ky_tu(aa[vtri],k);
					if (vtri==1) if (aa[vtri].dulieu.length()==2||aa[vtri].dulieu.length()==5) them_ky_tu(aa[vtri],47);
					if (vtri==2) if (aa[vtri].dulieu.length()==2) them_ky_tu(aa[vtri],58);
				}
				ve_khung(aa[vtri]);
				coutcolor(aa[vtri].x+21,aa[vtri].y,110,aa[vtri].dulieu);
				temp="";
				temp=aa[vtri].dulieu[aa[vtri].vt-1];
				if (temp.length()==0) temp=" ";
				coutcolor(aa[vtri].x+20+aa[vtri].vt,aa[vtri].y,62,temp);
		}	
   }
}
