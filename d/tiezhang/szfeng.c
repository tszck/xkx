// Room: /d/tiezhang/szfeng.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "食指峯");
	set("long", @LONG
你終於爬上了峯頂，已經累得氣喘吁吁了。這裏只有丈許方圓的地
方，寸草不生，到處都是光禿禿的岩石，滑不留腳。一陣狂風呼嘯而過，
吹得你一個趔趄，差點摔倒，看來還是趕快離開這裏的好。
LONG );
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2010);
	set("coor/y", -1880);
	set("coor/z", 100);
	setup();
}
void init()
{
	add_action("do_climb","climb");
}
int do_climb(string arg)
{
	object me=this_player();

	me->receive_damage("qi", 40);
	if ((int)me->query_skill("dodge",1)<100)
		me->improve_skill("dodge",me->query("int"));

	if (arg =="down") 
	{
		write("你攀緣着石壁，緩緩向下爬去。\n");
		message("vision",me->name() + "向下爬去。\n", environment(me), ({me}) );
		me->move(__DIR__"juebi5");
		message("vision",me->name() + "爬了下來。\n", environment(me), ({me}) );
	}
	else
		return notify_fail("你要往哪裏爬？\n");
	return 1;
}

