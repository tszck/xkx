// /guanwai/nancheng.c

inherit ROOM;

void create()
{
	set("short", "南城");
	set("long", @LONG
這裏是用黃土鋪就的街道，街上的行人不多，看起來很冷清。偶爾
有幾個身着異域服飾的行人走過，看起來是滿族，鮮祖的居民。西面有
一座低埃的土房，門口掛着一個寫滿鮮文的幌子，還傳來陣陣的肉香，
看起來象一個小飯館。
LONG );
	set("exits", ([
		"north" : __DIR__"jishi",
		"south" : __DIR__"muqiao",
		"west"  : __DIR__"rouguan",
	]));
	set("objects", ([
		__DIR__"npc/tengyilei" : 1,
	]));
	set("outdoors", "guanwai");
	set("coor/x", 6040);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}