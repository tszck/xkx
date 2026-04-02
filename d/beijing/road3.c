inherit ROOM;

void create()
{
	set("short", "大驛道");
	set("long", @LONG
你走在一條塵土飛揚的大驛道上。四周人來人往。挑擔子的、行商
的，趕着大車的馬伕，上京趕考的書生，熙熙攘攘，非常熱鬧。不時還
有兩三騎快馬從身邊飛馳而過，揚起一路塵埃。道路兩旁是整整齊齊的
楊樹林。東北方向是另一條大道。
LONG );
	set("exits", ([
		"northeast" : "/d/guanwai/laolongtou",
		"northwest" : __DIR__"road2",
		"south"     : __DIR__"road4",
	]));
	set("objects",([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", -140);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

