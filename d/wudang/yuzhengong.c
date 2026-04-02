//Room: yuzhengong.c 遇真宮
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","遇真宮");
	set("long",@LONG
這裏是進入武當山的第一道宮宇遇真宮，寬敞無比，可容千人食宿，
是進香客的一大歇腳處。三豐真人曾在此結庵修煉，因此宮中供着張三
豐真人像。由於張真人閉關已久，外人不知其是否仍在人間，民間傳説
他已得道仙逝，立像膜拜。
LONG);
	set("objects", ([
	     CLASS_D("wudang") +"/zhixiang": 1,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
	    "northdown": __DIR__"shijie1",
	    "southup"  : __DIR__"wdbl",
	]));
	set("coor/x", -2050);
	set("coor/y", -820);
	set("coor/z", 40);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( dir == "southup" &&
		me->query("wudang/offerring")<me->query("age") &&
		me->query("title") != "武當道童" &&
		me->query("family/family_name") != "武當派" &&
		objectp(present("lingxu daozhang", environment(me))) &&
		!objectp(present("incense", me)) )
	{
		return notify_fail("凌虛道長喝道：如不是上山敬香，即刻請回！\n");
	}
	return ::valid_leave(me, dir);
}
