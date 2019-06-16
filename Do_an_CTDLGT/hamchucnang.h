void Init()
{
	//Cay BST           HANH KHACH
	Tree_Init(tree);
	Tree_nhapFile();

	//mang con tro      MAY BAY
	Array_Init(ds); 
	Array_nhapFile();

	//danh sach lien ket CHUYEN BAY
	Link_Init(link);
	Link_nhapFile();


}

void Save_file()
{
	//Cay BST          HANH KHACH
	Tree_xuatFile(tree);
	
	//mang con tro       MAY BAY
	Array_xuatFile(ds);
	
	//danh sach lien ket      CHUYEN BAY
	
	Link_xuatFile(link);
} 

long long toint(string s)
{ 
	long long x=0; 
	stringstream geek(s); 
	geek >> x; 
	return x; 
}
string tostring(long long  n) 
{ 
	stringstream ss;
	string s1; 
	ss<<n; 
	s1=ss.str();
	return s1;
}

string setdata(char a[30])
{
	string s(a);
	return s;
}


string xuly_date(NODEPTR p)
{
	string s, s1, s2, s3;
	int k = p->info.dob.dd;
	while (k!= 0)
	{

		s1 += (k % 10) + '0';
		k /= 10;
	}
	reverse(s1.begin(), s1.end());
	if (s1.length() == 1) s1 = '0' + s1;
	s += s1 + '/';
	k = p->info.dob.mm;
	while (k!= 0)
	{

		s2 += (k % 10) + '0';
		k /= 10;
	}
	reverse(s2.begin(), s2.end());
	if (s2.length() == 1) s2 = '0' + s2;
	s += s2 + '/';
	k = p->info.dob.yy;
	while (k!= 0)
	{
		s3 += (k % 10) + '0';
		k /= 10;
	}
	reverse(s3.begin(), s3.end());
	s += s3;
	return s;
}

void xoa_ky_tu(khung &x)
{
	if (x.vt<=1||x.vt>=MAX_LENGTH+1) return; 
	x.dulieu.erase(x.dulieu.begin()+x.vt-2);  x.vt--;	
}


void them_ky_tu(khung &x,int k)
{
	if (x.dulieu.length()>=MAX_LENGTH-1) return;
	string temp;
	temp=temp+char(k);
	x.dulieu.insert(x.vt-1,temp);
	x.vt++;
}


void ve_khung(khung x)
{
	string temp;
	coutcolor(x.x,x.y,121,x.tenkhung);
	if (x.dulieu.length()>0)
	{
		temp=x.dulieu;
		for (int i=1;i<=(MAX_LENGTH-x.dulieu.length());i++) temp+=" ";
		coutcolor(x.x+x.tenkhung.length()+5,x.y,x.color,temp);
	}
	else
		for (int i=1;i<=MAX_LENGTH;i++) temp+=" "; coutcolor(x.x+x.tenkhung.length()+5,x.y,x.color,temp);
}


int check_ngay_thang(string s)
{
	if ((s[2]!='/')||(s[5]!='/')) return 0;
	if (s.length()!=10) return 0;
	int dd=(s[0]-'0')*10+(s[1]-'0');
	int mm=(s[3]-'0')*10+(s[4]-'0');
	int yy=(s[6]-'0')*1000+(s[7]-'0')*100+(s[8]-'0')*10+(s[9]-'0');
	int ddmax;
	if (yy<=1900 || mm<=0 || mm> 12 || dd<=0 || dd> 31)
    {
        return 0;
    }
    else
    {
        switch (mm)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              ddmax=31;
              break;
            case 2:
                if ((yy%4==0 && yy%100!=0) || (yy%400==0))
                    ddmax=29;
                else 
                    ddmax=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                ddmax=30;
                break;
        }
        if (dd<=ddmax)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


int check_thoi_gian(string s)
{
	if (s[2]!=':') return 0;
	if (s.length()!=5) return 0;
	int hh=(s[0]-'0')*10+(s[1]-'0');
	int mm=(s[3]-'0')*10+(s[4]-'0');
	if (hh<0||hh>24||mm<0||mm>60)
		return 0;
	else 
		return 1;
}

int so_sanh_thoi_gian(int hh1,int mm1, int hh2, int mm2)
{
	if (hh1*60+mm1<hh2*60+mm2) return 1; else return 0;
}

int check_cmnd(string s)
{
	if (s.length()==12||s.length()==9)
	{
		long long x=toint(s);
		if (Tree_Search(tree,x)==1) return 2; else return 1;
	 }
	 else return 0;
	
}
int thoigianhientai(string ngay,string gio)   
{
	
	// xu ly dau vao
	if ((ngay[2]!='/')||(ngay[5]!='/')) return 0;
	if (ngay.length()!=10) return 0;
	int dd=(ngay[0]-'0')*10+(ngay[1]-'0');
	int mm=(ngay[3]-'0')*10+(ngay[4]-'0');
	int yy=(ngay[6]-'0')*1000+(ngay[7]-'0')*100+(ngay[8]-'0')*10+(ngay[9]-'0');
	
	
	tm current_time;
    time_t timer =time(NULL);
    current_time = *localtime(&timer);
    
   // cout<<current_time.tm_hour<<":"<<current_time.tm_min<<":"<<current_time.tm_sec<<endl;
   // cout<<current_time.tm_mday<<":"<<current_time.tm_mon+1<<":"<<current_time.tm_year+1900<<endl;
    if (gio=="")
    {
		if (yy>current_time.tm_year+1900) return 2;
		if (yy<current_time.tm_year+1900) return 1;
		if (yy==current_time.tm_year+1900)
		{
			if (mm>current_time.tm_mon+1) return 2;
			if (mm<current_time.tm_mon+1) return 1;
			if (mm==current_time.tm_mon+1)
			{
				if (dd>current_time.tm_mday) return 2;
				if (dd<current_time.tm_mday) return 1;
				if (dd==current_time.tm_mday) return 2;	
			}
		}
	}
	else
	{
		if (gio[2]!=':') return 0;
		if (gio.length()!=5) return 0;
		int hh=(gio[0]-'0')*10+(gio[1]-'0');
		int mi=(gio[3]-'0')*10+(gio[4]-'0');
		
		
		if (yy>current_time.tm_year+1900) return 2;
		if (yy<current_time.tm_year+1900) return 1;
		if (yy==current_time.tm_year+1900)
		{
			if (mm>current_time.tm_mon+1) return 2;
			if (mm<current_time.tm_mon+1) return 1;
			if (mm==current_time.tm_mon+1)
			{
				if (dd>current_time.tm_mday) return 2;
				if (dd<current_time.tm_mday) return 1;
				if (dd==current_time.tm_mday)
				{
					if (hh>current_time.tm_hour) return 2;
					if (hh<current_time.tm_hour) return 1;
					if (hh==current_time.tm_hour)
					{
						if (mi>current_time.tm_min) return 2;
						if (mi<current_time.tm_min) return 1;
						if (mi==current_time.tm_min) return 1;
					}
				}
			}
		}
		
	}
	current_time.tm_sec+=1209600;
    mktime(&current_time);
}
