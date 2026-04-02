// Room: /city/bingyindamen.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "兵營大門");
	set("long", @LONG
你正站在兵營的門口，面對着一排簡陋的營房，可以看到穿着制服
的官兵正在操練，不時地傳來吶喊聲。老百姓是不允許在此觀看的，你
最好趕快走開。
LONG );
	set("exits", ([
		"south" : __DIR__"bingyin",
		"north" : __DIR__"hejiajie",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵攔住了你的去路。\n");
	return ::valid_leave(me, dir);
}