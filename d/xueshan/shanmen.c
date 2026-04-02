// shanmen.c 雪山寺山門

inherit ROOM;

void create()
{
	set("short","雪山寺山門");
	set("long",@LONG
這裏是雪山大輪寺的山門，門前是絡繹不絕的進香朝聖的信徒，有
的甚至來自烏絲藏西南的波絲。山門(gate)前站了個手持法器的葛倫布
在維持秩序，東方是一條青石板鋪成的山路。
LONG );
	set("outdoors","xueshansi");
	set("no_fight", 1);
	set("exits",([
		"north"    : __DIR__"guangchang",
		"eastdown" : "/d/xuedao/nroad4",
	]));
	set("item_desc",([
		"gate" : "兩扇厚厚的銅色大門，非合數人之力，是難以推動的。\n",
	]));
	set("objects",([
		CLASS_D("xueshan")+"/gelunbu": 1,
		"/d/wudang/npc/guest": 2,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -70000);
	set("coor/y", -20000);
	set("coor/z", 120);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "雪山寺") &&
		(dir == "north") &&
		(me->query_temp("marks/xueshangate") != 1) &&
		objectp(present("gelunbu", environment(me))))
	return notify_fail("葛倫布擋住你說：你準備用什麼供奉我們佛爺呀？\n");

	return ::valid_leave(me, dir);
}
