//ROOM: /d/yanziwu/bozhou.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "泊舟塢");
	set("long",@LONG
一片蘆葦，茭白叢中現出一座船塢，大小船隻依次排開。菱花荷葉
叢中條條水道四通八達，由此可乘船離開燕子塢。湖面正繫着幾尾小舟
(zhou)。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"east"  : __DIR__"pindi",
	]));
	set("item_desc", ([
		"zhou" : "這是燕子塢和湖外聯繫的各色小舟。島上的客人只要登舟(enter)就可以出發了。
素色小舟(white)  : 出湖
綠色小舟(green)  : 前往青雲莊
紅色小舟(red)    : 前往赤霞莊
黃色小舟(yellow) : 前往金鳳莊
黑色小舟(black)  : 前往玄霜莊
\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", 800);
	set("coor/y", -1520);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_enter", "enter");
}
int do_enter(string arg)
{
	object ob ;
 
	if( !arg || (arg!="white" && arg!="red" && arg!="green" && arg!="black" && arg!="yellow")) 
	{
		tell_object(this_player() , "你要投水？\n");
	 	return 1 ;
	}
	ob = this_player();
message_vision("船上一個秀美溫柔的江南少女看到$N登舟，竹篙輕點，舟已離岸，燕子
塢漸漸在視野裏遠去。\n", ob);
	ob ->move(__DIR__"taihu") ;
	tell_object(ob, HIG "你在湖上飄流，四周看不盡的江南美景。\n" NOR ) ;
	call_out("home", 10, ob, arg);
	return 1 ;
}
void home(object ob, string arg)
{
	tell_object(ob , "小舟終於戀戀不捨地靠岸了。你走下小舟來。少女揮手依依道別。\n" ) ;
	switch (arg)
	{
		case "white"  : ob->move (__DIR__"hupan"); break;
		case "red"    : ob->move (__DIR__"chixia"); break;
		case "green"  : ob->move (__DIR__"qingyun"); break;
		case "black"  : ob->move (__DIR__"xuanshuan"); break;
		case "yellow" : ob->move (__DIR__"jinfeng"); break;
	}
}