inherit ROOM;

void create()
{
	set("short", "西單");
	set("long", @LONG
這裏就是西單，人來人往，十分熱鬧。遊人雖然多，但大都只四處
晃悠，着東瞅瞅西看看，也不急着買什麼。西邊有家雜貨鋪，去那裏買
東西的人很多。不斷有人從北邊走來，似乎那裏也挺熱鬧。南邊是西長
安街。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"zahuopu",
		"south" : __DIR__"xichang2",
		"north" : __DIR__"xidan1",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan": 1,
		"/d/huashan/npc/youke": 2,
	]));
	set("coor/x", -220);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
