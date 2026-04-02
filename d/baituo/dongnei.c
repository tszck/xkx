// Room: /d/baituo/dongnei.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "洞內");
	set("long", @LONG
這裏是山賊的老窩的所在。陰森濕冷的土壁上，插着一些松明子。光
亮下，居中的虎皮大椅格外顯目。旁邊有一側洞，裏面隱隱傳來女子的哭
聲。
LONG	);
	set("exits", ([
		"west" : __DIR__"cedong",
		"south" : __DIR__"dongkou",
	]));
	set("objects",([
		__DIR__"npc/shanzei3" : 1,
	]));
	set("coor/x", -49960);
	set("coor/y", 20040);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
	if (  (dir == "west") &&
		objectp(present("shanzei tou", environment(me))) )
	return notify_fail("山賊頭操起拳頭：你想佔我老婆的便宜？快滾！\n");
	return ::valid_leave(me, dir);
}
