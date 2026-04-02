inherit ROOM;

void create()
{
	set("short", "僕人房");
	set("long", @LONG
這是專供僕人休息的小屋。屋裏放着五六張牀，擠擠地佔掉了屋子
的一大半地方。屋角很散亂地放了一些日常生活用具。中央放着一張桌
子，上面擺一茶壺和幾個杯子。
LONG );
	set("exits", ([
		"north"  : __DIR__"lianwuchang",
	]));
	set("objects", ([
		__DIR__"npc/puren" : 1,
	]) );    

	set_light(0) ;
	set("sleep_room","1") ;
	set("coor/x", 8980);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}