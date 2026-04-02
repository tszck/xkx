// Room: /d/shaolin/hsyuan4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "和尚院四部");
	set("long", @LONG
這裏是和尚院待客的地方，靠牆左右兩側擺着一溜太師椅。
牆角一幾，放着幾個茶壺。有個茶壺壺身上題了“碧螺春”三
個篆字，壺嘴熱氣騰騰，似乎是剛沏的新茶。一位小沙彌在一
邊垂手站立。
LONG );
	set("exits", ([
		"east" : __DIR__"wuchang3",
		"west" : __DIR__"zhulin4",
		"south" : __DIR__"zoulang6",
		"north" : __DIR__"hsyuan5",
	]));
	set("resource/water",1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-xu" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 890);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}