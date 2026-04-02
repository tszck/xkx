// Room: /yangzhou/kedian2.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "秦淮客寓二樓");
	set("long", @LONG
你正走在客寓二樓的走廊上，可以聽到客房裏不時地傳來呼呼的
打鼾聲，一陣高過一陣。不時有睡意朦朧的旅客進進出出，到樓下的
掌櫃處付了錢再上來睡覺。
LONG );
	set("exits", ([
		"down"  : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));

	set("objects", ([
                CLASS_D("shaolin") + "/xingzhe" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}