// Room: /d/guiyun/road4.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "歸雲莊前");
	set("long",@LONG
這是通向歸雲莊的道路，西面就是歸雲莊。向南是一條小路，北面
是一片綠油油的草地。
LONG
);
	set("exits",([
		"west"  : __DIR__"shiqiao",
		"south" : __DIR__"road3",
		"north" : __DIR__"caodi1",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west")
	{
		write("莊前有一個依據九宮算術布成的桃花陣。\n");
		if ((me->query("family/family_name") == "桃花島" &&
			me->query_skill("qimen-wuxing", 1) > 14) ||
			me->query_skill("qimen-wuxing", 1) > 39)
			write( "由於你平常看慣了這些簡易的陣法，所以不用細想，信步就走出了陣！\n");
		else {
			me->set_temp("jiugong_dir", "w");
			me->move(__DIR__"jiugong" + (random(9) + 1));
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
