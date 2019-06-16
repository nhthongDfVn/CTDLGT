//Bien toan cuc
//NODEPTR tree;
int ghe[251][7];
khung temp1[6];               // luu du lieu tam. cho phan chon ghe

//Hàm chuc nang su dung trong hanh khach

void tim_kiem_hanh_khach(int sign,string machuyenbay)            //1 Dat ve moi   2: chinh sua chuyen bay   3: huy ve  
{
	int k,dem,trangthai=0;
	char mk[30];
	khung a;
	LinkPTR q;
	setScreen();
	string temp;
	for (int i=1;i<=3;i++)
	{					
		coutcolor(56,9+i,57,"                                     ");
	}	
	for (int i=0;i<=5;i++)
	{					
		coutcolor(56,13+i,236,"                                     ");
	}		
	coutcolor(63,11,62," Vui long nhap so CMND "); 
	coutcolor(1,35,207,"                         ESC: Thoat                            |                                         Enter:    Chon                              ");
	a.x=54; a.y=15; a.color=110; a.vt=1;
	ve_khung(a);
	while (1)
	{
		k=getch();
		if (k==ESC_KEY)
		{
			menu();
		}
		if (k==ENTER_KEY)
		{
			if (a.dulieu.length()==9||a.dulieu.length()==12)
			{
				trangthai=0;
				for (q=link;q!=NULL;q=q->next)
				{
					dem=q->info.n;
					for (int z=0;z<dem;z++)
					{
						if (q->ds[z]->cmnd==toint(a.dulieu))
						{
							trangthai=q->info.trangthai;
							break;	
						}	
					}	
				}
				if (sign==1)
				{	
					if (dadatve(toint(a.dulieu))==1)
					{
						coutcolor(54,22,120,"                                            ");
						coutcolor(54,22,78,"         Ban da dat ve roi!             ");	 
					}
					else if (trangthai==2||trangthai==3)
					{
						coutcolor(54,22,120,"                                            ");
						coutcolor(54,22,78,"    Ban khong the dat ve chuyen bay nay     ");	 
					}
					else
					{
						if (Tree_Search(tree,toint(a.dulieu))==1) 
						{
							DatVe(toint(a.dulieu),2,"",machuyenbay,"");
						}
				    	else DatVe(toint(a.dulieu),1,"",machuyenbay,"");
					}
				}
				else if (sign==2)
				{
					if (trangthai==2)
					{
						coutcolor(54,22,120,"                                            ");
						coutcolor(54,22,78,"        Khong the sua thong tin          ");	 
					}
					else 
					if (trangthai==3)
					{
						coutcolor(54,22,120,"                                            ");
						coutcolor(54,22,78,"  Chuyen bay da bi huy! Hay huy ve truoc    ");	 
						k=getch();
						huyve(toint(a.dulieu));
					}
					else
					{
					if (Tree_Search(tree,toint(a.dulieu))==1) 
					{
						LinkPTR p;
						int g=0,ok=0;
						int vtghe,enter_g,enter_gy;
						string stt="";
						for (p=link;p!=NULL;p=p->next)
						{
							g=0;
							while (g<p->info.n)
							{
								if (p->ds[g]->cmnd==toint(a.dulieu)) 
								{
									machuyenbay=setdata(p->info.machuyenbay);
									vtghe=p->ds[g]->vitrighe;
								}
								g++;
							}
						}
					
					
						if (machuyenbay=="") DatVe(toint(a.dulieu),2,"","","");
						else DatVe(toint(a.dulieu),2,xac_dinh(vtghe),machuyenbay,"");
					}
				    else 
					{
						coutcolor(54,22,120,"                                            ");
						coutcolor(54,22,78,"     Khong tim thay. Vui long thu lai!    ");	        
					}
					}
				}
				else  
				{
					huyve(toint(a.dulieu));
				}
			}
			else
			{
				coutcolor(54,22,120,"                                            ");
				coutcolor(54,22,78," Vui long nhap so CMND hop le(9-12 chu so)");
			}
		}
		if (k==224)
		{
			k=getch();
			switch (k)
			{
				case LEFT_KEY:
				{
					string temp;
					temp=temp+a.dulieu[a.vt-1];
					coutcolor(a.x+3+a.vt,a.y,110,temp);
					a.vt--; if (a.vt<=1) a.vt=1;
					temp="";temp=temp+a.dulieu[a.vt-1];
					coutcolor(a.x+3+a.vt,a.y,62,temp);
					break;
				}
				case RIGHT_KEY:
				{
					string temp1;
					temp1=temp1+a.dulieu[a.vt-1];
					coutcolor(a.x+3+a.vt,a.y,110,temp1);
					a.vt++; if (a.vt>a.dulieu.length()) a.vt=a.dulieu.length()+1;
					temp1="";temp1=temp1+a.dulieu[a.vt-1];
					coutcolor(a.x+3+a.vt,a.y,62,temp1);
					break;
				}	
			}
		}
		else
		{
			if ((k>=48&&k<=57)||(k==BACKSPACE_KEY))
			{
				if (k==BACKSPACE_KEY) 
				{
					xoa_ky_tu(a);
				}
				else
				{
					them_ky_tu(a,k);
				}
				ve_khung(a);
				coutcolor(a.x+4,a.y,110,a.dulieu);
				temp="";
				temp=a.dulieu[a.vt-1];
				if (temp.length()==0) temp=" ";
				coutcolor(a.x+3+a.vt,a.y,62,temp);
			}
		
		}
	}
	
}

hkhach Tree_set_data(khung a[6])
{
	hkhach p;
	for (int i=0;i<=29;i++)
	{
		p.hoten[i]=a[1].dulieu[i];
		p.quequan[i]=a[5].dulieu[i];
	}
	
	if (a[2].dulieu==" Nam                          ") p.gioitinh=1;
	if (a[2].dulieu==" Nu                           ") p.gioitinh=0;
	if (a[2].dulieu==" Khac                         ") p.gioitinh=2;
	
	int d;
	d=(a[3].dulieu[0]-'0')*10+(a[3].dulieu[1]-'0');
	p.dob.dd=d;
	d=(a[3].dulieu[3]-'0')*10+(a[3].dulieu[4]-'0');
	p.dob.mm=d;
	d=(a[3].dulieu[6]-'0')*1000+(a[3].dulieu[7]-'0')*100+(a[3].dulieu[8]-'0')*10+(a[3].dulieu[9]-'0');
	p.dob.yy=d;

	long long m=0;
	m=toint(a[4].dulieu);
	p.cmnd=m;		
		 
	return p;
}

int check_ghe(int x, int y)
{
	if (ghe[x][y]==1) return 1; else return 0;
}

int xac_dinh_vi_tri(string s)  //xac dinh vi tri ghe ngoi   Ex: 18F->108
{
	int m=0;
	for (int i=0;i<=s.length()-2;i++)
	{
		m=m*10+(s[i]-'0');
	}
	m--;
	m=m*6;
	switch(s[s.length()-1])
	{
		case 'A' :{ m+=1; break;}
		case 'B' :{ m+=2; break;}
		case 'C' :{ m+=3; break;}
		case 'D' :{ m+=4; break;}
		case 'E' :{ m+=5; break;}
		case 'F' :{ m+=6; break;}
	}
	return m;
}

string xac_dinh(int k)
{
	string stt="";
	int x,y;
	x=k/6+1;
	if (x<10) stt="0";
	if (k%6==0) x--;
	stt=stt+tostring(x);
	y=k%6;
	switch(y)
	{
		case 1:{stt=stt+'A';break;}
		case 2:{stt=stt+'B';break;}
		case 3:{stt=stt+'C';break;}
		case 4:{stt=stt+'D';break;}
		case 5:{stt=stt+'E';break;}
		case 0:{stt=stt+'F';break;}	
	}
	return stt;
}
void Tree_xuatFile(NODEPTR &root)
{
	fstream fileout("D:\\DATABASE_KHACH_HANG.DATA", ios::out | ios::binary);
	if (!fileout)
	{
		cout << "Khong the mo file de ghi. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	NODEPTR Stack[500];
	int sp=-1;
	NODEPTR p=root;
	while (p!=NULL)
	{
		fileout.write(reinterpret_cast<char*>(&p->info), sizeof(hkhach));
		if (p->right!=NULL)
		  Stack[++sp]=p->right;
		if (p->left!=NULL)
		  p=p->left;
		else if (sp==-1)
		  break;
		else p=Stack[sp--];
	}
	fileout.close();
}

void Tree_nhapFile()
{
	fstream  filein("D:\\DATABASE_KHACH_HANG.DATA", ios::in  | ios::binary);
	if (!filein)
	{
		cout << "Khong the mo file de doc. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	hkhach hk1;
	while (filein.read(reinterpret_cast<char*>(&hk1), sizeof(hkhach)))
	{
		Tree_Insert_node(tree,hk1);
	}
	filein.close();
}
void Tree_Init(NODEPTR &root)   //Khoi tao cay
{
	root=NULL;
}

int Tree_Empty(NODEPTR root)
{
	return (root==NULL?1:0);
}

void Tree_Insert_node(NODEPTR &p, hkhach a)
{
	if (p==NULL)
   {
   	p=new node_tree;
   	p->info=a;
   	p->left=NULL;	p->right=NULL;
   }
   else
   {
   	 if (a.cmnd<p->info.cmnd)
   	     Tree_Insert_node(p->left,a);
	  else if (a.cmnd>p->info.cmnd) Tree_Insert_node(p->right,a);	
	}	
}

void Tree_Preorder(NODEPTR p)
{
	if (p!=NULL)
	{
		cout<<p->info.cmnd<<" "<<endl;
		cout<<p->info.dob.dd<<"/"<<p->info.dob.mm<<"/"<<p->info.dob.yy<<endl;
		cout<<p->info.gioitinh<<endl;
		cout<<p->info.hoten<<endl;
		cout<<p->info.quequan<<endl;
		Tree_Preorder(p->left);
		Tree_Preorder(p->right);
	}
}

int Tree_Search(NODEPTR root, long long  x)
{
	NODEPTR p;
	p=root;
	while (p!=NULL&&p->info.cmnd!=x)
	if (x<p->info.cmnd)
	  p=p->left;
	else
	 p=p->right;
	if (p==NULL) return 0;
	if (p->info.cmnd==x)
	return 1; else return 0;
}
NODEPTR Tree_Location(NODEPTR root,long long x)
{
	NODEPTR p;
	p=root;
	while (p!=NULL&&p->info.cmnd!=x)
	if (x<p->info.cmnd)
	  p=p->left;
	else
	 p=p->right;
    return p;
}
//Xoa nut
NODEPTR rp;
void Tree_remove_case3(NODEPTR &r)
{
	if (r->left!=NULL)
	   Tree_remove_case3(r->left);
	// tim duoc nut cuc trai 
	else
	{
		rp->info=r->info;
		rp=r;
		r=rp->right;
	}
}
void Tree_remove(long long  x,NODEPTR &p)
{
	if (p==NULL) cout<<"Khong tim thay";
	else
		if (x<p->info.cmnd) Tree_remove(x,p->left);
		else if (x>p->info.cmnd) Tree_remove(x,p->right);
		  else
		  {
		  	rp=p;
		  	if (rp->right==NULL) 
			    p=rp->left;
		  	else 
			   if (rp->left==NULL)
		  	         p=rp->right;
		  	    else Tree_remove_case3(rp->right);
		  	delete rp; 
		  }
}

void Tree_update(NODEPTR &tree,khung a[6], long long id, string machuyenbay,int vtghe)
{
	hkhach info;
	info=Tree_set_data(a);
	Tree_remove(id,tree);
	Tree_Insert_node(tree,info);
    Link_Array_Update(link,machuyenbay,id,toint(a[4].dulieu),vtghe);
}



void Hanhkhachchecksave(khung aa[6],int da_dien[6],long long id,string machuyenbay, int vtghe, int sign)
{
	int k;
	int dem=0;
	for (int i=1;i<=5;i++) if (da_dien[i]==1) dem++;
	if (dem==5)
	{
		if (sign==1)
		{
			Tree_Insert_node(tree,Tree_set_data(aa));
			if (Tree_Search(tree,toint(aa[4].dulieu))==1)
			{
				coutcolor(70,14,236,"Da luu thanh cong");
				k=getch();
				menu();
			}
			else
			{
				coutcolor(70,14,236,"Them that bai");
			}	
		}
		else
		{
			if (machuyenbay!="") Tree_update(tree,aa,id,machuyenbay,vtghe);
			else
			{
				hkhach info;
				info=Tree_set_data(aa);
				Tree_remove(id,tree);
				Tree_Insert_node(tree,info);
			}
			coutcolor(70,14,236,"Da luu thanh cong");
			k=getch();
			menu();	
		}
	}
	else
	{
		coutcolor(60,25,124,"Ban phai dien tat ca cac truong!");	// neu ng dung chua dien xong ma doi luu 
	}
}

void DatVe(long long id, int sign, string vtghe,string machuyenbay,string mamaybay)  
{
	
	//menu save
	int flag=0;	 //nhan biet xem ng dung co nhap hay chinh sua gi khong?
		
	khung aa[15];
	int k,vtri=1;
	int da_dien[6];		// check for filled
	
	string temp;
	setScreen();
	
	string sex[4]={""," Nam                          "," Nu                           "," Khac                         "};  // gioi tinh
	int vtsex=1;
	
	//	Vi ng dung da chon chuyen bay truoc roi, nen khong can hoi chuyen bay nua
	
	
	coutcolor(67,4,236," THONG TIN HANH KHACH  ");
	aa[1].id=1; aa[1].x=49; aa[1].y=8;   aa[1].tenkhung="Ho va ten       ";   aa[1].color=110; aa[1].vt=1; 
	aa[2].id=2; aa[2].x=49; aa[2].y=10;  aa[2].tenkhung="Gioi tinh       ";   aa[2].color=241; aa[2].vt=1; aa[2].dulieu="Enter de lua chon";
	aa[3].id=3; aa[3].x=49; aa[3].y=12;  aa[3].tenkhung="Ngay sinh       ";   aa[3].color=241; aa[3].vt=1;
	aa[4].id=4; aa[4].x=49; aa[4].y=14;  aa[4].tenkhung="So CMND         ";   aa[4].color=241; aa[4].vt=1; 
	aa[5].id=5; aa[5].x=49; aa[5].y=16;  aa[5].tenkhung="Que quan        ";   aa[5].color=241; aa[5].vt=1;
	
	if (sign==1) 
	{
		flag=1;
		aa[4].dulieu=tostring(id);	
	}
	if (sign==3)       // lay lai data luu tam thoi
	{
		flag=1;
		aa[1]=temp1[1];
		aa[2]=temp1[2];
		aa[3]=temp1[3];
		aa[4]=temp1[4];
		aa[5]=temp1[5];
	}
	
	if (sign==2)      //khach hang da nam trong CSDL
	{
		flag=1;
		NODEPTR p=Tree_Location(tree,id);
		aa[1].dulieu=setdata(p->info.hoten);
		switch(p->info.gioitinh)
		{
			case 0:{aa[2].dulieu=" Nu                           "; break;}
			case 1:{aa[2].dulieu=" Nam                          "; break;}
			case 2:{aa[2].dulieu=" Khac                         "; break;}
		}
		aa[3].dulieu=xuly_date(p);
		aa[4].dulieu=tostring(p->info.cmnd);
		aa[5].dulieu=setdata(p->info.quequan);
		for (int i=1;i<=5;i++) da_dien[i]=1;
	}
	
	//Tao giao dien
	ve_khung(aa[1]);
	ve_khung(aa[2]);
	ve_khung(aa[3]);
	ve_khung(aa[4]);
	ve_khung(aa[5]);
	coutcolor(72,19,236," Tiep theo ");
	coutcolor(1,35,207,"               ESC: Thoat                  |                 Up,Down,Left,Right  : Di chuyen                 |               Enter:    Chon          ");
	//Bat dau nhan dang ban phim
	while (1)
	{
		k=getch();
		// kiem tra du lieu dau vao
		if (vtri!=6)
		if (vtri==3&&aa[vtri].dulieu.length()>0)
		{
			if (check_ngay_thang(aa[vtri].dulieu)==0 )
			{
				da_dien[vtri]=0;
				coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
				coutcolor(aa[vtri].x+52,aa[vtri].y,124," Ngay khong hop le!");
			}
			else
			{
				if(thoigianhientai(aa[3].dulieu,"")==2)
				{
					da_dien[vtri]=0;
					coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
					coutcolor(aa[vtri].x+52,aa[vtri].y,124," Ngay khong hop le!");
				}
				else
				{
					da_dien[vtri]=1;
					coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                 ");
					coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
				}
			}
		}
		else if (vtri==4&&aa[vtri].dulieu.length()>0)
		{
			if (check_cmnd(aa[vtri].dulieu)==0)
			{
				da_dien[vtri]=0;
				coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
				coutcolor(aa[vtri].x+52,aa[vtri].y,124," So CMND khong hop le(9-12 so)!");
			}
			else
			if (check_cmnd(aa[vtri].dulieu)==2&&toint(aa[vtri].dulieu)!=id)
			{
				da_dien[vtri]=0;
				coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                ");
				coutcolor(aa[vtri].x+52,aa[vtri].y,124," So CMND da ton tai!");
			}
			else
			{
				da_dien[vtri]=1;
				coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                 ");
				coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
			}
		}
		else
		if (aa[vtri].dulieu.length()>0) 
		{
			da_dien[vtri]=1;
			coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
		}
		else 
		{
			da_dien[vtri]=0;
			coutcolor(aa[vtri].x+52,aa[vtri].y,122,"   ");	
		}
		
		// cac phim tat mo rong
		if (k==ENTER_KEY)
		{
			if (vtri==2) 
			{
				coutcolor(70,11,78,sex[1]);
				coutcolor(70,12,78,sex[2]);
				coutcolor(70,13,78,sex[3]);
				coutcolor(70,10+vtsex,78,sex[vtsex]);         //to mau vi tri gioi tinh da chon
				while (1)
				{
					k=getch();
					if (k==ESC_KEY||k==ENTER_KEY) 
					{
						aa[vtri].dulieu=sex[vtsex];
						coutcolor(70,11,119,sex[1]);                // to lai phan mau bi lem
						coutcolor(70,12,119,sex[2]);
						coutcolor(70,13,119,sex[3]);
						ve_khung(aa[3]);
						break;
					}
					if (k==DOWN_KEY)
					{
						coutcolor(70,10+vtsex,78,sex[vtsex]); vtsex++; if (vtsex==4) vtsex=1; 
						coutcolor(70,10+vtsex,174,sex[vtsex]);
					}
					if (k==UP_KEY)
					{
						coutcolor(70,10+vtsex,78,sex[vtsex]); vtsex--; if (vtsex==0) vtsex=3; 
						coutcolor(70,10+vtsex,174,sex[vtsex]);
					}
				}
			} 
			if (vtri!=6&&vtri!=2) 
			{
				aa[vtri].color=241; ve_khung(aa[vtri]);
			}
			if (vtri!=2) vtri++; 
			if (vtri>=6&&k==ENTER_KEY) 
			{
				if (vtri==6)
				{
					vtri=6;
					coutcolor(72,19,110," Tiep theo ");	
				}
				else
				{
					vtri=6;
					flag=0;
					coutcolor(72,19,110," Tiep theo ");
					int dem=0;
					for (int i=1;i<=5;i++) if (da_dien[i]==1) dem++;
					if (dem==5)
					{
						//ng dung du dieu kien de luu du lieu, da dien day du tat ca cac truong
						for (int i=1;i<=5;i++)
						{
							temp1[1]=aa[1];
							temp1[2]=aa[2];
							temp1[3]=aa[3];
							temp1[4]=aa[4];
							temp1[5]=aa[5];
						}
						if (sign==2)
						{
							if (machuyenbay=="")
							{
								for (int i=1;i<=6;i++)
								{					
									coutcolor(62,12+i,41,"                                          ");
								}	
								coutcolor(62,14,46,"       Ban chua dat ve may bay        ");
								coutcolor(78,17,95,"   OK    ");
								coutcolor(1,1,130,"");
								flag=1;
								k=getch();
								for (int i=1;i<=6;i++)
								{					
									coutcolor(62,12+i,120,"                                          ");
								}
								ve_khung(aa[2]);
								ve_khung(aa[3]);
								ve_khung(aa[4]);
								ve_khung(aa[5]);  
							}
							else
							{
								cho_ngoi(machuyenbay,vtghe,id,1);
							}
						}
						else
						{
							cho_ngoi(machuyenbay,vtghe,id,1);
						}	
					}
					else
					{
						coutcolor(60,25,124,"Ban phai dien tat ca cac truong!");	// neu ng dung chua dien xong ma doi luu 	
					}
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
					coutcolor(62,12+i,41,"                                          ");
				}	
				coutcolor(62,14,46,"   Ban co muon luu lai khong?(Y/N)    ");
				coutcolor(62,17,95,"   Co(Y)   ");
				coutcolor(75,17,95,"   Khong(N) ");
				coutcolor(89,17,95,"  Huy(ESC) ");
				coutcolor(1,1,130,"");
				while (1)
				{
					k=getch();
					if (k==ESC_KEY)
					{
						for (int i=1;i<=6;i++)
						{					
							coutcolor(62,12+i,120,"                                           ");
						}	
						ve_khung(aa[3]);
						ve_khung(aa[4]);
						ve_khung(aa[5]);
						break;
					}
					if (k=='Y'||k=='y')
					{
						if (sign==2)
						{
							if (vtghe=="") Hanhkhachchecksave(aa,da_dien,id,machuyenbay,0,2);
							else
							{
								//Hanhkhachchecksave(aa,da_dien,id,machuyenbay,xac_dinh_vi_tri(vtghe),2);
								coutcolor(62,14,46," Ban hay kiem tra lai vi tri ghe ngoi  ");
								coutcolor(62,17,95,"                 OK                       ");
								k=getch();
								for (int i=1;i<=6;i++)
								{					
									coutcolor(62,12+i,120,"                                           ");
								}	
								ve_khung(aa[3]);
								ve_khung(aa[4]);
								ve_khung(aa[5]);
								break;
							}
						}
						else
						{
							if (machuyenbay=="")
							{
								Hanhkhachchecksave(aa,da_dien,id,machuyenbay,0,2);
								
							}
							if (vtghe=="")
							{
								coutcolor(62,14,46,"   Ban vui long chon vi tri ghe ngoi   ");
								coutcolor(62,17,95,"                 OK                       ");
									k=getch();
									for (int i=1;i<=6;i++)
									{					
										coutcolor(62,12+i,120,"                                           ");
									}	
									ve_khung(aa[3]);
									ve_khung(aa[4]);
									ve_khung(aa[5]);
									break;
									
							}
							else
							{
								/*if (Link_Array_Search(link,machuyenbay,id)==0)
								{
								// luu may bay, luu hanh khach
								ds_ve d; d.cmnd=id; d.vitrighe=xac_dinh_vi_tri(vtghe);
								if (Tree_Search(tree,id)==0)	
								{
									Tree_Insert_node(tree,Tree_set_data(aa));
									Link_Insert_Passenger(link,machuyenbay,d);
								}
								else
								{
									Link_Insert_Passenger(link,machuyenbay,d);
								}*/
								coutcolor(62,14,46," Ban hay kiem tra lai vi tri ghe ngoi  ");
								coutcolor(62,17,95,"                 OK                       ");
								k=getch();
								for (int i=1;i<=6;i++)
								{					
									coutcolor(62,12+i,120,"                                           ");
								}	
								ve_khung(aa[3]);
								ve_khung(aa[4]);
								ve_khung(aa[5]);
								break;
							}	
						}
					}
					if (k=='N'||k=='n')
					{
						menu();
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
						coutcolor(72,19,110," Tiep theo ");	
					}
					break;
				}
				case UP_KEY:
				{
					if (vtri==6) 
					{
						coutcolor(72,19,236," Tiep theo "); 
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
					if (vtri==6) break;
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
					if (vtri==6) break;
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
				if ((vtri==1||vtri==5)&&((k>=48&&k<=57)||k==45)) continue;
				if ((vtri==3||vtri==4)&&(k<48||k>57)&&(k!=BACKSPACE_KEY)) continue;
				if (vtri==2) continue;  // vi tri cua gioi tinh
				flag=1;
				if (k==BACKSPACE_KEY) 
				{
					if (vtri==3) if (aa[vtri].vt==4||aa[vtri].vt==7) xoa_ky_tu(aa[vtri]);
					xoa_ky_tu(aa[vtri]);
					if (vtri==3) if (aa[1].dulieu.length()==6||aa[1].dulieu.length()==3) xoa_ky_tu(aa[vtri]);
					
				}
				else
				{
					if (vtri==3&&(aa[vtri].dulieu.length()==10)) continue;
					them_ky_tu(aa[vtri],k);
					if (vtri==3) if (aa[vtri].dulieu.length()==2||aa[vtri].dulieu.length()==5) them_ky_tu(aa[vtri],47);
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
void cho_ngoi(string machuyenbay,string vitricu, long long id, int sign)
{
	LinkPTR q;
	string temp,stt;
	temp=char(219);
	temp=temp+char(219);
	int x,y,k,g=0,m;
	int enter_x=0,enter_y=0,enter_g=1,enter_gy=1;
	int vtghes,toadox,toadoy; // 
	int limax,yz,xz; // xac dinh max cua toa do phia phai
	int xchon=0,ychon=0;
	
	q=Link_Search(link,machuyenbay);
	int kk=Array_Search(ds,setdata(q->info.sohieumb));
	int n=ds.nodes[kk]->socho;
	xz=n;
	for (int i=1;i<=250;i++)
	 for (int j=1;j<=6;j++) ghe[i][j]=0;
	
	for (int i=0;i<q->info.n;i++)
	{
		vtghes=q->ds[i]->vitrighe;
		if (vitricu!="")
		if (vtghes==xac_dinh_vi_tri(vitricu))
		{
			xchon=vtghes/6+1;
			ychon=vtghes%6;
			if (vtghes%6==0) 
			{
				xchon--;
				ychon=6;
			}
		}
		toadox=vtghes/6+1;
		toadoy=vtghes%6;
		if (vtghes%6==0) 
		{
			toadox--; toadoy=6;
		}
		ghe[toadox][toadoy]=1;
		//cout<<toadox<<" "<<toadoy;
	}
	//system("pause");
	
	
	
	setScreen();
	coutcolor(1,35,207,"      ESC: Quay lai       |             Phim S: Xac nhan           |         Up,Down,Left,Right  : Di chuyen        |      Enter:    Chon ghe        ");
	coutcolor(56,2,178,"THONG TIN DANG KI CHUYEN BAY "); cout<<machuyenbay<<endl; 
	if (sign==1)
	{
	coutcolor(60,4,124,"Ho va ten : "); cout<<temp1[1].dulieu;
	coutcolor(60,5,124,"Gioi tinh : "); cout<<temp1[2].dulieu;
	coutcolor(60,6,124,"Ngay sinh : "); cout<<temp1[3].dulieu;
	coutcolor(60,7,124,"CMND      : "); cout<<temp1[4].dulieu;
	coutcolor(60,8,124,"Que quan  : "); cout<<temp1[5].dulieu;
	}
    n=n/2;
    g=n/6+1;
    enter_g=n/6+1; enter_gy=0;
	for (int i=0;i<6;i++)
	{
		enter_gy++;
		enter_g=n/6+1;
		for (int j=0;j<n/6;j++) 
		{
			if (i==0) 
			{
				g--; enter_g--;
				stt="";
				stt=g/10+'0';
				stt+=(g%10+'0');
				coutcolor(72-j*3,13,249,stt); 	
				coutcolor(72-j*3,27,249,stt); 	
			}
			else enter_g--;
			coutcolor(72-j*3,15+i*2,12,temp);
		//	cout<<enter_gy<<" "<<enter_g<<endl;
		//	system("pause");
			if (check_ghe(enter_g,enter_gy)==1) coutcolor(72-j*3,15+i*2,78,temp); 	
		}
		cout<<endl;
	}
	g=n/6;
	enter_g=n/6+1;
	enter_gy=0;
	m=n%6;
	n+=m;
	for (int i=0;i<6;i++)
	{
		enter_gy++;
		enter_g=n/6-1;
		for (int j=0;j<n/6;j++) 
		{
			if (i==0) 
			{
				g++;
				enter_g++;
				stt="";
				stt=g/10+'0';
				stt+=(g%10+'0');
				coutcolor(75+j*3,13,249,stt); 	
				coutcolor(75+j*3,27,249,stt); 	
			}
			else enter_g++;
			coutcolor(75+j*3,15+i*2,12,temp); 	
			//cout<<enter_gy<<" "<<enter_g<<endl;
			//system("pause");
			if (check_ghe(enter_g,enter_gy)==1) coutcolor(75+j*3,15+i*2,78,temp); 	
			yz=j;
		}
		cout<<endl;
	}
	yz++;
	for (int i=0;i<xz%6;i++)
	{
		coutcolor(75+yz*3,15+i*2,102,temp); 	
	}
	coutcolor(25,30,153,temp); coutcolor(28,30,121,"Ban dang chon ghe nay");
	coutcolor(54,30,78,temp);coutcolor(57,30,121,"Ghe da co nguoi ngoi");
	coutcolor(81,30,102,temp);coutcolor(84,30,121,"Khong duoc chon");
	coutcolor(103,30,124,temp);coutcolor(106,30,121,"Ghe trong");
	coutcolor(118,30,42,temp);coutcolor(121,30,121,"Phim dieu huong");
	if (sign==2)
	{
		while (1)
		{
			k=getch();
			if (k==ESC_KEY) menu();	
		}
	}
	
	
	
	n-=m;
	enter_g=1, enter_gy=1;
	x=72-(n/6-1)*3;
	y=15;
	coutcolor(x,y,178,temp);
	coutcolor(58,10,178,"Ban dang chon ghe:");
	stt=vitricu;
	coutcolor(76,10,178,stt);
	while (1)
	{
			k=getch();
			if (k=='S'||k=='s')
			{
				if (vitricu=="")
				{
				if (stt=="") coutcolor(58,11,78,"Ban chua chon ghe ngoi");
				else
				{
					// luu may bay, luu hanh khach
					ds_ve d; d.cmnd=toint(temp1[4].dulieu); d.vitrighe=xac_dinh_vi_tri(stt);
					if (Tree_Search(tree,d.cmnd)==0)	
					{
						Tree_Insert_node(tree,Tree_set_data(temp1));
						Link_Insert_Passenger(link,machuyenbay,d);
					}
					else
					{
						Tree_remove(id,tree);
						Tree_Insert_node(tree,Tree_set_data(temp1));
						Link_Insert_Passenger(link,machuyenbay,d);
					}
					coutcolor(58,11,78,"   Ban da dat ve thanh cong   ");
					k=getch();
					menu();
				}
				}
				else
				{
					Tree_update(tree,temp1,id,machuyenbay,xac_dinh_vi_tri(stt));
					coutcolor(58,11,78,"   Ban da luu thanh cong   ");
					k=getch();
					menu();
				}
				
			}
			if (k==ESC_KEY)
			{
				DatVe(toint(temp1[4].dulieu),3,stt,machuyenbay,"");
				break;
			}
			if (k==ENTER_KEY)
			{
				ghe[xchon][ychon]=0; 
				if (ghe[enter_g][enter_gy]==1)
				{
					string sttam="";
					sttam=(enter_g)/10+'0';
					sttam+=(enter_g)%10+'0';
					switch(enter_gy)
					{
						case 1:{sttam=sttam+'A';break;}
						case 2:{sttam=sttam+'B';break;}
						case 3:{sttam=sttam+'C';break;}
						case 4:{sttam=sttam+'D';break;}
						case 5:{sttam=sttam+'E';break;}
						case 6:{sttam=sttam+'F';break;}	
					}
					if (sttam!=vitricu||vitricu!="") coutcolor(58,11,78,"Ban khong the chon ghe nay");
					else
					{
						if ((enter_x!=0)&&(enter_y!=0)) coutcolor(enter_x,enter_y,12,temp);
						coutcolor(x,y,153,temp);
						enter_x=x;
						enter_y=y;
						stt=sttam;
						coutcolor(58,11,120,"                                        ");
						coutcolor(76,10,178,stt);
					} 
					continue;
				}
				else
				{
				if ((enter_x!=0)&&(enter_y!=0)) coutcolor(enter_x,enter_y,12,temp);
				coutcolor(x,y,153,temp);
				enter_x=x;
				enter_y=y;
				stt=(enter_g)/10+'0';
				stt+=(enter_g)%10+'0';
				switch(enter_gy)
				{
					case 1:{stt=stt+'A';break;}
					case 2:{stt=stt+'B';break;}
					case 3:{stt=stt+'C';break;}
					case 4:{stt=stt+'D';break;}
					case 5:{stt=stt+'E';break;}
					case 6:{stt=stt+'F';break;}	
				}
				coutcolor(58,11,120,"                                        ");
				coutcolor(76,10,178,stt);
				continue;	
				}
			}
			if (k==224)
			{
				k=getch();
				switch(k)
				{
					case DOWN_KEY:
					{		
					    enter_gy++; if (enter_gy>6) enter_gy=6;
					    if (check_ghe(enter_g,enter_gy-1)==1) coutcolor(x,y,78,temp);else coutcolor(x,y,12,temp); y+=2; if (y>=25) y=25;
						coutcolor(x,y,178,temp);
						if ((enter_x!=0)&&(enter_y!=0)) coutcolor(enter_x,enter_y,153,temp);
						break;
					}
					case UP_KEY:
					{
						enter_gy--;	if (enter_gy<1) enter_gy=1;
						if (check_ghe(enter_g,enter_gy+1)==1) coutcolor(x,y,78,temp);else coutcolor(x,y,12,temp); y-=2; if (y<=15) y=15;
						coutcolor(x,y,178,temp);
						if ((enter_x!=0)&&(enter_y!=0)) coutcolor(enter_x,enter_y,153,temp);
						break;
					}
					case LEFT_KEY:
					{
						enter_g--;if (enter_g<1) enter_g=1;
						if (check_ghe(enter_g+1,enter_gy)==1) coutcolor(x,y,78,temp);else coutcolor(x,y,12,temp); x-=3;  if (x<=72-(n/6-1)*3) x=72-(n/6-1)*3;
						coutcolor(x,y,178,temp); 
					    if ((enter_x!=0)&&(enter_y!=0)) coutcolor(enter_x,enter_y,153,temp);
					    break;
					}	
					case RIGHT_KEY:
					{
						
						enter_g++; if (enter_g>g) 
						{
							enter_g=g; 
							continue;	
						}
				        if (check_ghe(enter_g-1,enter_gy)==1) coutcolor(x,y,78,temp);else coutcolor(x,y,12,temp); x+=3; if (x>=78+(n/6-1)*3) x=78+(n/6-1)*3;
						coutcolor(x,y,178,temp); 
					    if ((enter_x!=0)&&(enter_y!=0)) coutcolor(enter_x,enter_y,153,temp);
						break;
					}			
				}
			}
		}	
}
int timtu(string s,string s1)
{
	string temp;
	for (int i=0;i<s.length();i++)
	{
		s1[i]=tolower(s1[i]);
		s[i]=tolower(s[i]);
		temp+=s1[i];
	}
	if (s==temp) return 1; else return 0;
}
void huyve(long long cmnd)
{
	LinkPTR p;
	int vtghe=0;
	int size,i=0,check=0,k;
//	cout<<"Duyet cay"<<endl;
//	Tree_Preorder(tree);
//	cout<<"Duyet mang"<<endl;
	for (p=link;p!=NULL;p=p->next)
	{
//		cout<<"MAY BAY"<<p->info.machuyenbay<<endl;
		size=p->info.n;
		i=0;
		while (i<size)
		{
//			cout<<p->ds[i]->cmnd<<endl;
//				cout<<p->ds[i]->vitrighe<<endl;
			if (p->ds[i]->cmnd==cmnd)
			{
				vtghe=p->ds[i]->vitrighe;
				check=1;	
				break;	
			}
			i++;
		}
		if (check==1) break;
		//cout<<"----------------------------------------"<<endl;
	}
	//system("pause");
	if (check==1)
	{
		setScreen();
		for (int i=1;i<=13;i++)
		{					
			coutcolor(56,5+i,41,"                                       ");
		}	
		string s;
		NODEPTR t;
		t=Tree_Location(tree,cmnd);
		
		coutcolor(57,7,46,"Chuyen bay :"); cout<<p->info.machuyenbay;
		coutcolor(57,8,46,"Tan Son Nhat(SGN) -> "); cout<<p->info.sanbayden;
		coutcolor(95,8,120,"                         ");
		if (p->info.thoigian.ngay.dd<10) s=s+"0"+tostring(p->info.thoigian.ngay.dd)+"/"; else s=s+tostring(p->info.thoigian.ngay.dd)+"/";
		if (p->info.thoigian.ngay.mm<10) s=s+"0"+tostring(p->info.thoigian.ngay.mm)+"/"; else s=s+tostring(p->info.thoigian.ngay.mm)+"/";
		s=s+tostring(p->info.thoigian.ngay.yy);
		s="Ngay bay:"+s;
		coutcolor(57,9,46,s);
		s="Gio bay: ";
		if (p->info.thoigian.gio<10) s=s+"0"+tostring(p->info.thoigian.gio)+" : "; else s=s+tostring(p->info.thoigian.gio);s=s+":";
		if (p->info.thoigian.phut<10) s=s+"0"+tostring(p->info.thoigian.phut); else s=s+tostring(p->info.thoigian.phut);
		coutcolor(57,10,46,s);
		
		s="Ten hanh khach: "; 
		coutcolor(57,12,46,s);cout<<t->info.hoten;
		s="Ngay sinh: ";
		if (t->info.dob.dd<10) s=s+'0'+tostring(t->info.dob.dd); else s=s+tostring(t->info.dob.dd); s=s+"/";
		if (t->info.dob.mm<10) s=s+'0'+tostring(t->info.dob.mm); else s=s+tostring(t->info.dob.mm); s=s+"/";
		s=s+tostring(t->info.dob.yy);
		coutcolor(57,13,46,s); 
		s="CMND: ";
		coutcolor(57,14,46,s); cout<<t->info.cmnd;
		s="Vi tri ghe:";
		coutcolor(57,15,46,s); cout<<xac_dinh(vtghe);
		coutcolor(56,16,46," Ban co muon huy ve hay khong?(Y/N) ");
		coutcolor(56,18,95,"      Co(Y)       ");
		coutcolor(75,18,95,"     Khong(N)       ");
		coutcolor(1,1,130,"");
		while (1)
		{
			k=getch();
			if (k==ESC_KEY||k=='N'||k=='n') menu();
			else if (k=='Y'||k=='y')
			{
				//huy ve may bay
				int zz=Link_Array_Search(link,setdata(p->info.machuyenbay),cmnd);
				Link_Array_Delete(link,setdata(p->info.machuyenbay),zz);
				setScreen();
				for (int i=1;i<=6;i++)
				{					
					coutcolor(62,12+i,41,"                                      ");
				}	
				coutcolor(62,14,46,"          Huy ve thanh cong          ");
				coutcolor(78,17,95,"  OK  ");
				k=getch();
				menu();
			}
		}
	}
	else
	{
		setScreen();
		for (int i=1;i<=7;i++)
		{
			coutcolor(55,12,236,"                                             ");
		}
		if (Tree_Search(tree,cmnd)==0)
		{
			coutcolor(55,14,236,"         Khong tim thay CMND nay             ");
			coutcolor(55,15,236,"           <--Quay lai(ESC)                  ");
		}
		else
		{
			coutcolor(55,14,236,"      Quy khach chua dat ve may bay          ");
			coutcolor(55,15,236,"           <--Quay lai(ESC)                  ");
		}
	
		while (1)
		{
			k=getch();
			if (k==ESC_KEY)
			{
				menu();
			}
		}
	}
}

