inherit ROOM;

void create()
{
	set("short", "西客房");
	set("long", @LONG
這裏是西客房，一個掌櫃和兩個夥計躲在角落裏瑟瑟發抖。
LONG );
	set("exits", ([
		"east" : __DIR__"kedian2",
	]));
	set("objects", ([
		__DIR__"npc/zhanggui":1,
		__DIR__"npc/huoji":2,
	]));
	set("coor/x", -230);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
