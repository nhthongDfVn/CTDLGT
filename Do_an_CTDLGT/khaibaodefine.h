#include <string>
using namespace std;

//KEY
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define F6 64
#define F7 65
#define F8 66
#define F9 67
#define F10 68
#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define DELETE_KEY 83
#define ENTER_KEY 13
#define ESC_KEY 27
#define	SPACE_KEY 32
#define	TAB_KEY 9
#define BACKSPACE_KEY 8
#define MAX_LENGTH 30
//STRUCT dùng chung
struct date
{
	int dd,mm,yy;
};
struct datetime
{
	date ngay;
	int gio,phut;
};
long long toint(string s);
string setdata(char a[30]);
string tostring(long long  n);
void Init();
void Save_file();
void gioithieu();
void thankyou();
int thoigianhientai(string ngay,string gio);


							//dohoa.h
void textcolor(int x);
void gotoxy(int x, int y);
void coutcolor(int x, int y, int color, string s);
void thoigian();


							//menu.h
void menu();
void menu_con(int key);
void cap_nhat_ds_bay();





							//hamchucnang.h
struct khung
{
	int id,vt,x,y,color;
	string dulieu,tenkhung;	
};
void xoa_ky_tu(khung &x);
void them_ky_tu(khung &x,int k);
void ve_khung(khung x);
int so_sanh_thoi_gian(int hh1,int mm1, int hh2, int mm2);


							//maybay.h
void them_may_bay(string mamaynbay);
int check_may_bay(int vt);
void chon_may_bay(int id);               //1: hieu chinh      2. xoa        3. them chuyen bay
void in_thong_tin_may_bay(int vt);
void Maybaychecksave(khung aa[6],int da_dien[6], string mamaybay,int vitricu);   // kiem tra de luu lai thong tin may bay

const int MAX_ARRAY=301;

struct maybay
{
	char hangsanxuat[30];
	char hanghangkhong[30];
	char sohieu[30];
	char loai[30];
	int socho;
	int flag;     //cho biet may bay co dang thuc hien chuyen bay nao hay khong flag=0//khong flag=1 // co
	int sochuyendathuchien;
};

struct dlist
{
	int n=0;
	maybay *nodes[301];
};
void Array_nhapFile();
void Array_xuatFile(dlist &ds);
int Array_Full(dlist &ds);
int Array_Insert(dlist &ds, maybay &info);
int Array_Delete(dlist &ds,int i);
int Array_Empty(dlist &ds);
void Array_Traverse(dlist ds);
void Array_Init(dlist &ds);
int Array_Search(dlist &ds, string machuyen);
maybay Array_setdata(khung a[6]);
void Array_update(dlist &ds,khung a[6], int i);





							//chuyenbay.h
int check_chuyen_bay(int vt);
void them_chuyen_bay(string mamaybay,string machuyenbay,int  sign );
int check_ngay_thang(string s);
int check_thoi_gian(string s);
void tim_chuyen_bay(int sign);
void ket_qua_tim_chuyen_bay(string sanbayden,string ngaydi,int id);
void Chuyenbaychecksave(khung aa[6],int da_dien[6],int  sign,string machuyenhientai);

struct ds_ve
{
	int vitrighe;
	long long cmnd;
};
struct chuyenbay
{
	char machuyenbay[30];
	datetime thoigian;
	char sanbayden[30];
	char sohieumb[30];
	int trangthai; //0:Huy 1:Con ve 2:Het ve 3:Da cat canh
	int n=0;    // so luong ve cua chuyen bay
};
struct Linknode
{
	chuyenbay info;
	struct ds_ve *ds[251]; 
	Linknode* next;
};
typedef Linknode* LinkPTR;

void Link_nhapFile();
void Link_xuatFile(LinkPTR  &link);
void Link_Init(LinkPTR &First);
int Link_Empty(LinkPTR &First);
void Link_Insert_First(LinkPTR &First,chuyenbay info);
void Link_Insert_After(LinkPTR &First,chuyenbay info);
void Link_Delete_Info(LinkPTR &First, chuyenbay info);
LinkPTR Link_Search(LinkPTR &first,string machuyenbay);
void Link_Traverse(LinkPTR link);
chuyenbay Link_setdata(khung a[6]);
void Link_update(LinkPTR &link,khung a[6], string machuyenhientai);
void Link_Array_Update(LinkPTR &link,string machuyenbay,long long cmndcu,long long cmndmoi,int vtghe);


//danh cho mang con tro ben trong ds lien ket

int Link_Array_Empty(LinkPTR &link);
void Link_Array_Init(LinkPTR &link);
int Link_Insert_Passenger(LinkPTR &link,string machuyenbay,ds_ve info);
int Link_Array_Full(LinkPTR &link);
int Link_Array_Delete(LinkPTR &link,string machuyenbay,int i);
int Link_Array_Search(LinkPTR &link,string machuyenbay, long long cmnd);













							//hanhkhach.h
void DatVe(long long id, int sign, string vtghe,string machuyenbay,string mamaybay);	    //1: them hanh khach   2: chinh sua thong tin	3: lay data da luu tu truoc lai					
int check_cmnd(string s);	
int check_ghe(int x, int y);	
void cho_ngoi(string machuyenbay,string vitricu, long long id, int sign);		
int xac_dinh_vi_tri(string s);
string xac_dinh(int k);		
void tim_kiem_hanh_khach(int sign,string machuyenbay);
void huyve(long long cmnd);
int dadatve(long long cmnd);
							
							
struct hkhach
{
	char hoten[30];
	char quequan[30];
	date dob;
	int gioitinh;
	long long cmnd;	
};
struct node_tree
{
	hkhach info;
	struct node_tree *left;
	struct node_tree *right;
};
typedef struct node_tree *NODEPTR;


string xuly_date(NODEPTR p);
hkhach Tree_set_data(int i, khung a);

//Nhap xuat file
void Tree_write(NODEPTR &p); 
void Tree_xuatFile(NODEPTR &root);           
void Tree_nhapFile();

//Ham chuc nang BTS
void Tree_Insert_node(NODEPTR &p, hkhach a);
void Tree_Preorder(NODEPTR p);
void Tree_nhapFile();
void Tree_xuatFile(NODEPTR &root);
int Tree_Search(NODEPTR root, long long  x);
void Tree_Init(NODEPTR &root);
void Tree_remove_case3(NODEPTR &r);
void Tree_remove(long long  x,NODEPTR &p);
int Tree_Empty(NODEPTR root);
NODEPTR Tree_Location(NODEPTR root,long long x);
void Tree_update(NODEPTR &tree,khung a[6], long long id, string machuyenbay,int vtghe);
void Hanhkhachchecksave(khung aa[6],int da_dien[6],long long id,string machuyenbay, int vtghe, int sign);



									//caue2.h

void xuat_ds_nguoi(string mcb);


									// cauh.h
									
void hienthicauf();


									// cauf.h
void cauf(string sanbayden, string ngaydi);


dlist ds;
NODEPTR tree;
LinkPTR link;




