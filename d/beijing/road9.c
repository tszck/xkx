inherit ROOM;

void create()
{
	set("short", "大驛道");
	set("long", @LONG
你走在一條塵土飛揚的大驛道上。四周人來人往。挑擔子的、行商
的、趕着大車的馬伕、上京趕考的書生，熙熙攘攘，非常熱鬧。不時還
有兩三騎快馬從身邊飛馳而過，揚起一路塵埃。馬上的人個個身着勁裝，
衣甲鮮明，有的還隨身佩帶着刀劍，看來都是些習武的江湖人。道路兩
旁是整整齊齊的楊樹林。
LONG );
	set("exits", ([
		"north" : __DIR__"road8",
		"south" : __DIR__"road10",
	]));
	set("objects",([
		"/d/taishan/npc/tangzi" : 2,
	]));
	set("outdoors", "huabei");
	set("coor/x", 10);
	set("coor/y", 3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

