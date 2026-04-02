// /guanwai/rouguan.c

inherit ROOM;

void create()
{
	set("short", "香肉館");
	set("long", @LONG
這是一間很小的狗肉館，屋內有一個很大的土炕，幾乎佔去了房間
的一半。炕中是一個火竈，上架一口大鐵鍋，香噴噴的熱氣從鍋中不斷
冒出。飯館的老闆坐在鍋旁，不斷的給客人盛上一碗碗熱騰騰的肉湯。
LONG );
	set("exits", ([
		"east"  : __DIR__"nancheng",
	]));
	set("objects", ([
		__DIR__"npc/laoban" : 1,
	]));
	set("coor/x", 6030);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}