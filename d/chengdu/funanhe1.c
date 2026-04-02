// Room: /d/chengdu/eastroad2.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "府南河畔");
	set("long", @LONG
你信步來到了府南河畔，這裏便是被稱為成都母親河的府南河，兩
岸垂柳，隨風飄動，綠草如茵，彩蝶紛飛。河水清澈見底，魚兒遊來遊
去，河的對岸有羣洗衣婦人，一邊辛勤地勞作，一邊大聲地聊天，歡聲
笑語在河的這邊都可以聽見。遠處還有個老漁翁獨自垂釣。看到這裏，
你也彷彿入畫了。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southeast" : __DIR__"funanhe2",
		"northwest" : __DIR__"chunxilu3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}

