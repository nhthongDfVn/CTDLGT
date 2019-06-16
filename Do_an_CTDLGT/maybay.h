//bien toan cuc
//dlist ds;
void in_thong_tin_may_bay(int vt)
{
	string s="                                            ";
	for (int i=10;i<=14;i++) coutcolor(81,i,241,s);
	s="Hang san xuat  : ";
	s=s+setdata(ds.nodes[vt]->hangsanxuat);
	coutcolor(81,10,241,s);
	s="Hang hang khong: ";
	s=s+setdata(ds.nodes[vt]->hanghangkhong);
	coutcolor(81,11,241,s);
	s="So hieu may bay: ";
	s=s+setdata(ds.nodes[vt]->sohieu);
	coutcolor(81,12,241,s);
	s="Loai may bay   : ";
	s=s+setdata(ds.nodes[vt]->loai);
	coutcolor(81,13,241,s);
	s="So ghe ngoi    : ";
	s=s+tostring(ds.nodes[vt]->socho);
	coutcolor(81,14,241,s);
	if (ds.nodes[vt]->flag==1)
	coutcolor(81,15,78,"May bay da co duong bay");
	else
	coutcolor(81,15,241,"                                ");
	coutcolor(1,1,130,"");
}
void chon_may_bay(int id)  //1 
{
	setScreen();
	int somaybay=ds.n,k,vt=1,num=20,sopage=1;
	int page=1;
	string s="                                             ";
	string s1,temp;
	setScreen();
	coutcolor(67,4,62," DANH SACH MAY BAY HIEN CO ");
	//if (somaybay%num!=0) sopage=somaybay/num+1; else sopage=somaybay/num;
	sopage=1;
	s1="Trang ";
	s1=s1+tostring(page)+"/"+tostring(sopage);
	coutcolor(66,30,111,s1);
	
	
	coutcolor(30,9,139,"             Danh sach may bay               ");
	coutcolor(80,9,139,"            Thong tin may bay                ");
	if (id==2) coutcolor(1,35,207,"            ESC: Quay lai            |                  Up,Down,Left,Right  : Di chuyen, chuyen trang               |             Enter: Xoa         ");	
	else 	coutcolor(1,35,207,"            ESC: Quay lai            |                  Up,Down,Left,Right  : Di chuyen, chuyen trang               |             Enter: Chon        ");	
	for (int i=0;i<20;i++)
	{
		coutcolor(30,10+i,241,s);
		coutcolor(80,10+i,241,s);
	}
	if (somaybay<=0)                 // neu khong co may bay nao
	{
		// neu rong, ko co may bay nao
		s="Khong co thong tin hien thi                 ";
		coutcolor(81,10,241,s);
		s=s+" ";
		coutcolor(30,10,241,s);
		while (1)
		{
			k=getch();
			if (k==ESC_KEY) 
				menu();
		}		
	}
	for (int i=0;i<=num&&i<ds.n;i++)
	{
		coutcolor(35,9+i+1,241,ds.nodes[i]->sohieu);
	}
	if (id==2)   
	coutcolor(30,10,111,s); 
	coutcolor(35,10,111,ds.nodes[0]->sohieu);
	if (somaybay>0) in_thong_tin_may_bay(0);
	while (1)
	{
		k=getch();
		if (k==ESC_KEY)
		{
			menu();
		}
		if (k==ENTER_KEY)
		{
			if (id==3)
			{
				if(ds.nodes[vt-1]->flag==0) 
				{
					them_chuyen_bay(setdata(ds.nodes[vt-1]->sohieu),"",1);
				}
				else
				{
					for (int i=1;i<=6;i++)
					{					
						coutcolor(62,12+i,41,"                                      ");
					}	
					coutcolor(62,14,46,"     May bay nay da co duong bay     ");
					coutcolor(78,17,95,"  OK  ");
					k=getch();
					chon_may_bay(3);
				}
			}
			else
			if(id==2)
			{
				for (int i=1;i<=6;i++)
				{					
					coutcolor(62,12+i,41,"                                       ");
				}	
				if (ds.nodes[vt-1]->flag==1)
				{
					coutcolor(62,14,46,"  Khong the xoa.Dang co duong bay    ");
					coutcolor(78,17,95,"  OK  "); 
					k=getch();
					chon_may_bay(2);
				}
				coutcolor(62,14,46," Ban co muon xoa may bay khong?(Y/N)");
				coutcolor(62,17,95,"      Co(Y)       ");
				coutcolor(81,17,95,"     Khong(N)     ");
				coutcolor(1,1,130,"");
				while (1)
				{
					k=getch();
					{
						if (k==ESC_KEY)
						{
							chon_may_bay(id);
						}
						if (k==89||k==121)
						{
							Array_Delete(ds,vt-1);
							// xoa thanh cong
							for (int i=1;i<=6;i++)
							{					
							coutcolor(62,12+i,41,"                                      ");
							}	
							  coutcolor(62,14,46,"           Da xoa may bay            ");
							coutcolor(78,17,95,"  OK  ");
							k=getch();
							chon_may_bay(2);
						}
						if (k==78||k==110)
						{
							chon_may_bay(id);
						}
					}
				}
			}
			else
			{
				temp=setdata(ds.nodes[vt-1]->sohieu);
			    them_may_bay(temp);	
			}
		}
		if (k==224)
		{
			k=getch();
			switch(k)
			{
				case UP_KEY:
				{
					coutcolor(30,9+vt,241,s);
					coutcolor(35,9+vt,241,ds.nodes[num*(page-1)+vt-1]->sohieu);
					vt--; if (vt<=1) vt=1;
					coutcolor(30,9+vt,111,s);
					coutcolor(35,9+vt,111,ds.nodes[num*(page-1)+vt-1]->sohieu);
					in_thong_tin_may_bay(vt-1);
					break;	
				}
				case DOWN_KEY:
				{
					coutcolor(30,9+vt,241,s);
					coutcolor(35,9+vt,241,ds.nodes[num*(page-1)+vt-1]->sohieu);
					vt++;if (vt>=num) vt=num;
					if (vt>=ds.n) vt=ds.n; 
					coutcolor(30,9+vt,111,s);
					coutcolor(35,9+vt,111,ds.nodes[num*(page-1)+vt-1]->sohieu);
					in_thong_tin_may_bay(vt-1);
					break;
				}
			}
		}
	}
}
maybay Array_setdata(khung a[6])
{
	maybay info;
	for (int i=0;i<30;i++)
	{	
		info.hanghangkhong[i]=a[1].dulieu[i];
		info.hangsanxuat[i]=a[2].dulieu[i];
		info.sohieu[i]=a[3].dulieu[i];
		info.loai[i]=a[4].dulieu[i];
	}
	int m=0;
	m=toint(a[5].dulieu);
    info.socho=m;
    info.flag=0;
    info.sochuyendathuchien=0;
    return info;
}

void Array_nhapFile()
{
	
	fstream filein("D:\\DATABASE_MAY_BAY.DATA", ios::in | ios::binary);
	maybay mb;
	int i = 1;
	if (!filein)
	{
		cout << "Khong the mo file de doc. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	
	while (filein.read(reinterpret_cast<char*>(&mb), sizeof(maybay)))
	{
		Array_Insert(ds, mb);
	}
	filein.close();
}
void Array_xuatFile(dlist &ds)
{
	fstream fileout("D:\\DATABASE_MAY_BAY.DATA", ios::out | ios::binary);
	if (!fileout)
	{
		cout << "Khong the mo file de ghi. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	int i=0;
	while (i<ds.n)
	{
		maybay mb=*(ds.nodes[i]);
		fileout.write(reinterpret_cast<char*>(&mb), sizeof(maybay));
		i++;
	}
}
void Array_Init(dlist &ds)
{
	ds.n=0;
}
int Array_Full(dlist &ds)
{
	return ds.n==MAX_ARRAY;
}
int Array_Insert(dlist &ds, maybay &info)
{
	int j;
	if (Array_Full(ds)==1) return 0;
	ds.nodes[ds.n]=new maybay;
	*(ds.nodes[ds.n])=info;
	ds.n++;
	return 1;
	
}
int Array_Delete(dlist &ds,int i)
{
	int j;
	if (i<0||i>=ds.n||ds.n==0) return 0;
	for (j=i+1;j<ds.n;j++)
	  *(ds.nodes[j-1])=*(ds.nodes[j]);
	delete ds.nodes[ds.n];
	ds.n--;
	return 1;
}
int Array_Empty(dlist &ds)
{
	return ds.n==0;
}
void Array_Traverse(dlist ds)
{
	for (int i=0;i<ds.n;i++)
	{
		cout<<"MAY BAY THU"<<i<<endl;
		cout<<ds.nodes[i]->socho<<" ";
		cout<<ds.nodes[i]->hanghangkhong<<" ";
		cout<<ds.nodes[i]->hangsanxuat<<" ";
		cout<<ds.nodes[i]->loai<<" ";
		cout<<ds.nodes[i]->sohieu<<endl;
	}
}
int Array_Search(dlist &ds, string machuyen)
{
	char info[30];
	for (int i=0;i<30;i++) info[i]=machuyen[i];
	for (int i=0;i<ds.n;i++)
	{
		if (strcmp(ds.nodes[i]->sohieu,info)==0)
		    return i;
	}  
	return -1;
}
void Array_update(dlist &ds,khung a[6], int i)
{
	int m,sl;
	LinkPTR p;
	m=ds.nodes[i]->flag;
	sl=ds.nodes[i]->sochuyendathuchien;
	maybay ifo=Array_setdata(a);
	//cout<<endl;
	for (p=link;p!=NULL;p=p->next)
	{
		if (strcmp(p->info.sohieumb,ds.nodes[i]->sohieu)==0)
		{
			strcpy(p->info.sohieumb,ifo.sohieu);
		}
	}
	strcpy(ds.nodes[i]->hanghangkhong,ifo.hanghangkhong);
	strcpy(ds.nodes[i]->hangsanxuat,ifo.hangsanxuat);
	strcpy(ds.nodes[i]->loai,ifo.loai);
	ds.nodes[i]->socho=ifo.socho;
	strcpy(ds.nodes[i]->sohieu,ifo.sohieu);
	ds.nodes[i]->flag=m;
	ds.nodes[i]->sochuyendathuchien=sl;
	return;
}

int check_may_bay(int vt)
{
	//tim kiem xem so hieu may bay co bi trung hay khong?
	/*if (trung) return 0; else return 1;
	*/ 
}

void Maybaychecksave(khung aa[6],int da_dien[6], string mamaybay,int vitricu)
{
	int k;
	int dem=0;
	for (int i=1;i<=5;i++) if (da_dien[i]==1) dem++;
	//for (int i=1;i<=5;i++) cout<<da_dien[i]<<" ";
	if (dem==5)
	{
		//ng dung du dieu kien de luu du lieu, da dien day du tat ca cac truong
		if (mamaybay=="")
		{
			maybay mb= Array_setdata(aa);
			Array_Insert(ds,mb);
			if (Array_Search(ds,aa[3].dulieu)==-1||Array_Full(ds)==1)
			{
				coutcolor(60,25,110," Them that bai! ");	
			}
			else
			{
				coutcolor(60,25,110," Da them may bay ");				// neu may bay chua co trong danh sach	
				k=getch();
				chon_may_bay(1);
			}		
		}
		else
		{
			Array_update(ds,aa,vitricu);
			coutcolor(60,25,110,"  Luu thanh cong ");				// ng dung chinh sua may bay trong ds may bay
			k=getch();
			chon_may_bay(1);
		}
	}
	else
	{
		coutcolor(60,25,124,"Ban phai dien tat ca cac truong!");	// neu ng dung chua dien xong ma doi luu 
	}
}

void them_may_bay(string mamaybay)
{
	//menu save
	int flag=0;	 //nhan biet xem ng dung co nhap hay chinh sua gi khong?
	string sohieuhientai;
	khung aa[6];
	int k,vtri=1;
	int dem;             // dem so o da dien
	int da_dien[6];		// check for filled
	int vitricu;           // luu lai vi tri cu trong mang cua may bay, de chuan bi cho viec edit
											//SET MAN HINH CONSOLE
	string temp;
	setScreen();
	coutcolor(67,4,236," THONG TIN MAY BAY ");
	aa[1].id=1; aa[1].x=49; aa[1].y=8 ;  aa[1].tenkhung="Hang san xuat   ";   aa[1].color=110; aa[1].vt=1;
	aa[2].id=2; aa[2].x=49; aa[2].y=10;  aa[2].tenkhung="Hang hang khong ";   aa[2].color=241; aa[2].vt=1;
	aa[3].id=3; aa[3].x=49; aa[3].y=12;  aa[3].tenkhung="So hieu(15)     ";   aa[3].color=241; aa[3].vt=1;
	aa[4].id=4; aa[4].x=49; aa[4].y=14;  aa[4].tenkhung="Loai may bay(30)";   aa[4].color=241; aa[4].vt=1;
	aa[5].id=5; aa[5].x=49; aa[5].y=16;  aa[5].tenkhung="So cho ngoi     ";   aa[5].color=241; aa[5].vt=1;
	
	//Neu la cap nhat thong tin may bay, xuat thong tin da co cua may bay ra
	if (mamaybay!="")
	{
		flag=1;
		for (int i=1;i<=5;i++) da_dien[i]=1;
		int i=Array_Search(ds,mamaybay);
		vitricu=i;
		aa[1].dulieu=setdata(ds.nodes[i]->hangsanxuat);
		aa[2].dulieu=setdata(ds.nodes[i]->hanghangkhong);
		aa[3].dulieu=setdata(ds.nodes[i]->sohieu);
		aa[4].dulieu=setdata(ds.nodes[i]->loai);
		aa[5].dulieu=tostring(ds.nodes[i]->socho);
		sohieuhientai=aa[3].dulieu;
	}
	
	ve_khung(aa[1]);
	ve_khung(aa[2]);
	ve_khung(aa[3]);
	ve_khung(aa[4]);
	ve_khung(aa[5]);
	coutcolor(72,19,236," Luu lai ");
	coutcolor(1,35,207,"               ESC: Thoat                 |                     Up,Down,Left,Right  : Di chuyen              |             Enter:    Chon           ");

	

											//PHIEN LAM VIEC BAT DAU!
	while (1)
	{
		k=getch();
		
		// kiem tra tinh dung dan cua du lieu
		if (vtri!=6)
		{
		if (aa[vtri].dulieu.length()>0) 
		{
			if ((vtri==5)&&(toint(aa[5].dulieu)<20||toint(aa[5].dulieu)>250))
			{
				da_dien[vtri]=0;
				coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                     ");
				coutcolor(aa[vtri].x+52,aa[vtri].y,124," Khong hop le! (20<=so ghe<=250) ");
			}
			else if (vtri==3)
			{
			if (Array_Search(ds,aa[3].dulieu)>0)
			{
				if (mamaybay!="")
				{
					if (sohieuhientai==aa[3].dulieu)
					{
						da_dien[vtri]=1;
						coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                     ");
						coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
					}
					else
					{
						da_dien[vtri]=0;
						coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                     ");
						coutcolor(aa[vtri].x+52,aa[vtri].y,124," So hieu may bay da ton tai! ");
					}
				}
				else
				{
					da_dien[vtri]=0;
					coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                     ");
					coutcolor(aa[vtri].x+52,aa[vtri].y,124," So hieu may bay da ton tai! ");
				}
			}
			else
			{
				da_dien[vtri]=1;
				coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                     ");
				coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
			}	
			} 
			else
			{
				da_dien[vtri]=1;
				coutcolor(aa[vtri].x+52,aa[vtri].y,122,"                                     ");
				coutcolor(aa[vtri].x+52,aa[vtri].y,122," OK");
			}		
		}
		else 
		{
			da_dien[vtri]=0;
			coutcolor(aa[vtri].x+52,aa[vtri].y,122,"   ");	
		}
		}
		
		// cac phim tat dac biet
		if (k==ENTER_KEY)
		{
			if (vtri!=6) 
			{
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
					Maybaychecksave(aa,da_dien,mamaybay,vitricu);
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
					coutcolor(62,12+i,41,"                                      ");
				}	
				if (mamaybay=="")
				{
					coutcolor(62,14,46," Ban co muon them may bay khong?(Y/N) ");
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
								coutcolor(62,12+i,120,"                                       ");
							}	
							ve_khung(aa[3]);
							ve_khung(aa[4]);
							ve_khung(aa[5]);
							break;
						}
						if (k==89||k==121)
						{
							Maybaychecksave(aa,da_dien,mamaybay,vitricu);
						}
						if (k==78||k==110)
						{
							menu();
						}
					}
				}
				else
				{
					coutcolor(62,14,46," Ban co muon luu may bay khong?(Y/N) ");
					coutcolor(62,17,95,"      Co(Y)       ");
					coutcolor(81,17,95,"     Khong(N)     ");
					coutcolor(1,1,130,"");
					while (1)
					{
						k=getch();
						if (k==ESC_KEY)
						{
							for (int i=1;i<=6;i++)
							{					
								coutcolor(62,12+i,120,"                                         ");
							}	
							ve_khung(aa[3]);
							ve_khung(aa[4]);
							ve_khung(aa[5]);
							break;
						}
						if (k==89||k==121)
						{
							Maybaychecksave(aa,da_dien,mamaybay,vitricu);
						}
						if (k==78||k==110)
						{
							menu();
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
				if (vtri==5&&((k>=65&&k<=90)||(k>=97&&k<=122)||k==SPACE_KEY||k==45))
				{
					continue;
				}
				if ((vtri==3)&&(aa[vtri].dulieu.length()>15)&&(k!=BACKSPACE_KEY)&&(k!=45)) continue;
				flag=1;
				if (k==BACKSPACE_KEY) 
				{
					xoa_ky_tu(aa[vtri]);
				}
				else
				{
					them_ky_tu(aa[vtri],k);
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
