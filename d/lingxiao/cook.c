// Room: /d/lingxiao/cook.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","廚房");
	set("long",@LONG
這裏是凌霄城的廚房。一陣飯菜的香味充盈其間。一個凌霄弟子滿
頭大汗，正在做飯。他做飯方法倒也特別，人綁在一根倒吊的繩子上，
用一個奇大的鏟子來攪動一口極大的鍋。聽説是白自在去少林寺考察回
來後，要求每一個輪值做飯的弟子都要這樣幹，利於練功云云……你可
以用(serve)，來獲得飯菜。
LONG);
	set("exits",([
		"west" : __DIR__"zoulang2",
	]));
	set("objects",([
		__DIR__"npc/dizi" : 1,
	]));
	set("ricewater", 5);
	set("no_fight","1");
	set("coor/x", -30980);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
}
int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
	return notify_fail("凌霄弟子看了你一眼，喫飯傢伙你要拿到哪去？\n");
	return ::valid_leave(me, dir);
}
void init()
{
	add_action("do_serve","serve");
}
int do_serve()
{
	object me = this_player();
	object food;
	object water;

	if (me->query("family/family_name") != "凌霄城")
		return notify_fail("凌霄弟子道：你又不是凌霄城的，走開。\n");
	if(present("rice",this_player()) ) 
		return notify_fail("凌霄弟子道：喫完了再拿，別浪費食物。\n");
	if(present("rice",this_object()) ) 
		return notify_fail("凌霄弟子道：喫完了再拿，別浪費食物。\n");
	if (query("ricewater")>0)
	{
		message_vision("凌霄弟子笑道:你慢用。\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("弟子對$N歉聲道: 嗨，喫的喝的都沒了。\n",me);
	return 1; 
}

