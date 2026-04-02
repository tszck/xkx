// Room: /beijing/duchang.c

#include <ansi.h>
inherit ROOM;
string* npcs = ({
	CLASS_D("yunlong")+"/wuliuqi",
});

void create()
{
	int i = random(sizeof(npcs));
	set("short", "賭場");
	set("long", @LONG
這裏是賭場的大堂，四周的房間裏傳出來吆五喝六的賭博聲。北邊
是賭「大小」的房間，牆上掛着一塊牌子 (paizi)。樓上可以拱豬。一
進門，只見房中人聲嘈雜，十分混亂。有一桌圍着一羣人，其中一胖一
瘦兩個頭陀十分惹眼。一個老叫化正和他們賭得起勁。
LONG );
	set("item_desc", ([
		"paizi" : "二樓的拱豬房可以使用，為什麼沒人來呢?\n",
	]));
	set("exits", ([
		"up"    : __DIR__"duchang2",
		"north" : __DIR__"daxiao",
		"west"  : __DIR__"xidan1",
	]));
	set("no_clean_up", 0);
	set("objects", ([
		CLASS_D("shenlong")+"/shou": 1,
		npcs[i] : 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
//	int i;
	if(dir=="north" && 
		this_player()->query("party/party_name") != HIR"天地會"NOR &&
		objectp(present("wu", environment(me))) &&
		living(present("wu", environment(me))))
		return notify_fail("\n吳六奇攔住你説道：對不起，非本幫弟子不得自由出入。\n");	
	return ::valid_leave(me, dir);
}        