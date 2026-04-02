inherit ROOM;

void create()
{
	set("short", "康府內堂");
	set("long", @LONG
這裏是康府內堂，一個僕役正在和丫環們聊天。南邊是康府
後院，北邊是書房，西邊是一座佛堂。
LONG );
	set("exits", ([
  		"west"  : __DIR__"fotang",
  		"north" : __DIR__"shufang",
  		"south" : __DIR__"kang3",
	]));
	set("objects", ([
  		__DIR__"npc/puyi": 1,
  		__DIR__"npc/yahuan": 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4083);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
