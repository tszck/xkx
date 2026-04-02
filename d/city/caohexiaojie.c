// Room: /yangzhou/caohexiaojie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","草河小街");
	set("long",@LONG
沿小街西邊是揚州官衙的高牆，多開漏窗，倚牆種着槐樹，透過槐
樹、漏窗，依稀可看到牆內是個園子。東邊是官河，楊柳、碧桃臨河而
植。小街向北邊穿過小廣場通向揚州的府學「資政書院」；東面是通泗
橋，連接着官河對岸的十里長街；南邊多爲民宅；西面是通泗街。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"tongsijie",
		"east"      : __DIR__"tongsiqiao",
		"south"     : __DIR__"caohenanjie",
		"north"     : __DIR__"xiaosquare",
		"southwest" : __DIR__"wudao4",
	]));
	set("objects", ([
		__DIR__"npc/youke1" : 1,
		"/d/mingjiao/npc/fenggongying" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
 
	if (dir == "southwest") me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}