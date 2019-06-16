void menu_con(int key)                              // menu con
{  
	string s0[8]={"","                            ","                                  ","                                 ","                                   ","                            ","                               "};
	string s1[8]={""," Them may bay      "," Xem/Chinh sua     "," Xoa may bay       "," Thong ke luot bay "};
	string s2[8]={""," Them chuyen bay           "," Xem/Chinh sua             "," Xoa chuyen bay            "," Huy chuyen bay            "," Xem chuyen bay trong ngay "," Xem DS hanh khach         "};	
	string s3[8]={""," Dat ve            "," Xem/Chinh sua     "," Huy ve            "," Xem ghe trong     "};
	
	if (key==1){
		coutcolor(20,1,160,s1[1]);
		for (int i=2;i<5;i++) coutcolor(20,i,224,s1[i]);
	}
	if (key==2){
		coutcolor(20,1,160,s2[1]);
		for (int i=2;i<7;i++) coutcolor(20,i,224,s2[i]);
	}
	if (key==3){
		coutcolor(20,1,160,s3[1]);
		for (int i=2;i<5;i++) coutcolor(20,i,224,s3[i]);
	}
	
	int vtri=1;
	int k;
	while (1)
	{
		while (!kbhit()){ thoigian(); }
		
		k=getch();
		if (k==ESC_KEY){  for (int i=1;i<6;i++) coutcolor(20,i,119,s0[i]); return; } 
		
		if (k==ENTER_KEY)
		{
			if (key==1)
			{
				if (vtri==1) 
				{
				    //kiem tra xem so may bay co max hay chua?
				    if (Array_Full(ds)==1) coutcolor(10,15,78,"Khong the nhap may bay!"); 
				    else them_may_bay("");	 // neu ds tuyen tinh van con trong
				}
				if (vtri==2){ chon_may_bay(1); }
				if (vtri==3){ chon_may_bay(2); }
				if (vtri==4) { hienthicauf();  }
			}
			if (key==2)
			{
				if (vtri==1) { chon_may_bay(3); }
				if (vtri==2) { ket_qua_tim_chuyen_bay("","",2); }
				if (vtri==3) { ket_qua_tim_chuyen_bay("","",3); }
				if (vtri==4) { ket_qua_tim_chuyen_bay("","",4); }
				if (vtri==5) { tim_chuyen_bay(2); }
				if (vtri==6) { ket_qua_tim_chuyen_bay("","",5); }
			}
			if (key==3)
			{
				if (vtri==1) { tim_chuyen_bay(1); }
				if (vtri==2) { tim_kiem_hanh_khach(2,""); }
				if (vtri==3) { tim_kiem_hanh_khach(3,""); }
				if (vtri==4) { ket_qua_tim_chuyen_bay("","",6);}
			}
		}
		if (k==224)
		{
			k=getch();
			switch(k)
			{
				case DOWN_KEY:
				{
					if (key==1)
					{
						coutcolor(20,vtri,224,s1[vtri]); vtri++; if (vtri==5) vtri=1;
						coutcolor(20,vtri,160,s1[vtri]);
						break;
					}
					if (key==2)
					{
						coutcolor(20,vtri,224,s2[vtri]); vtri++; if (vtri==7) vtri=1;
						coutcolor(20,vtri,160,s2[vtri]);
						break;
					}
					if (key==3)
					{
						coutcolor(20,vtri,224,s3[vtri]); vtri++; if (vtri==5) vtri=1;
						coutcolor(20,vtri,160,s3[vtri]);
						break;
					}
				}
				case UP_KEY:
					{
						if (key==1)
						{
							coutcolor(20,vtri,224,s1[vtri]); vtri--; if (vtri==0) vtri=4;
							coutcolor(20,vtri,160,s1[vtri]);
							break;	
						}
						if (key==2)
						{
							coutcolor(20,vtri,224,s2[vtri]); vtri--; if (vtri==0) vtri=6;
							coutcolor(20,vtri,160,s2[vtri]);
							break;	
						}
						if (key==3)
						{
							coutcolor(20,vtri,224,s3[vtri]); vtri--; if (vtri==0) vtri=4;
							coutcolor(20,vtri,160,s3[vtri]);
							break;	
						}
					}
				case LEFT_KEY:
					{
						for (int i=1;i<7;i++) coutcolor(20,i,119,s0[i]);
						return;	
					}	
			}
		}
	}
}
void menu()
{
	
	string s[8]={"","1.May bay      ","2.Chuyen bay   ","3.Khach hang   ","4.Gioi thieu   ","5.Thoat        "};
	setScreen();
	coutcolor(1,35,207,"              ESC: Thoat              |                 Up,Down,Left,Right  : Di chuyen                   |               Enter:    Chon             ");
	char c=char(196);
	string s00; s00+=c;
	for (int i=0;i<=149;i++) coutcolor(i,7,114,s00);
	//Menu chinh
	coutcolor(5,1,160,s[1]);
	for (int i=2;i<6;i++){ coutcolor(5,i,224,s[i]); }
	int vtri=1,k;
	while (1)
    {
    	cap_nhat_ds_bay();
    	while (!kbhit()) { 	thoigian();}
    	k=getch();
    	thoigian();
    	if (k==ENTER_KEY) 
    	{
    	 	switch(vtri)
    	 	{
    	 		case 1: { menu_con(1); break;}
    	 		case 2: { menu_con(2); break;}
    	 		case 3: { menu_con(3); break;}
    	 		case 4: { gioithieu(); break;}
				case 5: { thankyou();   Save_file(); exit(0);}	
			}
		}
		if (k==ESC_KEY) 
		{
		 	thankyou(); Save_file(); exit(0);
		}
		if (k==224)
		{
		    k=getch();
			switch(k)
			{
				case DOWN_KEY:    //xuong
				{
					coutcolor(5,vtri,224,s[vtri]); vtri++; if (vtri==6) vtri=1;
					coutcolor(5,vtri,160,s[vtri]);
					break;
				}  	
				case UP_KEY:
				{
					coutcolor(5,vtri,224,s[vtri]); vtri--; if (vtri==0) vtri=5;
					coutcolor(5,vtri,160,s[vtri]);
					break;
				}
				case RIGHT_KEY:
				{
					switch(vtri)
    	 			{
    	 				case 1: {menu_con(1);break;}
    	 				case 2: {menu_con(2);break;}
    	 				case 3: {menu_con(3);break;}
					}		
				}
		    }		
		} 	
	} 
}
void cap_nhat_ds_bay()
{
	chuyenbay a[50];   // hien thi tam thoi cac chuyen bay
	int i=0;
	int n;
	LinkPTR p,q;
	string s;
	tm current_time;
    time_t timer =time(NULL);
    current_time = *localtime(&timer);
    

	// chuan bi du lieu
	for (p=link;p!=NULL;p=p->next)
	{
		if (p->info.thoigian.ngay.dd==current_time.tm_mday&&p->info.thoigian.ngay.mm==current_time.tm_mon+1&&p->info.thoigian.ngay.yy==current_time.tm_year+1900)
		{
			a[i]=p->info;
			i++;	
		}	
	}
	n=i;
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (a[i].thoigian.gio>a[j].thoigian.gio) swap(a[i],a[j]);
			else if (a[i].thoigian.gio==a[j].thoigian.gio) if (a[i].thoigian.phut>a[j].thoigian.phut) swap(a[i],a[j]);
		}
	}
	
	// kiem tra xem chuyen bay nao da bay roi
	
	for (int i=0;i<n;i++)
	{
		if (current_time.tm_hour>a[i].thoigian.gio)
		{
			for (q=link;q!=NULL;q=q->next)
			{
				if (strcmp(q->info.machuyenbay,a[i].machuyenbay)==0&&q->info.trangthai==1)
				{
					a[i].trangthai=2;
		 			int gg=Array_Search(ds,setdata(	a[i].sohieumb));
					ds.nodes[gg]->flag=0;
					ds.nodes[gg]->sochuyendathuchien++;
					q->info.trangthai=2;
					q->info.n=0;
					break;
				}
			}
		}
		if (current_time.tm_hour==a[i].thoigian.gio)
		 if (current_time.tm_min>=a[i].thoigian.phut)
		 {
			for (q=link;q!=NULL;q=q->next)
			{
				if (strcmp(q->info.machuyenbay,a[i].machuyenbay)==0&&q->info.trangthai==1)
				{
					q->info.trangthai=2;
					q->info.n=0;
				//	q->info.sohieumb="";
					a[i].trangthai=2;
		 			int gg=Array_Search(ds,setdata(	a[i].sohieumb));
					ds.nodes[gg]->flag=0;
					ds.nodes[gg]->sochuyendathuchien++;
					break;
				}
			}
		 }
	}
	current_time.tm_sec+=1209600;
    mktime(&current_time);
	
	//Tao khung Desktop
	coutcolor(59,9,78," BANG THONG TIN CAC CHUYEN BAY NGAY ");
	coutcolor(1,11,250,"      Gio bay      ");
	coutcolor(20,11,250,"|                 Noi den                   ");
	coutcolor(64,11,250,"|         May bay         ");
	coutcolor(89,11,250,"|    Cua    ");
	coutcolor(101,11,250,"|                   Ghi chu                      ");
	for (int i=0;i<=10;i++)
	{
			coutcolor(1,12+i,249,"                   ");
			coutcolor(20,12+i,249,"|                                            ");
			coutcolor(64,12+i,249,"|                         ");
			coutcolor(89,12+i,249,"|           ");
			coutcolor(101,12+i,249,"|                                                ");
	}
	if (i==0)
	{
		coutcolor(54,15,174,"KHONG CO CHUYEN BAY NAO HOAT DONG TRONG HOM NAY");
	}
	else
	{
		for (int i=0;i<n;i++)
		{
			coutcolor(7,12+i,249,""); cout<<a[i].thoigian.gio<<":"<<a[i].thoigian.phut;
			coutcolor(25,12+i,249,""); cout<<a[i].sanbayden;  coutcolor(45,12+i,249,"                ");
			coutcolor(74,12+i,249,""); cout<<a[i].sohieumb;
			coutcolor(94,12+i,249,""); cout<<"15D";
			if (a[i].trangthai==1) 
			{
				s=" Da dat "+tostring(a[i].n)+" ve may bay  ";
				coutcolor(106,12+i,47,s);
			}
			else if (a[i].trangthai==2)
			{
				s=" Da cat canh ";
				coutcolor(106,12+i,159,s);
			}
			else
			{
				s=" Chuyen bay da bi huy ";
				coutcolor(106,12+i,78,s);
			}
		}
	}
}

void gioithieu()
{
	setScreen();
	fstream filein;
	filein.open("hello.txt");
	string s;
	int k;
	
	while (!filein.eof())
	{
		getline(filein,s);
		cout<<s<<endl;
	}
	
	
	while (1)
	{
		k=getch();
		if (k==ESC_KEY) menu();
	}
}
void thankyou()
{
	setScreen();
	fstream filein;
	filein.open("goodbye.txt");
	string s;
	int k;
	
	while (!filein.eof())
	{
		getline(filein,s);
		cout<<s<<endl;
	}
	
	k=getch();
}

