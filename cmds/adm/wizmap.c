//Map here功能  By JackyBoy 1999/11/19
//由於嚴重影響速度（遞歸調用導致！），所以進行此命令的使用應該減少玩家的精力或者氣息
inherit F_CLEAN_UP;

#include <ansi.h>
#define MaxX 7
#define MaxY 30

int X=7,Y=10;
nosave mixed m;
nosave string *rfile;
int draw_room(int,int,object);
string clean_color(string arg)
{
	if(!arg)
		return "";
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BLINK,"");
	return arg;
}
int main(object me, string arg)
{
	object where;
	int i,j;
	string tmp;
	if(me->query("qi")<40)
		return notify_fail("你的體力不太好了，先休息一下吧！\n");
	me->add("qi",-20);
	if(arg)
	{
		//允許在指定範圍內自定義房間搜索範圍！
		arg=lower_case(arg);
		sscanf(arg,"%*sx=%d%*s",X);
		sscanf(arg,"%*sy=%d%*s",Y);
		if(X>MaxX||X==0) X=MaxX;
		if(Y>MaxY||Y==0) Y=MaxY;
	}
	tmp="即時地圖v1.0(By JackyBoy) 99/11/20 地圖大小："+X+"/"+Y+"\n";
	m=allocate(2*X+1);
	rfile=({});
	for(i=0;i<2*X+1;i++)
	{
		m[i]=allocate(2*Y+1);
		for(j=0;j<2*Y+1;j++)
			m[i][j]=" ";
	}
	where=environment(me);
	if(!objectp(where))
		return notify_fail("對不起，不知道你到底在哪裏呀！找巫師吧！\n");
	draw_room((2*X+1)/2,(2*Y+1)/2,where);
	for(i=0;i<2*Y+1;i++)
	{
		for(j=0;j<2*X+1;j++)
		{
			if(m[j][i]==" "&&i%2&&j%2)
				tmp+="        ";
			else
			{
				//如果此項為空，並且此時j為偶數列，則輸出空格
				if(m[j][i]==" "&&!(j%2))
					tmp+="  ";
				else
				if(m[j][i]==" ")
					tmp+="        ";
				else
				{
					tmp+=m[j][i];
					//if(!(i%2)&&!(j%2))
					if(m[j][i]!="--")
						for(int d=8-sizeof(clean_color(m[j][i]));d>0;d--)
							tmp+=" ";
				}
			}
		}
		tmp+="\n";
	}
	me->start_more(tmp);
	return 1;
}

object find_room(string path)
{
	object ob;
	if(objectp(ob=find_object(path))||objectp(ob=load_object(path)))
		return ob;
	return 0;
}

//←↑→↓↖↗↘↙
int draw_path(int x,int y,string direc)
{
	string str;
	int xx=0,yy=0;
	switch(direc)
	{
		case "south":
		case "north":str="   │   ";break;
		case "southdown":
		case "northup":str="   ↑   ";break;
		case "southup":
		case "northdown":str="   ↓   ";break;
		case "east":
		case "west":str="--";break;
		case "eastup":
		case "westdown":str="→";break;
		case "westup":
		case "eastdown":str="←";break;
		case "southeast":
		case "northwest":str="↗";break;
		case "shothwest":
		case "northeast":str="↖";break;
		default:
			return 0;
	}
	if(sscanf(direc,"%*ssouth%*s"))
		yy++;
	if(sscanf(direc,"%*snorth%*s"))
		yy--;
	if(sscanf(direc,"%*seast%*s"))
		xx++;
	if(sscanf(direc,"%*swest%*s"))
		xx--;
	if(x+xx<0||y+yy<0||x+xx>2*X||y+yy>2*Y)
		return 0;
	//write("設置第 "+(x+xx)+ " "+(y+yy)+" 項\n");
	m[x+xx][y+yy]=str;
	return 1;
}

int draw_room(int x,int y,object room)
{
	int i,nst=0,xx,yy;
	string name,*dirs;
	object nroom;
	mapping dir;
	reset_eval_cost();
	if(x<0||y<0||!objectp(room)||x>2*X||y>2*Y)
		return 0;
	name=clean_color(room->query("short"));//求取無顏色的房間short描述
	//write("座標："+x+" / "+ y+ "處理 "+name+" 文件名："+base_name(room)+"\n");
	rfile=rfile + ({ base_name(room) });
	dir=room->query("exits");
	if(!mapp(dir)||sizeof(dir)<1)
		return 0;
	dirs=keys(dir);
	for (i=0;i<sizeof(dirs);i++)
	{
		xx=0;yy=0;
		if(sscanf(dirs[i],"%*ssouth%*s"))
			yy+=2;
		if(sscanf(dirs[i],"%*snorth%*s"))
			yy-=2;
		if(sscanf(dirs[i],"%*seast%*s"))
			xx+=2;
		if(sscanf(dirs[i],"%*swest%*s"))
			xx-=2;
		if(!draw_path(x,y,dirs[i])||(xx==0&&yy==0))
			nst=1;
		nroom=find_room(dir[dirs[i]]);
		//避免重複調用
		if(!objectp(nroom)||nst)
			continue;
		if(member_array(base_name(nroom),rfile)==-1)
			draw_room(x+xx,y+yy,nroom);
	}
	if(strwidth(name)>8)
		name=name[0..7];
	if(strwidth(name)<7)//對不足4個漢字的房間名進行居中處理
	{
		int d=8-strwidth(name);
		if(d%2)
		{
			name+=" ";
			d--;
		}
		for(i=0;i<d/2;i++)
			name=" "+name+" ";
	}
	if(nst)
		name=HIY+name;
	if((x==(2*X+1)/2)&&(y==(2*Y+1)/2))
		name=BLINK+name;
	name+=NOR;
	m[x][y]=name;
	return 1;
}

int help()
{
	write(@HELP
	即時地圖 v1.0 (Write By JackyBoy 99/11/20)
	命令用法：map [x=1-7] [y=1-30]
本命令幫助玩家瞭解周圍的房間地圖的分佈狀況，並標誌出房間之間的連接情況。
理論上講，該命令應該能完全正確地反應地圖，但是由於巫師設計地圖不規範等多
種原因（比如迷宮、有不規範出口比如enter之類的，房間之間無法雙向關聯等），
導致地圖可能在顯示時與行走方向上有一定區別，甚至會出現走一步路，地圖就完
全變樣的情況。比如，房間A可以從south走到B房間，但是B房間走north卻走到C房
間，這時在A用該命令與在B用該命令效果完全不一樣！
此外，連接標誌中箭頭所指方向地勢更高，有不規範出口的房間以黃色標誌，你所
處的房間以閃爍來標誌！
本命令默認以x=7,y=10 的地圖大小顯示，你可以在命令行手動指定地圖大小。
HELP);
	return 1;
}
