inherit ROOM;

void create()
{
	set("short", "小道");
	set("long", @LONG
你走在一條塵土飛揚的大驛道上。四周人來人往。挑擔子的、行商
的、趕着大車的馬伕、上京趕考的書生，熙熙攘攘，非常熱鬧。不時還
有兩三騎快馬從身邊飛馳而過，揚起一路塵埃。道路兩旁是整整齊齊的
楊樹林。東邊就是大海之濱了。
LONG );
	set("exits", ([
		"east"  : __DIR__"haigang",
		"north" : __DIR__"road9",
		"south" : "/d/nanyang/ruzhou",
	]));
	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", 10);
	set("coor/y", 2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

