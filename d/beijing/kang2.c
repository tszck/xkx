inherit ROOM;

void create()
{
	set("short", "康府大院");
	set("long", @LONG
這是一個寬大的練武場，有幾個武師在這裏練功。其中一個禿頂和尚，
東走走，西看看，好象是這兒的領頭。還有一個身材瘦高的武師，兩手別
在腰後，似乎也有一身好武功。東面是一個小一些的練武場。北面是後院。
西邊有個武器庫。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"wuqiku",
		"east" : __DIR__"wuchang",
		"north" : __DIR__"kang3",
		"south" : __DIR__"kang1",
	]));
	set("objects", ([
		__DIR__"npc/shenzhao" : 1,
		__DIR__"npc/qi" : 1,
	]));
	set("coor/x", -180);
	set("coor/y", 4081);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
