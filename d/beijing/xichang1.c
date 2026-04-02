inherit ROOM;

void create()
{
	set("short", "西長安街");
	set("long", @LONG
這是一條寬闊的青石板街道，向東西兩頭延伸。往西望去，長長的
街道看不到頭。東邊就是天安門。一陣陣喝采聲不時從北邊的戲院傳來。
南邊就是京城最著名的‘回春堂’藥店。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"east"      : __DIR__"tian_anm",
		"west"      : __DIR__"xichang2",
		"south"     : __DIR__"huichunt",
		"north"     : __DIR__"xiyuan",
		"northeast" : "/d/beihai/ximen",
	]));
	set("objects", ([
		__DIR__"npc/flowerg": 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	me->delete_temp("warned");
	me->delete_temp("hastryup");
	return ::valid_leave(me, dir);
}
