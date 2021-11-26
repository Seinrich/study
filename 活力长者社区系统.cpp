/*
本系统分为会员管理，房屋管理，入住管理，娱乐设施管理，用户管理，班车管理六个基本模块
设置会员，员工，管理员三种权限，权限依次扩大，管理员拥有最高权限
会员管理分为新建，查询，修改，删除等功能，为主体功能
会员信息与房屋，用户，娱乐设施，班车多个模块信息相互交互影响
入住管理，房屋管理功能相对简单，诸多相关功能与会员管理的功能绑定因此不重复设定
班车管理相对独立，但与用户，会员有一定的联系，录入信息时请注意
娱乐设施管理功能实现相对复杂，需要针对一个操作对多个储存会员，队列，用户的链表进行修改
本系统主体数据大多由链表储存，一些相对简单的数据用数组，结构体等记录
会员指业主，用户指职工
本系统运用了多种结构如循环，分支，顺序
根据实际情况灵活运用了switch,while,for,if,if-else,do-while等结构
针对相对重复的代码采用了预处理的方式减少代码量，提高运行效率
本系统遵循模块化，结构化编程思想，设置多个函数通过按应用传递和按值传递实现功能
针对已不需要的内存空间，及时使用了free等函数释放了内存空间，保证了程序的正常运行
针对程序的稳定性，为增加程序容错性，采用多种方式保证输入格式的正确
本系统难点在于不同数据类型如何在不同函数内互相影响
变量为英文命名，并适当辅以注释，增加可读性
对一些使用频率相对较高的代码进行封装
合理利用了多种查找，排序算法进行对数据的处理 

******会员权限密码：123
******职工权限密码：456 
******管理员权限密码：789 
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h> 

#define BUILDING 6//栋数 
#define UNIT x//单元数 
#define FLOOR y//层数 
#define ROOM z//房间数 
//预处理将楼字母序号转化为数组序号  
#define VIPHOUSE \
cn=CN(startPtr->member.bulidingcharacter);\
*(house+BUILDING*FLOOR*UNIT*cn+FLOOR*UNIT*(startPtr->member.unitnumber-1)+UNIT*(startPtr->member.floornumber-1)+startPtr->member.roomnumber-1)='+'; 

#define ENJOY \
if(enjoy[newbuilt-1]==1){\
printf("不可重复新建，操作无效化处理\n");break;}

#define HOUSECN \
	int num;\
	char character;\
	int unumber,fnumber,rnumber;\
	while(character<'A'||character>'F'||unumber<1||unumber>UNIT||fnumber<1||fnumber>FLOOR||rnumber<1||rnumber>ROOM){\
printf("***请输入房屋基本信息（如：A 1 1 1 ）\n");\
scanf("%c %d %d %d",&character,&unumber,&fnumber,&rnumber);\
fflush(stdin);\
}\
num=CN(character);

#define BUSNUM \
int i;\
for(i=0;i<10;i++){\
	if(shuttle[i].number==0){\
	shuttlenum=i;\
	break;}\
	if(shuttle[9].number!=0){\
	printf("***批次已达上限，操作无效");\
	system("pause>nul");\
	return ;} \
}

//全局变量 
int choicepower=0;//权限 
int power=0;
struct vip{
	char vipname[20];//姓名 
	char vipdocument[20];//身份证号 
	int vipphone;//会员电话号码 
	int vipnumber;//会员账号 
	char bulidingcharacter;//楼号 
	int unitnumber;//单元号 
	int floornumber;//层数 
	int roomnumber;//房号 
};
typedef struct vip VIP;//定义会员信息的结构体类型 
VIP older;// VIP数最多为房屋的总数 

struct bus{
int number;//班车编号 
int fee;//乘车费用 
int timecome[2];//去社区班车时间 
int timego[2];//离社区班车时间 
};
typedef struct bus BUS;//定义班车信息的结构体类型 
BUS shuttle[10]; //最多十个批次
int shuttlenum=0;//记录班车批次数量 
int recreation;//娱乐活动 
int vipn=1;//辅助序号 
int usern=1;//辅助序号 
int x,y,z;//单元数，层数，户数 
unsigned int systemch;//系统选择 
int pingpong=0,badminton=0,yoga=0,chess=0,tableball=0,tea=0,newspaper=0,book=0;
int opera=0,shuttlecock=0,dance=0,handwriting=0,weave=0,chat=0;//储存提案数量
int enjoy[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};//记录娱乐设施状态
int enjoynum[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};//记录娱乐设施人数状态 

struct serviceLink{//会员，房屋，用户，班车，设施，入住情况挂钩，构建一个链表将其储存（关键） 
	VIP member;//储存会员信息（包含房屋信息） 
	int enjoyment;//储存娱乐设施预约信息  
	int staysituation;//储存入住状态
	int usercontact;//储存与职工联系的状态 
	int busstate;//储存提交途径地提案的状态 
	struct serviceLink *nextPtr;//自引用结构体（链表） 
}; 
typedef struct serviceLink ServiceLink;
typedef ServiceLink *ServiceLinkPtr;
ServiceLinkPtr startPtr=NULL;//初始化链表头结点

 struct user{
	char username[20];//职工姓名 
	int usernumber;//职工号
	int userphone;//职工电话号码 
	int account[10];//每个职工服务十个会员 
};
typedef struct user USER;//定义职工信息的结构体类型

struct userlink{
	USER information;//储存职工信息 
	int busstate;//储存提交途径地提案的状态 
	struct userlink *nextPtr;
};
typedef struct userlink UserLink;//定义职工链表的结构体类型
typedef UserLink *UserLinkPtr; 
USER worker;
UserLinkPtr startuserPtr=NULL;//创建一个储存职工信息的链表 
//因为预约不适用于队列（会有提前取消离开的情况），所以用链表记录排队情况 
struct link{//记录排队者 
	int account;
struct link *nextPtr;
};
typedef struct link Link;//构建排队的链表以应用于排队的场景  
typedef Link *LinkPtr;
//初始化头尾节点 
 LinkPtr headPtr[14]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
  
struct buswayslink{//构建班车途径地的链表储存途径地的信息 
	char placename[20];//途径地名称 
	int employeenumber;//职工账号 
	struct buswayslink *nextPtr;//指向下一节点 
};
typedef struct buswayslink BusLink;
typedef BusLink *BusLinkPtr;
BusLinkPtr startbusPtr[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
  
struct planning{//用于返回三个参数构建社区地图 
	int x;
	int y;
	int z;
};

//函数声明 
void permission();//申请会员，职工，管理员权限 
void management(char *house);//选择管理系统 
struct planning instructions();//阐述活力长者社区的基本情况 并返回单元，层，户 的参数 
void map(char *house);//通过打印地图直观展示社区 
void inithouse(char *house);//初始化社区房屋  
void vipmanage(char *house);//会员管理 
void housemanage(char *house);//房屋管理 
void staymanage(char *house);//入住管理 
void publicmanage(char *house);//公共设施管理 
void usermanage(char *house);//用户管理 
void routinemanage(char *house);//班车路线管理 
void vipbuilt(ServiceLinkPtr *sptr,char *house);//新建会员
void vipinquiry(ServiceLinkPtr sptr,char *house);//查询会员
void vipchange(ServiceLinkPtr *sptr,char *house);//修改会员
void changevipuserlink(UserLinkPtr *sptr,int useraccount,int vipaccount);//在删除会员的同时删除对应职工链表中服务人员信息 
void vipdelete(ServiceLinkPtr *sptr,char *house);//删除会员
void printlist(ServiceLinkPtr sptr);//打印会员列表 
int empty(ServiceLinkPtr sptr);//判断会员列表是否为空 
void housebuy(ServiceLinkPtr sptr,char *house);//查询房屋购买状况
void housestay(ServiceLinkPtr sptr,char *house);//查询房屋入住状况
void houseowner(ServiceLinkPtr sptr,char *house);//查看房屋所有者信息
void hire(ServiceLinkPtr sptr,char *house);//查询出租的房屋列表
void vacant(ServiceLinkPtr sptr,char *house);//查询空置的房屋列表
void onsale(ServiceLinkPtr sptr,char *house);//查看未售的房屋列表
void application(ServiceLinkPtr *sptr);//申请娱乐设施服务 
void new_built();//新建房屋列表 
void scheme();//上交提案 
void end(ServiceLinkPtr *sptr);//结束娱乐服务 
int isempty(LinkPtr headPtr);//检查队列是否为空
void enlink(LinkPtr *sptr,int num);//增加排队链表元素 
void printlinelink(LinkPtr sptr);//打印排队链表 
int delink(LinkPtr *sptr,int deletenumber);//删除预约人员 
void creatuser(UserLinkPtr *sptr);//新建服务人员服务 
void chooseuser(ServiceLinkPtr *sptr,UserLinkPtr *usersptr);//选择服务对象 
void visituser(UserLinkPtr *sptr);//查看服务对象
void printuser(UserLinkPtr sptr);//查看服务人员列表
void changecontact(ServiceLinkPtr *sptr,int account);//修改用户和成员联系参数 
void deleteuser(UserLinkPtr *startuserPtr);//删除服务人员	
int userempty(UserLinkPtr sptr) ;//检查是否为空  
void creatbus();//新建班车批次服务 
void deletebus();//删除班车批次
void deletebuslink(BusLinkPtr *sptr,ServiceLinkPtr *vipsptr,UserLinkPtr *usersptr);//删除公交途径地链表 
void buslist();//查看班车批次列表
void addplace(BusLinkPtr *sptr,char place[20],int number);//增加途径地 
void ways(UserLinkPtr *usersptr,ServiceLinkPtr *sptr);//添加班车途径地 
void changebus();//修改班车批次	
void busheadtailinit(BusLinkPtr *sptr); //初始化班车链表头结点为公交总站
void init(char *house);//初始化集合 
int  CN(char character);//字母转化序号
char  NC(int num);//序号转化字母 

void  gotoxy( int  x,  int  y) //gotoxy 源代码光标,用于打印地图等操作 
{
COORD pos;
pos.X = x ;
pos.Y = y ;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main(){//主函数	 
    permission();
    struct planning design;
    design=instructions();
    char house[6][design.y][design.x][design.z];//房屋
    init((char *)house);//初始化房屋数组 
    map((char *)house); 
    management((char *)house);
	return 0;
} 

void permission(){//申请会员，职工，管理员权限 
		system("color 0D");
	printf("********************************************************************\n");
	printf("***              ---------活力长者社区系统---------              ***\n");
	printf("********************************************************************\n"); 
	system("pause>nul"); 
int password;//设置密码 
system("color 0E");
while(power!=1&&power!=2&&power!=3){
	system("cls");
		printf("**********活力长者社区权限系统**********\n");
	    printf("****        ---请选择权限---        ****\n");
	    printf("***1.会员权限 2.职工权限 3.管理员权限***\n");
	    printf("****************************************\n");
	scanf("%d",&choicepower);
	fflush(stdin);
while(choicepower<1||choicepower>3){//分支权限 
	printf("***请选择权限\n***1.会员权限 2.职工权限 3.管理员权限\n");
	scanf("%d",&choicepower);//循环输入 
	fflush(stdin);
}
if(choicepower==1){ 
printf("***请输入会员权限密码：\n");
scanf("%d",&password);
fflush(stdin);
if(password!=123){
	printf("***密码输入错误，请重新选择\n");
	system("pause>nul");
	power=0;
}else power=1;
} 
else if(choicepower==2){ 
printf("***请输入职工权限密码：\n");
scanf("%d",&password);
fflush(stdin);
if(password!=456){
	power=0;
	printf("***密码输入错误，请重新选择\n");
	system("pause>nul");
}else power=2;
} 
else if(choicepower==3){ 
printf("***请输入管理员权限密码：\n");
scanf("%d",&password);
fflush(stdin);
if(password!=789){
	power=0;
	printf("***密码输入错误，请重新选择\n");
	system("pause>nul");
}else power=3;
}} 
if(power==1)
printf("***激活会员权限\n");
else if(power==2)
printf("***激活职工权限\n");
else if(power==3)
printf("***激活管理员权限\n");
system("pause>nul");
} 

int CN(char character){//字母转化序号
int num; 
 if(character=='A')num=0; 
 else if(character=='B')num=1; 
 else if(character=='C')num=2; 
 else if(character=='D')num=3; 
 else if(character=='E')num=4; 
 else if(character=='F')num=5;
 return num;
 }

char  NC(int num){//序号转化字母 
char character;
if(num==0) character='A';
else if(num==1) character='B';
else if(num==2) character='C';
else if(num==3) character='D';
else if(num==4) character='E';
else if(num==5) character='F';
return character;
} 
void inithouse(char *house)//初始化社区房屋 
{
int i,j,m,n;
	for(i=0;i<BUILDING;i++){//遍历赋值 
		for(j=0;j<FLOOR;j++){
			for(m=0;m<UNIT;m++){
				for(n=0;n<ROOM;n++){
					*(house+FLOOR*UNIT*ROOM*i+UNIT*ROOM*j+ROOM*m+n)='+';//居民房初始化 
				}
			}
		}
	} 
	system("pause>nul");
} 

void busheadtailinit(BusLinkPtr *sptr){//初始化班车链表头结点为公交总站
BusLinkPtr newPtr=(BusLinkPtr)malloc(sizeof(BusLink));
if(newPtr!=NULL){//判断是否有空间 
	strcpy(newPtr->placename,"BusStation");//将值赋给节点
	newPtr->employeenumber=0;//头尾 
	newPtr->nextPtr;//该节点不指向任何节点 
	BusLinkPtr previousPtr=NULL;
	BusLinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//下一个节点 
	}
	if(previousPtr==NULL){//说明是头结点 
		newPtr->nextPtr=*sptr;
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}
} 
else {
	printf("**内存已满，节点未能创建成功\n"); 
}
} 

void init(char *house){//初始化集合
int i;
inithouse((char *)house); 
for(i=0;i<10;i++){
busheadtailinit(&startbusPtr[i]);
}
}
 
void map(char *house)//打印社区地图 
{	
	system("cls");
		system("color 0C");
	int i1,i2,j,m,n;
	printf("\n*社区基本情况如图所示(\"+\"表示空房,\"@\"表示已住房，\"#\"表示已应用的休闲娱乐室\n");
	printf("\n");
	if(ROOM==2&&UNIT==4)
	printf("      A楼\t\t\t      F楼\n"); //打印楼号 
	else if(ROOM==3&&UNIT==4)
	printf("      A楼\t\t\t      \t\tF楼\n"); //打印楼号 
	else if(ROOM==2&&UNIT==5)
	printf("      A楼\t\t\t      \tF楼\n"); //打印楼号
	else if(ROOM==3&&UNIT==5) 
	printf("      A楼\t\t\t      \t  \tF楼\n"); //打印楼号 
		for(i1=0,i2=BUILDING-1;i1<BUILDING/2;i1++,i2--){//遍历打印不同状态的房间 
		for(j=0;j<FLOOR;j++){		
			for(m=0;m<UNIT;m++){		
			for(n=0;n<ROOM;n++){		
					printf("%c ",*(house+FLOOR*UNIT*ROOM*i1+UNIT*ROOM*j+ROOM*m+n));//打印居民房 
				}} 
				printf("\t\t");//留空 
			for(m=0;m<UNIT;m++){	
			for(n=0;n<ROOM;n++){		
					printf("%c ",*(house+FLOOR*UNIT*ROOM*i2+UNIT*ROOM*j+ROOM*m+n));//打印居民房 
				}}
	printf("\n");
		}
	printf("\n");
	if(i1==0){
	 	if(ROOM==2&&UNIT==4)
	printf("      B楼\t\t\t      E楼\n"); //打印楼号 
	else if(ROOM==3&&UNIT==4)
	printf("      B楼\t\t\t      \t\tE楼\n"); //打印楼号 
	else if(ROOM==2&&UNIT==5)
	printf("      B楼\t\t\t      \tE楼\n"); //打印楼号
	else if(ROOM==3&&UNIT==5) 
	printf("      B楼\t\t\t      \t  \tE楼\n"); //打印楼号 
}
	else if(i1==1) {
		if(ROOM==2&&UNIT==4)
	printf("      C楼\t\t\t      D楼\n"); //打印楼号 
	else if(ROOM==3&&UNIT==4)
	printf("      C楼\t\t\t      \t\tD楼\n"); //打印楼号 
	else if(ROOM==2&&UNIT==5)
	printf("      C楼\t\t\t      \tD楼\n"); //打印楼号
	else if(ROOM==3&&UNIT==5) 
	printf("      C楼\t\t\t      \t  \tD楼\n"); //打印楼号 
	}
	else printf("\n");
	}
		system("pause>nul");
} 

struct planning instructions()//提供社区介绍 
{
	struct planning design;
	unsigned int choice;
	system("cls");
	system("color 0A");
	printf("********************************************************************\n");
	printf("*****请先按要求输入活力长者社区基本情况以供系统更好地服务使用者*****\n");
	printf("********************************************************************\n");
	printf("*（输入的数据将会用于社区地图的构建和基本功能的实现）\n");
	printf("*本社区建设预案为A,B,C,D,E,F六栋居民楼，请自定义单元数，楼层数，每层户数三个参数（合理设计）\n");
	printf("*为保证居民生活质量，请选择如下建设方案：\n");
    printf("*****1.6*4*4*2型\n*****2.6*4*4*3型\n*****3.6*4*5*2型\n*****4.6*4*5*3型\n") ;
    printf("*****5.6*5*4*2型\n*****6.6*5*4*3型\n*****7.6*5*5*2型\n*****8.6*5*5*3型\n") ;
    scanf("%d",&choice);
    fflush(stdin);
    while(choice<1||choice>8){
    	printf("***输入错误，请重新输入\n");
scanf("%d",&choice);
fflush(stdin);
	}
	switch(choice){
		case 1:
			x=4;y=4;z=2;
			break;
		case 2:
			x=4;y=4;z=3;
			break;
		case 3:
			x=4;y=5;z=2;
			break;
		case 4:
			x=4;y=5;z=3;
			break;
		case 5:
			x=5;y=4;z=2;
			break;
		case 6:
			x=5;y=4;z=3;
			break;
		case 7:
			x=5;y=5;z=2;
			break;
		case 8:
			x=5;y=5;z=3;
			break;
	}
	printf("***您选择了%d单元%d层%d户方案\n",x,y,z);
	system("pause");
		system("cls");
		printf("    **********活力长者社区基本情况**********\n");
		printf("*A,B,C,D,E,F六栋为居民楼，每栋楼有%d个单元，%d层楼，每层有%d户人家，共%d个住房\n",x,y,z,6*x*y*z);
		printf("*每个空房可以根据需要改造为娱乐休闲室，供老人进行休闲活动\n");
		printf("本社区已经基本建设完毕，初始投资为1亿元,请合理利用，建设一个幸福指数与收益齐飞的社区"); 
		design.x=x;design.y=y;design.z=z;
		return design;//用结构体返回三个参数 
} 

void management(char *house)//选择管理系统 
{
	int i=0;
	system("cls");
	int choice=10;
	system("color 0B");
	printf("    **********活力长者社区系统**********\n");
	printf("    ***********请选择管理系统***********\n");
	if(power==1)
	printf("    1.会员管理 2.房屋管理 3.入住管理 4.场景设施排队管理 5.班车路线管理 0.查看地图 -1.结束程序\n");
	else 
	printf("    1.会员管理 2.房屋管理 3.入住管理 4.场景设施排队管理 5.班车路线管理 6.用户管理 0.查看地图 -1.结束程序\n");
	while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=0&&choice!=-1) 
	{
		gotoxy(0,3+i);
	printf("***请选择管理系统（输入数字）:\n"); 
	gotoxy(31,3+i);
	scanf("%d",&choice);
	fflush(stdin);//防止溢出 
	i++;
	}
	systemch=choice;//选择 
	if(systemch==1)vipmanage((char *)house); //会员管理 
	else if(systemch==2)housemanage((char *)house); //房屋管理 
	else if(systemch==3)staymanage((char *)house); //入住管理 
	else if(systemch==4)publicmanage((char *)house); //场景设施排队管理 
	else if(systemch==6&&power!=1)usermanage((char *)house); //用户管理 
	else if(systemch==5)routinemanage((char *)house); //班车路线管理 
	else if(systemch==0)map((char *)house);//查看地图 
	else if(systemch==-1)exit(1); //结束 
	management((char *)house);
	system("pause>nul");
}

void vipbuilt(ServiceLinkPtr *sptr,char *house)//新建会员
{
		system("cls");
	system("color 0F");
	int i=0; 
	char ch;
	int cn=10;//将楼号转化为数组中的序号 
	older.vipnumber=20210000+vipn;
	vipn++;
	printf("**请输入新会员的基本信息\n") ;
	printf("**1.姓名（英文）\n");
    scanf("%s",older.vipname) ;
    fflush(stdin);
    printf("**2.身份证号\n");
    scanf("%s", older.vipdocument);
    fflush(stdin);
    printf("**3.电话号码\n");
    scanf("%d",&older.vipphone);
    fflush(stdin);
    LOOP:
    do{
		 printf("**4.选择房屋(格式：A 1 1 1 为A楼1单元1层1室)\n");
	scanf("%c %d %d %d",&older.bulidingcharacter,&older.unitnumber,&older.floornumber,&older.roomnumber);
	fflush(stdin);
}
    while(older.bulidingcharacter<'A'||older.bulidingcharacter>'F'||
	older.unitnumber<1||older.unitnumber>UNIT||
	older.floornumber<1||older.floornumber>FLOOR||
	older.roomnumber<1||older.roomnumber>ROOM);//防止程序出错 
cn=CN(older.bulidingcharacter);
if(*(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(older.unitnumber-1)+ROOM*(older.floornumber-1)+older.roomnumber-1)=='@')
{
	printf("**该房屋已卖出，请重新选择\n");
	goto LOOP;
}
else *(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(older.unitnumber-1)+ROOM*(older.floornumber-1)+older.roomnumber-1)='@';
unsigned int situation=0;
while(situation!=1&&situation!=2&&situation!=3){
printf("**5.选择房屋状态 1.入住 2.出租 3.空置\n");
scanf("%d",&situation); 
fflush(stdin);
}
printf("\n**购买房屋成功，请查看会员信息\n");//打印会员信息 
printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,older.vipnumber,older.vipname,older.vipdocument,older.vipphone,older.bulidingcharacter,older.unitnumber,older.floornumber,older.roomnumber);
if(situation==1)
printf("***入住状态：已入住\n"); 
else if(situation==2)
printf("***入住状态：已出租\n");
else if(situation==3)
printf("***入住状态：空置\n");
printf("***尚未对该会员分配服务人员\n"); 
ServiceLinkPtr newPtr=(ServiceLinkPtr)malloc(sizeof(ServiceLink));
if(newPtr!=NULL){//判断是否有空间 
	newPtr->member=older;//将值赋给节点
	newPtr->usercontact=0;
	newPtr->staysituation=situation; 
	newPtr->enjoyment=0;//无预约状态 
	newPtr->nextPtr;//该节点不指向任何节点 
	ServiceLinkPtr previousPtr=NULL;
	ServiceLinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL&&older.vipnumber>currentPtr->member.vipnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//下一个节点 
	}
	if(previousPtr==NULL){
		newPtr->nextPtr=*sptr;
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}
} 
else {
	printf("**内存已满，会员账号%d未能创建成功",older.vipnumber); 
}
system("pause>nul");
}

void vipinquiry(ServiceLinkPtr sptr,char *house)//查询会员
{ 
	system("cls");
	system("color 0F");	
	int cn;
	if(!empty(sptr)){
	int inquirynumber;
	int result=0; 
	printf("***请输入查询会员的会员账号\n");
	scanf("%d",&inquirynumber);
	fflush(stdin);
	if(inquirynumber==(sptr)->member.vipnumber){//在第一个节点 
		printf("***查询成功\n");
printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,(sptr)->member.vipnumber,(sptr)->member.vipname,(sptr)->member.vipdocument,(sptr)->member.vipphone,
(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
if((sptr)->staysituation==1)
printf("***入住状态：已入住\n"); 
else if((sptr)->staysituation==2)
printf("***入住状态：已出租\n");
else if((sptr)->staysituation==3)
printf("***入住状态：空置\n");
if((sptr)->usercontact==0)
printf("***尚未分配服务人员\n");
else printf("***已分配服务人员 %d\n",(sptr)->usercontact);
		result=1;
	}
	else {
	ServiceLinkPtr previousPtr=(sptr);//未在第一个节点 
	ServiceLinkPtr currentPtr=(sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=inquirynumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//查询中间节点 
	printf("***查询成功\n");
	printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,currentPtr->member.bulidingcharacter,
currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
if(currentPtr->staysituation==1)
printf("***入住状态：已入住\n"); 
else if(currentPtr->staysituation==2)
printf("***入住状态：已出租\n");
else if(currentPtr->staysituation==3)
printf("***入住状态：空置\n");
if(currentPtr->usercontact==0)
printf("***尚未分配服务人员\n");
else printf("***已分配服务人员 %d\n",currentPtr->usercontact);
		result=1; 
	}
	}
	if(result==0) {
		printf("***未找到会员号为 %d 的会员\n",inquirynumber);
	}}
	else {
		printf("***会员列表为空\n");
	}	
	system("pause>nul");
}

void vipchange(ServiceLinkPtr (*sptr),char *house)//修改会员
{
	system("cls");
	system("color 0F");	
		int cn;
		unsigned int choice;
	if(!empty((*sptr))){
	int changenumber;
	int result=0; 
	printf("***请输入修改会员的会员账号\n");
	scanf("%d",&changenumber);
	fflush(stdin);
	if(changenumber==(*sptr)->member.vipnumber){
		printf("***请选择修改的内容\n");
		while (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5){
			printf("***1.姓名 2.身份证号 3.联系电话 4.会员房屋 5.入住状态\n");
			scanf("%d",&choice);
			fflush(stdin);
		}
		if(choice==1){
			printf("***请输入新的会员姓名\n") ;
			scanf("%s",(*sptr)->member.vipname);
			fflush(stdin);
		}
			else if(choice==2){
			printf("***请输入新的会员身份证号\n") ;
			scanf("%s",(*sptr)->member.vipdocument);
			fflush(stdin);
		}
			else if(choice==3){
			printf("***请输入新的会员联系电话\n") ;
			scanf("%d",&(*sptr)->member.vipphone);
			fflush(stdin);
		}
			else if(choice==4){
            VIPHOUSE//执行预处理命令 
    LOOP:
    do{
		 printf("**3.选择房屋(格式：A 1 1 1 为A楼1单元1层1室)\n");
	scanf("%c %d %d %d",&(*sptr)->member.bulidingcharacter,&(*sptr)->member.unitnumber,&(*sptr)->member.floornumber,&(*sptr)->member.roomnumber);
	fflush(stdin);
}
    while((*sptr)->member.bulidingcharacter<'A'||(*sptr)->member.bulidingcharacter>'F'||
	(*sptr)->member.unitnumber<1||(*sptr)->member.unitnumber>UNIT||
	(*sptr)->member.floornumber<1||(*sptr)->member.floornumber>FLOOR||
	(*sptr)->member.roomnumber<1||(*sptr)->member.roomnumber>ROOM);//防止程序出错 
cn=CN((*sptr)->member.bulidingcharacter);
if(*(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*((*sptr)->member.unitnumber-1)+ROOM*((*sptr)->member.floornumber-1)+(*sptr)->member.roomnumber-1)=='@')
{
	printf("**该房屋已卖出，请重新选择\n");
	goto LOOP;
}
else *(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*((*sptr)->member.unitnumber-1)+ROOM*((*sptr)->member.floornumber-1)+(*sptr)->member.roomnumber-1)='@';
		}
			else if(choice==5){
			printf("***请输入新的入住状态 1.入住 2.出租 3.空置\n") ;
			scanf("%d",&(*sptr)->staysituation);
			fflush(stdin);
			}
		printf("***修改成功\n"); 
printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,(*sptr)->member.vipnumber,(*sptr)->member.vipname,(*sptr)->member.vipdocument,(*sptr)->member.vipphone,
(*sptr)->member.bulidingcharacter,(*sptr)->member.unitnumber,(*sptr)->member.floornumber,(*sptr)->member.roomnumber);
if((*sptr)->staysituation==1)//打印入住状态 
printf("***入住状态：已入住\n"); 
else if((*sptr)->staysituation==2)
printf("***入住状态：已出租\n");
else if((*sptr)->staysituation==3)
printf("***入住状态：空置\n");
if((*sptr)->usercontact==0)
printf("***尚未分配服务人员\n");
else printf("***已分配服务人员 %d\n",(*sptr)->usercontact);
		result=1;
	}
	else {//分开头结点和其他情况 
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=changenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//修改中间节点 
		printf("***请选择修改的内容\n");
		while (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5){
			printf("***1.姓名 2.身份证号 3.联系电话 4.会员房屋 5.入住状态\n");
			scanf("%d",&choice);
			fflush(stdin);
		}
		if(choice==1){
			printf("***请输入新的会员姓名\n") ;
			scanf("%s",currentPtr->member.vipname);
			fflush(stdin);
		}
			else if(choice==2){
			printf("***请输入新的会员身份证号\n") ;
			scanf("%s",currentPtr->member.vipdocument);
			fflush(stdin);
		}
			else if(choice==3){
			printf("***请输入新的会员联系电话\n") ;
			scanf("%d",&currentPtr->member.vipphone);
			fflush(stdin);
		}
			else if(choice==4){
cn=CN(currentPtr->member.bulidingcharacter);
*(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(currentPtr->member.unitnumber-1)+ROOM*(currentPtr->member.floornumber-1)+currentPtr->member.roomnumber-1)='+'; 
    LOOP2:
    do{
		 printf("**3.选择房屋(格式：A 1 1 1 为A楼1单元1层1室)\n");
	scanf("%c %d %d %d",&currentPtr->member.bulidingcharacter,&currentPtr->member.unitnumber,&currentPtr->member.floornumber,&currentPtr->member.roomnumber);
	fflush(stdin);
}
    while(currentPtr->member.bulidingcharacter<'A'||currentPtr->member.bulidingcharacter>'F'||
	currentPtr->member.unitnumber<1||currentPtr->member.unitnumber>UNIT||//防止超出数组或错误赋值 
	currentPtr->member.floornumber<1||currentPtr->member.floornumber>FLOOR||
	currentPtr->member.roomnumber<1||currentPtr->member.roomnumber>ROOM);//防止程序出错 
cn=CN(currentPtr->member.bulidingcharacter);
if(*(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(currentPtr->member.unitnumber-1)+ROOM*(currentPtr->member.floornumber-1)+currentPtr->member.roomnumber-1)=='@')
{
	printf("**该房屋已卖出，请重新选择\n");
	goto LOOP2;
}
else *(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(currentPtr->member.unitnumber-1)+ROOM*(currentPtr->member.floornumber-1)+currentPtr->member.roomnumber-1)='@';
		}
			else if(choice==5){
			printf("***请输入新的入住状态 1.入住 2.出租 3.空置\n") ;
			scanf("%d",&currentPtr->staysituation);
			fflush(stdin);
			}
		printf("***修改成功\n"); 
printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,
currentPtr->member.bulidingcharacter,currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
if(currentPtr->staysituation==1)
printf("***入住状态：已入住\n"); 
else if(currentPtr->staysituation==2)
printf("***入住状态：已出租\n");
else if(currentPtr->staysituation==3)
printf("***入住状态：空置\n");
if(currentPtr->usercontact==0)
printf("***尚未分配服务人员\n");
else printf("***已分配服务人员 %d\n",currentPtr->usercontact);
		result=1;
	}
	}
	if(result==0) {
		printf("***未找到会员号为 %d 的会员\n",changenumber);
	}}
	else {
		printf("***会员列表为空\n");
	}
	system("pause>nul");
}

void changevipuserlink(UserLinkPtr *sptr,int useraccount,int vipaccount){//在删除会员的同时删除对应职工链表中服务人员信息 
int i;
	if(useraccount==(*sptr)->information.usernumber){
for(i=0;i<10;i++){//将10个会员账户信息全部初始化 
	if(vipaccount==(*sptr)->information.account[i]){
		(*sptr)->information.account[i]=0;
	}
}
	}
	else {
	UserLinkPtr previousPtr=(*sptr);
	UserLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->information.usernumber!=useraccount){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;}
	if(currentPtr!=NULL){//删除中间节点 
	for(i=0;i<10;i++){
	if(vipaccount==currentPtr->information.account[i]){
		currentPtr->information.account[i]=0;
	}
}
	}}
} 

void vipdelete(ServiceLinkPtr (*sptr),char *house)//删除会员
{
	system("cls");
	system("color 0F");
	int cn;
	if(!empty((*sptr))){
	int deletenumber;
	int result=0; 
	printf("***请输入被删除会员的会员账号\n");
	scanf("%d",&deletenumber);
	fflush(stdin);
	if(deletenumber==(*sptr)->member.vipnumber){
    VIPHOUSE//执行预处理命令 
    printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,(*sptr)->member.vipnumber,(*sptr)->member.vipname,(*sptr)->member.vipdocument,(*sptr)->member.vipphone,
(*sptr)->member.bulidingcharacter,(*sptr)->member.unitnumber,(*sptr)->member.floornumber,(*sptr)->member.roomnumber);
if((*sptr)->staysituation==1)
printf("***入住状态：已入住\n"); 
else if((*sptr)->staysituation==2)
printf("***入住状态：已出租\n");
else if((*sptr)->staysituation==3)
printf("***入住状态：空置\n");
changevipuserlink(&startuserPtr,(*sptr)->usercontact,deletenumber);
		ServiceLinkPtr tempPtr=(*sptr);//将(*sptr)赋给tempPtr用来释放空间 
		(*sptr)=(*sptr)->nextPtr;//将第二个节点赋给第一个节点 
		free(tempPtr);//释放内存空间 
		result=1;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=deletenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//删除中间节点 
	printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,
currentPtr->member.bulidingcharacter,currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
if(currentPtr->staysituation==1)
printf("***入住状态：已入住\n"); 
else if(currentPtr->staysituation==2)
printf("***入住状态：已出租\n");
else if(currentPtr->staysituation==3)
printf("***入住状态：空置\n");
changevipuserlink(&startuserPtr,currentPtr->usercontact,deletenumber);
		ServiceLinkPtr tempPtr=currentPtr;
		previousPtr->nextPtr=currentPtr->nextPtr;
		free(tempPtr);
		result=1; 
	}
	}
	if(result==1){
		printf("*****该会员已被删除\n"); 
	}
	else {
		printf("***未找到会员号为 %d 的会员\n",deletenumber);
	}}
	else {
		printf("***会员列表为空\n");
	}
	system("pause>nul");
}

void printlist(ServiceLinkPtr sptr){//打印会员列表 
		system("cls");
	system("color 0F");
	if(empty((sptr))){
		printf("\n*****会员列表为空\n");
	}
	else {
		printf("\n*****会员列表为：\n\n");
		while ((sptr)!=NULL){//循环打印节点 
			printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,(sptr)->member.vipnumber,(sptr)->member.vipname,(sptr)->member.vipdocument,(sptr)->member.vipphone,
(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
if((sptr)->usercontact==0)
printf("***尚未分配服务人员\n");
else printf("***已分配服务人员 %d\n",(sptr)->usercontact);
printf("\n\n");
(sptr)=(sptr)->nextPtr;
		}
	}
system("pause>nul");	
}

int empty(ServiceLinkPtr sptr){//判断会员列表是否为空 
	return sptr==NULL;
} 

void vipmanage(char * house)//会员管理 
{
	int choicevip=10;
	system("cls");
	system("color 0E");
	printf("    **********活力长者社区会员管理系统**********\n");
	printf("    ***************请选择会员服务***************\n");
	if(power==1){
		printf("    1.查询会员 2.新建会员 0.查看地图 -1.返回上一界面\n");
	while(choicevip!=1&&choicevip!=0&&choicevip!=-1&&choicevip!=2){
		printf("***请选择服务序号："); 
	scanf("%d",&choicevip);
	fflush(stdin);
}
if(choicevip==1) vipinquiry(startPtr,(char *)house);//查询
else if(choicevip==2) vipbuilt(&startPtr,(char *)house);//新建 
else if(choicevip==0) map((char *)house);//查看地图
else if(choicevip==-1) return ;//返回 
	} 
	else if(power==2){
	printf("    1.新建会员 2.查询会员 3.修改会员 4.删除会员 0.查看地图 -1.返回上一界面\n");
	while(choicevip!=1&&choicevip!=2&&choicevip!=3&&choicevip!=4&&choicevip!=0&&choicevip!=-1){
		printf("***请选择服务序号："); 
	scanf("%d",&choicevip);
	fflush(stdin);
}
if(choicevip==1) vipbuilt(&startPtr,(char *)house);//新建 
else if(choicevip==2) vipinquiry(startPtr,(char *)house);//查询 
else if(choicevip==3) vipchange(&startPtr,(char *)house);//修改 
else if(choicevip==4) vipdelete(&startPtr,(char *)house);//删除  
}
	else {
	printf("    1.新建会员 2.查询会员 3.修改会员 4.删除会员 5.现有会员展示 0.查看地图 -1.返回上一界面\n");
	while(choicevip!=1&&choicevip!=2&&choicevip!=3&&choicevip!=4&&choicevip!=0&&choicevip!=-1&&choicevip!=5){
		printf("***请选择服务序号："); 
	scanf("%d",&choicevip);
	fflush(stdin);
}
if(choicevip==1) vipbuilt(&startPtr,(char *)house);//新建 
else if(choicevip==2) vipinquiry(startPtr,(char *)house);//查询 
else if(choicevip==3) vipchange(&startPtr,(char *)house);//修改 
else if(choicevip==4) vipdelete(&startPtr,(char *)house);//删除 
else if(choicevip==5) printlist(startPtr);//打印会员列表 
}
if(choicevip==-1) return ;//返回 
else if(choicevip==0) map((char *)house);//查看地图
vipmanage((char *)house); 
} 
//序号，字母转化 
 
void housebuy(ServiceLinkPtr (sptr),char *house){//查询房屋购买状况
	system("cls");
	system("color 0F");
HOUSECN
 if( *(house+FLOOR*UNIT*ROOM*num+UNIT*ROOM*(unumber-1)+ROOM*(fnumber-1)+rnumber-1)!='@')
 printf("*****该房屋尚未出售\n");
 else{
 		printf("***查询成功\n");
 	if(character==(sptr)->member.bulidingcharacter&&unumber==(sptr)->member.unitnumber&&
	 fnumber==(sptr)->member.floornumber&&rnumber==(sptr)->member.roomnumber){
	 	printf("***该房屋已售出\n***户主联系电话：%d\n(户主姓名，账号，身份证号保密)\n",(sptr)->member.vipphone);
	 }
	 else{
	 		ServiceLinkPtr previousPtr=(sptr);
	ServiceLinkPtr currentPtr=(sptr)->nextPtr;
	while(currentPtr!=NULL&&character==currentPtr->member.bulidingcharacter&&unumber==currentPtr->member.unitnumber&&
	 fnumber==currentPtr->member.floornumber&&rnumber==currentPtr->member.roomnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	printf("***查询成功\n");
	printf("***该房屋已售出\n***户主联系电话：%d\n(户主姓名，账号，身份证号保密)\n",currentPtr->member.vipphone);
	 }
 } 
system("pause>nul");
}

void housestay(ServiceLinkPtr (sptr),char *house){//查询房屋入住状况 	
system("cls");
system("color 0F");
HOUSECN
 if( *(house+FLOOR*UNIT*ROOM*num+UNIT*ROOM*(unumber-1)+ROOM*(fnumber-1)+rnumber-1)!='@')
 printf("*****该房屋尚未出售\n");
  else{
 		printf("***查询成功\n");
 			if(character==(sptr)->member.bulidingcharacter&&unumber==(sptr)->member.unitnumber&&
	 fnumber==(sptr)->member.floornumber&&rnumber==(sptr)->member.roomnumber){
	 	printf("***该房屋已售出\n***户主姓名；%s\n***户主联系电话：%d\n(户主账号，身份证号保密)\n",(sptr)->member.vipname,(sptr)->member.vipphone);
	 	if((sptr)->staysituation==1)
printf("***入住状态：已入住\n"); 
else if((sptr)->staysituation==2)
printf("***入住状态：已出租\n");
else if((sptr)->staysituation==3)
printf("***入住状态：空置\n");
if((sptr)->usercontact==0)
printf("***尚未分配服务人员\n");
else printf("***已分配服务人员 %d\n",(sptr)->usercontact);
	 }
	 else{
	 		ServiceLinkPtr previousPtr=(sptr);
	ServiceLinkPtr currentPtr=(sptr)->nextPtr;
	while(currentPtr!=NULL&&character==currentPtr->member.bulidingcharacter&&unumber==currentPtr->member.unitnumber&&
	 fnumber==currentPtr->member.floornumber&&rnumber==currentPtr->member.roomnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	printf("***查询成功\n");
	printf("***该房屋已售出\n***户主姓名；%s\n***户主联系电话：%d\n(户主账号，身份证号保密)\n",currentPtr->member.vipname,currentPtr->member.vipphone);
if(currentPtr->staysituation==1)
printf("***入住状态：已入住\n"); 
else if(currentPtr->staysituation==2)
printf("***入住状态：已出租\n");
else if(currentPtr->staysituation==3)
printf("***入住状态：空置\n");
if(currentPtr->usercontact==0)
printf("***尚未分配服务人员\n");
else printf("***已分配服务人员 %d\n",currentPtr->usercontact);
 } } 
system("pause>nul");
} 

void houseowner(ServiceLinkPtr (sptr),char *house){//查看房屋所有者信息 
	system("cls");
	system("color 0F");
HOUSECN
 if( *(house+FLOOR*UNIT*ROOM*num+UNIT*ROOM*(unumber-1)+ROOM*(fnumber-1)+rnumber-1)!='@')
 printf("*****该房屋尚未出售\n");
  else{
 		printf("***查询成功\n");
 			if(character==(sptr)->member.bulidingcharacter&&unumber==(sptr)->member.unitnumber&&
	 fnumber==(sptr)->member.floornumber&&rnumber==(sptr)->member.roomnumber){
	 	printf("***该房屋已售出\n***户主账号：%d\n***户主姓名：%s\n***户主身份证号：%s\n***户主电话：%d\n"
,(sptr)->member.vipnumber,(sptr)->member.vipname,(sptr)->member.vipdocument,(sptr)->member.vipphone);
if((sptr)->staysituation==1)
printf("***入住状态：已入住\n"); 
else if((sptr)->staysituation==2)
printf("***入住状态：已出租\n");
else if((sptr)->staysituation==3)
printf("***入住状态：空置\n");
if((sptr)->usercontact==0)
printf("***尚未分配服务人员\n");
else printf("***已分配服务人员 %d\n",(sptr)->usercontact);
	 }
	 else{
	 ServiceLinkPtr previousPtr=(sptr);
	ServiceLinkPtr currentPtr=(sptr)->nextPtr;
	while(currentPtr!=NULL&&character==currentPtr->member.bulidingcharacter&&unumber==currentPtr->member.unitnumber&&
	 fnumber==currentPtr->member.floornumber&&rnumber==currentPtr->member.roomnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	printf("***查询成功\n");
	printf("***该房屋已售出\n***户主账号：%d\n***户主姓名：%s\n***户主身份证号：%s\n***户主电话：%d\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone);
if(currentPtr->staysituation==1)
printf("***入住状态：已入住\n"); 
else if(currentPtr->staysituation==2)
printf("***入住状态：已出租\n");
else if(currentPtr->staysituation==3)
printf("***入住状态：空置\n");	
if(currentPtr->usercontact==0)
printf("***尚未分配服务人员\n");
else printf("***已分配服务人员 %d\n",currentPtr->usercontact);
	 }
 } 
system("pause>nul");
}

void housemanage(char *house)//房屋管理 
{
	int choicehouse=10;
	system("cls");
	system("color 0E");
	printf("    **********活力长者社区房屋管理系统**********\n");
	printf("    ***************请选择房屋服务***************\n");
	if(power==1){
		printf("    1.查询房屋购买状况 0.查看地图 -1.返回上一界面\n");
	while(choicehouse!=1&&choicehouse!=0&&choicehouse!=-1&&choicehouse!=0){
		printf("***请选择服务序号："); 
	scanf("%d",&choicehouse);
	fflush(stdin);
}
if(choicehouse==1) housebuy(startPtr,(char *)house);//查询房屋购买状况
 else if(choicehouse==-1) return ;//返回 
 else if(choicehouse==0) map((char *)house);//查看地图 
	}
	else if(power==2){
		printf("    1.查询房屋购买状况 2.查询房屋入住状况 0.查看地图 -1.返回上一界面\n");
	while(choicehouse!=1&&choicehouse!=2&&choicehouse!=0&&choicehouse!=-1&&choicehouse!=0){
		printf("***请选择服务序号："); 
	scanf("%d",&choicehouse);
	fflush(stdin);
}
if(choicehouse==1) housebuy(startPtr,(char *)house);//查询房屋购买状况
else if(choicehouse==2) housestay(startPtr,(char *)house);//查询房屋入住状况
	}
	else{
	printf("    1.查询房屋购买状况 2.查询房屋入住状况 3.查看房屋所有者信息 0.查看地图 -1.返回上一界面\n");
	while(choicehouse!=1&&choicehouse!=2&&choicehouse!=3&&choicehouse!=0&&choicehouse!=-1&&choicehouse!=0){
		printf("***请选择服务序号："); 
	scanf("%d",&choicehouse);
	fflush(stdin);
}
if(choicehouse==1) housebuy(startPtr,(char *)house);//查询房屋购买状况
else if(choicehouse==2) housestay(startPtr,(char *)house);//查询房屋入住状况
else if(choicehouse==3) houseowner(startPtr,(char *)house);//查看房屋所有者信息 
}
if(choicehouse==-1) return ;//返回 
else if(choicehouse==0) map((char *)house);//查看地图
housemanage((char *)house); 
}
 
 void hire(ServiceLinkPtr sptr,char *house){//查询出租的房屋列表
 int serial=1; 
 	system("cls");
	system("color 0F");
		if(empty(sptr))
		printf("\n*****出租房屋列表为空\n");
	else {
		gotoxy(0,2); 
		while ((sptr)!=NULL){//循环打印出租房屋节点 
		if((sptr)->staysituation==2){
printf("***%d.%c座%d单元%d层%d室\n",serial,(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
        serial++;
			}
(sptr)=(sptr)->nextPtr;
		}
		if(serial==1){
		printf("\n*****出租房屋列表为空\n");}
	else {
			gotoxy(0,1);
			printf("*****出租房屋列表：\n");
	}
	}
	system("pause>nul");
 }
 
 void vacant(ServiceLinkPtr (sptr),char *house){//查询空置的房屋列表
 int serial=1; 
 	system("cls");
	system("color 0F");
		if(empty(sptr))
		printf("\n*****空置房屋列表为空\n");
	else {
		gotoxy(0,2) ;
		while ((sptr)!=NULL){//循环打印空置房屋节点 
		if((sptr)->staysituation==3){
printf("***%d.%c座%d单元%d层%d室\n",serial,(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
        serial++;
			}
(sptr)=(sptr)->nextPtr;
		}
		if(serial==1){
		printf("\n*****空置房屋列表为空\n");}
		else {
			gotoxy(0,1);
			printf("*****空置房屋列表：\n");
		}
	}
	system("pause>nul");
 }
 
void onsale(ServiceLinkPtr (sptr),char *house){//未售的房屋列表
	system("cls");
	system("color 0F");
printf("*****未售房屋列表：\n");
 	int i,j,m,n;
 	char c;
 	int serial=1;//序号 
 	for(i=0;i<BUILDING-1;i++){
 		for(j=0;j<UNIT;j++){
 			for(m=0;m<FLOOR;m++){
 				for(n=0;n<ROOM;n++){
 					if(*(house+FLOOR*UNIT*ROOM*i+UNIT*ROOM*j+ROOM*m+n)=='+'){
 					c=NC(i);
 					printf("%d.%c座%d单元%d层%d室\n",serial,c,j+1,m+1,n+1);
					 serial++;
					 }
				 }
			 }
		 }
	 }
	 system("pause>nul");
 }
 
void staymanage(char *house)//入住管理 
{
int choicestay=10;
	system("cls");
	system("color 0E");
	printf("    **********活力长者社区入住管理系统**********\n");
	printf("    ***************请选择入住服务***************\n");
	printf("    1.查询出租的房屋列表 2.查询空置的房屋列表 3.查看未售的房屋列表 0.查看地图 -1.返回上一界面\n");
	while(choicestay!=1&&choicestay!=2&&choicestay!=3&&choicestay!=0&&choicestay!=-1&&choicestay!=0){
		printf("***请选择服务序号："); 
	scanf("%d",&choicestay);
	fflush(stdin);
}
if(choicestay==1) hire(startPtr,(char *)house);//查询出租的房屋列表
else if(choicestay==2) vacant(startPtr,(char *)house);//查询空置的房屋列表
else if(choicestay==3) onsale(startPtr,(char *)house);//查看未售的房屋列表
 else if(choicestay==-1) return ;//返回 
 else if(choicestay==0) map((char *)house);//查看地图 
staymanage((char *)house); 
}

void new_built(){//新建
int i;
unsigned int newbuilt; 
system("cls");
system("color 0F");
printf("*****居民提案如下：\n");//用Switch语句实现选择，在多项选择中较好 
if(pingpong>0)printf("***乒乓球馆提案：%d\n",pingpong);
if(badminton>0)printf("***羽毛馆提案：%d\n",badminton);
if(yoga>0)printf("***瑜伽馆提案：%d\n",yoga);
if(chess>0)printf("***棋牌室提案：%d\n",chess);
if(tableball>0)printf("***台球室提案：%d\n",tableball);
if(tea>0)printf("***茶水室提案：%d\n",tea);
if(newspaper>0)printf("***报纸阅览室提案：%d\n",newspaper);
if(book>0)printf("***图书馆提案：%d\n",book);
if(opera>0)printf("***京剧社提案：%d\n",opera);
if(shuttlecock>0)printf("***毽子社提案：%d\n",shuttlecock);
if(dance>0)printf("***广场舞社提案：%d\n",dance);
if(handwriting>0)printf("***书法社提案：%d\n",handwriting);
if(weave>0)printf("***编织室提案：%d\n",weave);
if(chat>0)printf("***聊天室提案：%d\n",chat);
system("pause>nul");
printf("*****请根据居民提案选择新建娱乐设施的种类\n");
printf("***请选择以下建设方案：\n*1.乒乓球馆\t2.羽毛球馆\n*3.瑜伽馆\t4.棋牌室\n*5.台球馆\t6.茶水室\n7.报纸阅览室\t8.图书馆\n"); 
printf("*9.京剧社\t10.毽子社\n*11.广场舞社\t12.书法室\n*13.编织室\t14.聊天室\n"); 

scanf("%d",&newbuilt);
fflush(stdin);
switch (newbuilt){//用Switch语句实现选择，在多项选择中较好 
	case 1:{ENJOY enjoy[newbuilt-1]=1;printf("***新建乒乓球馆成功\n");break;}case 2:{ENJOY enjoy[newbuilt-1]=1;printf("***新建羽毛球馆成功\n");break;}
	case 3:{ENJOY enjoy[newbuilt-1]=1;printf("***新建瑜伽馆成功\n");break;}case 4:{ENJOY enjoy[newbuilt-1]=1;printf("***新建棋牌室成功\n");break;}
	case 5:{ENJOY enjoy[newbuilt-1]=1;printf("***新建台球馆成功\n");break;}case 6:{ENJOY enjoy[newbuilt-1]=1;printf("***新建茶水室成功\n");break;}
	case 7:{ENJOY enjoy[newbuilt-1]=1;printf("***新建报纸阅览室成功\n");break;}case 8:{ENJOY enjoy[newbuilt-1]=1;printf("***新建图书馆成功\n");break;}
	case 9:{ENJOY enjoy[newbuilt-1]=1;printf("***新建京剧社成功\n");break;}case 10:{ENJOY enjoy[newbuilt-1]=1;printf("***新建毽子社成功\n");break;}
	case 11:{ENJOY enjoy[newbuilt-1]=1;printf("***新建广场舞社成功\n");break;}case 12:{ENJOY enjoy[newbuilt-1]=1;printf("***新建书法室成功\n");break;}
	case 13:{ENJOY enjoy[newbuilt-1]=1;printf("***新建编织室成功\n");break;}case 14:{ENJOY enjoy[newbuilt-1]=1;printf("***新建聊天室成功\n");break;}
	default :{
	printf("***您选择尚不新建娱乐设施\n");
	system("pause>nul");
	return ;}	
}
system("pause>nul");
}

void scheme(){//上交提案 
unsigned int choice;
system("cls");
system("color 0F");
printf("***请选择以下预案（您的建议将会反馈给工作人员）：\n*1.乒乓球馆\t2.羽毛球馆\n*3.瑜伽馆\t4.棋牌室\n*5.台球馆\t6.茶水室\n7.报纸阅览室\t8.图书馆\n"); 
printf("*9.京剧社\t10.毽子社\n*11.广场舞社\t12.书法室\n*13.编织室\t14.聊天室\n"); 
scanf("%d",&choice);
fflush(stdin);
switch (choice){
	case 1:pingpong++;break;case 2:badminton++;break;
	case 3:yoga++;break;case 4:chess++;break;
	case 5:tableball++;break;case 6:tea++;break;
	case 7:newspaper++;break;case 8:book++;break;
	case 9:opera++;break;case 10:shuttlecock++;break;
	case 11:dance++;break;case 12:handwriting++;break;
	case 13:weave++;break;case 14:chat++;break;
	default :{
	printf("***提案不在预案内，提案无效\n");
	system("pause>nul");
	return ;}
}printf("***提交成功，请等待工作人员审批\n");
system("pause>nul");
}
 
int isempty(LinkPtr headPtr){//检查队列是否为空
return headPtr==NULL;
}
 
int delink(LinkPtr *sptr,int deletenumber){//删除预约人员 
int result=0;
	if(deletenumber==(*sptr)->account){
		LinkPtr tempPtr=(*sptr);//将(*sptr)赋给tempPtr用来释放空间 
		(*sptr)=(*sptr)->nextPtr;//将第二个节点赋给第一个节点 
		free(tempPtr);//释放内存空间 
		result=1;
	}
	else {
	LinkPtr previousPtr=(*sptr);
	LinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->account!=deletenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//删除中间节点 
		LinkPtr tempPtr=currentPtr;
		previousPtr->nextPtr=currentPtr->nextPtr;
		free(tempPtr);
		result=1; 
	}
	}
	return result;
}
 
void enlink(LinkPtr *sptr,int num){//增加排队链表元素 
	LinkPtr newPtr=(LinkPtr)malloc(sizeof(Link));
if(newPtr!=NULL){//判断是否有空间 
	newPtr->account=num;
	newPtr->nextPtr;//该节点不指向任何节点 
	LinkPtr previousPtr=NULL;
	LinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//下一个节点 
	}
	if(previousPtr==NULL){
		newPtr->nextPtr=*sptr;
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}
} 
else {
	printf("**内存已满，节点未能创建成功\n"); 
}
}

void printlinelink(LinkPtr sptr){//打印排队链表 
	if(sptr==NULL){
	printf("***队列为空\n");
}
else {
	printf("***队列为：\n***");
	while (sptr!=NULL){
		printf("%d-->",sptr->account);
		sptr=sptr->nextPtr;
	}
}
}
 
void application(ServiceLinkPtr *sptr){//申请娱乐设施服务
int t;//储存 enjoyment的值 
int result=0;
int applicationnumber;
	system("cls");
	system("color 0F");	
		int application;//用Switch语句实现选择，在多项选择中较好 
		printf("***每项设施可预约十人，请选择想要预约的服务\n");
printf("*1.乒乓球馆\t2.羽毛球馆\n*3.瑜伽馆\t4.棋牌室\n*5.台球馆\t6.茶水室\n7.报纸阅览室\t8.图书馆\n"); 
printf("*9.京剧社\t10.毽子社\n*11.广场舞社\t12.书法室\n*13.编织室\t14.聊天室\n"); 
scanf("%d",&application);
fflush(stdin);
if(application<1||application>14){
	printf("**未找到对应的娱乐设施，操作无效化处理\n");
	system("pause>nul");
	return ;}
	if(enjoy[application-1]==0){
		printf("**该设施尚未建成，您可以返回上一界面提出提案\n");
		system("pause>nul");
		return ;}
		if(enjoynum[application-1]>=10) {
			printf("**该设施预约人数已满，请排队等待他人服务结束\n");
			system("pause>nul");
			return ;
		}
	int cn;
	if(!empty(*sptr)){
//一个人只能预约一个服务 ，所以需要检验该账号是否已经预约，即检查enjoyment的值 
    result=0; 
	printf("***请输入会员账号\n");
	scanf("%d",&applicationnumber);
	fflush(stdin);
	if(applicationnumber==(*sptr)->member.vipnumber){
		result=1;
		t=(*sptr)->enjoyment;
		(*sptr)->enjoyment=application;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=applicationnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//查询中间节点 
		result=1; 
			t=currentPtr->enjoyment;
			currentPtr->enjoyment=application;
	}
	}
	if(result==0) {
		printf("***未找到会员号为 %d 的会员\n",applicationnumber);
		system("pause>nul");
		return ;
	}}
	else {
		printf("***会员列表为空\n");
		system("pause>nul");
		return ;
	}
	if(t!=0){
		printf("***您已预约，须结束服务后方能再次预约%d\n",t);//
			system("pause>nul");
		return ;
	}
		printf("**预约成功，结束后请进行结束服务操作让队列变化\n");
		enjoynum[application-1]++; 
			enlink(&headPtr[application-1],applicationnumber);
			printlinelink(headPtr[application-1]);
	system("pause>nul");
} 
 
void end(ServiceLinkPtr *sptr){//结束娱乐服务 
int result,search=0; 
int t;//储存enjoyment的值 
int applicationnumber;
system("cls");
system("color 0F");
	int cn;
	if(!empty(*sptr)){
    result=0; 
	printf("***请输入会员账号\n");
	scanf("%d",&applicationnumber);
	fflush(stdin);
	if(applicationnumber==(*sptr)->member.vipnumber){
		result=1;
		t=(*sptr)->enjoyment;
		(*sptr)->enjoyment=0;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=applicationnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//查询中间节点 
		result=1; 
		t=currentPtr->enjoyment;
		currentPtr->enjoyment=0;
	}
	}
	if(result==0) {
		printf("***未找到会员号为 %d 的会员\n",applicationnumber);
		system("pause>nul");
		return ;
	}}
	else {
		printf("***会员列表为空\n");
		system("pause>nul");
		return ;
	}
		search=delink(&headPtr[t-1],applicationnumber);
		if(search==1)
		printf("***%d 已结束服务\n",applicationnumber);
		else printf("***%d 不在队列里，操作无效\n");
		//结束服务的同时将会员娱乐设施使用状态重新初始化 
system("pause>nul");
}
 
void publicmanage(char *house)//公共设施管理
{
 int choicepublic=10;
	system("cls");
	system("color 0E");
	printf("    **********活力长者社区娱乐设施管理系统**********\n");
	printf("    ***************请选择设施管理服务***************\n");
	if(power==1){
	printf("    1.登录账号预约娱乐设施服务 2.上交娱乐设施建设提案 3.结束服务 0.查看地图 -1.返回上一界面\n");
	while(choicepublic!=1&&choicepublic!=2&&choicepublic!=0&&choicepublic!=-1&&choicepublic!=3){
		printf("***请选择服务序号："); 
	scanf("%d",&choicepublic);
	fflush(stdin);
}
if(choicepublic==1) application(&startPtr);//申请娱乐设施服务 
else if(choicepublic==2) scheme();//上交 
else if(choicepublic==3) end(&startPtr);//结束娱乐服务 
 else if(choicepublic==-1) return ;//返回 
 else if(choicepublic==0) map((char *)house);//查看地图 
	}
	else if(power==2){
		printf("     1.上交娱乐设施建设提案 0.查看地图 -1.返回上一界面\n");
	while(choicepublic!=1&&choicepublic!=0&&choicepublic!=-1){
		printf("***请选择服务序号："); 
	scanf("%d",&choicepublic);
	fflush(stdin);
}
 if(choicepublic==1) scheme();//上交 
	}
	else {
	printf("    1.登录账号预约娱乐设施服务 2.新建娱乐设施 3.上交娱乐设施建设提案 4.结束服务 0.查看地图 -1.返回上一界面\n");
	while(choicepublic!=1&&choicepublic!=2&&choicepublic!=3&&choicepublic!=0&&choicepublic!=-1&&choicepublic!=4){
		printf("***请选择服务序号："); 
	scanf("%d",&choicepublic);
	fflush(stdin);
}
if(choicepublic==1) application(&startPtr);//申请娱乐设施服务 
else if(choicepublic==2) new_built();//新建
else if(choicepublic==3) scheme();//上交 
else if(choicepublic==4) end(&startPtr);//结束娱乐服务 
}
if(choicepublic==-1) return ;//返回 
else if(choicepublic==0) map((char *)house);//查看地图
publicmanage((char *)house); 
}
 
void creatuser(UserLinkPtr *sptr){//新建服务人员服务 
	system("cls");
	system("color 0F");
	int i=0; 
	char ch;
	int cn=10;//将楼号转化为数组中的序号 
	worker.usernumber=2021000+usern;
	usern++;
	printf("**请输入新职工的基本信息\n") ;
	printf("**1.姓名（英文）\n");
    scanf("%s", worker.username);
    	fflush(stdin);
    printf("**3.电话号码\n");
    scanf("%d",&worker.userphone);
    fflush(stdin);
printf("\n**新建职工成功，请查看职工信息\n");//打印会员信息 
printf("***职工号：%d\n***职工姓名：%s\n***职工电话：%d\n"
,worker.usernumber,worker.username,worker.userphone);
UserLinkPtr newPtr=(UserLinkPtr)malloc(sizeof(UserLink));
if(newPtr!=NULL){//判断是否有空间 
	newPtr->information=worker;//将值赋给节点
	newPtr->nextPtr;//该节点不指向任何节点 
	UserLinkPtr previousPtr=NULL;
	UserLinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL&&worker.usernumber>currentPtr->information.usernumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//下一个节点 
	}
	if(previousPtr==NULL){
		newPtr->nextPtr=*sptr;//说明为头结点 
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}
} 
else {
	printf("**内存已满，会员账号%d未能创建成功",worker.usernumber); 
}
system("pause>nul");
}

void chooseuser(ServiceLinkPtr *sptr,UserLinkPtr *usersptr){//选择服务对象 
int i,result1=0,result2=0;
int workeraccount;
	system("cls");
	system("color 0F");
	if(!userempty(*usersptr)){
	printf("*****请输入职工账号\n");
	scanf("%d",&workeraccount);
	fflush(stdin);
	if(workeraccount==(*usersptr)->information.usernumber){//本函数在修改链表功能的基础上实现用户链表和会员链表的双向修改 
		result1=1;
		unsigned int choice;
	if(!empty((*sptr))){
	int changenumber;
	int result2=0; 
	printf("***请输入选择的服务对象账号\n");
	scanf("%d",&changenumber);
	fflush(stdin);
	if(changenumber==(*sptr)->member.vipnumber){
				if((*sptr)->usercontact!=0){
			printf("***该会员已有服务人员，操作无效\n");
				system("pause>nul");
			return ;
		}
		for(i=0;i<10;i++){
	if((*usersptr)->information.account[i]==0){
	(*usersptr)->information.account[i]=changenumber;
	break;}
	if(i==9){
	printf("***服务对象超过十人，操作无效\n");
	system("pause>nul");
	return ;}
}
	printf("***选择成功，已为您匹配如下会员：\n") ;
printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,(*sptr)->member.vipnumber,(*sptr)->member.vipname,(*sptr)->member.vipdocument,(*sptr)->member.vipphone,
(*sptr)->member.bulidingcharacter,(*sptr)->member.unitnumber,(*sptr)->member.floornumber,(*sptr)->member.roomnumber);
(*sptr)->usercontact=workeraccount; 
		result2=1;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);//不在头结点 
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=changenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//修改中间节点 
			if(currentPtr->usercontact!=0){
			printf("***该会员已有服务人员，操作无效\n");
				system("pause>nul");
			return ;
		}
		for(i=0;i<10;i++){
	if((*usersptr)->information.account[i]==0){
	(*usersptr)->information.account[i]=changenumber;
	break;}
	if(i==9){
	printf("***服务对象超过十人，操作无效\n");
	system("pause>nul");
	return ;}
} 
	printf("***选择成功，已为您匹配如下会员：\n") ;
printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,
currentPtr->member.bulidingcharacter,currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
		result2=1;	
	}
	}
	if(result2==0) {
		printf("***未找到会员号为 %d 的会员\n",changenumber);
	}}
	else {
		printf("***会员列表为空\n");
	}	
	}
	else {
	UserLinkPtr previoususerPtr=(*usersptr);
	UserLinkPtr currentuserPtr=(*usersptr)->nextPtr;
	while(currentuserPtr!=NULL&&currentuserPtr->information.usernumber!=workeraccount){
		previoususerPtr=currentuserPtr;
		currentuserPtr=currentuserPtr->nextPtr;
	}
	if(currentuserPtr!=NULL){//修改中间节点 
		result1=1;
		unsigned int choice;
	if(!empty((*sptr))){
	int changenumber;
	int result2=0; 
	printf("***请输入选择的服务对象账号\n");
	scanf("%d",&changenumber);
	fflush(stdin);
	if(changenumber==(*sptr)->member.vipnumber){
		if((*sptr)->usercontact!=0){//判断该会员是否和该用户有关系 
			printf("***该会员已有服务人员，操作无效\n");
				system("pause>nul");
			return ;
		}
		for(i=0;i<10;i++){
	if(currentuserPtr->information.account[i]==0){
	currentuserPtr->information.account[i]=changenumber;
	break;}
	if(i==9){
	printf("***服务对象超过十人，操作无效\n");
	system("pause>nul");
	return ;}
}
	printf("***选择成功，已为您匹配如下会员：\n") ;
printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"
,(*sptr)->member.vipnumber,(*sptr)->member.vipname,(*sptr)->member.vipdocument,(*sptr)->member.vipphone,
(*sptr)->member.bulidingcharacter,(*sptr)->member.unitnumber,(*sptr)->member.floornumber,(*sptr)->member.roomnumber);
(*sptr)->usercontact=workeraccount; 
		result2=1;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=changenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//修改中间节点 
			if(currentPtr->usercontact!=0){//判断该会员是否和该用户有关系 
			printf("***该会员已有服务人员，操作无效\n");
				system("pause>nul");
			return ;
		}
		for(i=0;i<10;i++){
	if(currentuserPtr->information.account[i]==0){
	currentuserPtr->information.account[i]=changenumber;
	break;}
	if(i==9){
	printf("***服务对象超过十人，操作无效\n");
	system("pause>nul");
	return ;}
} 
	printf("***选择成功，已为您匹配如下会员：\n") ;
printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"//打印会员信息 
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,
currentPtr->member.bulidingcharacter,currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
		result2=1;	
	}
	}
	if(result2==0) {
		printf("***未找到会员号为 %d 的会员\n",changenumber);
	}}
	else {
		printf("***会员列表为空\n");
	}
	}
	}
	if(result1==0) {
		printf("***未找到职工号为 %d 的会职工\n",workeraccount);
	}}
	else {
		printf("***职工列表为空\n");
	}
	system("pause>nul");
}

void visituser(ServiceLinkPtr sptr){//查看服务对象,即会员列表 
 	system("cls");
	system("color 0F");
	if(empty((sptr))){
		printf("\n*****服务对象列表为空\n");
	}
	else {
		printf("\n*****服务对象列表为：\n\n");
		while ((sptr)!=NULL){//循环打印节点 
			printf("***会员号：%d\n***会员姓名：%s\n***会员身份证号：%s\n***会员电话：%d\n***会员房屋：%c楼%d单元%d层%d室\n"//打印会员信息 
,(sptr)->member.vipnumber,(sptr)->member.vipname,(sptr)->member.vipdocument,(sptr)->member.vipphone,
(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
if(sptr->usercontact!=0)printf("***已分配服务人员 %d\n",sptr->usercontact);
else printf("***未分配服务人员\n");//判断会员的服务人员有无情况 
printf("\n\n");
(sptr)=(sptr)->nextPtr;
		}
	}
system("pause>nul");
}
 
 int userempty(UserLinkPtr sptr) {//检查是否为空 
 	return sptr==NULL;
 }
 
void printuser(UserLinkPtr sptr) {//查看服务人员列表 
int i;int m=1;
 	system("cls");
	system("color 0F");
	if(userempty((sptr))){
		printf("\n*****职工列表为空\n");
	}
	else {
		printf("\n*****职工列表为：\n\n");
		while ((sptr)!=NULL){//循环打印节点 
			printf("***职工号：%d\n***职工姓名：%s\n***职工电话：%d\n***服务对象有：\n"
,(sptr)->information.usernumber,(sptr)->information.username,(sptr)->information.userphone);
printf("***服务对象如下：（空即无服务对象）\n"); 
for(i=0;i<10;i++){
	if((sptr)->information.account[i]!=0){
		printf("%d.%d\n",m,(sptr)->information.account[i]);
		m++;
	}
}
printf("\n\n");
(sptr)=(sptr)->nextPtr;//指向下一节点 
		}
	}
system("pause>nul");
}
	
void changecontact(ServiceLinkPtr *sptr,int account){//修改用户和成员联系参数 
	if(account==(*sptr)->member.vipnumber){
(*sptr)->usercontact=0; }
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=account){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;}
	if(currentPtr!=NULL){//修改中间节点 
	currentPtr->usercontact=0; 
	}}	
}
	
void deleteuser(UserLinkPtr *sptr){//删除服务人员 
	system("cls");
	system("color 0F");
	int i,m=1,n=1; 
	if(!userempty((*sptr))){
	int deletenumber;
	int result=0; 
	printf("***请输入被删除职工账号\n");
	scanf("%d",&deletenumber);
	fflush(stdin);
	if(deletenumber==(*sptr)->information.usernumber){
    printf("***职工号：%d\n***职工姓名：%s\n***会员电话：%d\n"
,(*sptr)->information.usernumber,(*sptr)->information.username,(*sptr)->information.userphone);
printf("***服务对象如下：（空即无服务对象）\n");
for(i=0;i<10;i++){
	if((*sptr)->information.account[i]!=0){
		printf("%d.%d\n",m,(*sptr)->information.account[i]);
		m++;
			changecontact(&startPtr,(*sptr)->information.account[i]);
	}
}
		UserLinkPtr tempPtr=(*sptr);//将(*sptr)赋给tempPtr用来释放空间 
		(*sptr)=(*sptr)->nextPtr;//将第二个节点赋给第一个节点 
		free(tempPtr);//释放内存空间 
		result=1;
	}
	else {
	UserLinkPtr previousPtr=(*sptr);
	UserLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->information.usernumber!=deletenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//删除中间节点 
	 printf("***职工号：%d\n***职工姓名：%s\n***会员电话：%d\n"
,currentPtr->information.usernumber,currentPtr->information.username,currentPtr->information.userphone);
		UserLinkPtr tempPtr=currentPtr;
		for(i=0;i<10;i++){
	if(currentPtr->information.account[i]!=0){
		printf("%d.%d\n",n,currentPtr->information.account[i]);
		n++;
		changecontact(&startPtr,currentPtr->information.account[i]);
	}//引用函数改变两者联系状态 
}
		previousPtr->nextPtr=currentPtr->nextPtr;
		free(tempPtr);
		result=1; 
	}
	}
	if(result==1){
		printf("*****该职工已被删除\n"); 
	}
	else {
		printf("***未找到职工号为 %d 的职工\n",deletenumber);
	}}
	else {
		printf("***职工列表为空\n");
	}
	system("pause>nul");
}
	
void usermanage(char *house)//用户管理 
{
	unsigned int choiceuser=10; 
	system("cls");
	system("color 0E");
	printf("    **********活力长者社区用户管理系统**********\n");
	printf("    ***************请选择用户管理服务***************\n");
	if(power==2){
		printf("    1.新建服务人员 2.选择服务对象 3.查看服务对象 0.查看地图 -1.返回上一界面\n");
	while(choiceuser!=1&&choiceuser!=2&&choiceuser!=3&&choiceuser!=0&&choiceuser!=-1){
		printf("***请选择服务序号："); 
	scanf("%d",&choiceuser);
	fflush(stdin);
}
if(choiceuser==1) creatuser(&startuserPtr);//新建服务人员服务 
else if(choiceuser==2) chooseuser(&startPtr,&startuserPtr);//选择服务对象 
else if(choiceuser==3) visituser(startPtr);//查看服务对象 
	}
	else {
	printf("    1.新建服务人员 2.选择服务对象 3.查看服务对象 4.查看服务人员列表 5.删除服务人员 0.查看地图 -1.返回上一界面\n");
	while(choiceuser!=1&&choiceuser!=2&&choiceuser!=3&&choiceuser!=0&&choiceuser!=-1&&choiceuser!=4&&choiceuser!=5){
		printf("***请选择服务序号："); 
	scanf("%d",&choiceuser);
	fflush(stdin);
}
if(choiceuser==1) creatuser(&startuserPtr);//新建服务人员服务 
else if(choiceuser==2) chooseuser(&startPtr,&startuserPtr);//选择服务对象 
else if(choiceuser==3) visituser(startPtr);//查看服务对象
else if(choiceuser==4) printuser(startuserPtr);//查看服务人员列表 
else if(choiceuser==5) deleteuser(&startuserPtr);//删除服务人员
}
if(choiceuser==-1) return ;//返回 
else if(choiceuser==0) map((char *)house);//查看地图
usermanage((char *)house); 
}

void creatbus(){//新建班车批次服务 
	system("cls");
	system("color 0F");
	BUSNUM
	printf("***上班时间区间为上午五点到十点\n");
	printf("***上班时间区间为下午四点到九点\n");
	printf("***采用24小时计时\n");
	while(shuttle[shuttlenum].timecome[0]<5||shuttle[shuttlenum].timecome[0]>9||shuttle[shuttlenum].timecome[1]<0||shuttle[shuttlenum].timecome[1]>59){
			printf("***请输入新建班车批次的上班时间（8 30）形式\n");
		scanf("%d %d",&shuttle[shuttlenum].timecome[0],&shuttle[shuttlenum].timecome[1]);
		fflush(stdin);
	}
	while(shuttle[shuttlenum].timego[0]<16||shuttle[shuttlenum].timego[0]>20||shuttle[shuttlenum].timego[1]<0||shuttle[shuttlenum].timego[1]>59){
			printf("***请输入新建班车批次的下班时间（17 30）形式\n");
		scanf("%d %d",&shuttle[shuttlenum].timego[0],&shuttle[shuttlenum].timego[1]);
		fflush(stdin);
	}
	while(shuttle[shuttlenum].fee<1||shuttle[shuttlenum].fee>5) {
		printf("***请输入新建班车的乘车费用（一元到五元）(2)形式\n");
		scanf("%d",&shuttle[shuttlenum].fee);
		fflush(stdin);
	}
	shuttle[shuttlenum].number=202101+shuttlenum;
	printf("***新建成功，班车信息如下：\n");
	printf("***班车编号：%d\n***乘车费：%d元\n***上班时间：%02d:%02d\n***下班时间：%02d:%02d\n",shuttle[shuttlenum].number,shuttle[shuttlenum].fee,shuttle[shuttlenum].timecome[0],
	shuttle[shuttlenum].timecome[1],shuttle[shuttlenum].timego[0],shuttle[shuttlenum].timego[1]);
	system("pause>nul");
}

void deletebuslink(BusLinkPtr *sptr,ServiceLinkPtr *vipsptr,UserLinkPtr *usersptr){//删除公交途径地链表 
	BusLinkPtr currentPtr=(*sptr);
	BusLinkPtr tempPtr=currentPtr;
	while(currentPtr!=NULL){
		
//本函数在修改链表功能的基础上实现用户链表和会员链表和公交链表的多向修改 
	(*usersptr)->busstate=0;
	UserLinkPtr previoususerPtr=(*usersptr);
	UserLinkPtr currentuserPtr=(*usersptr)->nextPtr;
	while(currentuserPtr!=NULL){
	if(currentuserPtr!=NULL)//修改中间节点 
	currentuserPtr->busstate=0;
	previoususerPtr=currentuserPtr;
	currentuserPtr=currentuserPtr->nextPtr;
	}
//本函数在修改链表功能的基础上实现用户链表和会员链表和公交链表的多向修改 
	(*vipsptr)->busstate=0;
	ServiceLinkPtr previousvipPtr=(*vipsptr);
	ServiceLinkPtr currentvipPtr=(*vipsptr)->nextPtr;
	while(currentvipPtr!=NULL){
	if(currentvipPtr!=NULL)//修改中间节点 
	currentvipPtr->busstate=0;
	previousvipPtr=currentvipPtr;
	currentvipPtr=currentvipPtr->nextPtr;
	}
		tempPtr=currentPtr->nextPtr;
		free(currentPtr);
		currentPtr=tempPtr;
	}
} 

void deletebus(){//删除班车批次
int busnumber; 
int i;
int fail=1;//判断是否搜索成功 
	system("cls");
	system("color 0F");
	printf("***请输入删除班车的批次编号\n");
	scanf("%d",&busnumber);
	fflush(stdin);
	for(i=0;i<10;i++){
		if(busnumber==shuttle[i].number){
	shuttle[i].fee=0;//删除该批次信息 
	shuttle[i].timecome[1]=0;
	shuttle[i].timecome[0]=0;
	shuttle[i].timego[1]=0;	
	shuttle[i].timego[0]=0;	
	shuttle[i].number=0;
deletebuslink(&startbusPtr[busnumber-202101],&startPtr,&startuserPtr);
busheadtailinit(&startbusPtr[busnumber-202101]);
		printf("***已删除编号为%d的班车批次\n",busnumber) ;
		fail=0;
		break;
		}
	}
		if(fail==1)
		{
			printf("***未找到对应的班车批次\n");
		}
	system("pause>nul");

}

void changebus(){//修改班车批次	
    system("cls");
	system("color 0F");
	int changechoice; 
	int busnumber;//批次编号 
	int i;//循环 
	int fail=1;//判断是否搜索成功 
	printf("***请输入修改班车的批次编号\n");
	scanf("%d",&busnumber);
	fflush(stdin);
	for(i=0;i<10;i++){
		if(busnumber==shuttle[i].number){
		printf("***请选择修改的内容\n");
		printf("***1.班车费用\n***2.上班时间\n***3.下班时间\n");
	scanf("%d",&changechoice); 
	fflush(stdin);
	switch(changechoice){
		case 1:
			do {
		printf("***请输入修改后的乘车费用（一元到五元）(2)形式\n");
		scanf("%d",&shuttle[i].fee);
		fflush(stdin);
	}
		while(shuttle[i].fee<1||shuttle[i].fee>5);
		printf("***修改成功，班车信息如下：\n");
	printf("***班车编号：%d\n***乘车费：%d元\n***上班时间：%02d:%02d\n***下班时间：%02d:%02d\n",shuttle[i].number,shuttle[i].fee,shuttle[i].timecome[0],
	shuttle[i].timecome[1],shuttle[i].timego[0],shuttle[i].timego[1]);
			break;
		case 2:
			do{
			printf("***请输入修改后班车的上班时间（8 30）形式\n");
		scanf("%d %d",&shuttle[i].timecome[0],&shuttle[i].timecome[1]);
		fflush(stdin);
	}while(shuttle[i].timecome[0]<5||shuttle[i].timecome[0]>9||shuttle[i].timecome[1]<0||shuttle[i].timecome[1]>59);
	printf("***修改成功，班车信息如下：\n");
	printf("***班车编号：%d\n***乘车费：%d元\n***上班时间：%02d:%02d\n***下班时间：%02d:%02d\n",shuttle[i].number,shuttle[i].fee,shuttle[i].timecome[0],
	shuttle[i].timecome[1],shuttle[i].timego[0],shuttle[i].timego[1]);
			break;	
		case 3:
			do{
			printf("***请输入修改后班车的下班时间（17 30）形式\n");
		scanf("%d %d",&shuttle[i].timego[0],&shuttle[i].timego[1]);
		fflush(stdin);
	}while(shuttle[i].timego[0]<16||shuttle[i].timego[0]>20||shuttle[i].timego[1]<0||shuttle[i].timego[1]>59);
	printf("***修改成功，班车信息如下：\n");
	printf("***班车编号：%d\n***乘车费：%d元\n***上班时间：%02d:%02d\n***下班时间：%02d:%02d\n",shuttle[i].number,shuttle[i].fee,shuttle[i].timecome[0],
	shuttle[i].timecome[1],shuttle[i].timego[0],shuttle[i].timego[1]);
			break;	
		default:
			printf("***操作无效\n");
			break;
	}
		fail=0;
		break;
		}
	}
		if(fail==1)
		{
			printf("***未找到对应的班车批次\n");
		}
	system("pause>nul");
}

void printplacelink(BusLinkPtr sptr){//打印途径地链表 
		while ((sptr)!=NULL){//循环打印节点 
		if(sptr->employeenumber>=20210000)
		printf("%s(会员：%d)---",sptr->placename,sptr->employeenumber);
		else if(sptr->employeenumber>=2021000)
		printf("%s(职工：%d)---",sptr->placename,sptr->employeenumber);
		else 
		printf("%s---",sptr->placename,sptr->employeenumber);
(sptr)=(sptr)->nextPtr;
		}
		printf("ElderlyCommunity\n\n");	
}

void buslist(){//查看班车批次列表
	system("cls");
	system("color 0F");
	int i;
	int nul=0; 
	printf("***班车列表如下：\n\n");
	for(i=0;i<10;i++){
		if(shuttle[i].number!=0){
			nul=1;
	printf("***班车编号：%d\n***乘车费：%d元\n***上班时间：%02d:%02d\n***下班时间：%02d:%02d\n",shuttle[i].number,shuttle[i].fee,shuttle[i].timecome[0],
	shuttle[i].timecome[1],shuttle[i].timego[0],shuttle[i].timego[1]);
	printplacelink(startbusPtr[shuttle[i].number-202101]);
		}
	}if(nul==0){
	gotoxy(0,0);
	printf("*****班车列表为空\n\n");}
	system("pause>nul");
}

void addplace(BusLinkPtr *sptr,char place[20],int number){//增加途径地 
		BusLinkPtr newPtr=(BusLinkPtr)malloc(sizeof(BusLink));
if(newPtr!=NULL){//判断是否有空间 
	strcpy(newPtr->placename,place);//将值赋给节点
	newPtr->employeenumber=number;//头尾 
	newPtr->nextPtr;//该节点不指向任何节点 
	BusLinkPtr previousPtr=NULL;
	BusLinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL&&currentPtr->placename!="ElderlyCommunity"){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//下一个节点 
	}
	if(previousPtr==NULL){
		newPtr->nextPtr=*sptr;
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}
} 
else {
	printf("**内存已满，节点未能创建成功\n"); 
}
}

void ways(UserLinkPtr *usersptr,ServiceLinkPtr *sptr){//增加途径地 
UserLinkPtr previoususerPtr;//user过渡 
UserLinkPtr currentuserPtr;
ServiceLinkPtr previousPtr;//vip过渡 
ServiceLinkPtr currentPtr;
int i,result1=0;
int choice;
int identity=0;
if(power==1)identity=1;
else if(power==2)identity=2;
else if(power==3)identity=3;
int account;
	system("cls");
	system("color 0F");
	
	while(identity!=2&&identity!=1){
	printf("***请选择会员身份或职工身份\n***1.会员\n***2.职工\n");
	scanf("%d",&identity);
	fflush(stdin);
}if(identity==2){
		if(!userempty(*usersptr)){
			printf("*****请输入职工账号\n");
	scanf("%d",&account);
	fflush(stdin);
	if(account==(*usersptr)->information.usernumber){//本函数在修改链表功能的基础上实现用户链表和会员链表的双向修改 
	if(	(*usersptr)->busstate==1){
		printf("***该职工已填写预案，不可重复填写\n");
		system("pause>nul");
		return ;
	}
	(*usersptr)->busstate=1;
		result1=1;
	}
	else {
	UserLinkPtr previoususerPtr=(*usersptr);
	UserLinkPtr currentuserPtr=(*usersptr)->nextPtr;
	while(currentuserPtr!=NULL&&currentuserPtr->information.usernumber!=account){
		previoususerPtr=currentuserPtr;
		currentuserPtr=currentuserPtr->nextPtr;
	}
	if(currentuserPtr!=NULL){//修改中间节点 
		if(currentuserPtr->busstate==1){
		printf("***该职工已填写预案，不可重复填写\n");
		system("pause>nul");
		return ;
	}
	currentuserPtr->busstate=1;
		result1=1;
	}
	if(result1==0) {
		printf("***未找到职工号为 %d 的职工\n",account);
			system("pause>nul");
	return ;
	}}}
	else {
		printf("***职工列表为空\n");
			system("pause>nul");
	return ;
	}}
	else if(identity==1){
			int cn;
	if(!empty(*sptr)){
	int result=0; 
	printf("***请输入会员的会员账号\n");
	scanf("%d",&account);
	fflush(stdin);
	if(account==(*sptr)->member.vipnumber){
		if((*sptr)->busstate==1){
			printf("***该会员已填写预案，不可重复填写\n");
		system("pause>nul");
		return ;
		}
		(*sptr)->busstate=1;
		result=1;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=account){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//查询中间节点 
		if(currentPtr->busstate==1){
			printf("***该会员已填写预案，不可重复填写\n");
		system("pause>nul");
		return ;
		}
		currentPtr->busstate=1;
		result=1; 
	}
	}
	if(result==0) {
		printf("***未找到会员号为 %d 的会员\n",account);		
			system("pause>nul");
	return ;
	}}
	else {
		printf("***会员列表为空\n");
					system("pause>nul");
	return ;
	}}
	char place[20];//所在地英文简写 
	int busnumber; 
	int fail=1;
	printf("***请选择班车批次\n");
scanf("%d",&busnumber);
fflush(stdin);
	for(i=0;i<10;i++){
		if(busnumber==shuttle[i].number){
		printf("***请输入您的所在地（英文简写）\n");
	scanf("%s",place); 
	fflush(stdin);
addplace(&startbusPtr[busnumber-202101],place,account);
printf("***途径地添加成功\n");
		fail=0;
		break;
		}
	}if(fail==1)
		{
			if(identity==1){
			if(account==(*sptr)->member.vipnumber)
				(*sptr)->busstate=0;
			else currentPtr->busstate=0;
			}
			else {
			if(account==(*usersptr)->information.usernumber)
				(*usersptr)->busstate=0;
			else currentuserPtr->busstate=0;	
			}
			printf("***未找到对应的班车批次\n");
			system("pause>nul");
	return ;
		}
	system("pause>nul");
}

 void routinemanage(char *house)//班车路线管理 
{
unsigned int choicebus=10; 
	system("cls");
	system("color 0E");
	printf("    **********活力长者社区班车管理系统**********\n");
	printf("    ***************请选择班车管理服务***************\n");
	if(power==1||power==2){
		printf("    1.查看班车批次列表 2.上交班车批次提案 0.查看地图 -1.返回上一界面\n");
	while(choicebus!=1&&choicebus!=2&&choicebus!=0&&choicebus!=-1){
		printf("***请选择服务序号："); 
	scanf("%d",&choicebus);
	fflush(stdin);
}
 if(choicebus==1) buslist();//查看班车批次列表
else if(choicebus==2) ways(&startuserPtr,&startPtr);//增加途径地 
	}
	else{
	printf("    1.新建班车批次 2.删除班车批次 3.修改班车批次 4.查看班车批次列表 5.增加途径地 0.查看地图 -1.返回上一界面\n");
	while(choicebus!=1&&choicebus!=2&&choicebus!=3&&choicebus!=0&&choicebus!=-1&&choicebus!=4&&choicebus!=5){
		printf("***请选择服务序号："); 
	scanf("%d",&choicebus);
	fflush(stdin);
}
if(choicebus==1) creatbus();//新建班车批次服务 
else if(choicebus==2) deletebus();//删除班车批次
else if(choicebus==3) changebus();//修改班车批次
else if(choicebus==4) buslist();//查看班车批次列表
else if(choicebus==5) ways(&startuserPtr,&startPtr);//增加途径地 
}
if(choicebus==-1) return ;//返回 
else if(choicebus==0) map((char *)house);//查看地图 
routinemanage((char *)house); 
}
 
