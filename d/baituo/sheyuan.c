// Room: /d/baituo/sheyuan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","蛇園");
	set("long", @LONG
這裏是白駝山莊的蛇園。白駝山以毒名揚天下，最重要的毒質就來
自毒蛇。這裏遍地是蛇，牆上也巴着蛇，屋檐上也向下垂着蛇，樹枝上
也盤繞着蛇，不由你不心驚。
LONG );
	set("exits",([
		"west"  : __DIR__"tuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		"/d/shenlong/npc/jinshe" :1,
		"/d/shenlong/npc/dushe" :1,
		"/d/shenlong/npc/fushe" :1,
		"/d/shenlong/npc/qingshe" :1,
		"/d/yanping/npc/wubushe" :1,
	]));
	set("coor/x", -49990);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
