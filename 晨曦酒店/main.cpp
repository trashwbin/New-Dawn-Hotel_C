#include<stdio.h>
#include<string.h>
//测试变量
double BigRoom=99;


void CheckIn();
void CheckRe();
void BookRoom();
int ChangeRoom();
void BuildRoom();
void DeleteRoom();
void ChangeFee();

// 房间结构体
typedef struct {
	int roomNumber;
	int type;
	double price;
	int time;
	char name[20];
	int phone;
	int status=0;  // 0表示未订购，1表示已订购
} Room;
// 全局变量
int bulidings=50;
Room rooms[50];
int Admin=0;


int main(){
	int step;
	BuildRoom();
	int *roomCount1;
	do{
		do{
		// 顾客菜单
		int i,j=0;
		for(i=0;i<bulidings;i++){
		j+=rooms[i].status;}
		int roomCount = bulidings-j;
		if(roomCount==0){
			printf("\n\t今日房间已空！！无法继续预订！！\n");
		}
		printf("\n\t今日特惠,舒适大床房仅需99元！！限时抢购~\n");
		printf("\t房间仅剩：%d间！！！\n",roomCount);
		printf("\t------欢迎光临晨曦酒店------\n");
		printf("\t\t1. 查询预订\n");
		printf("\t\t2. 预订房间\n");
		printf("\t\t3. 管理员入口\n");
		printf("\t\t0. 退出\n");
		printf("\t请输入操作数：");
		scanf("%d",&step);
		if(step<0||step>3){
			printf("\n\t！！您的输入有误，请在0-3之间重新输入！！\n");
		}
	}while(step<0||step>3);
	switch(step){
		case 0:return 0;
		case 1:CheckRe();break;
		case 2:BookRoom();break;
		case 3:ChangeRoom();break;
	}}while(1);
	return 0;
}
void BookRoom(){
	FILE *fp = NULL;
	int i,j;
	if ((fp = fopen("user.data", "rb")) != NULL){
			fp = fopen("user.data", "w");
	for(j=0;j<bulidings;j++){
	fread(&rooms[j], sizeof(Room), 1, fp);
	}}
	fclose(fp);
	for(i=0;i<bulidings;i++){
	if(rooms[i].status==0)
	break;
	}
	rooms[i].roomNumber=i;
	do{
	printf("\n请选择房间类型：\n");
	printf("1.舒适大床房\n");
	scanf("%d", &rooms[i].type);
	if(rooms[i].type==1){
		printf("\n舒适大床房的价格为%.2f元每晚\n",BigRoom);
		rooms[i].price=BigRoom;
	}else{
		printf("暂无，请重新输入！\n");
	}}while(rooms[i].type!=1);
	printf("请输入入住晚数：\n");
	scanf("%d", &rooms[i].time);
	printf("请输入您的姓名：\n");
	getchar();
	gets(rooms[i].name);
	//scanf("%s", &rooms[i].name);
	printf("请输入您的电话号码：\n");
	scanf("%d", &rooms[i].phone);
	double bill,money=0;
	bill=rooms[i].price*rooms[i].time;
	do{
		printf("\n\t%s您好，您预定的房间共需支付%.2f元。",rooms[i].name,bill);
		if(Admin==0){
		printf("\n\t请输入票面：");
		scanf("%lf",&money);
		getchar();}
		if(money>=bill||Admin==1){
			if(money>bill){
				printf("\n\t找您%.2f元",money-bill);
			}
			if(Admin==1){
			printf("\n\t管理员办理成功！房间号为%d。\n",rooms[i].roomNumber+1);	
			}else{
			printf("\n\t预订成功！您的房间号为%d，请到前台报姓名入住。谢谢惠顾。\n",rooms[i].roomNumber+1);}
			rooms[i].status=1;
			if ((fp = fopen("user.data", "rb")) != NULL){
			fp = fopen("user.data", "w");
			if (fp) {
					for(j=0;j<bulidings;j++){
	 		fwrite(&rooms[j], sizeof(Room), 1, fp);
			}}}
			printf("\n操作预订成功，按回车建继续......");		
			getchar();
		}else{
			printf("\n\t您的票面不足，请重新支付！\n");
		}
	}while(money<bill&&Admin==0);
fclose(fp);
}

void CheckRe(){
	Room check;
	int i;
	printf("\n请输入您的姓名：\n");
	getchar();
	gets(check.name);
	printf("请输入您预留的电话号码：\n");
	scanf("%d",&check.phone);
	FILE *fp=fopen("user.data","r");
	getchar();
	for(i=0;i<bulidings;i++){
		if(strcmp(check.name,rooms[i].name)==0&&check.phone==rooms[i].phone){
			printf("\n\t%s您好，以下是您的入住信息：\n",rooms[i].name);
			printf("\t\t您的房间号为：%d\n",rooms[i].roomNumber+1);
			printf("\t\t您的预订时长为:%d天%d晚\n",rooms[i].time+1,rooms[i].time);
			printf("\t\t您所付房费为%.2f元\n",rooms[i].price*rooms[i].time);
			break;
		}
	}
	if(i==bulidings){
		printf("\n很遗憾，未查询到您的预定信息。请检查相关信息是否填写正确或咨询前台客服！\n");
	}
	printf("\n查询成功，按回车建继续......");		
	getchar();
	fclose(fp);
}
//创建房间 的函数，对系统进行数据的初始化
void BuildRoom() {
	 FILE *fp = NULL;
	 int i;
	 	if ((fp = fopen("user.data", "r")) == NULL) {
		fp = fopen("user.data", "w");
		for (i = 0; i < bulidings; i++) {
	 		   	rooms[i].phone=0;
	 		   	rooms[i].price=0.0;
	 		   	rooms[i].roomNumber=i;
	 		   	rooms[i].status=0;
	 		   	rooms[i].time=0;
	 		   	rooms[i].type=0;
				fwrite(&rooms[i], sizeof(Room), 1, fp);
			}
	} else {
			 for(i=0;i<bulidings;i++){
	 		 fread(&rooms[i], sizeof(Room), 1, fp);
	 		 }
	}
	fclose(fp);
}
	

int ChangeRoom(){
	char password[50];
	printf("\n请输入管理员密码：");
	getchar();
	gets(password);
	if(strcmp(password,"admin")==0){		
		printf("\n登录成功！\n");
		int step;
		Admin=1;
	do{
		do{
		printf("\n\t--------管理员菜单--------\n");
		printf("\t\t1. 查询入住房间\n");
		printf("\t\t2. 用户退房\n");
		printf("\t\t3. 超级开房\n");
		printf("\t\t0. 返回主界面\n");
		printf("\t请输入操作数：");
		scanf("%d",&step);
		if(step<0||step>4){
			printf("\n\t！！您的输入有误，请在0-3之间重新输入！！\n");
		}
	}while(step<0||step>4);
	switch(step){
		case 0:Admin=0;printf("\n\n\n");return 0;
		case 1:CheckIn();break;
		case 2:DeleteRoom();break;
		case 3:BookRoom();break;
	}
		
	}while(1);
	}else{
		printf("\n密码错误！\n");
	}
	Admin=0;
	return 0;
}

void CheckIn(){
	getchar();
	int i;
	for(i=0;i<bulidings;i++){
		if(rooms[i].status==1){
			printf("\n\t房间号：%d\n",rooms[i].roomNumber+1);
			printf("\t\t房间类型：");
			switch(rooms[i].type){
				case 1:printf("舒适大床房\n");break;
			}
			printf("\t\t用户姓名：%s\n",rooms[i].name);
			printf("\t\t用户预留号码：%d\n",rooms[i].phone);
			printf("\t\t预订时长为：%d天%d晚\n",rooms[i].time+1,rooms[i].time);
			printf("\t\t所付房费为：%.2f元\n",rooms[i].price*rooms[i].time);
		}
	}
	 	printf("\n操作成功，按回车建继续......");		
		getchar();
}

void DeleteRoom(){
	FILE *fp = NULL;
	int a;
	int i,j;
	if ((fp = fopen("user.data", "rb")) != NULL){
			fp = fopen("user.data", "w");
	for(j=0;j<bulidings;j++){
	fread(&rooms[j], sizeof(Room), 1, fp);
	}}
	fclose(fp);
	printf("\n请输入要退房的房间号：");
	scanf("%d",&a);
	a--;
	getchar();
	if(rooms[a].status==1){
			 	rooms[a].phone=0;
	 		   	rooms[a].price=0.0;
	 		   	rooms[a].roomNumber=a;
	 		   	rooms[a].status=0;
	 		   	rooms[a].time=0;
	 		   	rooms[a].type=0;
	if ((fp = fopen("user.data", "rb")) != NULL){
			fp = fopen("user.data", "w");
			if (fp) {
			for(j=0;j<bulidings;j++){
	 		fwrite(&rooms[j], sizeof(Room), 1, fp);
			}}}
	 		printf("\n操作退房成功，按回车建继续......");		
			getchar();
			}else{
				printf("\n！！您的输入有误！！\n");
			}

}